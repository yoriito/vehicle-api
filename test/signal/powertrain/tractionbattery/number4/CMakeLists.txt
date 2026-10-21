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
        test_powertrain_tractionbattery_number4
    LIBS
        yoriito_vehicle_api_powertrain
    SOURCES
        Signal_AccumulatedChargedEnergy_Test.cc
        Signal_AccumulatedChargedThroughput_Test.cc
        Signal_AccumulatedConsumedEnergy_Test.cc
        Signal_AccumulatedConsumedThroughput_Test.cc
        Signal_CurrentElectricity_Test.cc
        Signal_CurrentPower_Test.cc
        Signal_ErrorCodes_Test.cc
        Signal_GrossCapacity_Test.cc
        Signal_Id_Test.cc
        Signal_IsGroundConnected_Test.cc
        Signal_IsPowerConnected_Test.cc
        Signal_NetCapacity_Test.cc
        Signal_PowerLoss_Test.cc
        Signal_ProductionDate_Test.cc
        Signal_StateOfHealth_Test.cc
)



# ---- subdomains ----
add_subdirectory(temperature)

add_subdirectory(cellvoltage)

add_subdirectory(stateofcharge)

add_subdirectory(batteryconditioning)

add_subdirectory(cells)



