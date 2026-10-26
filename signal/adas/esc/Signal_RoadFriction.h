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

#ifndef SIGNAL_ADAS_ESC_SIGNAL_ROADFRICTION_H_
#define SIGNAL_ADAS_ESC_SIGNAL_ROADFRICTION_H_

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
#include "types/Struct_RoadFrictionRange.h"
#include "types/internal/struct_utility_traits.h"
#include "yoriito_log.h"

/**
 * @ingroup ADAS
 * @namespace yoriito::vehicle::adas::esc::roadfriction {
 * @brief Indicates the Vehicle.ADAS.ESC.RoadFriction signal.
 * @deprecated -
 * @version main
 */
// clang-format off
namespace yoriito::vehicle::adas::esc::roadfriction {
// clang-format on

constexpr const char* VEHICLE_ADAS_ESC_ROADFRICTION =
    "Vehicle.ADAS.ESC.RoadFriction";

using RoadFrictionRange = yoriito::types::RoadFrictionRange;

/**
 * @ingroup Get
 * @fn yoriito::Result<yoriito::signal::SignalGetDataPoint<RoadFrictionRange>>
 * Get()
 * @brief Retrieves the datapoint for Vehicle.ADAS.ESC.RoadFriction
 * @deprecated -
 * @pre Vehicle.ADAS.ESC.RoadFriction is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalGetDataPoint<RoadFrictionRange>): The
 * result indicates success.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalGetDataPoint<RoadFrictionRange>> Get();

/**
 * @ingroup Subscribe
 * @fn
 * yoriito::Result<yoriito::signal::SignalSubscribeContext<RoadFrictionRange>
 * Subscribe()
 * @brief Subscribes to changes in the datapoint for
 * Vehicle.ADAS.ESC.RoadFriction.
 * @deprecated -
 * @pre Vehicle.ADAS.ESC.RoadFriction is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalSubscribeContext<RoadFrictionRange>): The
 * result containing a subscription context.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalSubscribeContext<RoadFrictionRange>>
Subscribe();

/**
 * @ingroup UnSubscribe
 * @fn yoriito::Result<void>
 * UnSubscribe(yoriito::signal::SignalSubscribeContext<RoadFrictionRange
 * subscription_context)
 * @brief UnSubscribes from the datapoint for Vehicle.ADAS.ESC.RoadFriction.
 * @deprecated -
 * @pre The subscription to Vehicle.ADAS.ESC.RoadFriction has already been
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
    yoriito::signal::SignalSubscribeContext<RoadFrictionRange>
        subscription_context);

/**
 * @ingroup Inspect
 * @fn yoriito::Result<yoriito::signal::SignalInspecResponse<RoadFrictionRange>>
 * Inspect()
 * @brief Retrieves the metadata for Vehicle.ADAS.ESC.RoadFriction
 * @deprecated -
 * @pre Vehicle.ADAS.ESC.RoadFriction is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalInspectResponse<RoadFrictionRange>): The
 * result indicates success and the inspect response.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * yoriito::Result<yoriito::signal::SignalInspectResponse<RoadFrictionRange>>
 * ret = Inspect(); yoriito::signal::SignalInspectResponse<RoadFrictionRange>
 * metadata = ret.TakeOk().value();
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalInspectResponse<RoadFrictionRange>>
Inspect();

// clang-format off
}  // namespace yoriito::vehicle::adas::esc::roadfriction
// clang-format on

#endif  // SIGNAL_ADAS_ESC_SIGNAL_ROADFRICTION_H_
