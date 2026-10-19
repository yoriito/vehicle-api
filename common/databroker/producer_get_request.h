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

#ifndef COMMON_DATABROKER_PRODUCER_GET_REQUEST_H_
#define COMMON_DATABROKER_PRODUCER_GET_REQUEST_H_

#include <iostream>
#include <optional>
#include <string>
#include <utility>
#include <vector>

#include "databroker/filter/get_filter.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup producer
 * @class ProducerGetRequest
 * @brief Class representing a request to get datapoints for a DataBroker
 * producer.
 */
class ProducerGetRequest {
 public:
  /**
   * @ingroup producer
   * @fn explicit ProducerGetRequest(std::string&& path)
   * @brief Constructs a ProducerGetRequest with the specified path and no
   * filter.
   * @deprecated -
   * @pre -
   * @param path The datapoint path as a string (rvalue reference).
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerGetRequest(std::string&& path)
      : path_(std::move(path)), filter_(std::nullopt) {}

  /**
   * @ingroup producer
   * @fn ProducerGetRequest(std::string&& path, filter::GetFilter&& filter)
   * @brief Constructs a ProducerGetRequest with the specified path and filter.
   * @deprecated -
   * @pre -
   * @param path The datapoint path as a string (rvalue reference).
   * @param filter The GetFilter to apply for the request.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ProducerGetRequest(std::string&& path, filter::GetFilter&& filter)
      : path_(std::move(path)), filter_(std::move(filter)) {}

  // Getter

  /**
   * @ingroup producer
   * @fn const std::string& GetPath() const
   * @brief Gets the datapoint path for this get request.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Reference to the datapoint path string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetPath() const { return path_; }

  /**
   * @ingroup producer
   * @fn const std::optional<filter::GetFilter>& GetFilter() const
   * @brief Gets the filter applied to this get request, if any.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Reference to the optional GetFilter.
   * @note -
   * @code -
   * @endcode -
   */
  const std::optional<filter::GetFilter>& GetFilter() const { return filter_; }

  /**
   * @ingroup producer
   * @fn friend bool operator==(const ProducerGetRequest& lhs, const
   * ProducerGetRequest& rhs)
   * @brief Compares two ProducerGetRequest objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs The left-hand side ProducerGetRequest.
   * @param rhs The right-hand side ProducerGetRequest.
   * @retval true if both path and filter are equal; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const ProducerGetRequest& lhs,
                         const ProducerGetRequest& rhs) {
    return lhs.path_ == rhs.path_ && lhs.filter_ == rhs.filter_;
  }

 private:
  std::string path_;
  std::optional<filter::GetFilter> filter_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_PRODUCER_GET_REQUEST_H_
