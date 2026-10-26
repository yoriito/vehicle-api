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

#ifndef COMMON_SIGNAL_TYPES_SIGNAL_STRUCT_TYPE_H_
#define COMMON_SIGNAL_TYPES_SIGNAL_STRUCT_TYPE_H_

#include <cstdint>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

#include "databroker/types/property_type.h"
#include "databroker/types/struct_type.h"
#include "databroker/types/struct_type_ref.h"
#include "signal/types/signal_data_type.h"

/**
 * @ingroup common
 * @namespace yoriito::signal
 * @brief Namespace for Signal API common interfaces and types.
 */
namespace yoriito::signal {

class SignalStructType;

/**
 * @ingroup common
 * @class SignalPropertyType
 * @brief Class representing a property definition of SignalStructType.
 */
class SignalPropertyType {
 public:
  /**
   * @ingroup signal_api
   * @fn explicit SignalPropertyType(const yoriito::databroker::PropertyType*
   * property)
   * @brief Constructs a SignalPropertyType instance.
   * @deprecated -
   * @pre -
   * @param property Pointer to the PropertyType.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit SignalPropertyType(const yoriito::databroker::PropertyType* property)
      : property_(property) {}

  const std::string& GetPath() const { return property_->GetPath(); }
  const std::string& GetUnit() const { return property_->GetUnit(); }
  const std::string& GetDescription() const {
    return property_->GetDescription();
  }
  const std::string& GetDeprecation() const {
    return property_->GetDeprecation();
  }
  const std::string& GetComment() const { return property_->GetComment(); }
  const std::string& GetPattern() const { return property_->GetPattern(); }
  const std::vector<std::string>& GetAllowed() const {
    return property_->GetAllowed();
  }
  uint64_t GetArraySize() const { return property_->GetArraySize(); }
  const std::map<std::string, std::string>& GetCustomAttributes() const {
    return property_->GetCustomAttributes();
  }
  SignalDataType GetDataType() const {
    return ConvertToSignalDataType(property_->GetDataType());
  }

  /**
   * @ingroup signal_api
   * @fn bool IsStruct() const
   * @brief Checks whether the underlying property represents a structure.
   * @deprecated -
   * @pre -
   * @retval true If the property is a structure.
   * @retval false If the property is not a structure.
   * @note -
   * @code -
   * @endcode -
   */
  bool IsStruct() const { return property_->IsStruct(); }

  /**
   * @ingroup signal_api
   * @fn template <typename U> std::optional<U> GetMinAs() const
   * @brief Retrieves the minimum value of the property converted to type U.
   * @tparam U Target type for value extraction.
   * @deprecated -
   * @pre -
   * @retval std::optional<U> The minimum value if extraction succeeds;
   * otherwise, std::nullopt.
   * @note -
   * @code -
   * @endcode -
   */
  template <typename U>
  std::optional<U> GetMinAs() const {
    return ExtractValue<U>(property_->GetMin());
  }

  /**
   * @ingroup signal_api
   * @fn template <typename U> std::optional<U> GetMaxAs() const
   * @brief Retrieves the maximum value of the property converted to type U.
   * @tparam U Target type for value extraction.
   * @deprecated -
   * @pre -
   * @retval std::optional<U> The maximum value if extraction succeeds;
   * otherwise, std::nullopt.
   * @note -
   * @code -
   * @endcode -
   */
  template <typename U>
  std::optional<U> GetMaxAs() const {
    return ExtractValue<U>(property_->GetMax());
  }

  std::optional<SignalStructType> GetStructType() const;

 private:
  const yoriito::databroker::PropertyType* property_;
};

/**
 * @ingroup common
 * @class SignalStructType
 * @brief Class representing a struct type definition in the Signal API.
 */
class SignalStructType {
 public:
  /**
   * @ingroup signal_api
   * @fn explicit
   * SignalStructType(std::shared_ptr<yoriito::databroker::StructType>
   * struct_type)
   * @brief Constructs a SignalStructType instance.
   * @deprecated -
   * @pre -
   * @param struct_type Shared pointer to the StructType.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit SignalStructType(
    std::shared_ptr<yoriito::databroker::StructType> struct_type)
      : struct_type_(std::move(struct_type)) {}

  const std::string& GetPath() const { return struct_type_->GetPath(); }
  const std::string& GetDescription() const {
    return struct_type_->GetDescription();
  }
  const std::string& GetDeprecation() const {
    return struct_type_->GetDeprecation();
  }
  const std::string& GetComment() const { return struct_type_->GetComment(); }
  const std::map<std::string, std::string>& GetCustomAttributes() const {
    return struct_type_->GetCustomAttributes();
  }

  /**
   * @ingroup signal_api
   * @fn std::vector<SignalPropertyType> GetProperties() const
   * @brief Retrieves all properties belonging to this structure type.
   * @deprecated -
   * @pre -
   * @retval std::vector<SignalPropertyType> A list of properties contained in
   * this structure type.
   * @note -
   * @code -
   * @endcode -
   */
  std::vector<SignalPropertyType> GetProperties() const {
    std::vector<SignalPropertyType> result;
    const auto properties = struct_type_->GetProperties();
    result.reserve(properties.size());
    for (const auto& property : properties) {
      // suppress unused return value warning (MISRA C++-2023 Rule 0.1.2) by
      // casting to void
      static_cast<void>(result.emplace_back(&property));
    }
    return result;
  }

 private:
  std::shared_ptr<yoriito::databroker::StructType> struct_type_;
};

/**
 * @ingroup signal_api
 * @fn inline std::optional<SignalStructType>
 * SignalPropertyType::GetStructType() const
 * @brief Retrieves the structure type definition associated with this property
 * if resolved.
 * @deprecated -
 * @pre -
 * @retval std::optional<SignalStructType> The resolved structure type if
 * available; otherwise, std::nullopt.
 * @note -
 * @code -
 * @endcode -
 */
inline std::optional<SignalStructType> SignalPropertyType::GetStructType()
  const {
  const auto& ref = property_->GetDataTypeRef();
  if (!ref.IsResolved()) {
    return std::nullopt;
  }
  return SignalStructType(ref.Resolved());
}

}  // namespace yoriito::signal

#endif  // COMMON_SIGNAL_TYPES_SIGNAL_STRUCT_TYPE_H_
