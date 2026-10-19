// SPDX-License-Identifier: Apache-2.0
//
// Copyright 2026 JASPAR
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// FuzzGet_Float.cc
// Target signal: yoriito::vehicle::speed::Get()
// Detects: std::get<float>(data) type mismatch -> std::bad_variant_access crash
//
// Input format:
//   buf[0]   : ValueType variant index (0-25), controls which type is injected
//   buf[1:]  : raw bytes used as the variant value
//
// When buf[0] selects any type other than float, Get() calls
// std::get<float>(data) and throws std::bad_variant_access -> SIGABRT.

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include "error.h"
#include "mock/mock_databroker_consumer.h"
#include "result.h"
#include "signal/Signal_Speed.h"
#include "FuzzHelpers.h"

namespace sig = yoriito::vehicle::speed;

int main(int, char**) {
  __AFL_INIT();

  uint8_t buf[256];

  while (__AFL_LOOP(1000)) {
    auto& mock = fuzz_mock::GetMock();
    mock.Reset();

    size_t len = fread(buf, 1, sizeof(buf), stdin);
    if (len < 1) continue;

    // buf[0] controls the ValueType variant; buf[1:] provides the data bytes.
    // When buf[0] maps to any type != float, std::get<float>
    // inside Get() throws std::bad_variant_access -> detected as crash.
    uint8_t type_index = buf[0];
    mock.get_value = make_value_from_index(type_index, buf + 1, len - 1);

    try {
      auto result = sig::Get();
      if (result.IsErr()) {
        auto err = result.TakeErr();
        assert(err != nullptr);
      }
    } catch (...) {
      // In AFL++ persistent mode, an uncaught exception causes terminate() ->
      // abort() -> SIGABRT, killing the process mid-loop. AFL++ waits for
      // the process to return to __AFL_LOOP(), but it never does, so AFL++
      // classifies it as a hang instead of a crash.
      // _Exit(42) exits immediately without destructors, and AFL_CRASH_EXITCODE=42
      // in run_fuzz_all.sh tells AFL++ to treat this as a crash.
      _Exit(42);
    }
  }

  return 0;
}
