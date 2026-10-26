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

#ifndef COMMON_DATABROKER_CONSUMER_SET_DATAPOINT_H_
#define COMMON_DATABROKER_CONSUMER_SET_DATAPOINT_H_

#include <string>

#include "databroker/base_set_datapoint.h"
#include "databroker_type.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup consumer
 * @class ConsumerSetDataPoint
 * @brief Class representing a datapoint to be set by a DataBroker consumer.
 */
class ConsumerSetDataPoint : public BaseSetDataPoint {
 public:
  /**
   * @ingroup consumer
   * @fn ConsumerSetDataPoint::ConsumerSetDataPoint(const std::string& path,
   * const ValueType& data)
   * @brief Construct a ConsumerSetDataPoint object.
   * @deprecated -
   * @pre -
   * @param path The datapoint path.
   * @param data The datapoint value.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ConsumerSetDataPoint(const std::string& path, const ValueType& data)
      : BaseSetDataPoint(path, data) {}

  /**
   * @ingroup consumer
   * @fn bool operator==(const ConsumerSetDataPoint& lhs, const
   * ConsumerSetDataPoint& rhs)
   * @brief Compare two ConsumerSetDataPoint objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs Left-hand side object.
   * @param rhs Right-hand side object.
   * @retval true Objects are equal
   * @retval false Objects are not equal
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const ConsumerSetDataPoint& lhs,
                         const ConsumerSetDataPoint& rhs) {
    return static_cast<const BaseSetDataPoint&>(lhs) ==
           static_cast<const BaseSetDataPoint&>(rhs);
  }
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_CONSUMER_SET_DATAPOINT_H_
