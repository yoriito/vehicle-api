/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright 2026 JASPAR
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SIGNAL_TYPES_INTERNAL_STRUCT_VEHICLELOCATION_INTERNAL_H_
#define SIGNAL_TYPES_INTERNAL_STRUCT_VEHICLELOCATION_INTERNAL_H_

#include <string>

#include "databroker/consumer_inspect_response.h"
#include "databroker_type.h"
#include "error.h"
#include "result.h"
#include "types/Struct_VehicleLocation.h"
#include "yoriito_log.h"

// clang-format off
namespace yoriito::types::internal {
// clang-format on

class VehicleLocationUtility {
 public:
  // Convert VehicleLocation data to StructData.
  static yoriito::StructDataPtr ToStructData(const VehicleLocation& data);

  // Load VehicleLocation data from StructData.
  static bool FromStructData(const yoriito::StructData& struct_data,
                             VehicleLocation* data);

  // Validate VehicleLocation data.
  static yoriito::Result<void> Validate(
      const yoriito::databroker::ConsumerInspectResponse& inspect_response,
      const VehicleLocation& data);

 private:
  template <typename T>
  static bool ExtractProperty(const yoriito::StructData& struct_data,
                              const std::string& prop_name, T* prop_value);

  static yoriito::Result<void> ValidateProperties(
      const std::shared_ptr<yoriito::databroker::StructType>& struct_type,
      const VehicleLocation& data);

  template <typename T>
  static yoriito::Result<void> ValidatePropertyRange(
      const std::shared_ptr<yoriito::databroker::StructType>& struct_type,
      const std::string& prop_path, const T& prop_value);
};

// clang-format off
}  // namespace yoriito::types::internal
// clang-format on

#endif  // SIGNAL_TYPES_INTERNAL_STRUCT_VEHICLELOCATION_INTERNAL_H_
