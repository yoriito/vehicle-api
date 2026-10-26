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

#ifndef SIGNAL_CHASSIS_AXLE_ROW1_WHEEL_LEFT_TIRE_SIGNAL_RUBBERTEMPERATURE_H_
#define SIGNAL_CHASSIS_AXLE_ROW1_WHEEL_LEFT_TIRE_SIGNAL_RUBBERTEMPERATURE_H_

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
#include "yoriito_log.h"

/**
 * @ingroup Chassis
 * @namespace
 * yoriito::vehicle::chassis::axle::row1::wheel::left::tire::rubbertemperature {
 * @brief Indicates the
 * Vehicle.Chassis.Axle.Row1.Wheel.Left.Tire.RubberTemperature signal.
 * @deprecated -
 * @version main
 */
// clang-format off
namespace yoriito::vehicle::chassis::axle::row1::wheel::left::tire::rubbertemperature {
// clang-format on

constexpr const char*
    VEHICLE_CHASSIS_AXLE_ROW1_WHEEL_LEFT_TIRE_RUBBERTEMPERATURE =
        "Vehicle.Chassis.Axle.Row1.Wheel.Left.Tire.RubberTemperature";

/**
 * @ingroup Get
 * @fn yoriito::Result<yoriito::signal::SignalGetDataPoint<float>> Get()
 * @brief Retrieves the datapoint for
 * Vehicle.Chassis.Axle.Row1.Wheel.Left.Tire.RubberTemperature
 * @deprecated -
 * @pre Vehicle.Chassis.Axle.Row1.Wheel.Left.Tire.RubberTemperature is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalGetDataPoint<float>): The result indicates
 * success.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalGetDataPoint<float>> Get();

/**
 * @ingroup Subscribe
 * @fn yoriito::Result<yoriito::signal::SignalSubscribeContext<float>
 * Subscribe()
 * @brief Subscribes to changes in the datapoint for
 * Vehicle.Chassis.Axle.Row1.Wheel.Left.Tire.RubberTemperature.
 * @deprecated -
 * @pre Vehicle.Chassis.Axle.Row1.Wheel.Left.Tire.RubberTemperature is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalSubscribeContext<float>): The result
 * containing a subscription context.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalSubscribeContext<float>> Subscribe();

/**
 * @ingroup UnSubscribe
 * @fn yoriito::Result<void>
 * UnSubscribe(yoriito::signal::SignalSubscribeContext<float
 * subscription_context)
 * @brief UnSubscribes from the datapoint for
 * Vehicle.Chassis.Axle.Row1.Wheel.Left.Tire.RubberTemperature.
 * @deprecated -
 * @pre The subscription to
 * Vehicle.Chassis.Axle.Row1.Wheel.Left.Tire.RubberTemperature has already been
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
    yoriito::signal::SignalSubscribeContext<float> subscription_context);

/**
 * @ingroup Inspect
 * @fn yoriito::Result<yoriito::signal::SignalInspecResponse<float>> Inspect()
 * @brief Retrieves the metadata for
 * Vehicle.Chassis.Axle.Row1.Wheel.Left.Tire.RubberTemperature
 * @deprecated -
 * @pre Vehicle.Chassis.Axle.Row1.Wheel.Left.Tire.RubberTemperature is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalInspectResponse<float>): The result
 * indicates success and the inspect response.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * yoriito::Result<yoriito::signal::SignalInspectResponse<float>> ret =
 * Inspect(); yoriito::signal::SignalInspectResponse<float> metadata =
 * ret.TakeOk().value();
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalInspectResponse<float>> Inspect();

// clang-format off
}  // namespace yoriito::vehicle::chassis::axle::row1::wheel::left::tire::rubbertemperature
// clang-format on

#endif  // SIGNAL_CHASSIS_AXLE_ROW1_WHEEL_LEFT_TIRE_SIGNAL_RUBBERTEMPERATURE_H_
