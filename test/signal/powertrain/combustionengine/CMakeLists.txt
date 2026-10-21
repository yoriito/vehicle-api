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
        test_powertrain_combustionengine
    LIBS
        yoriito_vehicle_api_powertrain
    SOURCES
        Signal_AspirationType_Test.cc
        Signal_Bore_Test.cc
        Signal_CompressionRatio_Test.cc
        Signal_Configuration_Test.cc
        Signal_Displacement_Test.cc
        Signal_EOP_Test.cc
        Signal_EngineCode_Test.cc
        Signal_EngineHours_Test.cc
        Signal_IdleHours_Test.cc
        Signal_IsRunning_Test.cc
        Signal_MAF_Test.cc
        Signal_MAP_Test.cc
        Signal_MaxPower_Test.cc
        Signal_MaxTorque_Test.cc
        Signal_NumberOfCylinders_Test.cc
        Signal_NumberOfValvesPerCylinder_Test.cc
        Signal_Power_Test.cc
        Signal_Speed_Test.cc
        Signal_StrokeLength_Test.cc
        Signal_TPS_Test.cc
        Signal_Torque_Test.cc
)



# ---- subdomains ----
add_subdirectory(engineoil)

add_subdirectory(enginecoolant)

add_subdirectory(dieselexhaustfluid)

add_subdirectory(dieselparticulatefilter)



