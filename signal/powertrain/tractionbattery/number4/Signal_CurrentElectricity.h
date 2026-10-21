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

#ifndef SIGNAL_POWERTRAIN_TRACTIONBATTERY_NUMBER4_SIGNAL_CURRENTELECTRICITY_H_
#define SIGNAL_POWERTRAIN_TRACTIONBATTERY_NUMBER4_SIGNAL_CURRENTELECTRICITY_H_

#include <cstdint>
#include <memory>
#include <variant>

#include "databroker/databroker_consumer.h"
#include "databroker/databroker_consumer_factory.h"
#include "error.h"
#include "result.h"
#include "signal/signal_get_datapoint.h"
#include "signal/signal_inspect_data.h"
#include "signal/signal_inspect_response.h"
#include "signal/signal_subscribe_context.h"
#include "types/Struct_Electricity.h"
#include "types/internal/struct_utility_traits.h"
#include "yoriito_log.h"

/**
 * @ingroup Powertrain
 * @namespace
 * yoriito::vehicle::powertrain::tractionbattery::number4::currentelectricity {
 * @brief Indicates the
 * Vehicle.Powertrain.TractionBattery.Number4.CurrentElectricity signal.
 * @deprecated -
 * @version main
 */
// clang-format off
namespace yoriito::vehicle::powertrain::tractionbattery::number4::currentelectricity {
// clang-format on

constexpr const char*
    VEHICLE_POWERTRAIN_TRACTIONBATTERY_NUMBER4_CURRENTELECTRICITY =
        "Vehicle.Powertrain.TractionBattery.Number4.CurrentElectricity";

using Electricity = yoriito::types::Electricity;

/**
 * @ingroup Get
 * @fn yoriito::Result<yoriito::signal::SignalGetDataPoint<Electricity>> Get()
 * @brief Retrieves the datapoint for
 * Vehicle.Powertrain.TractionBattery.Number4.CurrentElectricity
 * @deprecated -
 * @pre Vehicle.Powertrain.TractionBattery.Number4.CurrentElectricity is
 * capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalGetDataPoint<Electricity>): The result
 * indicates success.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalGetDataPoint<Electricity>> Get();

/**
 * @ingroup Subscribe
 * @fn yoriito::Result<yoriito::signal::SignalSubscribeContext<Electricity>
 * Subscribe()
 * @brief Subscribes to changes in the datapoint for
 * Vehicle.Powertrain.TractionBattery.Number4.CurrentElectricity.
 * @deprecated -
 * @pre Vehicle.Powertrain.TractionBattery.Number4.CurrentElectricity is
 * capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalSubscribeContext<Electricity>): The result
 * containing a subscription context.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalSubscribeContext<Electricity>>
Subscribe();

/**
 * @ingroup UnSubscribe
 * @fn yoriito::Result<void>
 * UnSubscribe(yoriito::signal::SignalSubscribeContext<Electricity
 * subscription_context)
 * @brief UnSubscribes from the datapoint for
 * Vehicle.Powertrain.TractionBattery.Number4.CurrentElectricity.
 * @deprecated -
 * @pre The subscription to
 * Vehicle.Powertrain.TractionBattery.Number4.CurrentElectricity has already
 * been called.
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
    yoriito::signal::SignalSubscribeContext<Electricity> subscription_context);

/**
 * @ingroup Inspect
 * @fn yoriito::Result<yoriito::signal::SignalInspecResponse<Electricity>>
 * Inspect()
 * @brief Retrieves the metadata for
 * Vehicle.Powertrain.TractionBattery.Number4.CurrentElectricity
 * @deprecated -
 * @pre Vehicle.Powertrain.TractionBattery.Number4.CurrentElectricity is
 * capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalInspectResponse<Electricity>): The result
 * indicates success and the inspect response.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * yoriito::Result<yoriito::signal::SignalInspectResponse<Electricity>> ret =
 * Inspect(); yoriito::signal::SignalInspectResponse<Electricity> metadata =
 * ret.TakeOk().value();
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalInspectResponse<Electricity>> Inspect();

// clang-format off
}  // namespace yoriito::vehicle::powertrain::tractionbattery::number4::currentelectricity
// clang-format on

#endif  // SIGNAL_POWERTRAIN_TRACTIONBATTERY_NUMBER4_SIGNAL_CURRENTELECTRICITY_H_
