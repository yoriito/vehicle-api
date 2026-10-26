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

#ifndef COMMON_DATABROKER_FILTER_SUBSCRIBE_FILTER_H_
#define COMMON_DATABROKER_FILTER_SUBSCRIBE_FILTER_H_

#include <iostream>
#include <string>
#include <vector>

#include "databroker/filter/change_filter.h"
#include "databroker/filter/paths_filter.h"
#include "databroker/filter/range_filter.h"
#include "databroker/filter/timebased_filter.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker::filter
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker::filter {

using MiscFilterVariant =
  std::variant<std::monostate,
               yoriito::databroker::filter::RangeFilter,   //
               yoriito::databroker::filter::ChangeFilter,  //
               yoriito::databroker::filter::TimeBasedFilter>;

/**
 * @ingroup common
 * @class SubscribeFilter
 * @brief Class representing a subscribe filter for datapoints in the
 * DataBroker.
 */
class SubscribeFilter {
 public:
  /**
   * @ingroup common
   * @fn explicit SubscribeFilter(std::optional<PathsFilter> paths_filter,
   * MiscFilterVariant misc_filter = std::monostate{})
   * @brief Constructs a SubscribeFilter with the specified paths and
   * miscellaneous filter.
   * @deprecated -
   * @pre -
   * @param paths_filter Optional PathsFilter for datapoint paths.
   * @param misc_filter Miscellaneous filter variant (default: monostate).
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit SubscribeFilter(std::optional<PathsFilter> paths_filter,
                           MiscFilterVariant misc_filter = std::monostate{})
      : paths_filter_(std::move(paths_filter)),
        misc_filter_(std::move(misc_filter)) {}

  /**
   * @ingroup common
   * @fn explicit SubscribeFilter(MiscFilterVariant misc_filter =
   * std::monostate{})
   * @brief Constructs a SubscribeFilter with only a miscellaneous filter.
   * @deprecated -
   * @pre -
   * @param misc_filter Miscellaneous filter variant (default: monostate).
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit SubscribeFilter(MiscFilterVariant misc_filter = std::monostate{})
      : paths_filter_(std::nullopt), misc_filter_(std::move(misc_filter)) {}

  /**
   * @ingroup common
   * @fn SubscribeFilter(SubscribeFilter&&)
   * @brief Move constructor for SubscribeFilter.
   * @deprecated -
   * @pre -
   * @param other The SubscribeFilter to move from.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  SubscribeFilter(SubscribeFilter&&) = default;

  /**
   * @ingroup common
   * @fn SubscribeFilter& operator=(SubscribeFilter&&)
   * @brief Move assignment operator for SubscribeFilter.
   * @deprecated -
   * @pre -
   * @param other The SubscribeFilter to move assign from.
   * @retval Reference to this SubscribeFilter.
   * @note -
   * @code -
   * @endcode -
   */
  SubscribeFilter& operator=(SubscribeFilter&&) = default;

  /**
   * @ingroup common
   * @fn ~SubscribeFilter()
   * @brief Destructor for SubscribeFilter.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ~SubscribeFilter() = default;

  /**
   * @ingroup common
   * @fn const std::optional<PathsFilter>& GetPathsFilter() const
   * @brief Gets the optional PathsFilter for this subscribe filter.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Reference to the optional PathsFilter.
   * @note -
   * @code -
   * @endcode -
   */
  const std::optional<PathsFilter>& GetPathsFilter() const& {
    return paths_filter_;
  }
  std::optional<PathsFilter> GetPathsFilter() const&& { return paths_filter_; }

  /**
   * @ingroup common
   * @fn const MiscFilterVariant& GetMiscFilter() const
   * @brief Gets the miscellaneous filter variant for this subscribe filter.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Reference to the MiscFilterVariant.
   * @note -
   * @code -
   * @endcode -
   */
  const MiscFilterVariant& GetMiscFilter() const& { return misc_filter_; }
  // RangeFilter/ChangeFilter/TimeBasedFilter are move-only, so move rather than
  // copy.
  MiscFilterVariant GetMiscFilter() && { return std::move(misc_filter_); }

  /**
   * @ingroup common
   * @fn friend bool operator==(const SubscribeFilter& lhs, const
   * SubscribeFilter& rhs)
   * @brief Compares two SubscribeFilter objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs The left-hand side SubscribeFilter.
   * @param rhs The right-hand side SubscribeFilter.
   * @retval true if both paths_filter_ and misc_filter_ are equal; false
   * otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const SubscribeFilter& lhs,
                         const SubscribeFilter& rhs) {
    return lhs.paths_filter_ == rhs.paths_filter_ &&
           lhs.misc_filter_ == rhs.misc_filter_;
  }

 private:
  std::optional<PathsFilter> paths_filter_;
  MiscFilterVariant misc_filter_;
};
}  // namespace yoriito::databroker::filter
#endif  // COMMON_DATABROKER_FILTER_SUBSCRIBE_FILTER_H_
