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

#ifndef SIGNAL_POWERTRAIN_TRACTIONBATTERY_NUMBER3_SIGNAL_PRODUCTIONDATE_H_
#define SIGNAL_POWERTRAIN_TRACTIONBATTERY_NUMBER3_SIGNAL_PRODUCTIONDATE_H_

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
 * @ingroup Powertrain
 * @namespace
 * yoriito::vehicle::powertrain::tractionbattery::number3::productiondate
 * @brief Indicates the
 * Vehicle.Powertrain.TractionBattery.Number3.ProductionDate signal.
 * @deprecated -
 * @version main
 */
// clang-format off
namespace yoriito::vehicle::powertrain::tractionbattery::number3::productiondate {
// clang-format on

constexpr const char*
    VEHICLE_POWERTRAIN_TRACTIONBATTERY_NUMBER3_PRODUCTIONDATE =
        "Vehicle.Powertrain.TractionBattery.Number3.ProductionDate";

/**
 * @ingroup Get
 * @fn yoriito::Result<yoriito::signal::SignalGetDataPoint<std::string>> Get()
 * @brief Retrieves the datapoint for
 * Vehicle.Powertrain.TractionBattery.Number3.ProductionDate
 * @deprecated -
 * @pre Vehicle.Powertrain.TractionBattery.Number3.ProductionDate is capable.
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
 * @ingroup Inspect
 * @fn yoriito::Result<yoriito::signal::SignalInspecResponse<std::string>>
 * Inspect()
 * @brief Retrieves the metadata for
 * Vehicle.Powertrain.TractionBattery.Number3.ProductionDate
 * @deprecated -
 * @pre Vehicle.Powertrain.TractionBattery.Number3.ProductionDate is capable.
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
}  // namespace yoriito::vehicle::powertrain::tractionbattery::number3::productiondate
// clang-format on

#endif  // SIGNAL_POWERTRAIN_TRACTIONBATTERY_NUMBER3_SIGNAL_PRODUCTIONDATE_H_
