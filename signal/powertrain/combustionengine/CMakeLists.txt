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



target_sources(yoriito_vehicle_api_powertrain
    PRIVATE
        Signal_AspirationType.cc
        Signal_Bore.cc
        Signal_CompressionRatio.cc
        Signal_Configuration.cc
        Signal_Displacement.cc
        Signal_EOP.cc
        Signal_EngineCode.cc
        Signal_EngineHours.cc
        Signal_IdleHours.cc
        Signal_IsRunning.cc
        Signal_MAF.cc
        Signal_MAP.cc
        Signal_MaxPower.cc
        Signal_MaxTorque.cc
        Signal_NumberOfCylinders.cc
        Signal_NumberOfValvesPerCylinder.cc
        Signal_Power.cc
        Signal_Speed.cc
        Signal_StrokeLength.cc
        Signal_TPS.cc
        Signal_Torque.cc
)



# ---- subdomains ----
add_subdirectory(engineoil)

add_subdirectory(enginecoolant)

add_subdirectory(dieselexhaustfluid)

add_subdirectory(dieselparticulatefilter)



