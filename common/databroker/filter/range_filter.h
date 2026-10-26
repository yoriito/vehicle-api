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

#ifndef COMMON_DATABROKER_FILTER_RANGE_FILTER_H_
#define COMMON_DATABROKER_FILTER_RANGE_FILTER_H_

#include <utility>
#include <variant>
#include <vector>

#include "databroker/filter/range_condition.h"
#include "databroker/filter/range_condition_array.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker::filter
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker::filter {

using RangeFilterType = std::variant<RangeCondition, RangeConditionArray>;

/**
 * @ingroup common
 * @class RangeFilter
 * @brief Class representing a range filter for datapoints in the DataBroker.
 */
class RangeFilter {
 public:
  RangeFilter() = delete;
  /**
   * @ingroup common
   * @fn explicit RangeFilter(RangeFilterType&& filter)
   * @brief Constructs a RangeFilter with a variant filter type.
   * @deprecated -
   * @pre -
   * @param filter The RangeFilterType variant to use.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit RangeFilter(RangeFilterType filter) : filter_(std::move(filter)) {}

  /**
   * @ingroup common
   * @fn explicit RangeFilter(OperatorType op, int32_t boundary)
   * @brief Constructs a RangeFilter with a single RangeCondition.
   * @deprecated -
   * @pre -
   * @param op The operator type for the condition.
   * @param boundary The boundary value (int32_t).
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit RangeFilter(OperatorType op, int32_t boundary)
      : filter_(RangeCondition(op, boundary)) {}

  /**
   * @ingroup common
   * @fn explicit RangeFilter(const std::vector<RangeConditionWithOp>&
   * conditions)
   * @brief Constructs a RangeFilter with an array of RangeConditionWithOp.
   * @deprecated -
   * @pre -
   * @param conditions The vector of RangeConditionWithOp objects.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit RangeFilter(const std::vector<RangeConditionWithOp>& conditions)
      : filter_(RangeConditionArray(conditions)) {}

  /**
   * @ingroup common
   * @fn RangeFilter(RangeFilter&&)
   * @brief Move constructor for RangeFilter.
   * @deprecated -
   * @pre -
   * @param other The RangeFilter to move from.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  RangeFilter(RangeFilter&&) = default;

  /**
   * @ingroup common
   * @fn RangeFilter& operator=(RangeFilter&&)
   * @brief Move assignment operator for RangeFilter.
   * @deprecated -
   * @pre -
   * @param other The RangeFilter to move assign from.
   * @retval Reference to this RangeFilter.
   * @note -
   * @code -
   * @endcode -
   */
  RangeFilter& operator=(RangeFilter&&) = default;

  /**
   * @ingroup common
   * @fn ~RangeFilter()
   * @brief Destructor for RangeFilter.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ~RangeFilter() = default;

  /**
   * @ingroup common
   * @fn bool IsSingleCondition() const
   * @brief Checks if the filter contains a single condition.
   * @deprecated -
   * @pre -
   * @param -
   * @retval true if single condition; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  bool IsSingleCondition() const {
    return std::holds_alternative<RangeCondition>(filter_);
  }

  /**
   * @ingroup common
   * @fn bool IsConditionArray() const
   * @brief Checks if the filter contains an array of conditions.
   * @deprecated -
   * @pre -
   * @param -
   * @retval true if condition array; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  bool IsConditionArray() const {
    return std::holds_alternative<RangeConditionArray>(filter_);
  }

  /**
   * @ingroup common
   * @fn const RangeCondition* GetSingleCondition() const
   * @brief Gets the single condition if present.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Pointer to the RangeCondition, or nullptr if not present.
   * @note -
   * @code -
   * @endcode -
   */
  const RangeCondition* GetSingleCondition() const {
    return std::get_if<RangeCondition>(&filter_);
  }

  /**
   * @ingroup common
   * @fn const RangeConditionArray* GetConditionArray() const
   * @brief Gets the condition array if present.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Pointer to the RangeConditionArray, or nullptr if not present.
   * @note -
   * @code -
   * @endcode -
   */
  const RangeConditionArray* GetConditionArray() const {
    return std::get_if<RangeConditionArray>(&filter_);
  }

  /**
   * @ingroup common
   * @fn friend bool operator==(const RangeFilter& lhs, const RangeFilter& rhs)
   * @brief Compares two RangeFilter objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs The left-hand side RangeFilter.
   * @param rhs The right-hand side RangeFilter.
   * @retval true if both filter_ are equal; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const RangeFilter& lhs, const RangeFilter& rhs) {
    return lhs.filter_ == rhs.filter_;
  }

 private:
  RangeFilterType filter_;
};

}  // namespace yoriito::databroker::filter

#endif  // COMMON_DATABROKER_FILTER_RANGE_FILTER_H_
