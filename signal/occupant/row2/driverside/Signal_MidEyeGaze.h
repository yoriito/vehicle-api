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

#ifndef SIGNAL_OCCUPANT_ROW2_DRIVERSIDE_SIGNAL_MIDEYEGAZE_H_
#define SIGNAL_OCCUPANT_ROW2_DRIVERSIDE_SIGNAL_MIDEYEGAZE_H_

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
#include "types/Struct_PointingDirection.h"
#include "types/internal/struct_utility_traits.h"
#include "yoriito_log.h"

/**
 * @ingroup Occupant
 * @namespace yoriito::vehicle::occupant::row2::driverside::mideyegaze {
 * @brief Indicates the Vehicle.Occupant.Row2.DriverSide.MidEyeGaze signal.
 * @deprecated -
 * @version main
 */
// clang-format off
namespace yoriito::vehicle::occupant::row2::driverside::mideyegaze {
// clang-format on

constexpr const char* VEHICLE_OCCUPANT_ROW2_DRIVERSIDE_MIDEYEGAZE =
    "Vehicle.Occupant.Row2.DriverSide.MidEyeGaze";

using PointingDirection = yoriito::types::PointingDirection;

/**
 * @ingroup Get
 * @fn yoriito::Result<yoriito::signal::SignalGetDataPoint<PointingDirection>>
 * Get()
 * @brief Retrieves the datapoint for
 * Vehicle.Occupant.Row2.DriverSide.MidEyeGaze
 * @deprecated -
 * @pre Vehicle.Occupant.Row2.DriverSide.MidEyeGaze is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalGetDataPoint<PointingDirection>): The
 * result indicates success.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalGetDataPoint<PointingDirection>> Get();

/**
 * @ingroup Subscribe
 * @fn
 * yoriito::Result<yoriito::signal::SignalSubscribeContext<PointingDirection>
 * Subscribe()
 * @brief Subscribes to changes in the datapoint for
 * Vehicle.Occupant.Row2.DriverSide.MidEyeGaze.
 * @deprecated -
 * @pre Vehicle.Occupant.Row2.DriverSide.MidEyeGaze is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalSubscribeContext<PointingDirection>): The
 * result containing a subscription context.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalSubscribeContext<PointingDirection>>
Subscribe();

/**
 * @ingroup UnSubscribe
 * @fn yoriito::Result<void>
 * UnSubscribe(yoriito::signal::SignalSubscribeContext<PointingDirection
 * subscription_context)
 * @brief UnSubscribes from the datapoint for
 * Vehicle.Occupant.Row2.DriverSide.MidEyeGaze.
 * @deprecated -
 * @pre The subscription to Vehicle.Occupant.Row2.DriverSide.MidEyeGaze has
 * already been called.
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
    yoriito::signal::SignalSubscribeContext<PointingDirection>
        subscription_context);

/**
 * @ingroup Inspect
 * @fn yoriito::Result<yoriito::signal::SignalInspecResponse<PointingDirection>>
 * Inspect()
 * @brief Retrieves the metadata for Vehicle.Occupant.Row2.DriverSide.MidEyeGaze
 * @deprecated -
 * @pre Vehicle.Occupant.Row2.DriverSide.MidEyeGaze is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalInspectResponse<PointingDirection>): The
 * result indicates success and the inspect response.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * yoriito::Result<yoriito::signal::SignalInspectResponse<PointingDirection>>
 * ret = Inspect(); yoriito::signal::SignalInspectResponse<PointingDirection>
 * metadata = ret.TakeOk().value();
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalInspectResponse<PointingDirection>>
Inspect();

// clang-format off
}  // namespace yoriito::vehicle::occupant::row2::driverside::mideyegaze
// clang-format on

#endif  // SIGNAL_OCCUPANT_ROW2_DRIVERSIDE_SIGNAL_MIDEYEGAZE_H_
