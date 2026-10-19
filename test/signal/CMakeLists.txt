# SPDX-License-Identifier: Apache-2.0
#
# Copyright 2026 JASPAR
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.



yoriito_add_test(
    NAME
        "test_"
    LIBS
        yoriito_vehicle_api_vehicle
    SOURCES
        Signal_Acceleration_Test.cc
        Signal_AngularVelocity_Test.cc
        Signal_AverageSpeed_Test.cc
        Signal_CargoVolume_Test.cc
        Signal_CurbWeight_Test.cc
        Signal_CurrentOverallWeight_Test.cc
        Signal_EmissionsCO2_Test.cc
        Signal_GrossWeight_Test.cc
        Signal_Height_Test.cc
        Signal_IsAutoPowerOptimize_Test.cc
        Signal_IsBrokenDown_Test.cc
        Signal_IsMoving_Test.cc
        Signal_Length_Test.cc
        Signal_LowVoltageSystemState_Test.cc
        Signal_MaxTowBallWeight_Test.cc
        Signal_MaxTowWeight_Test.cc
        Signal_PowerOptimizeLevel_Test.cc
        Signal_RoofLoad_Test.cc
        Signal_Speed_Test.cc
        Signal_StartTime_Test.cc
        Signal_TraveledDistanceSinceStart_Test.cc
        Signal_TraveledDistance_Test.cc
        Signal_TripDuration_Test.cc
        Signal_TurningDiameter_Test.cc
        Signal_WidthExcludingMirrors_Test.cc
        Signal_WidthFoldedMirrors_Test.cc
        Signal_WidthIncludingMirrors_Test.cc
)



# ---- subdomains ----
if (ENABLE_POWERTRAIN)
    add_subdirectory(powertrain)
endif()

if (ENABLE_BODY)
    add_subdirectory(body)
endif()

if (ENABLE_CABIN)
    add_subdirectory(cabin)
endif()

if (ENABLE_ADAS)
    add_subdirectory(adas)
endif()

if (ENABLE_CHASSIS)
    add_subdirectory(chassis)
endif()

if (ENABLE_DRIVER)
    add_subdirectory(driver)
endif()

if (ENABLE_OCCUPANT)
    add_subdirectory(occupant)
endif()

if (ENABLE_EXTERIOR)
    add_subdirectory(exterior)
endif()

if (ENABLE_VERSIONVSS)
    add_subdirectory(versionvss)
endif()

if (ENABLE_VEHICLEIDENTIFICATION)
    add_subdirectory(vehicleidentification)
endif()

if (ENABLE_LOWVOLTAGEBATTERY)
    add_subdirectory(lowvoltagebattery)
endif()

if (ENABLE_TRAILER)
    add_subdirectory(trailer)
endif()

if (ENABLE_CURRENTLOCATION)
    add_subdirectory(currentlocation)
endif()

if (ENABLE_MOTIONMANAGEMENT)
    add_subdirectory(motionmanagement)
endif()

if (ENABLE_VERSIONYORIITOVSS)
    add_subdirectory(versionyoriitovss)
endif()

if (ENABLE_TRIPMETER)
    add_subdirectory(tripmeter)
endif()

