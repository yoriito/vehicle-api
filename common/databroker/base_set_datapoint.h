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

#ifndef COMMON_DATABROKER_BASE_SET_DATAPOINT_H_
#define COMMON_DATABROKER_BASE_SET_DATAPOINT_H_

#include <string>

#include "databroker_type.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {
/**
 * @ingroup common
 * @class BaseSetDataPoint
 * @brief Base class for setting datapoint values in the DataBroker.
 */
class BaseSetDataPoint {
 public:
  BaseSetDataPoint(const BaseSetDataPoint& other)
      : path_(other.path_), data_(CloneValueType(other.data_)) {}

  BaseSetDataPoint& operator=(const BaseSetDataPoint& other) & {
    if (this == &other) {
      return *this;
    }
    path_ = other.path_;
    data_ = CloneValueType(other.data_);
    return *this;
  }

  BaseSetDataPoint(BaseSetDataPoint&&) noexcept = default;
  BaseSetDataPoint& operator=(BaseSetDataPoint&&) noexcept = default;

  /**
   * @ingroup common
   * @fn BaseSetDataPoint::BaseSetDataPoint()
   * @brief Deleted default constructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  BaseSetDataPoint() = delete;
  /**
   * @ingroup common
   * @fn BaseSetDataPoint::BaseSetDataPoint(const std::string& path, const
   * ValueType& data)
   * @brief Construct a BaseSetDataPoint object.
   * @deprecated -
   * @pre -
   * @param path The datapoint path.
   * @param data The datapoint value.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  BaseSetDataPoint(const std::string& path, const ValueType& data)
      : path_(path), data_(CloneValueType(data)) {}

  /**
   * @ingroup common
   * @fn const std::string& BaseSetDataPoint::GetPath() const
   * @brief Get the datapoint path.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::string Datapoint path
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetPath() const& { return path_; }
  // Rvalue overloads return by value to avoid a reference dangling past the
  // temporary's lifetime.
  std::string GetPath() const&& { return path_; }

  /**
   * @ingroup common
   * @fn const ValueType& BaseSetDataPoint::GetData() const
   * @brief Get the datapoint value.
   * @deprecated -
   * @pre -
   * @param -
   * @retval ValueType Datapoint value
   * @note -
   * @code -
   * @endcode -
   */
  const ValueType& GetData() const& { return data_; }
  // ValueType holds a move-only unique_ptr alternative, so clone rather than
  // copy directly.
  ValueType GetData() const&& { return CloneValueType(data_); }

  /**
   * @ingroup common
   * @fn bool operator==(const BaseSetDataPoint& lhs, const BaseSetDataPoint&
   * rhs)
   * @brief Compare two BaseSetDataPoint objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs Left-hand side object.
   * @param rhs Right-hand side object.
   * @retval true Objects are equal
   * @retval false Objects are not equal
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const BaseSetDataPoint& lhs,
                         const BaseSetDataPoint& rhs) {
    return lhs.path_ == rhs.path_ && ValueTypeEquals(lhs.data_, rhs.data_);
  }

 private:
  std::string path_;
  ValueType data_;
};
}  // namespace yoriito::databroker
#endif  // COMMON_DATABROKER_BASE_SET_DATAPOINT_H_
