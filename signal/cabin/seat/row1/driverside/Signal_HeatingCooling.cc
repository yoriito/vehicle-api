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

#include "Signal_HeatingCooling.h"

//-------------------------------------------------------------------------------------
// VSS Signal: Vehicle.Cabin.Seat.Row1.DriverSide.HeatingCooling
// Type      : actuator
// DataType  : int8
// Unit      : percent
//-------------------------------------------------------------------------------------
// clang-format off
namespace yoriito::vehicle::cabin::seat::row1::driverside::heatingcooling {
// clang-format on

yoriito::Result<yoriito::signal::SignalGetDataPoint<int8_t>> Get() {
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Entering function [Get].");
  yoriito::databroker::DataBrokerConsumer* consumer =
      yoriito::databroker::DataBrokerConsumerFactory::GetInstance();
  yoriito::databroker::ConsumerGetRequest request(
      VEHICLE_CABIN_SEAT_ROW1_DRIVERSIDE_HEATINGCOOLING);
  yoriito::Result<yoriito::databroker::ConsumerGetResponse> ret =
      consumer->Get(request);
  if (!ret.IsOk()) {
    std::unique_ptr<yoriito::ErrorType> err_ptr = ret.TakeErr();
    YORIITO_LOG_ERROR("SAPI_SignalAPI", err_ptr->Message());
    return yoriito::Result<yoriito::signal::SignalGetDataPoint<int8_t>>::Err(
        std::move(err_ptr));
  }
  auto response = ret.TakeOk().value();
  if (response.GetDataPoints().empty()) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", std::string(yoriito::ErrorType::to_msg(
                                            yoriito::ErrorCode::ERROR_NODATA)));
    return yoriito::Result<yoriito::signal::SignalGetDataPoint<int8_t>>::Err(
        std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_NODATA));
  }
  const auto& data_point = response.GetDataPoints().front();
  if (!std::holds_alternative<int8_t>(data_point.GetData())) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", "Unexpected data type");
    return yoriito::Result<yoriito::signal::SignalGetDataPoint<int8_t>>::Err(
        std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_BADMSG));
  }
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Exiting function [Get].");
  return yoriito::Result<yoriito::signal::SignalGetDataPoint<int8_t>>::Ok(
      data_point);
}

yoriito::Result<void> Set(const int8_t& value) {
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Entering function [Set].");

  yoriito::databroker::DataBrokerConsumer* consumer =
      yoriito::databroker::DataBrokerConsumerFactory::GetInstance();
  yoriito::databroker::ConsumerInspectRequest inspect_request(
      VEHICLE_CABIN_SEAT_ROW1_DRIVERSIDE_HEATINGCOOLING);
  yoriito::Result<yoriito::databroker::ConsumerInspectResponse> inspect_ret =
      consumer->Inspect(inspect_request);
  if (!inspect_ret.IsOk()) {
    std::unique_ptr<yoriito::ErrorType> err_ptr = inspect_ret.TakeErr();
    YORIITO_LOG_ERROR("SAPI_SignalAPI", err_ptr->Message());
    return yoriito::Result<void>::Err(std::move(err_ptr));
  }
  auto inspect_response = inspect_ret.TakeOk().value();
  if (inspect_response.GetDataPoints().empty()) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", std::string(yoriito::ErrorType::to_msg(
                                            yoriito::ErrorCode::ERROR_NODATA)));
    return yoriito::Result<void>::Err(std::make_unique<yoriito::CommonError>(
        yoriito::ErrorCode::ERROR_NODATA));
  }
  const auto& inspect_data = inspect_response.GetDataPoints().front();
  const auto& min_data = inspect_data.GetMin();
  if (!std::holds_alternative<int8_t>(min_data)) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", "Unexpected data type");
    return yoriito::Result<void>::Err(std::make_unique<yoriito::CommonError>(
        yoriito::ErrorCode::ERROR_BADMSG));
  }
  const auto& min_value = std::get<int8_t>(min_data);
  if (value < min_value) {
    std::string err_msg = std::string(yoriito::ErrorType::to_msg(
                              yoriito::ErrorCode::ERROR_INVAL)) +
                          std::to_string(static_cast<int32_t>(value));
    YORIITO_LOG_ERROR("SAPI_SignalAPI", err_msg);
    return yoriito::Result<void>::Err(std::make_unique<yoriito::CommonError>(
        yoriito::ErrorCode::ERROR_INVAL, err_msg));
  }
  const auto& max_data = inspect_data.GetMax();
  if (!std::holds_alternative<int8_t>(max_data)) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", "Unexpected data type");
    return yoriito::Result<void>::Err(std::make_unique<yoriito::CommonError>(
        yoriito::ErrorCode::ERROR_BADMSG));
  }
  const auto& max_value = std::get<int8_t>(max_data);
  if (value > max_value) {
    std::string err_msg = std::string(yoriito::ErrorType::to_msg(
                              yoriito::ErrorCode::ERROR_INVAL)) +
                          std::to_string(static_cast<int32_t>(value));
    YORIITO_LOG_ERROR("SAPI_SignalAPI", err_msg);
    return yoriito::Result<void>::Err(std::make_unique<yoriito::CommonError>(
        yoriito::ErrorCode::ERROR_INVAL, err_msg));
  }

  yoriito::databroker::ConsumerSetRequest set_request(
      std::vector<yoriito::databroker::ConsumerSetDataPoint>{
          yoriito::databroker::ConsumerSetDataPoint(
              VEHICLE_CABIN_SEAT_ROW1_DRIVERSIDE_HEATINGCOOLING, value)});
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Exiting function [Set].");
  return consumer->Set(set_request);
}

