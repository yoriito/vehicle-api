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

#ifndef COMMON_DATABROKER_CONSUMER_INSPECT_REQUEST_H_
#define COMMON_DATABROKER_CONSUMER_INSPECT_REQUEST_H_

#include <iostream>
#include <optional>
#include <string>
#include <utility>
#include <vector>

#include "databroker/filter/inspect_filter.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup consumer
 * @class ConsumerInspectRequest
 * @brief Request class for inspecting datapoint metadata in the DataBroker.
 */
class ConsumerInspectRequest {
 public:
  /**
   * @ingroup consumer
   * @fn ConsumerInspectRequest::ConsumerInspectRequest(std::string&& path)
   * @brief Construct a ConsumerInspectRequest with path only.
   * @deprecated -
   * @pre -
   * @param path The datapoint path.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ConsumerInspectRequest(std::string path)
      : path_(std::move(path)), filter_(std::nullopt) {}

  /**
   * @ingroup consumer
   * @fn ConsumerInspectRequest::ConsumerInspectRequest(std::string&& path,
   * filter::InspectFilter&& filter)
   * @brief Construct a ConsumerInspectRequest with path and filter.
   * @deprecated -
   * @pre -
   * @param path The datapoint path.
   * @param filter The inspect filter.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ConsumerInspectRequest(std::string path, filter::InspectFilter filter)
      : path_(std::move(path)), filter_(std::move(filter)) {}

  /**
   * @ingroup consumer
   * @fn const std::string& ConsumerInspectRequest::GetPath() const
   * @brief Get the datapoint path.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::string Datapoint path
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetPath() const & { return path_; }
  std::string GetPath() const && { return path_; }

  /**
   * @ingroup consumer
   * @fn const std::optional<filter::InspectFilter>&
   * ConsumerInspectRequest::GetFilter() const
   * @brief Get the inspect filter if set.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::optional<filter::InspectFilter> Inspect filter or nullopt
   * @note -
   * @code -
   * @endcode -
   */
  const std::optional<filter::InspectFilter>& GetFilter() const & {
    return filter_;
  }
  std::optional<filter::InspectFilter> GetFilter() const && { return filter_; }

  /**
   * @ingroup consumer
   * @fn bool operator==(const ConsumerInspectRequest& lhs, const
   * ConsumerInspectRequest& rhs)
   * @brief Compare two ConsumerInspectRequest objects for equality.
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
  friend bool operator==(const ConsumerInspectRequest& lhs,
                         const ConsumerInspectRequest& rhs) {
    return lhs.path_ == rhs.path_ && lhs.filter_ == rhs.filter_;
  }

 private:
  std::string path_;
  std::optional<filter::InspectFilter> filter_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_CONSUMER_INSPECT_REQUEST_H_
