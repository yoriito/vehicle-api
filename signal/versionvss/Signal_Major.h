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

#ifndef SIGNAL_VERSIONVSS_SIGNAL_MAJOR_H_
#define SIGNAL_VERSIONVSS_SIGNAL_MAJOR_H_

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
 * @ingroup VersionVSS
 * @namespace yoriito::vehicle::versionvss::major
 * @brief Indicates the Vehicle.VersionVSS.Major signal.
 * @deprecated -
 * @version main
 */
// clang-format off
namespace yoriito::vehicle::versionvss::major {
// clang-format on

constexpr const char* VEHICLE_VERSIONVSS_MAJOR = "Vehicle.VersionVSS.Major";

/**
 * @ingroup Get
 * @fn yoriito::Result<yoriito::signal::SignalGetDataPoint<uint32_t>> Get()
 * @brief Retrieves the datapoint for Vehicle.VersionVSS.Major
 * @deprecated -
 * @pre Vehicle.VersionVSS.Major is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalGetDataPoint<uint32_t>): The result
 * indicates success.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * -
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalGetDataPoint<uint32_t>> Get();

/**
 * @ingroup Inspect
 * @fn yoriito::Result<yoriito::signal::SignalInspecResponse<uint32_t>>
 * Inspect()
 * @brief Retrieves the metadata for Vehicle.VersionVSS.Major
 * @deprecated -
 * @pre Vehicle.VersionVSS.Major is capable.
 * @param -
 * @retval Ok(yoriito::signal::SignalInspectResponse<uint32_t>): The result
 * indicates success and the inspect response.
 * @retval Err(UnsetValueError): The result indicates the value has been not
 * set.
 * @retval Err(UnknownError): The result indicates an unknown error.
 * @note Thread safe.
 * @code
 * yoriito::Result<yoriito::signal::SignalInspectResponse<uint32_t>> ret =
 * Inspect(); yoriito::signal::SignalInspectResponse<uint32_t> metadata =
 * ret.TakeOk().value();
 * @endcode
 */
yoriito::Result<yoriito::signal::SignalInspectResponse<uint32_t>> Inspect();

// clang-format off
}  // namespace yoriito::vehicle::versionvss::major
// clang-format on

#endif  // SIGNAL_VERSIONVSS_SIGNAL_MAJOR_H_
