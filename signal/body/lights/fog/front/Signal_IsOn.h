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

#ifndef SIGNAL_BODY_LIGHTS_FOG_FRONT_SIGNAL_ISON_H_
#define SIGNAL_BODY_LIGHTS_FOG_FRONT_SIGNAL_ISON_H_

#include <cstdint>
#include <memory>
#include <string>
#include <variant>

#include "databroker/databroker_consumer.h"
#include "databroker/databroker_consumer_factory.h"
#include "error.h"
#include "result.h"
#include "signal/signal_get_datapoint.h"
#include "signal/signal_inspect_data.h"
#include "signal/signal_inspect_response.h"
#include "signal/signal_subscribe_context.h"
#include "yoriito_log.h"

/**
 * @ingroup Body
 * @namespace yoriito::vehicle::body::lights::fog::front::ison
 * @brief Indicates the Vehicle.Body.Lights.Fog.Front.IsOn signal.
 * @deprecated -
 * @version main
 */
// clang-format off
namespace yoriito::vehicle::body::lights::fog::front::ison {
// clang-format on

constexpr const char* VEHICLE_BODY_LIGHTS_FOG_FRONT_ISON =
    "Vehicle.Body.Lights.Fog.Front.IsOn";

/**
 * @ingroup Get
 * @fn yoriito::Result<yoriito::signal::SignalGetDataPoint<bool>> Get()
 * @brief Retrieves the datapoint for Vehicle.Body.Lights.Fog.Front.IsOn
 * @deprecated -
 * @pre Vehicle.Body.Lights.Fog.Front.IsOn is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalGetDataPoint<bool>): The result indicates
 * success.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalGetDataPoint<bool>> Get();

/**
 * @ingroup Set
 * @fn yoriito::Result<void> Set(const bool& value)
 * @brief Sets the target value for Vehicle.Body.Lights.Fog.Front.IsOn.
 * @deprecated -
 * @pre Vehicle.Body.Lights.Fog.Front.IsOn is available.
 * @param value: The value to set.
 * @retval Ok(): The result indicates success.
 * @retval Err(ParameterError): The result indicates a parameter error.
 * @retval Err(InvalidValueError): The result indicates an invalid value.
 * @retval Err(NotAvailableError): The result indicates an unavailable value.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe. Last-come, first-served.
 * @code
 * -
 * @endcode
 */
yoriito::Result<void> Set(const bool& value);

/**
 * @ingroup Subscribe
 * @fn yoriito::Result<yoriito::signal::SignalSubscribeContext<bool> Subscribe()
 * @brief Subscribes to changes in the datapoint for
 * Vehicle.Body.Lights.Fog.Front.IsOn.
 * @deprecated -
 * @pre Vehicle.Body.Lights.Fog.Front.IsOn is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalSubscribeContext<bool>): The result
 * containing a subscription context.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalSubscribeContext<bool>> Subscribe();

/**
 * @ingroup UnSubscribe
 * @fn yoriito::Result<void>
 * UnSubscribe(yoriito::signal::SignalSubscribeContext<bool
 * subscription_context)
 * @brief UnSubscribes from the datapoint for
 * Vehicle.Body.Lights.Fog.Front.IsOn.
 * @deprecated -
 * @pre The subscription to Vehicle.Body.Lights.Fog.Front.IsOn has already been
 * called.
 * @param -
 * @retval Ok(): The result indicates success.
 * @retval Err(NotSubscribeError): The result indicates that it has not been
 * subscribed.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<void> UnSubscribe(
    yoriito::signal::SignalSubscribeContext<bool> subscription_context);

/**
 * @ingroup Inspect
 * @fn yoriito::Result<yoriito::signal::SignalInspecResponse<bool>> Inspect()
 * @brief Retrieves the metadata for Vehicle.Body.Lights.Fog.Front.IsOn
 * @deprecated -
 * @pre Vehicle.Body.Lights.Fog.Front.IsOn is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalInspectResponse<bool>): The result
 * indicates success and the inspect response.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * yoriito::Result<yoriito::signal::SignalInspectResponse<bool>> ret =
 * Inspect(); yoriito::signal::SignalInspectResponse<bool> metadata =
 * ret.TakeOk().value();
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalInspectResponse<bool>> Inspect();

// clang-format off
}  // namespace yoriito::vehicle::body::lights::fog::front::ison
// clang-format on
#endif  // SIGNAL_BODY_LIGHTS_FOG_FRONT_SIGNAL_ISON_H_
