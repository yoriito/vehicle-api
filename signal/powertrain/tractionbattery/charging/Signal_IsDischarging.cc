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

#include "Signal_IsDischarging.h"

//-------------------------------------------------------------------------------------
// VSS Signal: Vehicle.Powertrain.TractionBattery.Charging.IsDischarging
// Type      : sensor
// DataType  : boolean
// Unit      : None
//-------------------------------------------------------------------------------------
// clang-format off
namespace yoriito::vehicle::powertrain::tractionbattery::charging::isdischarging {
// clang-format on

yoriito::Result<yoriito::signal::SignalGetDataPoint<bool>> Get() {
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Entering function [Get].");
  yoriito::databroker::DataBrokerConsumer* consumer =
      yoriito::databroker::DataBrokerConsumerFactory::GetInstance();
  yoriito::databroker::ConsumerGetRequest request(
      VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_ISDISCHARGING);
  yoriito::Result<yoriito::databroker::ConsumerGetResponse> ret =
      consumer->Get(request);
  if (!ret.IsOk()) {
    std::unique_ptr<yoriito::ErrorType> err_ptr = ret.TakeErr();
    YORIITO_LOG_ERROR("SAPI_SignalAPI", err_ptr->Message());
    return yoriito::Result<yoriito::signal::SignalGetDataPoint<bool>>::Err(
        std::move(err_ptr));
  }
  auto response = ret.TakeOk().value();
  if (response.GetDataPoints().empty()) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", std::string(yoriito::ErrorType::to_msg(
                                            yoriito::ErrorCode::ERROR_NODATA)));
    return yoriito::Result<yoriito::signal::SignalGetDataPoint<bool>>::Err(
        std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_NODATA));
  }
  const auto& data_point = response.GetDataPoints().front();
  if (!std::holds_alternative<bool>(data_point.GetData())) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", "Unexpected data type");
    return yoriito::Result<yoriito::signal::SignalGetDataPoint<bool>>::Err(
        std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_BADMSG));
  }
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Exiting function [Get].");
  return yoriito::Result<yoriito::signal::SignalGetDataPoint<bool>>::Ok(
      data_point);
}

yoriito::Result<yoriito::signal::SignalSubscribeContext<bool>> Subscribe() {
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Entering function [Subscribe].");
  yoriito::databroker::DataBrokerConsumer* consumer =
      yoriito::databroker::DataBrokerConsumerFactory::GetInstance();
  yoriito::databroker::ConsumerSubscribeRequest request(
      VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_ISDISCHARGING);
  auto ret = consumer->Subscribe(request);
  if (!ret.IsOk()) {
    std::unique_ptr<yoriito::ErrorType> err_ptr = ret.TakeErr();
    YORIITO_LOG_ERROR("SAPI_SignalAPI", err_ptr->Message());
    return yoriito::Result<yoriito::signal::SignalSubscribeContext<bool>>::Err(
        std::move(err_ptr));
  }
  auto subscription_context = ret.TakeOk().value();
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Exiting function [Subscribe].");
  return yoriito::Result<yoriito::signal::SignalSubscribeContext<bool>>::Ok(
      yoriito::signal::SignalSubscribeContext<bool>(
          std::move(subscription_context)));
}

yoriito::Result<void> UnSubscribe(
    yoriito::signal::SignalSubscribeContext<bool> subscription_context) {
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

yoriito::Result<yoriito::signal::SignalInspectResponse<bool>> Inspect() {
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Entering function [Inspect].");
  yoriito::databroker::DataBrokerConsumer* consumer =
      yoriito::databroker::DataBrokerConsumerFactory::GetInstance();
  yoriito::databroker::ConsumerInspectRequest request(
      VEHICLE_POWERTRAIN_TRACTIONBATTERY_CHARGING_ISDISCHARGING);
  yoriito::Result<yoriito::databroker::ConsumerInspectResponse> ret =
      consumer->Inspect(request);
  if (!ret.IsOk()) {
    std::unique_ptr<yoriito::ErrorType> err_ptr = ret.TakeErr();
    YORIITO_LOG_ERROR("SAPI_SignalAPI", err_ptr->Message());
    return yoriito::Result<yoriito::signal::SignalInspectResponse<bool>>::Err(
        std::move(err_ptr));
  }
  auto response = ret.TakeOk();
  if (response.value().GetDataPoints().empty()) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", std::string(yoriito::ErrorType::to_msg(
                                            yoriito::ErrorCode::ERROR_NODATA)));
    return yoriito::Result<yoriito::signal::SignalInspectResponse<bool>>::Err(
        std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_NODATA));
  }
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Exiting function [Inspect].");
  return yoriito::Result<yoriito::signal::SignalInspectResponse<bool>>::Ok(
      yoriito::signal::SignalInspectResponse<bool>(
          std::move(response.value())));
}

// clang-format off
}  // namespace yoriito::vehicle::powertrain::tractionbattery::charging::isdischarging
// clang-format on
