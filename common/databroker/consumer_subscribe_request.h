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

#ifndef COMMON_DATABROKER_CONSUMER_SUBSCRIBE_REQUEST_H_
#define COMMON_DATABROKER_CONSUMER_SUBSCRIBE_REQUEST_H_

#include <string>

#include "databroker/filter/subscribe_filter.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup consumer
 * @class ConsumerSubscribeRequest
 * @brief Class representing a request to subscribe to datapoints by a
 * DataBroker consumer.
 */
class ConsumerSubscribeRequest {
 public:
  /**
   * @ingroup consumer
   * @fn ConsumerSubscribeRequest::ConsumerSubscribeRequest(std::string path)
   * @brief Construct a ConsumerSubscribeRequest with path only.
   * @deprecated -
   * @pre -
   * @param path The datapoint path.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ConsumerSubscribeRequest(std::string path)
      : path_(std::move(path)), filter_(std::nullopt) {}

  /**
   * @ingroup consumer
   * @fn ConsumerSubscribeRequest::ConsumerSubscribeRequest(std::string path,
   * yoriito::databroker::filter::SubscribeFilter&& filter)
   * @brief Construct a ConsumerSubscribeRequest with path and filter.
   * @deprecated -
   * @pre -
   * @param path The datapoint path.
   * @param filter The subscribe filter.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ConsumerSubscribeRequest(
    std::string path, yoriito::databroker::filter::SubscribeFilter filter)
      : path_(std::move(path)), filter_(std::move(filter)) {}

  ConsumerSubscribeRequest(const ConsumerSubscribeRequest&) = delete;
  ConsumerSubscribeRequest& operator=(const ConsumerSubscribeRequest&) = delete;
  ConsumerSubscribeRequest(ConsumerSubscribeRequest&&) = default;
  ConsumerSubscribeRequest& operator=(ConsumerSubscribeRequest&&) = default;
  ~ConsumerSubscribeRequest() = default;

  /**
   * @ingroup consumer
   * @fn const std::string& ConsumerSubscribeRequest::GetPath() const
   * @brief Get the datapoint path.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::string Datapoint path
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetPath() const& { return path_; }
  std::string GetPath() const&& { return path_; }
  /**
   * @ingroup consumer
   * @fn const std::optional<yoriito::databroker::filter::SubscribeFilter>&
   * ConsumerSubscribeRequest::GetFilter() const
   * @brief Get the subscribe filter if set.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::optional<SubscribeFilter> Subscribe filter or nullopt
   * @note -
   * @code -
   * @endcode -
   */
  const std::optional<yoriito::databroker::filter::SubscribeFilter>& GetFilter()
    const& {
    return filter_;
  }
  // SubscribeFilter is move-only, so the rvalue overload moves rather than
  // copies.
  std::optional<yoriito::databroker::filter::SubscribeFilter> GetFilter() && {
    return std::move(filter_);
  }

  /**
   * @ingroup consumer
   * @fn bool operator==(const ConsumerSubscribeRequest& lhs, const
   * ConsumerSubscribeRequest& rhs)
   * @brief Compare two ConsumerSubscribeRequest objects for equality.
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
  friend bool operator==(const ConsumerSubscribeRequest& lhs,
                         const ConsumerSubscribeRequest& rhs) {
    return lhs.path_ == rhs.path_ && lhs.filter_ == rhs.filter_;
  }

 private:
  std::string path_;
  std::optional<yoriito::databroker::filter::SubscribeFilter> filter_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_CONSUMER_SUBSCRIBE_REQUEST_H_
