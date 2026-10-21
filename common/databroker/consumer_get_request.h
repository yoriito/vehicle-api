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

#ifndef COMMON_DATABROKER_CONSUMER_GET_REQUEST_H_
#define COMMON_DATABROKER_CONSUMER_GET_REQUEST_H_

#include <optional>
#include <string>
#include <utility>

#include "databroker/filter/get_filter.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup consumer
 * @class ConsumerGetRequest
 * @brief Class representing a request to get datapoints by a DataBroker
 * consumer.
 */
class ConsumerGetRequest {
 public:
  /**
   * @ingroup consumer
   * @fn explicit ConsumerGetRequest(std::string&& path)
   * @brief Constructs a ConsumerGetRequest with the specified path and no
   * filter.
   * @deprecated -
   * @pre -
   * @param path The datapoint path as a string (rvalue reference).
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ConsumerGetRequest(std::string path)
      : path_(std::move(path)), filter_(std::nullopt) {}

  /**
   * @ingroup consumer
   * @fn explicit ConsumerGetRequest(std::string&& path, filter::GetFilter&&
   * filter)
   * @brief Constructs a ConsumerGetRequest with the specified path and filter.
   * @deprecated -
   * @pre -
   * @param path The datapoint path as a string (rvalue reference).
   * @param filter The GetFilter to apply for the request.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ConsumerGetRequest(std::string path, filter::GetFilter filter)
      : path_(std::move(path)), filter_(std::move(filter)) {}

  /**
   * @ingroup consumer
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
  const std::string& GetPath() const& { return path_; }
  std::string GetPath() const&& { return path_; }

  /**
   * @ingroup consumer
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
  const std::optional<filter::GetFilter>& GetFilter() const& { return filter_; }
  std::optional<filter::GetFilter> GetFilter() const&& { return filter_; }

  /**
   * @ingroup consumer
   * @fn friend bool operator==(const ConsumerGetRequest& lhs, const
   * ConsumerGetRequest& rhs)
   * @brief Compares two ConsumerGetRequest objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs The left-hand side ConsumerGetRequest.
   * @param rhs The right-hand side ConsumerGetRequest.
   * @retval true if both path and filter are equal; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const ConsumerGetRequest& lhs,
                         const ConsumerGetRequest& rhs) {
    return lhs.path_ == rhs.path_ && lhs.filter_ == rhs.filter_;
  }

 private:
  std::string path_;
  std::optional<filter::GetFilter> filter_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_CONSUMER_GET_REQUEST_H_
