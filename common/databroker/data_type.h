/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright 2026 JASPAR
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef COMMON_DATABROKER_DATA_TYPE_H_
#define COMMON_DATABROKER_DATA_TYPE_H_

namespace yoriito::databroker {

enum class DataType {
  DATA_TYPE_UNSPECIFIED,
  DATA_TYPE_STRING,
  DATA_TYPE_BOOLEAN,
  DATA_TYPE_INT8,
  DATA_TYPE_INT16,
  DATA_TYPE_INT32,
  DATA_TYPE_INT64,
  DATA_TYPE_UINT8,
  DATA_TYPE_UINT16,
  DATA_TYPE_UINT32,
  DATA_TYPE_UINT64,
  DATA_TYPE_FLOAT,
  DATA_TYPE_DOUBLE,
  DATA_TYPE_TIMESTAMP,  // Not exist in VSS
  DATA_TYPE_STRING_ARRAY,
  DATA_TYPE_BOOLEAN_ARRAY,
  DATA_TYPE_INT8_ARRAY,
  DATA_TYPE_INT16_ARRAY,
  DATA_TYPE_INT32_ARRAY,
  DATA_TYPE_INT64_ARRAY,
  DATA_TYPE_UINT8_ARRAY,
  DATA_TYPE_UINT16_ARRAY,
  DATA_TYPE_UINT32_ARRAY,
  DATA_TYPE_UINT64_ARRAY,
  DATA_TYPE_FLOAT_ARRAY,
  DATA_TYPE_DOUBLE_ARRAY,
  DATA_TYPE_STRUCT,
  DATA_TYPE_STRUCT_ARRAY
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_DATA_TYPE_H_
