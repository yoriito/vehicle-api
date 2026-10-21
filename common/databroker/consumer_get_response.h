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

#ifndef COMMON_DATABROKER_CONSUMER_GET_RESPONSE_H_
#define COMMON_DATABROKER_CONSUMER_GET_RESPONSE_H_

#include <iostream>
#include <optional>
#include <string>
#include <utility>
#include <vector>

#include "databroker/consumer_get_datapoint.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup consumer
 * @class ConsumerGetResponse
 * @brief Class representing a response containing datapoints retrieved by a
 * DataBroker consumer.
 */
class ConsumerGetResponse {
 public:
  /**
   * @ingroup consumer
   * @fn ConsumerGetResponse::ConsumerGetResponse()
   * @brief Deleted default constructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ConsumerGetResponse() = delete;

  /**
   * @ingroup consumer
   * @fn
   * ConsumerGetResponse::ConsumerGetResponse(std::vector<yoriito::databroker::ConsumerGetDataPoint>&&
   * data_points)
   * @brief Construct a ConsumerGetResponse object with datapoints.
   * @deprecated -
   * @pre -
   * @param data_points Vector of ConsumerGetDataPoint objects.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ConsumerGetResponse(
    std::vector<yoriito::databroker::ConsumerGetDataPoint> data_points)
      : data_points_(std::move(data_points)) {}

  /**
   * @ingroup consumer
   * @fn const std::vector<ConsumerGetDataPoint>&
   * ConsumerGetResponse::GetDataPoints() const
   * @brief Get the vector of ConsumerGetDataPoint objects.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::vector<ConsumerGetDataPoint> Vector of datapoints
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<ConsumerGetDataPoint>& GetDataPoints() const& {
    return data_points_;
  }
  std::vector<ConsumerGetDataPoint> GetDataPoints() const&& {
    return data_points_;
  }

 private:
  std::vector<ConsumerGetDataPoint> data_points_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_CONSUMER_GET_RESPONSE_H_
