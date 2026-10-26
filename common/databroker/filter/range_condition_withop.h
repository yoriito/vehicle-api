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

#ifndef COMMON_DATABROKER_FILTER_RANGE_CONDITION_WITHOP_H_
#define COMMON_DATABROKER_FILTER_RANGE_CONDITION_WITHOP_H_

#include "databroker/filter/operator_type.h"
#include "databroker/filter/range_condition.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker::filter
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker::filter {

/**
 * @ingroup common
 * @class RangeConditionWithOp
 * @brief Class representing a range condition with an optional logical
 * operator.
 */
class RangeConditionWithOp : public RangeCondition {
 public:
  /**
   * @ingroup common
   * @fn RangeConditionWithOp(OperatorType boundary_operator, int32_t boundary,
   * std::optional<LogicalOperatorType> logical_op = std::nullopt)
   * @brief Constructs a RangeConditionWithOp with the specified boundary and
   * logical operator.
   * @deprecated -
   * @pre -
   * @param boundary_operator The boundary operator type.
   * @param boundary The boundary value (int32_t).
   * @param logical_op Optional logical operator type.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  RangeConditionWithOp(
      OperatorType boundary_operator, int32_t boundary,
      std::optional<LogicalOperatorType> logical_op = std::nullopt)
      : RangeCondition(boundary_operator, boundary), logical_op_(logical_op) {}

  /**
   * @ingroup common
   * @fn ~RangeConditionWithOp()
   * @brief Destructor for RangeConditionWithOp.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ~RangeConditionWithOp() override = default;

  /**
   * @ingroup common
   * @fn std::optional<LogicalOperatorType> GetLogicalOperator() const
   * @brief Gets the logical operator type, if any, for this condition.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Optional logical operator type.
   * @note -
   * @code -
   * @endcode -
   */
  std::optional<LogicalOperatorType> GetLogicalOperator() const {
    return logical_op_;
  }

  /**
   * @ingroup common
   * @fn friend bool operator==(const RangeConditionWithOp& lhs, const
   * RangeConditionWithOp& rhs)
   * @brief Compares two RangeConditionWithOp objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs The left-hand side RangeConditionWithOp.
   * @param rhs The right-hand side RangeConditionWithOp.
   * @retval true if both base and logical_op_ are equal; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const RangeConditionWithOp& lhs,
                         const RangeConditionWithOp& rhs) {
    return static_cast<const RangeCondition&>(lhs) ==
               static_cast<const RangeCondition&>(rhs) &&
           lhs.logical_op_ == rhs.logical_op_;
  }

 private:
  std::optional<LogicalOperatorType> logical_op_;
};

}  // namespace yoriito::databroker::filter
#endif  // COMMON_DATABROKER_FILTER_RANGE_CONDITION_WITHOP_H_
