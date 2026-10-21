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

#ifndef COMMON_DATABROKER_FILTER_CHANGE_FILTER_H_
#define COMMON_DATABROKER_FILTER_CHANGE_FILTER_H_

#include "databroker/filter/operator_type.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker::filter {
/**
 * @ingroup common
 * @class ChangeFilter
 * @brief Class representing a change filter for datapoints in the DataBroker.
 */
class ChangeFilter {
 public:
  ChangeFilter() = delete;

  /**
   * @ingroup common
   * @fn explicit ChangeFilter(const OperatorType logic_op, const int32_t diff)
   * @brief Constructs a ChangeFilter with the specified operator and difference
   * value.
   * @deprecated -
   * @pre -
   * @param logic_op The logical operator type to use.
   * @param diff The difference value for the filter.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ChangeFilter(const OperatorType logic_op, const int32_t diff)
      : logic_op_(logic_op), diff_(diff) {}

  /**
   * @ingroup common
   * @fn OperatorType GetLogicOperator() const
   * @brief Gets the logical operator type used in this filter.
   * @deprecated -
   * @pre -
   * @param -
   * @retval The logical operator type.
   * @note -
   * @code -
   * @endcode -
   */
  OperatorType GetLogicOperator() const { return logic_op_; }

  /**
   * @ingroup common
   * @fn int32_t GetDiff() const
   * @brief Gets the difference value used in this filter.
   * @deprecated -
   * @pre -
   * @param -
   * @retval The difference value (int32_t).
   * @note -
   * @code -
   * @endcode -
   */
  int32_t GetDiff() const { return diff_; }

  /**
   * @ingroup common
   * @fn friend bool operator==(const ChangeFilter& lhs, const ChangeFilter&
   * rhs)
   * @brief Compares two ChangeFilter objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs The left-hand side ChangeFilter.
   * @param rhs The right-hand side ChangeFilter.
   * @retval true if both logic_op and diff are equal; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const ChangeFilter& lhs, const ChangeFilter& rhs) {
    return (lhs.logic_op_ == rhs.logic_op_) && (lhs.diff_ == rhs.diff_);
  }

 private:
  OperatorType logic_op_;
  int32_t diff_;
};
}  // namespace yoriito::databroker::filter
#endif  // COMMON_DATABROKER_FILTER_CHANGE_FILTER_H_
