/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright 2026 JASPAR
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "Struct_ThreePhaseVoltageMeasurements_internal.h"

// clang-format off
namespace yoriito::types::internal {
// clang-format on

yoriito::StructDataPtr ThreePhaseVoltageMeasurementsUtility::ToStructData(
    const ThreePhaseVoltageMeasurements& data) {
  auto struct_data = std::make_unique<yoriito::StructData>();
  struct_data->SetProperty("Phase1", yoriito::ValueType{data.phase1});
  struct_data->SetProperty("Phase2", yoriito::ValueType{data.phase2});
  struct_data->SetProperty("Phase3", yoriito::ValueType{data.phase3});
  return struct_data;
}

// Load ThreePhaseVoltageMeasurements data from StructData.
bool ThreePhaseVoltageMeasurementsUtility::FromStructData(
    const yoriito::StructData& struct_data,
    ThreePhaseVoltageMeasurements* data) {
  return ExtractProperty(struct_data, "Phase1", &data->phase1) &&
         ExtractProperty(struct_data, "Phase2", &data->phase2) &&
         ExtractProperty(struct_data, "Phase3", &data->phase3);
}

// Validate ThreePhaseVoltageMeasurements data.
yoriito::Result<void> ThreePhaseVoltageMeasurementsUtility::Validate(
    const yoriito::databroker::ConsumerInspectResponse& inspect_response,
    const ThreePhaseVoltageMeasurements& data) {
  if (inspect_response.GetDataPoints().empty()) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", std::string(yoriito::ErrorType::to_msg(
                                            yoriito::ErrorCode::ERROR_NODATA)));
    return yoriito::Result<void>::Err(std::make_unique<yoriito::CommonError>(
        yoriito::ErrorCode::ERROR_NODATA));
  }

  const auto& inspect_data = inspect_response.GetDataPoints().front();
  const auto& ref = inspect_data.GetDataTypeRef();
  if (ref.has_value() && ref->IsResolved()) {
    const auto struct_type = ref->Resolved();
    // RESERVE: Implement validation for struct if needed. Currently, we only
    // validate the struct properties. check struct properties metadata
    auto result = ValidateProperties(struct_type, data);
    if (!result.IsOk()) {
      return result;
    }
  } else {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", std::string(yoriito::ErrorType::to_msg(
                                            yoriito::ErrorCode::ERROR_NODATA)));
    return yoriito::Result<void>::Err(std::make_unique<yoriito::CommonError>(
        yoriito::ErrorCode::ERROR_NODATA));
  }
  return yoriito::Result<void>::Ok();
}

template <typename T>
bool ThreePhaseVoltageMeasurementsUtility::ExtractProperty(
    const yoriito::StructData& struct_data, const std::string& prop_name,
    T* prop_value) {
  auto it = struct_data.GetProperties().find(prop_name);
  if (it == struct_data.GetProperties().end()) {
    return false;
  }
  if (std::holds_alternative<yoriito::StructDataPtr>(it->second)) {
    // property is nested struct.
    // RESERVED: Implement nested struct extract.
  } else {
    // property is primitive
    if (!std::holds_alternative<T>(it->second)) {
      return false;
    } else {
      *prop_value = std::get<T>(it->second);
    }
  }
  return true;
}

yoriito::Result<void> ThreePhaseVoltageMeasurementsUtility::ValidateProperties(
    const std::shared_ptr<yoriito::databroker::StructType>& struct_type,
    const ThreePhaseVoltageMeasurements& data) {
  auto result = ValidatePropertyRange(
      struct_type, "Types.ThreePhaseVoltageMeasurements.Phase1", data.phase1);
  if (!result.IsOk()) {
    return result;
  }
  result = ValidatePropertyRange(
      struct_type, "Types.ThreePhaseVoltageMeasurements.Phase2", data.phase2);
  if (!result.IsOk()) {
    return result;
  }
  result = ValidatePropertyRange(
      struct_type, "Types.ThreePhaseVoltageMeasurements.Phase3", data.phase3);
  if (!result.IsOk()) {
    return result;
  }
  return yoriito::Result<void>::Ok();
}

template <typename T>
yoriito::Result<void>
ThreePhaseVoltageMeasurementsUtility::ValidatePropertyRange(
    const std::shared_ptr<yoriito::databroker::StructType>& struct_type,
    const std::string& prop_path, const T& prop_value) {
  const auto* prop = struct_type->GetPropertyByName(prop_path);
  if (prop == nullptr) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", std::string(yoriito::ErrorType::to_msg(
                                            yoriito::ErrorCode::ERROR_NODATA)));
    return yoriito::Result<void>::Err(std::make_unique<yoriito::CommonError>(
        yoriito::ErrorCode::ERROR_NODATA));
  }

  if (prop->IsStruct()) {
    // property is nested struct.
    // RESERVED: Implement nested struct validation.
  } else {
    const auto& min_data = prop->GetMin();
    if (std::holds_alternative<T>(min_data)) {
      const auto& min_value = std::get<T>(min_data);
      if (prop_value < min_value) {
        std::string err_msg = std::string(
            yoriito::ErrorType::to_msg(yoriito::ErrorCode::ERROR_INVAL));
        err_msg += std::string(prop_path);
        YORIITO_LOG_ERROR("SAPI_SignalAPI", err_msg);
        return yoriito::Result<void>::Err(
            std::make_unique<yoriito::CommonError>(
                yoriito::ErrorCode::ERROR_INVAL, err_msg));
      }
    }

    const auto& max_data = prop->GetMax();
    if (std::holds_alternative<T>(max_data)) {
      const auto& max_value = std::get<T>(max_data);
      if (prop_value > max_value) {
        std::string err_msg = std::string(
            yoriito::ErrorType::to_msg(yoriito::ErrorCode::ERROR_INVAL));
        err_msg += std::string(prop_path);
        YORIITO_LOG_ERROR("SAPI_SignalAPI", err_msg);
        return yoriito::Result<void>::Err(
            std::make_unique<yoriito::CommonError>(
                yoriito::ErrorCode::ERROR_INVAL, err_msg));
      }
    }

    // TODO(Functional Enhancement Team): Check Allowed after GetAllowed return
    // type is fixed.
    if constexpr (std::is_same_v<T, std::string>) {
      const auto& allowed_values = prop->GetAllowed();
      if (!allowed_values.empty()) {
        bool matched = false;
        for (const auto& allowed_value : allowed_values) {
          if (allowed_value == prop_value) {
            matched = true;
            break;
          }
        }
        if (!matched) {
          std::string err_msg = std::string(
              yoriito::ErrorType::to_msg(yoriito::ErrorCode::ERROR_INVAL));
          err_msg += std::string(prop_path);
          YORIITO_LOG_ERROR("SAPI_SignalAPI", err_msg);
          return yoriito::Result<void>::Err(
              std::make_unique<yoriito::CommonError>(
                  yoriito::ErrorCode::ERROR_INVAL, err_msg));
        }
      }
    }
  }
  return yoriito::Result<void>::Ok();
}

// clang-format off
}  // namespace yoriito::types::internal
// clang-format on
