// SPDX-License-Identifier: Apache-2.0
//
// Copyright 2026 JASPAR
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Signal_HeadPosition.h"

//-------------------------------------------------------------------------------------
// VSS Signal: Vehicle.Occupant.Row2.PassengerSide.HeadPosition
// Type      : sensor
// DataType  : Types.Pose
// Unit      : None
//-------------------------------------------------------------------------------------
// clang-format off
namespace yoriito::vehicle::occupant::row2::passengerside::headposition {
// clang-format on
namespace internal = yoriito::types::internal;

yoriito::Result<yoriito::signal::SignalGetDataPoint<Pose>> Get() {
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Entering function [Get].");
  yoriito::databroker::DataBrokerConsumer* consumer =
      yoriito::databroker::DataBrokerConsumerFactory::GetInstance();
  yoriito::databroker::ConsumerGetRequest request(
      VEHICLE_OCCUPANT_ROW2_PASSENGERSIDE_HEADPOSITION);
  yoriito::Result<yoriito::databroker::ConsumerGetResponse> ret =
      consumer->Get(request);
  if (!ret.IsOk()) {
    std::unique_ptr<yoriito::ErrorType> err_ptr = ret.TakeErr();
    YORIITO_LOG_ERROR("SAPI_SignalAPI", err_ptr->Message());
    return yoriito::Result<yoriito::signal::SignalGetDataPoint<Pose>>::Err(
        std::move(err_ptr));
  }
  auto response = ret.TakeOk().value();
  if (response.GetDataPoints().empty()) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", std::string(yoriito::ErrorType::to_msg(
                                            yoriito::ErrorCode::ERROR_NODATA)));
    return yoriito::Result<yoriito::signal::SignalGetDataPoint<Pose>>::Err(
        std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_NODATA));
  }
  const auto& data_point = response.GetDataPoints().front();
  const auto& data = data_point.GetData();

  // Extract StructDataPtr from ValueType
  if (!std::holds_alternative<yoriito::StructDataPtr>(data)) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", "Unexpected data type");
    return yoriito::Result<yoriito::signal::SignalGetDataPoint<Pose>>::Err(
        std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_BADMSG));
  }

  const auto& struct_data_ptr = std::get<yoriito::StructDataPtr>(data);
  if (!struct_data_ptr) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", "Data pointer is null");
    return yoriito::Result<yoriito::signal::SignalGetDataPoint<Pose>>::Err(
        std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_NODATA));
  }

  // Load Pose data from StructData
  Pose result;
  if (!internal::FromStructData(*struct_data_ptr, &result)) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI",
                      "Failed to extract Pose data from StructData");
    return yoriito::Result<yoriito::signal::SignalGetDataPoint<Pose>>::Err(
        std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_NODATA));
  }
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Exiting function [Get].");
  return yoriito::Result<yoriito::signal::SignalGetDataPoint<Pose>>::Ok(
      yoriito::signal::SignalGetDataPoint<Pose>(
          data_point.GetPath(), result, data_point.IsAvailableSensor(),
          data_point.IsAvailableActuator(), data_point.GetStoredTimestamp(),
          data_point.GetProducedTimestamp()));
}

yoriito::Result<yoriito::signal::SignalSubscribeContext<Pose>> Subscribe() {
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Entering function [Subscribe].");
  yoriito::databroker::DataBrokerConsumer* consumer =
      yoriito::databroker::DataBrokerConsumerFactory::GetInstance();
  yoriito::databroker::ConsumerSubscribeRequest request(
      VEHICLE_OCCUPANT_ROW2_PASSENGERSIDE_HEADPOSITION);
  auto ret = consumer->Subscribe(request);
  if (!ret.IsOk()) {
    std::unique_ptr<yoriito::ErrorType> err_ptr = ret.TakeErr();
    YORIITO_LOG_ERROR("SAPI_SignalAPI", err_ptr->Message());
    return yoriito::Result<yoriito::signal::SignalSubscribeContext<Pose>>::Err(
        std::move(err_ptr));
  }
  auto subscription_context = ret.TakeOk().value();
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Exiting function [Subscribe].");
  return yoriito::Result<yoriito::signal::SignalSubscribeContext<Pose>>::Ok(
      yoriito::signal::SignalSubscribeContext<Pose>(
          std::move(subscription_context)));
}

yoriito::Result<void> UnSubscribe(
    yoriito::signal::SignalSubscribeContext<Pose> subscription_context) {
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Entering function [UnSubscribe].");
  yoriito::databroker::DataBrokerConsumer* consumer =
      yoriito::databroker::DataBrokerConsumerFactory::GetInstance();
  auto internal_ctx =
      yoriito::signal::SubscribeContextAccess::Release(&subscription_context);
  if (!internal_ctx) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI",
                      std::string(yoriito::ErrorType::to_msg(
                          yoriito::ErrorCode::ERROR_UNSUBSCRIBE)));
    return yoriito::Result<void>::Err(std::make_unique<yoriito::CommonError>(
        yoriito::ErrorCode::ERROR_UNSUBSCRIBE));
  }
  auto ret = consumer->UnSubscribe(std::move(internal_ctx));
  if (!ret.IsOk()) {
    std::unique_ptr<yoriito::ErrorType> err_ptr = ret.TakeErr();
    YORIITO_LOG_ERROR("SAPI_SignalAPI", err_ptr->Message());
    return yoriito::Result<void>::Err(std::move(err_ptr));
  }
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Exiting function [UnSubscribe].");
  return ret;
}

yoriito::Result<yoriito::signal::SignalInspectResponse<Pose>> Inspect() {
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Entering function [Inspect].");
  yoriito::databroker::DataBrokerConsumer* consumer =
      yoriito::databroker::DataBrokerConsumerFactory::GetInstance();
  yoriito::databroker::ConsumerInspectRequest request(
      VEHICLE_OCCUPANT_ROW2_PASSENGERSIDE_HEADPOSITION);
  yoriito::Result<yoriito::databroker::ConsumerInspectResponse> ret =
      consumer->Inspect(request);
  if (!ret.IsOk()) {
    std::unique_ptr<yoriito::ErrorType> err_ptr = ret.TakeErr();
    YORIITO_LOG_ERROR("SAPI_SignalAPI", err_ptr->Message());
    return yoriito::Result<yoriito::signal::SignalInspectResponse<Pose>>::Err(
        std::move(err_ptr));
  }
  auto response = ret.TakeOk();
  if (response.value().GetDataPoints().empty()) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", std::string(yoriito::ErrorType::to_msg(
                                            yoriito::ErrorCode::ERROR_NODATA)));
    return yoriito::Result<yoriito::signal::SignalInspectResponse<Pose>>::Err(
        std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_NODATA));
  }
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Exiting function [Inspect].");
  return yoriito::Result<yoriito::signal::SignalInspectResponse<Pose>>::Ok(
      yoriito::signal::SignalInspectResponse<Pose>(
          std::move(response.value())));
}

// clang-format off
}  // namespace yoriito::vehicle::occupant::row2::passengerside::headposition
// clang-format on
