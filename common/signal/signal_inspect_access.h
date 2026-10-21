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

#ifndef COMMON_SIGNAL_SIGNAL_INSPECT_ACCESS_H_
#define COMMON_SIGNAL_SIGNAL_INSPECT_ACCESS_H_

#include <utility>

#include "databroker/consumer_inspect_data.h"
#include "databroker/consumer_inspect_response.h"
#include "signal/signal_inspect_data.h"
#include "signal/signal_inspect_response.h"

/**
 * @ingroup common
 * @namespace yoriito::signal
 * @brief Namespace for Signal API common interfaces and types.
 */
namespace yoriito::signal {
/**
 * @ingroup signal_api
 * @class SignalInspectAccess
 * @brief Friend accessor that converts between public inspect types and
 *        internal DataBroker types.
 */
class SignalInspectAccess {
 public:
  /**
   * @ingroup signal_api
   * @fn static SignalInspectResponse SignalInspectAccess::Make(
   * yoriito::databroker::ConsumerInspectResponse&& response)
   * @brief Wrap an internal response into the public response type.
   * @deprecated -
   * @pre -
   * @param response Internal response. Move semantics are used.
   * @retval SignalInspectResponse Public response object.
   * @note -
   * @code -
   * @endcode -
   */
  static SignalInspectResponse Make(
      yoriito::databroker::ConsumerInspectResponse&& response) {
    return SignalInspectResponse(std::move(response));
  }

  /**
   * @ingroup signal_api
   * @fn static SignalInspectData SignalInspectAccess::MakeData(
   * const yoriito::databroker::ConsumerInspectData& data)
   * @brief Wrap an internal inspect data object into the public view type.
   * @deprecated -
   * @pre -
   * @param data Internal inspect data.
   * @retval SignalInspectData Public view object.
   * @note -
   * @code -
   * @endcode -
   */
  static SignalInspectData MakeData(
      const yoriito::databroker::ConsumerInspectData& data) {
    return SignalInspectData(data);
  }

  /**
   * @ingroup signal_api
   * @fn static const yoriito::databroker::ConsumerInspectData&
   * SignalInspectAccess::Unwrap(const SignalInspectData& data)
   * @brief Retrieve the internal object behind a public view.
   * @deprecated -
   * @pre -
   * @param data Public view object.
   * @retval const yoriito::databroker::ConsumerInspectData& Internal inspect
   *         data.
   * @note -
   * @code -
   * @endcode -
   */
  static const yoriito::databroker::ConsumerInspectData& Unwrap(
      const SignalInspectData& data) {
    return *data.impl_;
  }
};

}  // namespace yoriito::signal

#endif  // COMMON_SIGNAL_SIGNAL_INSPECT_ACCESS_H_
