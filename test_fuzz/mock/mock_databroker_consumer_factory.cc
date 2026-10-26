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

// mock_databroker_consumer_factory.cc
// Provides a strong-symbol override of DataBrokerConsumerFactory::GetInstance()
// so that the fuzz mock is returned instead of the real implementation.
// Compiled as a .cc file so the linker prefers this definition over the shared
// library's weak symbol.

#include "mock/mock_databroker_consumer.h"

namespace yoriito::databroker {
  DataBrokerConsumer* DataBrokerConsumerFactory::GetInstance() {
    return &fuzz_mock::GetMock();
  }
}  // namespace yoriito::databroker
