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

// FuzzGet_VehicleLocation.cc
// Target signal: yoriito::vehicle::currentlocation::vehiclelocation::Get()
// Exercises: FromStructData() deserialization with arbitrary StructData inputs.
//
// Input format (112 bytes total):
//   buf[0:64] : Timestamp (std::string)
//   buf[64:72] : Latitude (double)
//   buf[72:80] : Longitude (double)
//   buf[80:88] : HorizontalAccuracy (double)
//   buf[88:96] : Altitude (double)
//   buf[96:104] : VerticalAccuracy (double)
//   buf[104:112] : Heading (double)

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
#include "signal/currentlocation/Signal_VehicleLocation.h"
#include "FuzzHelpers.h"

namespace sig = yoriito::vehicle::currentlocation::vehiclelocation;

int main(int, char**) {
  __AFL_INIT();

  uint8_t buf[112];

  while (__AFL_LOOP(1000)) {
    auto& mock = fuzz_mock::GetMock();
    mock.Reset();

    size_t len = fread(buf, 1, sizeof(buf), stdin);

    yoriito::StructData struct_data;
    if (len > 0) {
      size_t str_len = std::min(len - 0, static_cast<size_t>(64));
      struct_data.SetProperty("Timestamp",
        std::string(reinterpret_cast<const char*>(buf + 0), str_len));
    }
    if (len >= 72) {
      double tmp{};
      std::memcpy(&tmp, buf + 64, sizeof(tmp));
      struct_data.SetProperty("Latitude", tmp);
    }
    if (len >= 80) {
      double tmp{};
      std::memcpy(&tmp, buf + 72, sizeof(tmp));
      struct_data.SetProperty("Longitude", tmp);
    }
    if (len >= 88) {
      double tmp{};
      std::memcpy(&tmp, buf + 80, sizeof(tmp));
      struct_data.SetProperty("HorizontalAccuracy", tmp);
    }
    if (len >= 96) {
      double tmp{};
      std::memcpy(&tmp, buf + 88, sizeof(tmp));
      struct_data.SetProperty("Altitude", tmp);
    }
    if (len >= 104) {
      double tmp{};
      std::memcpy(&tmp, buf + 96, sizeof(tmp));
      struct_data.SetProperty("VerticalAccuracy", tmp);
    }
    if (len >= 112) {
      double tmp{};
      std::memcpy(&tmp, buf + 104, sizeof(tmp));
      struct_data.SetProperty("Heading", tmp);
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
