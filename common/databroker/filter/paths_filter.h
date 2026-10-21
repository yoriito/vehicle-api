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

#ifndef COMMON_DATABROKER_FILTER_PATHS_FILTER_H_
#define COMMON_DATABROKER_FILTER_PATHS_FILTER_H_

#include <string>
#include <utility>
#include <vector>

/**
 * @ingroup common
 * @namespace yoriito::databroker::filter
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker::filter {
/**
 * @ingroup common
 * @class PathsFilter
 * @brief Class representing a filter based on multiple datapoint paths in the
 * DataBroker.
 */
class PathsFilter {
 public:
  PathsFilter() = delete;

  /**
   * @ingroup common
   * @fn explicit PathsFilter(const std::vector<std::string>& paths)
   * @brief Constructs a PathsFilter with the specified vector of paths.
   * @deprecated -
   * @pre -
   * @param paths The vector of datapoint paths to filter.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit PathsFilter(const std::vector<std::string>& paths) : paths_(paths) {}

  /**
   * @ingroup common
   * @fn const std::vector<std::string>& GetPaths() const &
   * @brief Gets the datapoint paths contained in this filter.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Reference to the vector of datapoint paths.
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<std::string>& GetPaths() const & { return paths_; }

  /**
   * @ingroup common
   * @fn std::vector<std::string> GetPaths() const &&
   * @brief Gets the datapoint paths contained in this filter.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Copy of the vector of datapoint paths.
   * @note -
   * @code -
   * @endcode -
   */
  std::vector<std::string> GetPaths() const && { return paths_; }

  /**
   * @ingroup common
   * @fn friend bool operator==(const PathsFilter& lhs, const PathsFilter& rhs)
   * @brief Compares two PathsFilter objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs The left-hand side PathsFilter.
   * @param rhs The right-hand side PathsFilter.
   * @retval true if both paths_ are equal; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const PathsFilter& lhs, const PathsFilter& rhs) {
    return lhs.paths_ == rhs.paths_;
  }

 private:
  std::vector<std::string> paths_;
};
}  // namespace yoriito::databroker::filter
#endif  // COMMON_DATABROKER_FILTER_PATHS_FILTER_H_
