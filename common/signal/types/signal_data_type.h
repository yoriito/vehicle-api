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

#ifndef COMMON_SIGNAL_TYPES_SIGNAL_DATA_TYPE_H_
#define COMMON_SIGNAL_TYPES_SIGNAL_DATA_TYPE_H_

#include <optional>
#include <type_traits>
#include <variant>

#include "databroker/base_inspect_data.h"
#include "databroker/data_type.h"
#include "databroker_type.h"

/**
 * @ingroup common
 * @namespace yoriito::signal
 * @brief Namespace for Signal API common interfaces and types.
 */
namespace yoriito::signal {

enum class SignalEntryType: int32_t {
  SIGNAL_ENTRY_TYPE_UNSPECIFIED,
  SIGNAL_ENTRY_TYPE_ATTRIBUTE,
  SIGNAL_ENTRY_TYPE_SENSOR,
  SIGNAL_ENTRY_TYPE_ACTUATOR
};

enum class SignalDataType: int32_t {
  SIGNAL_DATA_TYPE_UNSPECIFIED,
  SIGNAL_DATA_TYPE_STRING,
  SIGNAL_DATA_TYPE_BOOLEAN,
  SIGNAL_DATA_TYPE_INT8,
  SIGNAL_DATA_TYPE_INT16,
  SIGNAL_DATA_TYPE_INT32,
  SIGNAL_DATA_TYPE_INT64,
  SIGNAL_DATA_TYPE_UINT8,
  SIGNAL_DATA_TYPE_UINT16,
  SIGNAL_DATA_TYPE_UINT32,
  SIGNAL_DATA_TYPE_UINT64,
  SIGNAL_DATA_TYPE_FLOAT,
  SIGNAL_DATA_TYPE_DOUBLE,
  SIGNAL_DATA_TYPE_TIMESTAMP,  // Not exist in VSS
  SIGNAL_DATA_TYPE_STRING_ARRAY,
  SIGNAL_DATA_TYPE_BOOLEAN_ARRAY,
  SIGNAL_DATA_TYPE_INT8_ARRAY,
  SIGNAL_DATA_TYPE_INT16_ARRAY,
  SIGNAL_DATA_TYPE_INT32_ARRAY,
  SIGNAL_DATA_TYPE_INT64_ARRAY,
  SIGNAL_DATA_TYPE_UINT8_ARRAY,
  SIGNAL_DATA_TYPE_UINT16_ARRAY,
  SIGNAL_DATA_TYPE_UINT32_ARRAY,
  SIGNAL_DATA_TYPE_UINT64_ARRAY,
  SIGNAL_DATA_TYPE_FLOAT_ARRAY,
  SIGNAL_DATA_TYPE_DOUBLE_ARRAY,
  SIGNAL_DATA_TYPE_STRUCT,
  SIGNAL_DATA_TYPE_STRUCT_ARRAY
};

/**
 * @ingroup signal_api
 * @fn constexpr SignalEntryType
 * ConvertToSignalEntryType(yoriito::databroker::BaseInspectData::EntryType
 * entry_type)
 * @brief Converts an internal EntryType to the corresponding public
 * SignalEntryType.
 * @deprecated -
 * @pre -
 * @param entry_type The internal EntryType value to convert.
 * @retval SignalEntryType The corresponding public-facing entry type.
 * @note Falls back to SIGNAL_ENTRY_TYPE_UNSPECIFIED if entry_type does not
 *       match any known case.
 * @code -
 * @endcode -
 */
constexpr SignalEntryType ConvertToSignalEntryType(
    yoriito::databroker::BaseInspectData::EntryType entry_type) noexcept {
  switch (entry_type) {
    case yoriito::databroker::BaseInspectData::EntryType::
        ENTRY_TYPE_UNSPECIFIED:
      return SignalEntryType::SIGNAL_ENTRY_TYPE_UNSPECIFIED;
    case yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_ATTRIBUTE:
      return SignalEntryType::SIGNAL_ENTRY_TYPE_ATTRIBUTE;
    case yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_SENSOR:
      return SignalEntryType::SIGNAL_ENTRY_TYPE_SENSOR;
    case yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_ACTUATOR:
      return SignalEntryType::SIGNAL_ENTRY_TYPE_ACTUATOR;
    default:
      return SignalEntryType::SIGNAL_ENTRY_TYPE_UNSPECIFIED;
  }
  return SignalEntryType::SIGNAL_ENTRY_TYPE_UNSPECIFIED;
}

/**
 * @ingroup signal_api
 * @fn constexpr SignalDataType
 * ConvertToSignalDataType(yoriito::databroker::DataType data_type)
 * @brief Converts an internal DataType to the corresponding public
 * SignalDataType.
 * @deprecated -
 * @pre -
 * @param data_type The internal DataType value to convert.
 * @retval SignalDataType The corresponding public-facing data type.
 * @note Falls back to SIGNAL_DATA_TYPE_UNSPECIFIED if data_type does not
 *       match any known case.
 * @code -
 * @endcode -
 */
constexpr SignalDataType ConvertToSignalDataType(
    yoriito::databroker::DataType data_type) noexcept {
  // #lizard forgives(cyclomatic_complexity)
  switch (data_type) {
    case yoriito::databroker::DataType::DATA_TYPE_UNSPECIFIED:
      return SignalDataType::SIGNAL_DATA_TYPE_UNSPECIFIED;
    case yoriito::databroker::DataType::DATA_TYPE_STRING:
      return SignalDataType::SIGNAL_DATA_TYPE_STRING;
    case yoriito::databroker::DataType::DATA_TYPE_BOOLEAN:
      return SignalDataType::SIGNAL_DATA_TYPE_BOOLEAN;
    case yoriito::databroker::DataType::DATA_TYPE_INT8:
      return SignalDataType::SIGNAL_DATA_TYPE_INT8;
    case yoriito::databroker::DataType::DATA_TYPE_INT16:
      return SignalDataType::SIGNAL_DATA_TYPE_INT16;
    case yoriito::databroker::DataType::DATA_TYPE_INT32:
      return SignalDataType::SIGNAL_DATA_TYPE_INT32;
    case yoriito::databroker::DataType::DATA_TYPE_INT64:
      return SignalDataType::SIGNAL_DATA_TYPE_INT64;
    case yoriito::databroker::DataType::DATA_TYPE_UINT8:
      return SignalDataType::SIGNAL_DATA_TYPE_UINT8;
    case yoriito::databroker::DataType::DATA_TYPE_UINT16:
      return SignalDataType::SIGNAL_DATA_TYPE_UINT16;
    case yoriito::databroker::DataType::DATA_TYPE_UINT32:
      return SignalDataType::SIGNAL_DATA_TYPE_UINT32;
    case yoriito::databroker::DataType::DATA_TYPE_UINT64:
      return SignalDataType::SIGNAL_DATA_TYPE_UINT64;
    case yoriito::databroker::DataType::DATA_TYPE_FLOAT:
      return SignalDataType::SIGNAL_DATA_TYPE_FLOAT;
    case yoriito::databroker::DataType::DATA_TYPE_DOUBLE:
      return SignalDataType::SIGNAL_DATA_TYPE_DOUBLE;
    case yoriito::databroker::DataType::DATA_TYPE_TIMESTAMP:
      return SignalDataType::SIGNAL_DATA_TYPE_TIMESTAMP;
    case yoriito::databroker::DataType::DATA_TYPE_STRING_ARRAY:
      return SignalDataType::SIGNAL_DATA_TYPE_STRING_ARRAY;
    case yoriito::databroker::DataType::DATA_TYPE_BOOLEAN_ARRAY:
      return SignalDataType::SIGNAL_DATA_TYPE_BOOLEAN_ARRAY;
    case yoriito::databroker::DataType::DATA_TYPE_INT8_ARRAY:
      return SignalDataType::SIGNAL_DATA_TYPE_INT8_ARRAY;
    case yoriito::databroker::DataType::DATA_TYPE_INT16_ARRAY:
      return SignalDataType::SIGNAL_DATA_TYPE_INT16_ARRAY;
    case yoriito::databroker::DataType::DATA_TYPE_INT32_ARRAY:
      return SignalDataType::SIGNAL_DATA_TYPE_INT32_ARRAY;
    case yoriito::databroker::DataType::DATA_TYPE_INT64_ARRAY:
      return SignalDataType::SIGNAL_DATA_TYPE_INT64_ARRAY;
    case yoriito::databroker::DataType::DATA_TYPE_UINT8_ARRAY:
      return SignalDataType::SIGNAL_DATA_TYPE_UINT8_ARRAY;
    case yoriito::databroker::DataType::DATA_TYPE_UINT16_ARRAY:
      return SignalDataType::SIGNAL_DATA_TYPE_UINT16_ARRAY;
    case yoriito::databroker::DataType::DATA_TYPE_UINT32_ARRAY:
      return SignalDataType::SIGNAL_DATA_TYPE_UINT32_ARRAY;
    case yoriito::databroker::DataType::DATA_TYPE_UINT64_ARRAY:
      return SignalDataType::SIGNAL_DATA_TYPE_UINT64_ARRAY;
    case yoriito::databroker::DataType::DATA_TYPE_FLOAT_ARRAY:
      return SignalDataType::SIGNAL_DATA_TYPE_FLOAT_ARRAY;
    case yoriito::databroker::DataType::DATA_TYPE_DOUBLE_ARRAY:
      return SignalDataType::SIGNAL_DATA_TYPE_DOUBLE_ARRAY;
    case yoriito::databroker::DataType::DATA_TYPE_STRUCT:
      return SignalDataType::SIGNAL_DATA_TYPE_STRUCT;
    case yoriito::databroker::DataType::DATA_TYPE_STRUCT_ARRAY:
      return SignalDataType::SIGNAL_DATA_TYPE_STRUCT_ARRAY;
    default:
      return SignalDataType::SIGNAL_DATA_TYPE_UNSPECIFIED;
  }
  return SignalDataType::SIGNAL_DATA_TYPE_UNSPECIFIED;
}

/**
 * @ingroup signal_api
 * @struct IsVariantAlternative
 * @brief Type trait to check if a type is one of the alternative types in a
 * std::variant.
 * @tparam U The target type to search for.
 * @tparam Variant The std::variant type to inspect.
 * @deprecated -
 * @pre -
 * @note Uses `std::disjunction` and `std::is_same` internally for template
 * argument evaluation.
 * @code -
 * @endcode -
 */
template <typename U, typename Variant>
struct IsVariantAlternative : std::false_type {};

template <typename U, typename... Ts>
struct IsVariantAlternative<U, std::variant<Ts...>>
    : std::disjunction<std::is_same<U, Ts>...> {};

template <typename U, typename Variant>
inline constexpr bool IsVariantAlternative_v =
    IsVariantAlternative<U, Variant>::value;

/**
 * @ingroup signal_api
 * @fn std::optional<U> ExtractValue(const yoriito::ValueType& value)
 * @brief Extracts a value of type U from the internal ValueType variant.
 * @deprecated -
 * @pre -
 * @param value The internal ValueType to extract from.
 * @retval std::optional<U> The extracted value, or nullopt.
 * @note Returns nullopt when U is not an alternative of ValueType (e.g. for
 *       struct-typed signals) or when the variant currently holds another
 *       type.
 * @code -
 * @endcode -
 */
template <typename U>
inline std::optional<U> ExtractValue(const yoriito::ValueType& value) {
  if constexpr (IsVariantAlternative_v<U, yoriito::ValueType>) {
    if (std::holds_alternative<U>(value)) {
      return std::get<U>(value);
    }
  }
  return std::nullopt;
}

}  // namespace yoriito::signal

#endif  // COMMON_SIGNAL_TYPES_SIGNAL_DATA_TYPE_H_
