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

#ifndef COMMON_DATABROKER_FILTER_OPERATOR_TYPE_H_
#define COMMON_DATABROKER_FILTER_OPERATOR_TYPE_H_

/**
 * @ingroup common
 * @namespace yoriito::databroker::filter
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker::filter {

/**
 * @ingroup common
 * @enum OperatorType
 * @brief Enumeration for comparison operators used in filters.
 * @deprecated -
 * @pre -
 * @param -
 * @retval -
 * @note -
 * @code -
 * @endcode -
 */
enum class OperatorType {
  OPERATOR_UNDEFINED,
  OPERATOR_EQ,   // equal
  OPERATOR_NE,   // not equal
  OPERATOR_GT,   // greater than
  OPERATOR_GTE,  // greater than or equal
  OPERATOR_LT,   // less than
  OPERATOR_LTE   // less than equal
};

/**
 * @ingroup common
 * @enum LogicalOperatorType
 * @brief Enumeration for logical operators used in filters.
 * @deprecated -
 * @pre -
 * @param -
 * @retval -
 * @note -
 * @code -
 * @endcode -
 */
enum class LogicalOperatorType {
  LOGICAL_OPERATOR_UNDEFINED,
  LOGICAL_OPERATOR_AND,  // AND
  LOGICAL_OPERATOR_OR    // OR
};

}  // namespace yoriito::databroker::filter
#endif  // COMMON_DATABROKER_FILTER_OPERATOR_TYPE_H_
