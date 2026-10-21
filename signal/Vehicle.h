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

#ifndef SIGNAL_VEHICLE_H_
#define SIGNAL_VEHICLE_H_

#include "Signal_Acceleration.h"
#include "Signal_AngularVelocity.h"
#include "Signal_AverageSpeed.h"
#include "Signal_CargoVolume.h"
#include "Signal_CurbWeight.h"
#include "Signal_CurrentOverallWeight.h"
#include "Signal_EmissionsCO2.h"
#include "Signal_GrossWeight.h"
#include "Signal_Height.h"
#include "Signal_IsAutoPowerOptimize.h"
#include "Signal_IsBrokenDown.h"
#include "Signal_IsMoving.h"
#include "Signal_Length.h"
#include "Signal_LowVoltageSystemState.h"
#include "Signal_MaxTowBallWeight.h"
#include "Signal_MaxTowWeight.h"
#include "Signal_PowerOptimizeLevel.h"
#include "Signal_RoofLoad.h"
#include "Signal_Speed.h"
#include "Signal_StartTime.h"
#include "Signal_TraveledDistance.h"
#include "Signal_TraveledDistanceSinceStart.h"
#include "Signal_TripDuration.h"
#include "Signal_TurningDiameter.h"
#include "Signal_WidthExcludingMirrors.h"
#include "Signal_WidthFoldedMirrors.h"
#include "Signal_WidthIncludingMirrors.h"
#include "adas/ADAS.h"
#include "body/Body.h"
#include "cabin/Cabin.h"
#include "chassis/Chassis.h"
#include "currentlocation/CurrentLocation.h"
#include "driver/Driver.h"
#include "exterior/Exterior.h"
#include "lowvoltagebattery/LowVoltageBattery.h"
#include "motionmanagement/MotionManagement.h"
#include "occupant/Occupant.h"
#include "powertrain/Powertrain.h"
#include "trailer/Trailer.h"
#include "tripmeter/TripMeter.h"
#include "vehicleidentification/VehicleIdentification.h"
#include "versionvss/VersionVSS.h"
#include "versionyoriitovss/VersionYoriitoVSS.h"

#endif  // SIGNAL_VEHICLE_H_
