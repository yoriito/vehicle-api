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

#ifndef SIGNAL_CURRENTLOCATION_GNSSRECEIVER_SIGNAL_GNSSLOCATIONTYPE_H_
#define SIGNAL_CURRENTLOCATION_GNSSRECEIVER_SIGNAL_GNSSLOCATIONTYPE_H_

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
#include "types/Struct_GNSSLocation.h"
#include "types/internal/struct_utility_traits.h"
#include "yoriito_log.h"

/**
 * @ingroup CurrentLocation
 * @namespace yoriito::vehicle::currentlocation::gnssreceiver::gnsslocationtype
 * {
 * @brief Indicates the Vehicle.CurrentLocation.GNSSReceiver.GNSSLocationType
 * signal.
 * @deprecated -
 * @version main
 */
// clang-format off
namespace yoriito::vehicle::currentlocation::gnssreceiver::gnsslocationtype {
// clang-format on

constexpr const char* VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE =
    "Vehicle.CurrentLocation.GNSSReceiver.GNSSLocationType";

using GNSSLocation = yoriito::types::GNSSLocation;

/**
 * @ingroup Get
 * @fn yoriito::Result<yoriito::signal::SignalGetDataPoint<GNSSLocation>> Get()
 * @brief Retrieves the datapoint for
 * Vehicle.CurrentLocation.GNSSReceiver.GNSSLocationType
 * @deprecated -
 * @pre Vehicle.CurrentLocation.GNSSReceiver.GNSSLocationType is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalGetDataPoint<GNSSLocation>): The result
 * indicates success.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalGetDataPoint<GNSSLocation>> Get();

/**
 * @ingroup Subscribe
 * @fn yoriito::Result<yoriito::signal::SignalSubscribeContext<GNSSLocation>
 * Subscribe()
 * @brief Subscribes to changes in the datapoint for
 * Vehicle.CurrentLocation.GNSSReceiver.GNSSLocationType.
 * @deprecated -
 * @pre Vehicle.CurrentLocation.GNSSReceiver.GNSSLocationType is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalSubscribeContext<GNSSLocation>): The result
 * containing a subscription context.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalSubscribeContext<GNSSLocation>>
Subscribe();

/**
 * @ingroup UnSubscribe
 * @fn yoriito::Result<void>
 * UnSubscribe(yoriito::signal::SignalSubscribeContext<GNSSLocation
 * subscription_context)
 * @brief UnSubscribes from the datapoint for
 * Vehicle.CurrentLocation.GNSSReceiver.GNSSLocationType.
 * @deprecated -
 * @pre The subscription to
 * Vehicle.CurrentLocation.GNSSReceiver.GNSSLocationType has already been
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
    yoriito::signal::SignalSubscribeContext<GNSSLocation> subscription_context);

/**
 * @ingroup Inspect
 * @fn yoriito::Result<yoriito::signal::SignalInspecResponse<GNSSLocation>>
 * Inspect()
 * @brief Retrieves the metadata for
 * Vehicle.CurrentLocation.GNSSReceiver.GNSSLocationType
 * @deprecated -
 * @pre Vehicle.CurrentLocation.GNSSReceiver.GNSSLocationType is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalInspectResponse<GNSSLocation>): The result
 * indicates success and the inspect response.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * yoriito::Result<yoriito::signal::SignalInspectResponse<GNSSLocation>> ret =
 * Inspect(); yoriito::signal::SignalInspectResponse<GNSSLocation> metadata =
 * ret.TakeOk().value();
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalInspectResponse<GNSSLocation>> Inspect();

// clang-format off
}  // namespace yoriito::vehicle::currentlocation::gnssreceiver::gnsslocationtype
// clang-format on

#endif  // SIGNAL_CURRENTLOCATION_GNSSRECEIVER_SIGNAL_GNSSLOCATIONTYPE_H_
