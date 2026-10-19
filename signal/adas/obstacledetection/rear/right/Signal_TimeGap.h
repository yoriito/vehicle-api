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

#ifndef SIGNAL_ADAS_OBSTACLEDETECTION_REAR_RIGHT_SIGNAL_TIMEGAP_H_
#define SIGNAL_ADAS_OBSTACLEDETECTION_REAR_RIGHT_SIGNAL_TIMEGAP_H_

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
 * @ingroup ADAS
 * @namespace yoriito::vehicle::adas::obstacledetection::rear::right::timegap {
 * @brief Indicates the Vehicle.ADAS.ObstacleDetection.Rear.Right.TimeGap
 * signal.
 * @deprecated -
 * @version main
 */
// clang-format off
namespace yoriito::vehicle::adas::obstacledetection::rear::right::timegap {
// clang-format on

constexpr const char* VEHICLE_ADAS_OBSTACLEDETECTION_REAR_RIGHT_TIMEGAP =
    "Vehicle.ADAS.ObstacleDetection.Rear.Right.TimeGap";

/**
 * @ingroup Get
 * @fn yoriito::Result<yoriito::signal::SignalGetDataPoint<int32_t>> Get()
 * @brief Retrieves the datapoint for
 * Vehicle.ADAS.ObstacleDetection.Rear.Right.TimeGap
 * @deprecated -
 * @pre Vehicle.ADAS.ObstacleDetection.Rear.Right.TimeGap is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalGetDataPoint<int32_t>): The result
 * indicates success.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalGetDataPoint<int32_t>> Get();

/**
 * @ingroup Subscribe
 * @fn yoriito::Result<yoriito::signal::SignalSubscribeContext<int32_t>
 * Subscribe()
 * @brief Subscribes to changes in the datapoint for
 * Vehicle.ADAS.ObstacleDetection.Rear.Right.TimeGap.
 * @deprecated -
 * @pre Vehicle.ADAS.ObstacleDetection.Rear.Right.TimeGap is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalSubscribeContext<int32_t>): The result
 * containing a subscription context.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalSubscribeContext<int32_t>> Subscribe();

/**
 * @ingroup UnSubscribe
 * @fn yoriito::Result<void>
 * UnSubscribe(yoriito::signal::SignalSubscribeContext<int32_t
 * subscription_context)
 * @brief UnSubscribes from the datapoint for
 * Vehicle.ADAS.ObstacleDetection.Rear.Right.TimeGap.
 * @deprecated -
 * @pre The subscription to Vehicle.ADAS.ObstacleDetection.Rear.Right.TimeGap
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
    yoriito::signal::SignalSubscribeContext<int32_t> subscription_context);

/**
 * @ingroup Inspect
 * @fn yoriito::Result<yoriito::signal::SignalInspecResponse<int32_t>> Inspect()
 * @brief Retrieves the metadata for
 * Vehicle.ADAS.ObstacleDetection.Rear.Right.TimeGap
 * @deprecated -
 * @pre Vehicle.ADAS.ObstacleDetection.Rear.Right.TimeGap is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalInspectResponse<int32_t>): The result
 * indicates success and the inspect response.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * yoriito::Result<yoriito::signal::SignalInspectResponse<int32_t>> ret =
 * Inspect(); yoriito::signal::SignalInspectResponse<int32_t> metadata =
 * ret.TakeOk().value();
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalInspectResponse<int32_t>> Inspect();

// clang-format off
}  // namespace yoriito::vehicle::adas::obstacledetection::rear::right::timegap
// clang-format on

#endif  // SIGNAL_ADAS_OBSTACLEDETECTION_REAR_RIGHT_SIGNAL_TIMEGAP_H_
