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

#ifndef SIGNAL_TYPES_INTERNAL_STRUCT_UTILITY_TRAITS_H_
#define SIGNAL_TYPES_INTERNAL_STRUCT_UTILITY_TRAITS_H_

#include "Struct_Acceleration_internal.h"
#include "Struct_AngularVelocity_internal.h"
#include "Struct_Electricity_internal.h"
#include "Struct_GNSSLocation_internal.h"
#include "Struct_Location_internal.h"
#include "Struct_PointingDirection_internal.h"
#include "Struct_Pose_internal.h"
#include "Struct_RoadFrictionRange_internal.h"
#include "Struct_ThreePhaseCurrentMeasurements_internal.h"
#include "Struct_ThreePhaseVoltageMeasurements_internal.h"
#include "Struct_VehicleLocation_internal.h"
#include "databroker/consumer_inspect_response.h"
#include "databroker_type.h"
#include "result.h"

// clang-format off
namespace yoriito::types::internal {
// clang-format on

// Type trait mapping: Struct type -> Utility class
template <typename T>
struct StructUtilityTraits;

template <typename T>
inline yoriito::StructDataPtr ToStructData(const T& data) {
  return StructUtilityTraits<T>::Utility::ToStructData(data);
}

template <typename T>
inline bool FromStructData(const yoriito::StructData& struct_data, T* data) {
  return StructUtilityTraits<T>::Utility::FromStructData(struct_data, data);
}

template <typename T>
inline yoriito::Result<void> Validate(
    const yoriito::databroker::ConsumerInspectResponse& inspect_response,
    const T& data) {
  return StructUtilityTraits<T>::Utility::Validate(inspect_response, data);
}

// Register struct-utility mapping
template <>
struct StructUtilityTraits<yoriito::types::Acceleration> {
  using Utility = yoriito::types::internal::AccelerationUtility;
};

template <>
struct StructUtilityTraits<yoriito::types::AngularVelocity> {
  using Utility = yoriito::types::internal::AngularVelocityUtility;
};

template <>
struct StructUtilityTraits<yoriito::types::Electricity> {
  using Utility = yoriito::types::internal::ElectricityUtility;
};

template <>
struct StructUtilityTraits<yoriito::types::GNSSLocation> {
  using Utility = yoriito::types::internal::GNSSLocationUtility;
};

template <>
struct StructUtilityTraits<yoriito::types::Location> {
  using Utility = yoriito::types::internal::LocationUtility;
};

template <>
struct StructUtilityTraits<yoriito::types::PointingDirection> {
  using Utility = yoriito::types::internal::PointingDirectionUtility;
};

template <>
struct StructUtilityTraits<yoriito::types::Pose> {
  using Utility = yoriito::types::internal::PoseUtility;
};

template <>
struct StructUtilityTraits<yoriito::types::RoadFrictionRange> {
  using Utility = yoriito::types::internal::RoadFrictionRangeUtility;
};

template <>
struct StructUtilityTraits<yoriito::types::ThreePhaseCurrentMeasurements> {
  using Utility =
      yoriito::types::internal::ThreePhaseCurrentMeasurementsUtility;
};

template <>
struct StructUtilityTraits<yoriito::types::ThreePhaseVoltageMeasurements> {
  using Utility =
      yoriito::types::internal::ThreePhaseVoltageMeasurementsUtility;
};

template <>
struct StructUtilityTraits<yoriito::types::VehicleLocation> {
  using Utility = yoriito::types::internal::VehicleLocationUtility;
};

// clang-format off
}  // namespace yoriito::types::internal
// clang-format on

#endif  // SIGNAL_TYPES_INTERNAL_STRUCT_UTILITY_TRAITS_H_
