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

#ifndef COMMON_DATABROKER_TYPES_PROPERTY_TYPE_H_
#define COMMON_DATABROKER_TYPES_PROPERTY_TYPE_H_

#include <string>
#include <utility>

#include "databroker_type.h"
#include "databroker/data_type.h"
#include "databroker/types/struct_type_ref.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup common
 * @class PropertyType
 * @brief Class representing a property definition of StructType.
 */
class PropertyType {
 public:
  /**
   * @ingroup common
   * @fn PropertyType::PropertyType(std::string path, DataType dataType,
   * StructTypeRef dataTypeRef)
   * @brief Construct a PropertyType object.
   * @deprecated -
   * @pre -
   * @param path Property path.
   * @param dataType Property data type.
   * @param dataTypeRef Struct type reference used when data type is struct.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  PropertyType(std::string path, DataType dataType,
               StructTypeRef dataTypeRef = {})
      : path_(std::move(path)),
        dataType_(dataType),
        dataTypeRef_(std::move(dataTypeRef)) {}

  /**
   * @ingroup common
   * @fn const std::string& PropertyType::GetPath() const noexcept
   * @brief Get property path.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Property path.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetPath() const& noexcept { return path_; }
  std::string GetPath() const&& { return path_; }

  /**
   * @ingroup common
   * @fn DataType PropertyType::GetDataType() const noexcept
   * @brief Get property data type.
   * @deprecated -
   * @pre -
   * @param -
   * @retval DataType Data type.
   * @note -
   * @code -
   * @endcode -
   */
  DataType GetDataType() const noexcept { return dataType_; }

  /**
   * @ingroup common
   * @fn StructTypeRef& PropertyType::GetDataTypeRef() noexcept
   * @brief Get mutable struct type reference.
   * @deprecated -
   * @pre -
   * @param -
   * @retval StructTypeRef& Struct type reference.
   * @note -
   * @code -
   * @endcode -
   */
  StructTypeRef& GetDataTypeRef() & noexcept { return dataTypeRef_; }

  /**
   * @ingroup common
   * @fn const StructTypeRef& PropertyType::GetDataTypeRef() const noexcept
   * @brief Get const struct type reference.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const StructTypeRef& Struct type reference.
   * @note -
   * @code -
   * @endcode -
   */
  const StructTypeRef& GetDataTypeRef() const& noexcept { return dataTypeRef_; }
  // StructTypeRef holds a shared_ptr, so the rvalue overload moves rather than
  // copies.
  StructTypeRef GetDataTypeRef() && { return std::move(dataTypeRef_); }

  /**
   * @ingroup common
   * @fn bool PropertyType::IsStruct() const noexcept
   * @brief Check whether property type is struct.
   * @deprecated -
   * @pre -
   * @param -
   * @retval true Property type is struct
   * @retval false Property type is not struct
   * @note -
   * @code -
   * @endcode -
   */
  bool IsStruct() const noexcept {
    return (dataType_ == DataType::DATA_TYPE_STRUCT) ||
           (dataType_ == DataType::DATA_TYPE_STRUCT_ARRAY);
  }

  /**
   * @ingroup common
   * @fn const ValueType& PropertyType::GetMin() const
   * @brief Get minimum value.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const ValueType& Minimum value.
   * @note -
   * @code -
   * @endcode -
   */
  const ValueType& GetMin() const& { return min_; }
  // ValueType holds a move-only unique_ptr alternative, so clone rather than
  // copy directly.
  ValueType GetMin() const&& { return CloneValueType(min_); }

  /**
   * @ingroup common
   * @fn const ValueType& PropertyType::GetMax() const
   * @brief Get maximum value.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const ValueType& Maximum value.
   * @note -
   * @code -
   * @endcode -
   */
  const ValueType& GetMax() const& { return max_; }
  ValueType GetMax() const&& { return CloneValueType(max_); }

  /**
   * @ingroup common
   * @fn const std::string& PropertyType::GetUnit() const
   * @brief Get unit.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Unit string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetUnit() const& { return unit_; }
  std::string GetUnit() const&& { return unit_; }

  /**
   * @ingroup common
   * @fn const std::string& PropertyType::GetDescription() const noexcept
   * @brief Get description.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Description string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetDescription() const& noexcept { return description_; }
  std::string GetDescription() const&& { return description_; }

  /**
   * @ingroup common
   * @fn const std::string& PropertyType::GetDeprecation() const noexcept
   * @brief Get deprecation message.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Deprecation string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetDeprecation() const& noexcept { return deprecation_; }
  std::string GetDeprecation() const&& { return deprecation_; }

  /**
   * @ingroup common
   * @fn const std::string& PropertyType::GetComment() const noexcept
   * @brief Get comment.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Comment string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetComment() const& noexcept { return comment_; }
  std::string GetComment() const&& { return comment_; }

  /**
   * @ingroup common
   * @fn const std::vector<std::string>& PropertyType::GetAllowed() const
   * noexcept
   * @brief Get allowed values.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::vector<std::string>& Allowed values.
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<std::string>& GetAllowed() const& noexcept {
    return allowed_;
  }
  std::vector<std::string> GetAllowed() const&& { return allowed_; }

  /**
   * @ingroup common
   * @fn uint64_t PropertyType::GetArraySize() const noexcept
   * @brief Get array size.
   * @deprecated -
   * @pre -
   * @param -
   * @retval uint64_t Array size.
   * @note -
   * @code -
   * @endcode -
   */
  uint64_t GetArraySize() const noexcept { return arraysize_; }

