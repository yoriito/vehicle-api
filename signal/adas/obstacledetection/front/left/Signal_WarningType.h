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

#ifndef SIGNAL_ADAS_OBSTACLEDETECTION_FRONT_LEFT_SIGNAL_WARNINGTYPE_H_
#define SIGNAL_ADAS_OBSTACLEDETECTION_FRONT_LEFT_SIGNAL_WARNINGTYPE_H_

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
 * @ingroup ADAS
 * @namespace
 * yoriito::vehicle::adas::obstacledetection::front::left::warningtype {
 * @brief Indicates the Vehicle.ADAS.ObstacleDetection.Front.Left.WarningType
 * signal.
 * @deprecated -
 * @version main
 */
// clang-format off
namespace yoriito::vehicle::adas::obstacledetection::front::left::warningtype {
// clang-format on

constexpr const char* VEHICLE_ADAS_OBSTACLEDETECTION_FRONT_LEFT_WARNINGTYPE =
    "Vehicle.ADAS.ObstacleDetection.Front.Left.WarningType";

/**
 * @ingroup Get
 * @fn yoriito::Result<yoriito::signal::SignalGetDataPoint<std::string>> Get()
 * @brief Retrieves the datapoint for
 * Vehicle.ADAS.ObstacleDetection.Front.Left.WarningType
 * @deprecated -
 * @pre Vehicle.ADAS.ObstacleDetection.Front.Left.WarningType is capable.
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
 * @ingroup Subscribe
 * @fn yoriito::Result<yoriito::signal::SignalSubscribeContext<std::string>
 * Subscribe()
 * @brief Subscribes to changes in the datapoint for
 * Vehicle.ADAS.ObstacleDetection.Front.Left.WarningType.
 * @deprecated -
 * @pre Vehicle.ADAS.ObstacleDetection.Front.Left.WarningType is capable.
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
 * Vehicle.ADAS.ObstacleDetection.Front.Left.WarningType.
 * @deprecated -
 * @pre The subscription to
 * Vehicle.ADAS.ObstacleDetection.Front.Left.WarningType has already been
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
    yoriito::signal::SignalSubscribeContext<std::string> subscription_context);

/**
 * @ingroup Inspect
 * @fn yoriito::Result<yoriito::signal::SignalInspecResponse<std::string>>
 * Inspect()
 * @brief Retrieves the metadata for
 * Vehicle.ADAS.ObstacleDetection.Front.Left.WarningType
 * @deprecated -
 * @pre Vehicle.ADAS.ObstacleDetection.Front.Left.WarningType is capable.
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
}  // namespace yoriito::vehicle::adas::obstacledetection::front::left::warningtype
// clang-format on

#endif  // SIGNAL_ADAS_OBSTACLEDETECTION_FRONT_LEFT_SIGNAL_WARNINGTYPE_H_
