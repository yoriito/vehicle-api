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

#ifndef COMMON_SIGNAL_SIGNAL_SUBSCRIBE_CONTEXT_H_
#define COMMON_SIGNAL_SIGNAL_SUBSCRIBE_CONTEXT_H_

#include <memory>
#include <string>
#include <type_traits>
#include <utility>

#include "error.h"
#include "result.h"
#include "yoriito_log.h"
#include "databroker/consumer_subscribe_context.h"
#include "signal/signal_get_datapoint.h"
#include "types/internal/struct_utility_traits.h"

/**
 * @ingroup common
 * @namespace yoriito::signal
 * @brief Namespace for Signal API common interfaces and types.
 */
namespace yoriito::signal {
/**
 * @ingroup signal_api
 * @class SubscribeContextAccess
 * @brief Helper class for internal access to SignalSubscribeContext.
 */
class SubscribeContextAccess;

template <typename T>
using StructUtilityOf =
  typename yoriito::types::internal::StructUtilityTraits<T>::Utility;

template <typename T, typename = void>
struct IsCustomStruct : std::false_type {};

template <typename T>
struct IsCustomStruct<T, std::void_t<StructUtilityOf<T>>> : std::true_type {};

template <typename T>
inline constexpr bool kIsCustomStruct = IsCustomStruct<T>::value;

/**
 * @ingroup signal_api
 * @class SignalSubscribeContext
 * @brief Managing signal subscription context for a Signal API.
 */
template <typename T>
class SignalSubscribeContext {
 public:
  /**
   * @ingroup signal_api
   * @fn SignalSubscribeContext::SignalSubscribeContext()
   * @brief Default constructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  SignalSubscribeContext() = default;

  /**
   * @ingroup signal_api
   * @fn SignalSubscribeContext::SignalSubscribeContext(
   * std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext> ctx)
   * @brief Constructor a SignalSubscribeContext object with a
   * ConsumerSubscribeContext.
   * @deprecated -
   * @pre -
   * @param ctx Unique pointer to a ConsumerSubscribeContext object.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit SignalSubscribeContext(
    std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext> ctx)
      : ctx_(std::move(ctx)) {}

  /**
   * @ingroup signal_api
   * @fn SignalSubscribeContext::~SignalSubscribeContext()
   * @brief Default destructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ~SignalSubscribeContext() = default;

  // Definition of ownership semantics
  SignalSubscribeContext(const SignalSubscribeContext&) = delete;
  SignalSubscribeContext& operator=(const SignalSubscribeContext&) = delete;
  SignalSubscribeContext(SignalSubscribeContext&&) = default;
  SignalSubscribeContext& operator=(SignalSubscribeContext&&) = default;

  /**
   * @ingroup signal_api
   * @fn yoriito::Result<SignalGetDataPoint<T>>
   * SignalSubscribeContext::Messages()
   * @brief Retrieve subscription messages from the Signal API.
   * @deprecated -
   * @pre -
   * @param -
   * @retval yoriito::Result<SignalGetDataPoint> Ok: DataPoint, Err: error
   * @note -
   * @code -
   * @endcode -
   */
  yoriito::Result<yoriito::signal::SignalGetDataPoint<T>> Messages() {
    YORIITO_LOG_DEBUG("SAPI_SignalAPI",
                      "Entering function [SignalSubscribeContext.Messages].");
    if (!this->ctx_) {
      YORIITO_LOG_ERROR("SAPI_SignalAPI",
                        std::string(yoriito::ErrorType::to_msg(
                          yoriito::ErrorCode::ERROR_UNSUBSCRIBE)));
      return yoriito::Result<yoriito::signal::SignalGetDataPoint<T>>::Err(
        std::make_unique<yoriito::CommonError>(
          yoriito::ErrorCode::ERROR_UNSUBSCRIBE));
    }
    auto ret = this->ctx_->Messages();
    if (!ret.IsOk()) {
      std::unique_ptr<yoriito::ErrorType> err_ptr = ret.TakeErr();
      YORIITO_LOG_ERROR("SAPI_SignalAPI", err_ptr->Message());
      return yoriito::Result<yoriito::signal::SignalGetDataPoint<T>>::Err(
        std::move(err_ptr));
    }
    auto response = ret.TakeOk().value();
    if (response.GetDataPoints().empty()) {
      YORIITO_LOG_ERROR("SAPI_SignalAPI",
                        std::string(yoriito::ErrorType::to_msg(
                          yoriito::ErrorCode::ERROR_NODATA)));
      return yoriito::Result<yoriito::signal::SignalGetDataPoint<T>>::Err(
        std::make_unique<yoriito::CommonError>(
          yoriito::ErrorCode::ERROR_NODATA));
    }
    const auto& data_point = response.GetDataPoints().front();
    if constexpr (yoriito::signal::kIsCustomStruct<T>) {
      const auto& data = data_point.GetData();
      if (!std::holds_alternative<yoriito::StructDataPtr>(data)) {
        YORIITO_LOG_ERROR("SAPI_SignalAPI", "Unexpected data type");
        return yoriito::Result<yoriito::signal::SignalGetDataPoint<T>>::Err(
          std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_UNKNOWN));
      }

      const auto& struct_data_ptr = std::get<yoriito::StructDataPtr>(data);
      if (!struct_data_ptr) {
        YORIITO_LOG_ERROR("SAPI_SignalAPI", "Data pointer is null");
        return yoriito::Result<yoriito::signal::SignalGetDataPoint<T>>::Err(
          std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_NODATA));
      }

