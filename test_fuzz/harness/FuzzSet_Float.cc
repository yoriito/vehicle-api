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

// FuzzSet_Float.cc
// Target signal: yoriito::vehicle::body::rearmainspoilerposition::Set()
// Validation pattern: min_max

// Detects: std::get<float>(min_data) / std::get<float>(max_data)
//          type mismatch -> std::bad_variant_access crash
//
// Input format:
//   buf[0]             : type_index for min (controls variant type injected into min)
//   buf[1]             : type_index for max
//   buf[2:2+sizeof(T)] : set value bytes

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include "databroker/base_inspect_data.h"
#include "databroker/consumer_inspect_data.h"
#include "error.h"
#include "mock/mock_databroker_consumer.h"
#include "result.h"
#include "signal/body/Signal_RearMainSpoilerPosition.h"
#include "FuzzHelpers.h"

namespace sig = yoriito::vehicle::body::rearmainspoilerposition;

int main(int, char**) {
  __AFL_INIT();

  uint8_t buf[2 + sizeof(float)];

  while (__AFL_LOOP(1000)) {
    auto& mock = fuzz_mock::GetMock();
    mock.Reset();

    size_t len = fread(buf, 1, sizeof(buf), stdin);
    if (len < 2) continue;

    // buf[0] = type_index for min; buf[1] = type_index for max; buf[2:] = set value bytes
    const uint8_t* payload = buf + 2;
    size_t payload_len = len > 2 ? len - 2 : 0;
    yoriito::ValueType fuzz_min =
      make_value_from_index(buf[0], payload, payload_len);
    yoriito::ValueType fuzz_max =
      make_value_from_index(buf[1], payload, payload_len);

    auto builder = yoriito::databroker::ConsumerInspectData::CreateBuilder();
    builder.SetPath(sig::VEHICLE_BODY_REARMAINSPOILERPOSITION)
      .SetDataType(
        yoriito::databroker::BaseInspectData::DataType::DATA_TYPE_FLOAT)
      .SetEntryType(
        yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_ACTUATOR)
      .SetMin(fuzz_min)
      .SetMax(fuzz_max);
    auto inspect_data =
      yoriito::databroker::ConsumerInspectData::CreateFromBuilder(builder);
    mock.inspect_data = &inspect_data;

    float value{};
    if (len >= 2 + sizeof(float)) {
      memcpy(&value, buf + 2, sizeof(float));
    }

    try {
      auto set_ret = sig::Set(value);
      if (set_ret.IsErr()) {
        auto err = set_ret.TakeErr();
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
