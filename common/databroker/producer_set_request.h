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

#ifndef COMMON_DATABROKER_PRODUCER_SET_REQUEST_H_
#define COMMON_DATABROKER_PRODUCER_SET_REQUEST_H_

#include <string>
#include <string_view>
#include <utility>
#include <variant>
#include <vector>

#include "databroker/producer_set_datapoint.h"
#include "databroker_type.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup producer
 * @class ProducerSetRequest
 * @brief Class representing a request to set datapoints by a DataBroker
 * producer.
 */
class ProducerSetRequest {
 public:
  ProducerSetRequest() = delete;

  /**
   * @ingroup producer
   * @fn explicit ProducerSetRequest(const
   * std::vector<yoriito::databroker::ProducerSetDataPoint>& data_points)
   * @brief Constructs a ProducerSetRequest with a vector of
   * ProducerSetDataPoint (copy).
   * @deprecated -
   * @pre -
   * @param data_points The vector of ProducerSetDataPoint to copy.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerSetRequest(
      const std::vector<yoriito::databroker::ProducerSetDataPoint>& data_points)
      : data_points_(data_points) {}

  /**
   * @ingroup producer
   * @fn explicit
   * ProducerSetRequest(std::vector<yoriito::databroker::ProducerSetDataPoint>&&
   * data_points)
   * @brief Constructs a ProducerSetRequest with a vector of
   * ProducerSetDataPoint (move).
   * @deprecated -
   * @pre -
   * @param data_points The vector of ProducerSetDataPoint to move.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerSetRequest(
      std::vector<yoriito::databroker::ProducerSetDataPoint>&& data_points)
      : data_points_(std::move(data_points)) {}

  /**
   * @ingroup producer
   * @fn
   * ProducerSetRequest(std::initializer_list<yoriito::databroker::ProducerSetDataPoint>
   * data_points)
   * @brief Constructs a ProducerSetRequest with an initializer list of
   * ProducerSetDataPoint.
   * @deprecated -
   * @pre -
   * @param data_points The initializer list of ProducerSetDataPoint.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ProducerSetRequest(
      std::initializer_list<yoriito::databroker::ProducerSetDataPoint>
          data_points)
      : data_points_(data_points) {}

  // Getter

  /**
   * @ingroup producer
   * @fn const std::vector<yoriito::databroker::ProducerSetDataPoint>&
   * GetDataPoints() const
   * @brief Gets the datapoints contained in this set request.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Reference to the vector of ProducerSetDataPoint.
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<yoriito::databroker::ProducerSetDataPoint>& GetDataPoints()
      const {
    return data_points_;
  }

  /**
   * @ingroup producer
   * @fn friend bool operator==(const ProducerSetRequest& lhs, const
   * ProducerSetRequest& rhs)
   * @brief Compares two ProducerSetRequest objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs The left-hand side ProducerSetRequest.
   * @param rhs The right-hand side ProducerSetRequest.
   * @retval true if both data_points_ are equal; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const ProducerSetRequest& lhs,
                         const ProducerSetRequest& rhs) {
    return lhs.data_points_ == rhs.data_points_;
  }

 private:
  std::vector<yoriito::databroker::ProducerSetDataPoint> data_points_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_PRODUCER_SET_REQUEST_H_