  /**
   * @ingroup common
   * @fn const std::string& PropertyType::GetPattern() const noexcept
   * @brief Get pattern.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Pattern string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetPattern() const& noexcept { return pattern_; }
  std::string GetPattern() const&& { return pattern_; }

  /**
   * @ingroup common
   * @fn const std::map<std::string, std::string>&
   * PropertyType::GetCustomAttributes() const noexcept
   * @brief Get custom attributes.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::map<std::string, std::string>& Custom attributes.
   * @note -
   * @code -
   * @endcode -
   */
  const std::map<std::string, std::string>& GetCustomAttributes()
    const& noexcept {
    return custom_attributes_;
  }
  std::map<std::string, std::string> GetCustomAttributes() const&& {
    return custom_attributes_;
  }
  /**
   * @ingroup common
   * @fn void PropertyType::SetDataType(DataType dataType) noexcept
   * @brief Set property data type.
   * @deprecated -
   * @pre -
   * @param dataType Data type.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetDataType(DataType dataType) noexcept { dataType_ = dataType; }
  /**
   * @ingroup common
   * @fn void PropertyType::SetStructTypeRef(const std::shared_ptr<StructType>&
   * ref)
   * @brief Set resolved struct type reference.
   * @deprecated -
   * @pre -
   * @param ref Struct type shared pointer.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetStructTypeRef(const std::shared_ptr<StructType>& ref) {
    dataTypeRef_ = StructTypeRef(ref);
  }

  /**
   * @ingroup common
   * @fn void PropertyType::SetMin(const ValueType& min)
   * @brief Set minimum value.
   * @deprecated -
   * @pre -
   * @param min Minimum value.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetMin(const ValueType& min) { this->min_ = CloneValueType(min); }

  /**
   * @ingroup common
   * @fn void PropertyType::SetMax(const ValueType& max)
   * @brief Set maximum value.
   * @deprecated -
   * @pre -
   * @param max Maximum value.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetMax(const ValueType& max) { this->max_ = CloneValueType(max); }

  /**
   * @ingroup common
   * @fn void PropertyType::SetUnit(const std::string& unit)
   * @brief Set unit.
   * @deprecated -
   * @pre -
   * @param unit Unit string.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetUnit(const std::string& unit) { this->unit_ = unit; }

  /**
   * @ingroup common
   * @fn void PropertyType::SetDescription(std::string description)
   * @brief Set description.
   * @deprecated -
   * @pre -
   * @param description Description string.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetDescription(std::string description) {
    description_ = std::move(description);
  }

  /**
   * @ingroup common
   * @fn void PropertyType::SetDeprecation(std::string deprecation)
   * @brief Set deprecation message.
   * @deprecated -
   * @pre -
   * @param deprecation Deprecation string.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetDeprecation(std::string deprecation) {
    deprecation_ = std::move(deprecation);
  }

  /**
   * @ingroup common
   * @fn void PropertyType::SetComment(std::string comment)
   * @brief Set comment.
   * @deprecated -
   * @pre -
   * @param comment Comment string.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetComment(std::string comment) { comment_ = std::move(comment); }

  /**
   * @ingroup common
   * @fn void PropertyType::SetAllowed(std::vector<std::string> allowed)
   * @brief Set allowed values.
   * @deprecated -
   * @pre -
   * @param allowed Allowed values.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetAllowed(std::vector<std::string> allowed) {
    allowed_ = std::move(allowed);
  }

  /**
   * @ingroup common
   * @fn void PropertyType::SetArraySize(uint64_t arraysize) noexcept
   * @brief Set array size.
   * @deprecated -
   * @pre -
   * @param arraysize Array size.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetArraySize(uint64_t arraysize) noexcept { arraysize_ = arraysize; }

  /**
   * @ingroup common
   * @fn void PropertyType::SetPattern(std::string pattern)
   * @brief Set pattern.
   * @deprecated -
   * @pre -
   * @param pattern Pattern string.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetPattern(std::string pattern) { pattern_ = std::move(pattern); }

  /**
   * @ingroup common
   * @fn void PropertyType::SetCustomAttributes(std::map<std::string,
   * std::string> custom_attributes)
   * @brief Set custom attributes map.
   * @deprecated -
   * @pre -
   * @param custom_attributes Custom attributes map.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetCustomAttributes(
    std::map<std::string, std::string> custom_attributes) {
    custom_attributes_ = std::move(custom_attributes);
  }

  /**
   * @ingroup common
   * @fn void PropertyType::AddCustomAttribute(std::string key, std::string
   * value)
   * @brief Add custom attribute.
   * @deprecated -
   * @pre -
   * @param key Attribute key.
   * @param value Attribute value.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void AddCustomAttribute(std::string key, std::string value) {
    custom_attributes_[std::move(key)] = std::move(value);
  }

 private:
  std::string path_;
  DataType dataType_;
  StructTypeRef dataTypeRef_;
  std::string deprecation_{};
  std::string unit_{};
  ValueType min_{};
  ValueType max_{};
  std::string comment_{};
  std::vector<std::string> allowed_{};
  std::string description_{};
  uint64_t arraysize_ = 0;
  std::string pattern_{};
  std::map<std::string, std::string> custom_attributes_{};
};

}  // namespace yoriito::databroker
#endif  // COMMON_DATABROKER_TYPES_PROPERTY_TYPE_H_
