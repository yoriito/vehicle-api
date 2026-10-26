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

#ifndef COMMON_DATABROKER_PRODUCER_SUBSCRIBE_REQUEST_H_
#define COMMON_DATABROKER_PRODUCER_SUBSCRIBE_REQUEST_H_

#include <string>
#include <utility>

#include "databroker/filter/subscribe_filter.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup producer
 * @class ProducerSubscribeRequest
 * @brief Class representing a request to subscribe to datapoints by a
 * DataBroker producer.
 */
class ProducerSubscribeRequest {
 public:
  /**
   * @ingroup producer
   * @fn explicit ProducerSubscribeRequest(std::string path)
   * @brief Constructs a ProducerSubscribeRequest with the specified path and no
   * filter.
   * @deprecated -
   * @pre -
   * @param path The datapoint path as a string.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerSubscribeRequest(std::string path)
      : path_(std::move(path)), filter_(std::nullopt) {}

  /**
   * @ingroup producer
   * @fn explicit ProducerSubscribeRequest(std::string path,
   * yoriito::databroker::filter::SubscribeFilter&& filter)
   * @brief Constructs a ProducerSubscribeRequest with the specified path and
   * filter.
   * @deprecated -
   * @pre -
   * @param path The datapoint path as a string.
   * @param filter The SubscribeFilter to apply for the subscription.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerSubscribeRequest(
      std::string path, yoriito::databroker::filter::SubscribeFilter&& filter)
      : path_(std::move(path)), filter_(std::move(filter)) {}

  ProducerSubscribeRequest(const ProducerSubscribeRequest&) = delete;
  ProducerSubscribeRequest& operator=(const ProducerSubscribeRequest&) = delete;
  ProducerSubscribeRequest(ProducerSubscribeRequest&&) = default;
  ProducerSubscribeRequest& operator=(ProducerSubscribeRequest&&) = default;
  ~ProducerSubscribeRequest() = default;

  /**
   * @ingroup producer
   * @fn const std::string& GetPath() const
   * @brief Gets the datapoint path for this subscription request.
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
   * @fn const std::optional<yoriito::databroker::filter::SubscribeFilter>&
   * GetFilter() const
   * @brief Gets the filter applied to this subscription request, if any.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Reference to the optional SubscribeFilter.
   * @note -
   * @code -
   * @endcode -
   */
  const std::optional<yoriito::databroker::filter::SubscribeFilter>& GetFilter()
      const {
    return filter_;
  }

  /**
   * @ingroup producer
   * @fn friend bool operator==(const ProducerSubscribeRequest& lhs, const
   * ProducerSubscribeRequest& rhs)
   * @brief Compares two ProducerSubscribeRequest objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs The left-hand side ProducerSubscribeRequest.
   * @param rhs The right-hand side ProducerSubscribeRequest.
   * @retval true if both path and filter are equal; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const ProducerSubscribeRequest& lhs,
                         const ProducerSubscribeRequest& rhs) {
    return lhs.path_ == rhs.path_ && lhs.filter_ == rhs.filter_;
  }

 private:
  std::string path_;
  std::optional<yoriito::databroker::filter::SubscribeFilter> filter_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_PRODUCER_SUBSCRIBE_REQUEST_H_
