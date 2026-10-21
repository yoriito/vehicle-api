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

#ifndef COMMON_DATABROKER_FILTER_GET_FILTER_H_
#define COMMON_DATABROKER_FILTER_GET_FILTER_H_

#include <string>
#include <utility>
#include <vector>

#include "databroker/filter/paths_filter.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker::filter {

/**
 * @ingroup common
 * @class GetFilter
 * @brief Class representing a get filter for datapoints in the DataBroker.
 */
class GetFilter : public PathsFilter {
 public:
  GetFilter() = delete;
  /**
   * @ingroup common
   * @fn explicit GetFilter(const std::vector<std::string>& paths)
   * @brief Constructs a GetFilter with the specified paths.
   * @deprecated -
   * @pre -
   * @param paths The vector of datapoint paths to filter.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit GetFilter(const std::vector<std::string>& paths)
      : PathsFilter(paths) {}

  /**
   * @ingroup common
   * @fn friend bool operator==(const GetFilter& lhs, const GetFilter& rhs)
   * @brief Compares two GetFilter objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs The left-hand side GetFilter.
   * @param rhs The right-hand side GetFilter.
   * @retval true if both GetPaths() are equal; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const GetFilter& lhs, const GetFilter& rhs) {
    return lhs.GetPaths() == rhs.GetPaths();
  }
};
}  // namespace yoriito::databroker::filter
#endif  // COMMON_DATABROKER_FILTER_GET_FILTER_H_
