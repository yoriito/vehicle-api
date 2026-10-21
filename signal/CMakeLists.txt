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


# ---- Common include settings for all signal-domain libraries ----
include(CMakePackageConfigHelpers)

# ---- vehicle (signal root) library ----
yoriito_add_library(
    NAME
        "yoriito_vehicle_api_vehicle"
    SOURCES
        Signal_Acceleration.cc
        Signal_AngularVelocity.cc
        Signal_AverageSpeed.cc
        Signal_CargoVolume.cc
        Signal_CurbWeight.cc
        Signal_CurrentOverallWeight.cc
        Signal_EmissionsCO2.cc
        Signal_GrossWeight.cc
        Signal_Height.cc
        Signal_IsAutoPowerOptimize.cc
        Signal_IsBrokenDown.cc
        Signal_IsMoving.cc
        Signal_Length.cc
        Signal_LowVoltageSystemState.cc
        Signal_MaxTowBallWeight.cc
        Signal_MaxTowWeight.cc
        Signal_PowerOptimizeLevel.cc
        Signal_RoofLoad.cc
        Signal_Speed.cc
        Signal_StartTime.cc
        Signal_TraveledDistance.cc
        Signal_TraveledDistanceSinceStart.cc
        Signal_TripDuration.cc
        Signal_TurningDiameter.cc
        Signal_WidthExcludingMirrors.cc
        Signal_WidthFoldedMirrors.cc
        Signal_WidthIncludingMirrors.cc
    INSTALL_SUBDIR
        "signal"
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

# ---- structs ----
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/types)
  add_subdirectory(types)
  target_link_libraries(yoriito_vehicle_api_struct PRIVATE yoriito_vehicle_api_includes)
endif()

configure_package_config_file(
	"${CMAKE_SOURCE_DIR}/cmake/yoriito_vehicle_apiConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/yoriito_vehicle_apiConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/yoriito_vehicle_api
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/yoriito_vehicle_apiConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/yoriito_vehicle_api
)

install(EXPORT yoriito_vehicle_apiTargets
  FILE yoriito_vehicle_apiTargets.cmake
  NAMESPACE yoriito::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/yoriito_vehicle_api
)
