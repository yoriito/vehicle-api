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

#ifndef SIGNAL_CABIN_CONVERTIBLE_SIGNAL_POSITION_H_
#define SIGNAL_CABIN_CONVERTIBLE_SIGNAL_POSITION_H_

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
 * @ingroup Cabin
 * @namespace yoriito::vehicle::cabin::convertible::position
 * @brief Indicates the Vehicle.Cabin.Convertible.Position signal.
 * @deprecated -
 * @version main
 */
// clang-format off
namespace yoriito::vehicle::cabin::convertible::position {
// clang-format on

constexpr const char* VEHICLE_CABIN_CONVERTIBLE_POSITION =
    "Vehicle.Cabin.Convertible.Position";

/**
 * @ingroup Get
 * @fn yoriito::Result<yoriito::signal::SignalGetDataPoint<uint8_t>> Get()
 * @brief Retrieves the datapoint for Vehicle.Cabin.Convertible.Position
 * @deprecated -
 * @pre Vehicle.Cabin.Convertible.Position is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalGetDataPoint<uint8_t>): The result
 * indicates success.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalGetDataPoint<uint8_t>> Get();

/**
 * @ingroup Set
 * @fn yoriito::Result<void> Set(const uint8_t& value)
 * @brief Sets the target value for Vehicle.Cabin.Convertible.Position.
 * @deprecated -
 * @pre Vehicle.Cabin.Convertible.Position is available.
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
yoriito::Result<void> Set(const uint8_t& value);

/**
 * @ingroup Subscribe
 * @fn yoriito::Result<yoriito::signal::SignalSubscribeContext<uint8_t>
 * Subscribe()
 * @brief Subscribes to changes in the datapoint for
 * Vehicle.Cabin.Convertible.Position.
 * @deprecated -
 * @pre Vehicle.Cabin.Convertible.Position is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalSubscribeContext<uint8_t>): The result
 * containing a subscription context.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalSubscribeContext<uint8_t>> Subscribe();

/**
 * @ingroup UnSubscribe
 * @fn yoriito::Result<void>
 * UnSubscribe(yoriito::signal::SignalSubscribeContext<uint8_t
 * subscription_context)
 * @brief UnSubscribes from the datapoint for
 * Vehicle.Cabin.Convertible.Position.
 * @deprecated -
 * @pre The subscription to Vehicle.Cabin.Convertible.Position has already been
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
    yoriito::signal::SignalSubscribeContext<uint8_t> subscription_context);

/**
 * @ingroup Inspect
 * @fn yoriito::Result<yoriito::signal::SignalInspecResponse<uint8_t>> Inspect()
 * @brief Retrieves the metadata for Vehicle.Cabin.Convertible.Position
 * @deprecated -
 * @pre Vehicle.Cabin.Convertible.Position is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalInspectResponse<uint8_t>): The result
 * indicates success and the inspect response.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * yoriito::Result<yoriito::signal::SignalInspectResponse<uint8_t>> ret =
 * Inspect(); yoriito::signal::SignalInspectResponse<uint8_t> metadata =
 * ret.TakeOk().value();
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalInspectResponse<uint8_t>> Inspect();

// clang-format off
}  // namespace yoriito::vehicle::cabin::convertible::position
// clang-format on
#endif  // SIGNAL_CABIN_CONVERTIBLE_SIGNAL_POSITION_H_
