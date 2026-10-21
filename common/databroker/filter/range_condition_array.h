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

#ifndef COMMON_DATABROKER_FILTER_RANGE_CONDITION_ARRAY_H_
#define COMMON_DATABROKER_FILTER_RANGE_CONDITION_ARRAY_H_

#include <optional>
#include <vector>

#include "databroker/filter/range_condition_withop.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker::filter
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker::filter {

/**
 * @ingroup common
 * @class RangeConditionArray
 * @brief Class representing an array of range conditions with logical
 * operators.
 */
class RangeConditionArray {
 public:
  /**
   * @ingroup common
   * @fn explicit RangeConditionArray(const std::vector<RangeConditionWithOp>&
   * conditions)
   * @brief Constructs a RangeConditionArray with the specified conditions.
   * @deprecated -
   * @pre -
   * @param conditions The vector of RangeConditionWithOp objects.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit RangeConditionArray(
    const std::vector<RangeConditionWithOp>& conditions)
      : conditions_(conditions) {}

  /**
   * @ingroup common
   * @fn ~RangeConditionArray()
   * @brief Destructor for RangeConditionArray.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ~RangeConditionArray() = default;

  /**
   * @ingroup common
   * @fn RangeConditionArray(const RangeConditionArray&)
   * @brief Copy constructor for RangeConditionArray.
   * @deprecated -
   * @pre -
   * @param other The RangeConditionArray to copy from.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  RangeConditionArray(const RangeConditionArray&) = default;

  /**
   * @ingroup common
   * @fn RangeConditionArray& operator=(const RangeConditionArray&)
   * @brief Copy assignment operator for RangeConditionArray.
   * @deprecated -
   * @pre -
   * @param other The RangeConditionArray to assign from.
   * @retval Reference to this RangeConditionArray.
   * @note -
   * @code -
   * @endcode -
   */
  RangeConditionArray& operator=(const RangeConditionArray&) = default;

  /**
   * @ingroup common
   * @fn RangeConditionArray(RangeConditionArray&&)
   * @brief Move constructor for RangeConditionArray.
   * @deprecated -
   * @pre -
   * @param other The RangeConditionArray to move from.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  RangeConditionArray(RangeConditionArray&&) = default;

  /**
   * @ingroup common
   * @fn RangeConditionArray& operator=(RangeConditionArray&&)
   * @brief Move assignment operator for RangeConditionArray.
   * @deprecated -
   * @pre -
   * @param other The RangeConditionArray to move assign from.
   * @retval Reference to this RangeConditionArray.
   * @note -
   * @code -
   * @endcode -
   */
  RangeConditionArray& operator=(RangeConditionArray&&) = default;

  /**
   * @ingroup common
   * @fn const std::vector<RangeConditionWithOp>& GetConditions() const
   * @brief Gets the conditions contained in this array.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Reference to the vector of RangeConditionWithOp.
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<RangeConditionWithOp>& GetConditions() const& {
    return conditions_;
  }
  std::vector<RangeConditionWithOp> GetConditions() const&& {
    return conditions_;
  }

  /**
   * @ingroup common
   * @fn size_t Size() const
   * @brief Gets the number of conditions in this array.
   * @deprecated -
   * @pre -
   * @param -
   * @retval The number of conditions (size_t).
   * @note -
   * @code -
   * @endcode -
   */
  size_t Size() const { return conditions_.size(); }

  /**
   * @ingroup common
   * @fn bool IsEmpty() const
   * @brief Checks if the array of conditions is empty.
   * @deprecated -
   * @pre -
   * @param -
   * @retval true if empty; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  bool IsEmpty() const { return conditions_.empty(); }

  /**
   * @ingroup common
   * @fn friend bool operator==(const RangeConditionArray& lhs, const
   * RangeConditionArray& rhs)
   * @brief Compares two RangeConditionArray objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs The left-hand side RangeConditionArray.
   * @param rhs The right-hand side RangeConditionArray.
   * @retval true if both conditions_ are equal; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const RangeConditionArray& lhs,
                         const RangeConditionArray& rhs) {
    return lhs.conditions_ == rhs.conditions_;
  }

 private:
  std::vector<RangeConditionWithOp> conditions_;
};

}  // namespace yoriito::databroker::filter

#endif  // COMMON_DATABROKER_FILTER_RANGE_CONDITION_ARRAY_H_
