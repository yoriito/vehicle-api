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

#ifndef COMMON_DATABROKER_CONSUMER_SET_REQUEST_H_
#define COMMON_DATABROKER_CONSUMER_SET_REQUEST_H_

#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

#include "databroker_type.h"
#include "databroker/consumer_set_datapoint.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup consumer
 * @class ConsumerSetRequest
 * @brief Class representing a request to set datapoints by a DataBroker
 * consumer.
 */
class ConsumerSetRequest {
 public:
  /**
   * @ingroup consumer
   * @fn ConsumerSetRequest::ConsumerSetRequest()
   * @brief Deleted default constructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ConsumerSetRequest() = delete;

  /**
   * @ingroup consumer
   * @fn
   * ConsumerSetRequest::ConsumerSetRequest(std::vector<yoriito::databroker::ConsumerSetDataPoint>&&
   * data_points)
   * @brief Construct a ConsumerSetRequest object with data points.
   * @deprecated -
   * @pre -
   * @param data_points Vector of ConsumerSetDataPoint objects.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ConsumerSetRequest(
    std::vector<yoriito::databroker::ConsumerSetDataPoint> data_points)
      : data_points_(std::move(data_points)) {}

  /**
   * @ingroup consumer
   * @fn const std::vector<yoriito::databroker::ConsumerSetDataPoint>&
   * ConsumerSetRequest::GetDataPoints() const
   * @brief Get the vector of ConsumerSetDataPoint objects.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::vector<ConsumerSetDataPoint> Vector of data points
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<yoriito::databroker::ConsumerSetDataPoint>& GetDataPoints()
    const& {
    return data_points_;
  }
  std::vector<yoriito::databroker::ConsumerSetDataPoint> GetDataPoints()
    const&& {
    return data_points_;
  }

  /**
   * @ingroup consumer
   * @fn bool operator==(const ConsumerSetRequest& lhs, const
   * ConsumerSetRequest& rhs)
   * @brief Compare two ConsumerSetRequest objects for equality.
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
  friend bool operator==(const ConsumerSetRequest& lhs,
                         const ConsumerSetRequest& rhs) {
    return lhs.data_points_ == rhs.data_points_;
  }

 private:
  std::vector<yoriito::databroker::ConsumerSetDataPoint> data_points_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_CONSUMER_SET_REQUEST_H_
