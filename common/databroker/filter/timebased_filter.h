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

#ifndef COMMON_DATABROKER_FILTER_TIMEBASED_FILTER_H_
#define COMMON_DATABROKER_FILTER_TIMEBASED_FILTER_H_

/**
 * @ingroup common
 * @namespace yoriito::databroker::filter
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker::filter {
/**
 * @ingroup common
 * @class TimeBasedFilter
 * @brief Class representing a time-based filter for datapoints in the
 * DataBroker.
 */
class TimeBasedFilter {
 public:
  TimeBasedFilter() = delete;
  /**
   * @ingroup common
   * @fn explicit TimeBasedFilter(const uint32_t period)
   * @brief Constructs a TimeBasedFilter with the specified period.
   * @deprecated -
   * @pre -
   * @param period The period value (uint32_t).
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit TimeBasedFilter(const uint32_t period) : period_(period) {}

  /**
   * @ingroup common
   * @fn uint32_t GetPeriod() const
   * @brief Gets the period value for this filter.
   * @deprecated -
   * @pre -
   * @param -
   * @retval The period value (uint32_t).
   * @note -
   * @code -
   * @endcode -
   */
  uint32_t GetPeriod() const { return period_; }

  /**
   * @ingroup common
   * @fn friend bool operator==(const TimeBasedFilter& lhs, const
   * TimeBasedFilter& rhs)
   * @brief Compares two TimeBasedFilter objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs The left-hand side TimeBasedFilter.
   * @param rhs The right-hand side TimeBasedFilter.
   * @retval true if both period_ are equal; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const TimeBasedFilter& lhs,
                         const TimeBasedFilter& rhs) {
    return lhs.period_ == rhs.period_;
  }

 private:
  uint32_t period_;
};
}  // namespace yoriito::databroker::filter

#endif  // COMMON_DATABROKER_FILTER_TIMEBASED_FILTER_H_
