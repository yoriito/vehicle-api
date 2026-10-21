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

#ifndef SIGNAL_LOWVOLTAGEBATTERY_SIGNAL_NOMINALVOLTAGE_H_
#define SIGNAL_LOWVOLTAGEBATTERY_SIGNAL_NOMINALVOLTAGE_H_

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
 * @ingroup LowVoltageBattery
 * @namespace yoriito::vehicle::lowvoltagebattery::nominalvoltage
 * @brief Indicates the Vehicle.LowVoltageBattery.NominalVoltage signal.
 * @deprecated -
 * @version main
 */
// clang-format off
namespace yoriito::vehicle::lowvoltagebattery::nominalvoltage {
// clang-format on

constexpr const char* VEHICLE_LOWVOLTAGEBATTERY_NOMINALVOLTAGE =
    "Vehicle.LowVoltageBattery.NominalVoltage";

/**
 * @ingroup Get
 * @fn yoriito::Result<yoriito::signal::SignalGetDataPoint<uint16_t>> Get()
 * @brief Retrieves the datapoint for Vehicle.LowVoltageBattery.NominalVoltage
 * @deprecated -
 * @pre Vehicle.LowVoltageBattery.NominalVoltage is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalGetDataPoint<uint16_t>): The result
 * indicates success.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalGetDataPoint<uint16_t>> Get();

/**
 * @ingroup Inspect
 * @fn yoriito::Result<yoriito::signal::SignalInspecResponse<uint16_t>>
 * Inspect()
 * @brief Retrieves the metadata for Vehicle.LowVoltageBattery.NominalVoltage
 * @deprecated -
 * @pre Vehicle.LowVoltageBattery.NominalVoltage is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalInspectResponse<uint16_t>): The result
 * indicates success and the inspect response.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * yoriito::Result<yoriito::signal::SignalInspectResponse<uint16_t>> ret =
 * Inspect(); yoriito::signal::SignalInspectResponse<uint16_t> metadata =
 * ret.TakeOk().value();
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalInspectResponse<uint16_t>> Inspect();

// clang-format off
}  // namespace yoriito::vehicle::lowvoltagebattery::nominalvoltage
// clang-format on

#endif  // SIGNAL_LOWVOLTAGEBATTERY_SIGNAL_NOMINALVOLTAGE_H_
