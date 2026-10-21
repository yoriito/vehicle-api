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

#ifndef COMMON_DATABROKER_PRODUCER_GET_DATAPOINT_H_
#define COMMON_DATABROKER_PRODUCER_GET_DATAPOINT_H_

#include <iostream>
#include <optional>
#include <string>
#include <vector>

#include "databroker/base_get_datapoint.h"
#include "databroker_type.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup producer
 * @class ProducerGetDataPoint
 * @brief Class representing a datapoint retrieved by a DataBroker producer.
 */
class ProducerGetDataPoint : public BaseGetDataPoint {
 public:
  /**
   * @ingroup producer
   * @fn ProducerGetDataPoint(const std::string& path, const ValueType& data)
   * @brief Constructs a ProducerGetDataPoint with the specified path and data.
   * @deprecated -
   * @pre -
   * @param path The datapoint path as a string.
   * @param data The value to be set for the datapoint.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ProducerGetDataPoint(const std::string& path, const ValueType& data)
      : BaseGetDataPoint(path, data) {}
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_PRODUCER_GET_DATAPOINT_H_
