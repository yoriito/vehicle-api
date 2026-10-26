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

#ifndef COMMON_SIGNAL_SIGNAL_INSPECT_RESPONSE_H_
#define COMMON_SIGNAL_SIGNAL_INSPECT_RESPONSE_H_

#include <memory>
#include <utility>
#include <vector>

#include "databroker/consumer_inspect_response.h"
#include "signal/signal_inspect_data.h"

/**
 * @ingroup common
 * @namespace yoriito::signal
 * @brief Namespace for Signal API common interfaces and types.
 */
namespace yoriito::signal {
/**
 * @ingroup signal_api
 * @class SignalInspectResponse
 * @brief Public response object returned by the inspect API.
 */
template <typename T>
class SignalInspectResponse {
 public:
  /**
   * @ingroup signal_api
   * @fn SignalInspectResponse::SignalInspectResponse()
   * @brief Deleted default constructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  SignalInspectResponse() = delete;

  /**
   * @ingroup signal_api
   * @fn explicit
   * SignalInspectResponse::SignalInspectResponse(yoriito::databroker::ConsumerInspectResponse
   * response)
   * @brief Constructs a SignalInspectResponse instance.
   * @deprecated -
   * @pre -
   * @param response SignalInspectResponse object.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit SignalInspectResponse(
      yoriito::databroker::ConsumerInspectResponse response)
      : response_(std::move(response)) {}

  /**
   * @ingroup signal_api
   * @brief Copy operations are disabled.
   */
  SignalInspectResponse(const SignalInspectResponse&) = delete;
  SignalInspectResponse& operator=(const SignalInspectResponse&) = delete;

  /**
   * @ingroup signal_api
   * @brief Move operations.
   */
  SignalInspectResponse(SignalInspectResponse&&) noexcept = default;
  SignalInspectResponse& operator=(SignalInspectResponse&&) noexcept = default;

  /**
   * @ingroup signal_api
   * @brief Destroys the SignalInspectResponse instance.
   */
  ~SignalInspectResponse() = default;

  /**
   * @ingroup signal_api
   * @fn const std::vector<SignalInspectData<T>>
   * SignalInspectResponse::GetDataPoints() const
   * @brief Get the inspected datapoints.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::vector<SignalInspectData<T>> Datapoint metadata list.
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<SignalInspectData<T>> GetDataPoints() const {
    std::vector<SignalInspectData<T>> result;
    result.reserve(response_.GetDataPoints().size());
    for (const auto& data : response_.GetDataPoints()) {
      result.emplace_back(data);
    }
    return result;
  }

  /**
   * @ingroup signal_api
   * @fn const std::vector<SignalStructType>
   * SignalInspectResponse::GetStructTypes() const
   * @brief Get the struct type definitions referenced by the datapoints.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::vector<SignalStructType> Struct type definitions.
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<SignalStructType> GetStructTypes() const {
    std::vector<SignalStructType> result;
    result.reserve(response_.GetStructTypes().size());
    for (const auto& struct_type : response_.GetStructTypes()) {
      result.emplace_back(struct_type);
    }
    return result;
  }

 private:
  yoriito::databroker::ConsumerInspectResponse response_;
};

}  // namespace yoriito::signal

#endif  // COMMON_SIGNAL_SIGNAL_INSPECT_RESPONSE_H_
