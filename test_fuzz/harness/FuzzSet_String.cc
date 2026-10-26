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

// FuzzSet_String.cc
// Target signal: yoriito::vehicle::powertrain::transmission::performancemode::Set()
// Validation pattern: allowed

// Detects: allowed-value list logic bugs (string type, no std::get<> involved)
//
// Input format: raw string bytes passed to Set()

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#include "databroker/base_inspect_data.h"
#include "databroker/consumer_inspect_data.h"
#include "error.h"
#include "mock/mock_databroker_consumer.h"
#include "result.h"
#include "signal/powertrain/transmission/Signal_PerformanceMode.h"
#include "FuzzHelpers.h"

namespace sig = yoriito::vehicle::powertrain::transmission::performancemode;

int main(int, char**) {
  __AFL_INIT();

  char buf[256];

  while (__AFL_LOOP(1000)) {
    auto& mock = fuzz_mock::GetMock();
    mock.Reset();

    auto builder = yoriito::databroker::ConsumerInspectData::CreateBuilder();
    builder.SetPath(sig::VEHICLE_POWERTRAIN_TRANSMISSION_PERFORMANCEMODE)
      .SetDataType(
        yoriito::databroker::BaseInspectData::DataType::DATA_TYPE_STRING)
      .SetEntryType(
        yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_ACTUATOR)
      .SetAllowed(
        std::vector<std::string>{"NORMAL", "SPORT", "ECONOMY", "SNOW", "RAIN"});
    auto inspect_data =
      yoriito::databroker::ConsumerInspectData::CreateFromBuilder(builder);
    mock.inspect_data = &inspect_data;

    size_t len = fread(buf, 1, sizeof(buf) - 1, stdin);
    if (len == 0) continue;
    buf[len] = '\0';
    std::string value(buf, len);

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
