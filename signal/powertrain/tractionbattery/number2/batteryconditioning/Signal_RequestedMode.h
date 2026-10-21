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

#ifndef SIGNAL_POWERTRAIN_TRACTIONBATTERY_NUMBER2_BATTERYCONDITIONING_SIGNAL_REQUESTEDMODE_H_
#define SIGNAL_POWERTRAIN_TRACTIONBATTERY_NUMBER2_BATTERYCONDITIONING_SIGNAL_REQUESTEDMODE_H_

#include <algorithm>
#include <cstdint>
#include <memory>
#include <set>
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
 * @ingroup Powertrain
 * @namespace
 * yoriito::vehicle::powertrain::tractionbattery::number2::batteryconditioning::requestedmode
 * @brief Indicates the
 * Vehicle.Powertrain.TractionBattery.Number2.BatteryConditioning.RequestedMode
 * signal.
 * @deprecated -
 * @version main
 */
// clang-format off
namespace yoriito::vehicle::powertrain::tractionbattery::number2::batteryconditioning::requestedmode {
// clang-format on

constexpr const char*
    VEHICLE_POWERTRAIN_TRACTIONBATTERY_NUMBER2_BATTERYCONDITIONING_REQUESTEDMODE =
        "Vehicle.Powertrain.TractionBattery.Number2.BatteryConditioning.RequestedMode";

/**
 * @ingroup Get
 * @fn yoriito::Result<yoriito::signal::SignalGetDataPoint<std::string>> Get()
 * @brief Retrieves the datapoint for
 * Vehicle.Powertrain.TractionBattery.Number2.BatteryConditioning.RequestedMode
 * @deprecated -
 * @pre
 * Vehicle.Powertrain.TractionBattery.Number2.BatteryConditioning.RequestedMode
 * is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalGetDataPoint<std::string>): The result
 * indicates success.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalGetDataPoint<std::string>> Get();

/**
 * @ingroup Set
 * @fn yoriito::Result<void> Set(const std::string& value)
 * @brief Sets the target value for
 * Vehicle.Powertrain.TractionBattery.Number2.BatteryConditioning.RequestedMode.
 * @deprecated -
 * @pre
 * Vehicle.Powertrain.TractionBattery.Number2.BatteryConditioning.RequestedMode
 * is available.
 * @param value: The value to set. ['INACTIVE', 'FAST_CHARGING_PREPARATION',
 * 'DRIVING_PREPARATION']
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
yoriito::Result<void> Set(const std::string& value);

/**
 * @ingroup Subscribe
 * @fn yoriito::Result<yoriito::signal::SignalSubscribeContext<std::string>
 * Subscribe()
 * @brief Subscribes to changes in the datapoint for
 * Vehicle.Powertrain.TractionBattery.Number2.BatteryConditioning.RequestedMode.
 * @deprecated -
 * @pre
 * Vehicle.Powertrain.TractionBattery.Number2.BatteryConditioning.RequestedMode
 * is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalSubscribeContext<std::string>): The result
 * containing a subscription context.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalSubscribeContext<std::string>>
Subscribe();

/**
 * @ingroup UnSubscribe
 * @fn yoriito::Result<void>
 * UnSubscribe(yoriito::signal::SignalSubscribeContext<std::string
 * subscription_context)
 * @brief UnSubscribes from the datapoint for
 * Vehicle.Powertrain.TractionBattery.Number2.BatteryConditioning.RequestedMode.
 * @deprecated -
 * @pre The subscription to
 * Vehicle.Powertrain.TractionBattery.Number2.BatteryConditioning.RequestedMode
 * has already been called.
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
    yoriito::signal::SignalSubscribeContext<std::string> subscription_context);

/**
 * @ingroup Inspect
 * @fn yoriito::Result<yoriito::signal::SignalInspecResponse<std::string>>
 * Inspect()
 * @brief Retrieves the metadata for
 * Vehicle.Powertrain.TractionBattery.Number2.BatteryConditioning.RequestedMode
 * @deprecated -
 * @pre
 * Vehicle.Powertrain.TractionBattery.Number2.BatteryConditioning.RequestedMode
 * is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalInspectResponse<std::string>): The result
 * indicates success and the inspect response.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * yoriito::Result<yoriito::signal::SignalInspectResponse<std::string>> ret =
 * Inspect(); yoriito::signal::SignalInspectResponse<std::string> metadata =
 * ret.TakeOk().value();
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalInspectResponse<std::string>> Inspect();

// clang-format off
}  // namespace yoriito::vehicle::powertrain::tractionbattery::number2::batteryconditioning::requestedmode
// clang-format on
#endif  // SIGNAL_POWERTRAIN_TRACTIONBATTERY_NUMBER2_BATTERYCONDITIONING_SIGNAL_REQUESTEDMODE_H_
