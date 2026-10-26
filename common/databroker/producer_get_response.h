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

#ifndef COMMON_DATABROKER_PRODUCER_GET_RESPONSE_H_
#define COMMON_DATABROKER_PRODUCER_GET_RESPONSE_H_

#include <iostream>
#include <optional>
#include <string>
#include <utility>
#include <vector>

#include "databroker/producer_get_datapoint.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup producer
 * @class ProducerGetResponse
 * @brief Class representing a response containing datapoints retrieved by a
 * DataBroker producer.
 */
class ProducerGetResponse {
 public:
  ProducerGetResponse() = delete;

  /**
   * @ingroup producer
   * @fn explicit ProducerGetResponse(std::vector<ProducerGetDataPoint>&&
   * data_points)
   * @brief Constructs a ProducerGetResponse with the given datapoints.
   * @deprecated -
   * @pre -
   * @param data_points The vector of ProducerGetDataPoint objects.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerGetResponse(std::vector<ProducerGetDataPoint>&& data_points)
      : data_points_(std::move(data_points)) {}

  /**
   * @ingroup producer
   * @fn const std::vector<ProducerGetDataPoint>& GetDataPoints() const
   * @brief Gets the datapoints contained in this get response.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Reference to the vector of ProducerGetDataPoint.
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<ProducerGetDataPoint>& GetDataPoints() const {
    return data_points_;
  }

 private:
  std::vector<ProducerGetDataPoint> data_points_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_PRODUCER_GET_RESPONSE_H_
