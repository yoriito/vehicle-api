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

#ifndef TEST_FUZZ_HARNESS_FUZZ_HELPERS_H_
#define TEST_FUZZ_HARNESS_FUZZ_HELPERS_H_

#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

#include "databroker_type.h"

#ifndef __AFL_INIT
#define __AFL_INIT() \
  do {               \
  } while (0)
#define __AFL_LOOP(x)  \
  ({                   \
    static int _l = 0; \
    _l++ < 1;          \
  })
#endif

yoriito::ValueType make_value_from_index(uint8_t index, const uint8_t* data,
                                         size_t len);

#endif  // TEST_FUZZ_HARNESS_FUZZ_HELPERS_H_