yoriito::Result<yoriito::signal::SignalSubscribeContext<int8_t>> Subscribe() {
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Entering function [Subscribe].");
  yoriito::databroker::DataBrokerConsumer* consumer =
      yoriito::databroker::DataBrokerConsumerFactory::GetInstance();
  yoriito::databroker::ConsumerSubscribeRequest request(
      VEHICLE_CABIN_SEAT_ROW1_DRIVERSIDE_HEATINGCOOLING);
  auto ret = consumer->Subscribe(request);
  if (!ret.IsOk()) {
    std::unique_ptr<yoriito::ErrorType> err_ptr = ret.TakeErr();
    YORIITO_LOG_ERROR("SAPI_SignalAPI", err_ptr->Message());
    return yoriito::Result<yoriito::signal::SignalSubscribeContext<int8_t>>::
        Err(std::move(err_ptr));
  }
  auto subscription_context = ret.TakeOk().value();
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Exiting function [Subscribe].");
  return yoriito::Result<yoriito::signal::SignalSubscribeContext<int8_t>>::Ok(
      yoriito::signal::SignalSubscribeContext<int8_t>(
          std::move(subscription_context)));
}

yoriito::Result<void> UnSubscribe(
    yoriito::signal::SignalSubscribeContext<int8_t> subscription_context) {
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

yoriito::Result<yoriito::signal::SignalInspectResponse<int8_t>> Inspect() {
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Entering function [Inspect].");
  yoriito::databroker::DataBrokerConsumer* consumer =
      yoriito::databroker::DataBrokerConsumerFactory::GetInstance();
  yoriito::databroker::ConsumerInspectRequest request(
      VEHICLE_CABIN_SEAT_ROW1_DRIVERSIDE_HEATINGCOOLING);
  yoriito::Result<yoriito::databroker::ConsumerInspectResponse> ret =
      consumer->Inspect(request);
  if (!ret.IsOk()) {
    std::unique_ptr<yoriito::ErrorType> err_ptr = ret.TakeErr();
    YORIITO_LOG_ERROR("SAPI_SignalAPI", err_ptr->Message());
    return yoriito::Result<yoriito::signal::SignalInspectResponse<int8_t>>::Err(
        std::move(err_ptr));
  }
  auto response = ret.TakeOk();
  if (response.value().GetDataPoints().empty()) {
    YORIITO_LOG_ERROR("SAPI_SignalAPI", std::string(yoriito::ErrorType::to_msg(
                                            yoriito::ErrorCode::ERROR_NODATA)));
    return yoriito::Result<yoriito::signal::SignalInspectResponse<int8_t>>::Err(
        std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_NODATA));
  }
  YORIITO_LOG_DEBUG("SAPI_SignalAPI", "Exiting function [Inspect].");
  return yoriito::Result<yoriito::signal::SignalInspectResponse<int8_t>>::Ok(
      yoriito::signal::SignalInspectResponse<int8_t>(
          std::move(response.value())));
}

// clang-format off
}  // namespace yoriito::vehicle::cabin::seat::row1::driverside::heatingcooling
// clang-format on
