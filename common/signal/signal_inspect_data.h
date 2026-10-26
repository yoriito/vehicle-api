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

#ifndef COMMON_SIGNAL_SIGNAL_INSPECT_DATA_H_
#define COMMON_SIGNAL_SIGNAL_INSPECT_DATA_H_

#include <cstdint>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

#include "databroker/consumer_inspect_data.h"
#include "signal/types/signal_data_type.h"
#include "signal/types/signal_struct_type.h"

/**
 * @ingroup common
 * @namespace yoriito::signal
 * @brief Namespace for Signal API common interfaces and types.
 */
namespace yoriito::signal {
/**
 * @ingroup signal_api
 * @class SignalInspectData
 * @brief Public read-only accessor for the metadata of a single datapoint.
 */
template <typename T>
class SignalInspectData {
 public:
  /**
   * @ingroup signal_api
   * @fn SignalInspectData::SignalInspectData()
   * @brief Deleted default constructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  SignalInspectData() = delete;

  /**
   * @ingroup signal_api
   * @fn explicit SignalInspectData(yoriito::databroker::ConsumerInspectData
   * data)
   * @brief Constructs a SignalInspectData instance.
   * @deprecated -
   * @pre -
   * @param data ConsumerInspectData object.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit SignalInspectData(yoriito::databroker::ConsumerInspectData data)
      : data_(std::move(data)) {}

  /**
   * @ingroup signal_api
   * @fn const std::string& SignalInspectData::GetPath() const
   * @brief Get the datapoint path.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Datapoint path.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetPath() const { return data_.GetPath(); }

  /**
   * @ingroup signal_api
   * @fn const std::string& SignalInspectData::GetDescription() const
   * @brief Get the description.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Description string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetDescription() const { return data_.GetDescription(); }

  /**
   * @ingroup signal_api
   * @fn const std::string& SignalInspectData::GetComment() const
   * @brief Get the comment.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Comment string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetComment() const { return data_.GetComment(); }

  /**
   * @ingroup signal_api
   * @fn const std::string& SignalInspectData::GetDeprecation() const
   * @brief Get the deprecation message.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Deprecation string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetDeprecation() const { return data_.GetDeprecation(); }

  /**
   * @ingroup signal_api
   * @fn const std::string& SignalInspectData::GetUnit() const
   * @brief Get the unit.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Unit string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetUnit() const { return data_.GetUnit(); }

  /**
   * @ingroup signal_api
   * @fn const std::vector<std::string>& SignalInspectData::GetAllowed() const
   * @brief Get the allowed values.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::vector<std::string>& Allowed values.
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<std::string>& GetAllowed() const {
    return data_.GetAllowed();
  }

  /**
   * @ingroup signal_api
   * @fn uint64_t SignalInspectData::GetArraySize() const
   * @brief Get the array size.
   * @deprecated -
   * @pre -
   * @param -
   * @retval uint64_t Array size.
   * @note -
   * @code -
   * @endcode -
   */
  uint64_t GetArraySize() const { return data_.GetArraySize(); }

  /**
   * @ingroup signal_api
   * @fn const std::string& SignalInspectData::GetPattern() const
   * @brief Get the pattern.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Pattern string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetPattern() const { return data_.GetPattern(); }

  /**
   * @ingroup signal_api
   * @fn const std::map<std::string, std::string>&
   * SignalInspectData::GetCustomAttributes() const
   * @brief Get the custom attributes.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::map<std::string, std::string>& Custom attributes.
   * @note -
   * @code -
   * @endcode -
   */
  const std::map<std::string, std::string>& GetCustomAttributes() const {
    return data_.GetCustomAttributes();
  }

  /**
   * @ingroup signal_api
   * @fn yoriito::signal::SignalDataType SignalInspectData::GetDataType() const
   * @brief Get the data type of the datapoint.
   * @deprecated -
   * @pre -
   * @param -
   * @retval yoriito::signal::SignalDataType Data type.
   * @note -
   * @code -
   * @endcode -
   */
  yoriito::signal::SignalDataType GetDataType() const {
    return yoriito::signal::ConvertToSignalDataType(data_.GetDataType());
  }

  /**
   * @ingroup signal_api
   * @fn yoriito::signal::SignalEntryType SignalInspectData::GetEntryType()
   * const
   * @brief Get the entry type of the datapoint.
   * @deprecated -
   * @pre -
   * @param -
   * @retval yoriito::signal::SignalEntryType Entry type.
   * @note -
   * @code -
   * @endcode -
   */
  yoriito::signal::SignalEntryType GetEntryType() const {
    return yoriito::signal::ConvertToSignalEntryType(data_.GetEntryType());
  }

  /**
   * @ingroup signal_api
   * @fn bool SignalInspectData::IsStruct() const
   * @brief Check whether the datapoint is a struct type.
   * @deprecated -
   * @pre -
   * @param -
   * @retval true Datapoint is a struct
   * @retval false Datapoint is not a struct
   * @note -
   * @code -
   * @endcode -
   */
  bool IsStruct() const {
    return GetDataType() ==
           yoriito::signal::SignalDataType::SIGNAL_DATA_TYPE_STRUCT;
  }

  /**
   * @ingroup signal_api
   * @fn std::optional<T> SignalInspectData::GetMin() const
   * @brief Get the minimum value.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::optional<T> Minimum value.
   * @note -
   * @code -
   * @endcode -
   */
  std::optional<T> GetMin() const { return ExtractValue<T>(data_.GetMin()); }

  /**
   * @ingroup signal_api
   * @fn std::optional<T> SignalInspectData::GetMax() const
   * @brief Get the maximum value.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::optional<T> Maximum value.
   * @note -
   * @code -
   * @endcode -
   */
  std::optional<T> GetMax() const { return ExtractValue<T>(data_.GetMax()); }

  /**
   * @ingroup signal_api
   * @fn std::optional<T> SignalInspectData::GetDefaultValue() const
   * @brief Get the default value.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::optional<T> Default value.
   * @note -
   * @code -
   * @endcode -
   */
  std::optional<T> GetDefaultValue() const {
    return ExtractValue<T>(data_.GetDefaultValue());
  }

  /**
   * @ingroup signal_api
   * @fn std::shared_ptr<yoriito::databroker::StructType>
   * SignalInspectData::GetStructType() const
   * @brief Get the resolved struct type definition.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::shared_ptr<yoriito::databroker::StructType> Resolved struct
   *         type.
   * @retval nullptr Datapoint is not a struct, or the reference is unresolved.
   * @note -
   * @code -
   * @endcode -
   */
  std::optional<yoriito::signal::SignalStructType> GetStructType() const {
    const auto& ref = data_.GetDataTypeRef();
    if (!ref.has_value() || !ref->IsResolved()) {
      return std::nullopt;
    }
    return SignalStructType(ref->Resolved());
  }

 private:
  yoriito::databroker::ConsumerInspectData data_;
};

}  // namespace yoriito::signal

#endif  // COMMON_SIGNAL_SIGNAL_INSPECT_DATA_H_
