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

#ifndef COMMON_DATABROKER_FILTER_INSPECT_FILTER_H_
#define COMMON_DATABROKER_FILTER_INSPECT_FILTER_H_

#include <string>
#include <vector>

#include "databroker/filter/get_filter.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker::filter {
/**
 * @ingroup common
 * @class InspectFilter
 * @brief Class representing an inspect filter for datapoints in the DataBroker.
 */
class InspectFilter : public GetFilter {
 public:
  InspectFilter() = delete;
  /**
   * @ingroup common
   * @fn explicit InspectFilter(const std::vector<std::string>& paths)
   * @brief Constructs an InspectFilter with the specified paths.
   * @deprecated -
   * @pre -
   * @param paths The vector of datapoint paths to filter.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit InspectFilter(const std::vector<std::string>& paths)
      : GetFilter(paths) {}

  /**
   * @ingroup common
   * @fn friend bool operator==(const InspectFilter& lhs, const InspectFilter&
   * rhs)
   * @brief Compares two InspectFilter objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs The left-hand side InspectFilter.
   * @param rhs The right-hand side InspectFilter.
   * @retval true if both filters are equal; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const InspectFilter& lhs, const InspectFilter& rhs) {
    return static_cast<const GetFilter&>(lhs) ==
           static_cast<const GetFilter&>(rhs);
  }
};
}  // namespace yoriito::databroker::filter
#endif  // COMMON_DATABROKER_FILTER_INSPECT_FILTER_H_
