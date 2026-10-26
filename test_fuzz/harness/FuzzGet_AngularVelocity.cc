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

// FuzzGet_AngularVelocity.cc
// Target signal: yoriito::vehicle::angularvelocity::Get()
// Exercises: FromStructData() deserialization with arbitrary StructData inputs.
//
// Input format (12 bytes total):
//   buf[0:4] : Roll (float)
//   buf[4:8] : Pitch (float)
//   buf[8:12] : Yaw (float)

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>

#include "databroker_type.h"
#include "error.h"
#include "mock/mock_databroker_consumer.h"
#include "result.h"
#include "signal/Signal_AngularVelocity.h"
#include "FuzzHelpers.h"

namespace sig = yoriito::vehicle::angularvelocity;

int main(int, char**) {
  __AFL_INIT();

  uint8_t buf[12];

  while (__AFL_LOOP(1000)) {
    auto& mock = fuzz_mock::GetMock();
    mock.Reset();

    size_t len = fread(buf, 1, sizeof(buf), stdin);

    yoriito::StructData struct_data;
    if (len >= 4) {
      float tmp{};
      std::memcpy(&tmp, buf + 0, sizeof(tmp));
      struct_data.SetProperty("Roll", tmp);
    }
    if (len >= 8) {
      float tmp{};
      std::memcpy(&tmp, buf + 4, sizeof(tmp));
      struct_data.SetProperty("Pitch", tmp);
    }
    if (len >= 12) {
      float tmp{};
      std::memcpy(&tmp, buf + 8, sizeof(tmp));
      struct_data.SetProperty("Yaw", tmp);
    }

    mock.struct_get_data = &struct_data;

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