      // Load struct data from StructData
      T result;
      if (!yoriito::types::internal::FromStructData(*struct_data_ptr, &result)) {
        YORIITO_LOG_ERROR("SAPI_SignalAPI",
                          "Failed to extract {{ custom_struct.name | lower }} "
                          "data from StructData");
        return yoriito::Result<yoriito::signal::SignalGetDataPoint<T>>::Err(
          std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_NODATA));
      }
      auto out = yoriito::signal::SignalGetDataPoint<T>(
        data_point.GetPath(), result, data_point.IsAvailableSensor(),
        data_point.IsAvailableActuator(), data_point.GetStoredTimestamp(),
        data_point.GetProducedTimestamp());
      YORIITO_LOG_DEBUG("SAPI_SignalAPI",
                        "Exiting function [SignalSubscribeContext.Messages].");
      return yoriito::Result<yoriito::signal::SignalGetDataPoint<T>>::Ok(
        yoriito::signal::SignalGetDataPoint<T>(out));
    } else {
      YORIITO_LOG_DEBUG("SAPI_SignalAPI",
                        "Exiting function [SignalSubscribeContext.Messages].");
      return yoriito::Result<yoriito::signal::SignalGetDataPoint<T>>::Ok(
        yoriito::signal::SignalGetDataPoint<T>(data_point));
    }
  }

 private:
  friend class SubscribeContextAccess;

  /**
   * @ingroup signal_api
   * @fn std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>
   * SignalSubscribeContext::Release()
   * @brief Release ownership of the underlying ConsumerSubscribeContext.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>
   * Subscription context
   * @note -
   * @code -
   * @endcode -
   */
  std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext> Release() {
    return std::move(ctx_);
  }

  std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext> ctx_;
};

class SubscribeContextAccess {
 public:
  /**
   * @ingroup signal_api
   * @fn std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>
   * SubscribeContextAccess::Release(SignalSubscribeContext<T>& ctx)
   * @brief Retrieves ownership of the internal context from a
   * ISignalSubscribeContext<T> (internal use only).
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>
   * Subscription context
   * @note -
   * @code -
   * @endcode -
   */
  template <typename T>
  static std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext> Release(
    SignalSubscribeContext<T>* ctx) {
    return ctx->Release();
  }
};

}  // namespace yoriito::signal

#endif  // COMMON_SIGNAL_SIGNAL_SUBSCRIBE_CONTEXT_H_
