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

#ifndef COMMON_DATABROKER_BASE_INSPECT_DATA_H_
#define COMMON_DATABROKER_BASE_INSPECT_DATA_H_

#include <map>
#include <optional>
#include <string>
#include <utility>
#include <vector>

#include "databroker_type.h"
#include "databroker/data_type.h"
#include "databroker/types/struct_type.h"
#include "databroker/types/struct_type_ref.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup common
 * @class BaseInspectData
 * @brief Base class for inspecting datapoint metadata in the DataBroker.
 */
class BaseInspectData {
 public:
  enum class EntryType {
    ENTRY_TYPE_UNSPECIFIED,
    ENTRY_TYPE_ATTRIBUTE,
    ENTRY_TYPE_SENSOR,
    ENTRY_TYPE_ACTUATOR
  };
  using DataType = yoriito::databroker::DataType;
  /**
   * @ingroup common
   * @fn BaseInspectData::BaseInspectData()
   * @brief Deleted default constructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  BaseInspectData() = delete;

  BaseInspectData(const BaseInspectData& other)
      : path(other.path),
        data_type(other.data_type),
        entry_type(other.entry_type),
        deprecation(other.deprecation),
        unit(other.unit),
        min(CloneValueType(other.min)),
        max(CloneValueType(other.max)),
        comment(other.comment),
        allowed(other.allowed),
        default_value(CloneValueType(other.default_value)),
        description(other.description),
        arraysize(other.arraysize),
        pattern(other.pattern),
        custom_attributes(other.custom_attributes),
        dataTypeRef_(other.dataTypeRef_) {}

  BaseInspectData& operator=(const BaseInspectData& other) & {
    if (this == &other) {
      return *this;
    }
    path = other.path;
    data_type = other.data_type;
    entry_type = other.entry_type;
    deprecation = other.deprecation;
    unit = other.unit;
    min = CloneValueType(other.min);
    max = CloneValueType(other.max);
    comment = other.comment;
    allowed = other.allowed;
    default_value = CloneValueType(other.default_value);
    description = other.description;
    arraysize = other.arraysize;
    pattern = other.pattern;
    custom_attributes = other.custom_attributes;
    dataTypeRef_ = other.dataTypeRef_;
    return *this;
  }

  BaseInspectData(BaseInspectData&&) noexcept = default;
  BaseInspectData& operator=(BaseInspectData&&) noexcept = default;

  /**
   * @ingroup common
   * @fn BaseInspectData::BaseInspectData(std::string path, DataType data_type,
   * EntryType entry_type, std::string deprecation, std::string unit, ValueType
   * min, ValueType max, std::string comment, std::vector<std::string> allowed,
   * ValueType default_value, std::string description, uint64_t arraysize,
   * std::string pattern, std::map<std::string, std::string> custom_attributes)
   * @brief Construct a BaseInspectData object with all attributes.
   * @deprecated -
   * @pre -
   * @param path Datapoint path.
   * @param data_type Data type.
   * @param entry_type Entry type.
   * @param deprecation Deprecation string.
   * @param unit Unit string.
   * @param min Minimum value.
   * @param max Maximum value.
   * @param comment Comment string.
   * @param allowed Allowed values.
   * @param default_value Default value.
   * @param description Description string.
   * @param arraysize Array size.
   * @param pattern Pattern string.
   * @param custom_attributes Custom attributes map.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit BaseInspectData(
    const std::string& path, DataType data_type, EntryType entry_type,
    const std::string& deprecation, const std::string& unit, ValueType min,
    ValueType max, const std::string& comment,
    const std::vector<std::string>& allowed, ValueType default_value,
    const std::string& description, uint64_t arraysize,
    const std::string& pattern,
    const std::map<std::string, std::string>& custom_attributes)
      : path(path),
        data_type(data_type),
        entry_type(entry_type),
        deprecation(deprecation),
        unit(unit),
        min(CloneValueType(min)),
        max(CloneValueType(max)),
        comment(comment),
        allowed(allowed),
        default_value(CloneValueType(default_value)),
        description(description),
        arraysize(arraysize),
        pattern(pattern),
        custom_attributes(custom_attributes) {}

  /**
   * @ingroup common
   * @fn bool operator==(const BaseInspectData& lhs, const BaseInspectData& rhs)
   * @brief Compare two BaseInspectData objects for equality.
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
  friend bool operator==(const BaseInspectData& lhs,
                         const BaseInspectData& rhs) {
    return (lhs.path == rhs.path) && (lhs.data_type == rhs.data_type) &&
           (lhs.entry_type == rhs.entry_type) &&
           (lhs.arraysize == rhs.arraysize) &&
           (ValueTypeEquals(lhs.min, rhs.min)) &&
           (ValueTypeEquals(lhs.max, rhs.max)) &&
           (ValueTypeEquals(lhs.default_value, rhs.default_value)) &&
           (lhs.unit == rhs.unit) && (lhs.deprecation == rhs.deprecation) &&
           (lhs.comment == rhs.comment) && (lhs.pattern == rhs.pattern) &&
           (lhs.description == rhs.description) &&
           (lhs.allowed == rhs.allowed) &&
           (lhs.custom_attributes == rhs.custom_attributes);
  }

  DataType GetDataType() const { return data_type; }
  EntryType GetEntryType() const { return static_cast<EntryType>(entry_type); }
  // Rvalue overloads below return by value (cloning ValueType, which holds a
  // move-only unique_ptr alternative) to avoid a reference dangling past the
  // temporary's lifetime.
  const std::string& GetPath() const& { return path; }
  std::string GetPath() const&& { return path; }
  const std::string& GetDescription() const& { return description; }
  std::string GetDescription() const&& { return description; }
  const std::string& GetComment() const& { return comment; }
  std::string GetComment() const&& { return comment; }
  const std::string& GetDeprecation() const& { return deprecation; }
  std::string GetDeprecation() const&& { return deprecation; }
  const std::string& GetUnit() const& { return unit; }
  std::string GetUnit() const&& { return unit; }
  const ValueType& GetMin() const& { return min; }
  ValueType GetMin() const&& { return CloneValueType(min); }
  const ValueType& GetMax() const& { return max; }
  ValueType GetMax() const&& { return CloneValueType(max); }
  const std::vector<std::string>& GetAllowed() const& { return allowed; }
  std::vector<std::string> GetAllowed() const&& { return allowed; }
  const ValueType& GetDefaultValue() const& { return default_value; }
  ValueType GetDefaultValue() const&& { return CloneValueType(default_value); }
  uint64_t GetArraySize() const { return arraysize; }
  const std::string& GetPattern() const& { return pattern; }
  std::string GetPattern() const&& { return pattern; }
  const std::map<std::string, std::string>& GetCustomAttributes() const& {
    return custom_attributes;
  }
  std::map<std::string, std::string> GetCustomAttributes() const&& {
    return custom_attributes;
  }
  const std::optional<yoriito::databroker::StructTypeRef>& GetDataTypeRef()
    const& {
    return dataTypeRef_;
  }
  std::optional<yoriito::databroker::StructTypeRef> GetDataTypeRef() const&& {
    return dataTypeRef_;
  }
  void SetDataTypeRef(yoriito::databroker::StructTypeRef dataTypeRef) {
    dataTypeRef_ = std::move(dataTypeRef);
  }
  /**
   * @ingroup common
   * @brief Builder class for constructing BaseInspectData objects.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  class Builder {
   private:
    std::string path;
    DataType data_type = DataType::DATA_TYPE_UNSPECIFIED;
    EntryType entry_type = EntryType::ENTRY_TYPE_UNSPECIFIED;
    std::string deprecation;
    std::string unit;
    ValueType min;
    ValueType max;
    std::string comment;
    std::vector<std::string> allowed;
    ValueType default_value;
    std::string description;
    uint64_t arraysize = 0;
    std::string pattern;
    std::map<std::string, std::string> custom_attributes;

   public:
    /**
     * @ingroup common
     * @fn BaseInspectData::Builder::Builder()
     * @brief Default constructor for Builder.
     * @deprecated -
     * @pre -
     * @param -
     * @retval -
     * @note -
     * @code -
     * @endcode -
     */
    Builder() = default;
    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetPath(const std::string& new_path)
     * @brief Set the datapoint path.
     * @deprecated -
     * @pre -
     * @param new_path Datapoint path.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetPath(const std::string& new_path) & {
      path = new_path;
      return *this;
    }
    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetDataType(DataType new_data_type)
     * @brief Set the data type.
     * @deprecated -
     * @pre -
     * @param new_data_type Data type.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetDataType(DataType new_data_type) & {
      data_type = new_data_type;
      return *this;
    }

    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetEntryType(EntryType new_entry_type)
     * @brief Set the entry type.
     * @deprecated -
     * @pre -
     * @param new_entry_type Entry type.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetEntryType(EntryType new_entry_type) & {
      entry_type = new_entry_type;
      return *this;
    }

    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetDescription(const std::string&
     * new_description)
     * @brief Set the description string.
     * @deprecated -
     * @pre -
     * @param new_description Description string.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetDescription(const std::string& new_description) & {
      description = new_description;
      return *this;
    }
    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetComment(const std::string& new_comment)
     * @brief Set the comment string.
     * @deprecated -
     * @pre -
     * @param new_comment Comment string.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetComment(const std::string& new_comment) & {
      comment = new_comment;
      return *this;
    }
    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetDeprecation(const std::string&
     * new_deprecation)
     * @brief Set the deprecation string.
     * @deprecated -
     * @pre -
     * @param new_deprecation Deprecation string.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetDeprecation(const std::string& new_deprecation) & {
      deprecation = new_deprecation;
      return *this;
    }
    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetUnit(conststd::string& new_unit)
     * @brief Set the unit string.
     * @deprecated -
     * @pre -
     * @param new_unit Unit string.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetUnit(const std::string& new_unit) & {
      unit = new_unit;
      return *this;
    }
    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetMin(constValueType& new_min)
     * @brief Set the minimum value.
     * @deprecated -
     * @pre -
     * @param new_min Minimum value.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetMin(const ValueType& new_min) & {
      min = CloneValueType(new_min);
      return *this;
    }
    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetMax(const ValueType& new_max)
     * @brief Set the maximum value.
     * @deprecated -
     * @pre -
     * @param new_max Maximum value.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetMax(const ValueType& new_max) & {
      max = CloneValueType(new_max);
      return *this;
    }
    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetAllowed(std::vector<std::string>
     * new_allowed)
     * @brief Set the allowed values.
     * @deprecated -
     * @pre -
     * @param new_allowed Allowed values.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetAllowed(std::vector<std::string> new_allowed) & {
      allowed = std::move(new_allowed);
      return *this;
    }
    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetDefaultValue(const ValueType&
     * new_default_value)
     * @brief Set the default value.
     * @deprecated -
     * @pre -
     * @param new_default_value Default value.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetDefaultValue(const ValueType& new_default_value) & {
      default_value = CloneValueType(new_default_value);
      return *this;
    }
    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetArraySize(uint64_t new_arraysize)
     * @brief Set the array size.
     * @deprecated -
     * @pre -
     * @param new_arraysize Array size.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetArraySize(uint64_t new_arraysize) & {
      arraysize = new_arraysize;
      return *this;
    }
    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetPattern(const std::string& new_pattern)
     * @brief Set the pattern string.
     * @deprecated -
     * @pre -
     * @param new_pattern Pattern string.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetPattern(const std::string& new_pattern) & {
      pattern = new_pattern;
      return *this;
    }
    /**
     * @ingroup common
     * @fn BaseInspectData::Builder&
     * BaseInspectData::Builder::SetCustomAttributes(const std::map<std::string,
     * std::string>& new_custom_attributes)
     * @brief Set the custom attributes map.
     * @deprecated -
     * @pre -
     * @param new_custom_attributes Custom attributes map.
     * @retval Builder& Reference to this builder
     * @note -
     * @code -
     * @endcode -
     */
    Builder& SetCustomAttributes(
      const std::map<std::string, std::string>& new_custom_attributes) & {
      custom_attributes = new_custom_attributes;
      return *this;
    }
    /**
     * @ingroup common
     * @fn BaseInspectData BaseInspectData::Builder::Build()
     * @brief Build a BaseInspectData object from the builder.
     * @deprecated -
     * @pre -
     * @param -
     * @retval BaseInspectData Built object
     * @note -
     * @code -
     * @endcode -
     */
    BaseInspectData Build() const {
      BaseInspectData data(path, data_type, entry_type, deprecation, unit,
                           CloneValueType(min), CloneValueType(max), comment,
                           allowed, CloneValueType(default_value), description,
                           arraysize, pattern, custom_attributes);
      return data;
    }
  };
  static Builder CreateBuilder() { return Builder(); }

 private:
  std::string path;
  DataType data_type;
  EntryType entry_type;
  std::string deprecation;
  std::string unit;
  ValueType min;
  ValueType max;
  std::string comment;
  std::vector<std::string> allowed;
  ValueType default_value;
  std::string description;
  uint64_t arraysize;
  std::string pattern;
  std::map<std::string, std::string> custom_attributes;
  std::optional<yoriito::databroker::StructTypeRef> dataTypeRef_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_BASE_INSPECT_DATA_H_
