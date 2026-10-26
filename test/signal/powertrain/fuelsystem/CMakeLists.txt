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
        test_powertrain_fuelsystem
    LIBS
        yoriito_vehicle_api_powertrain
    SOURCES
        Signal_AbsoluteLevel_Test.cc
        Signal_AfterRefuelingFuelEconomy_Test.cc
        Signal_AverageConsumption_Test.cc
        Signal_ConsumptionSinceLastRefuel_Test.cc
        Signal_ConsumptionSinceStart_Test.cc
        Signal_CumulativeFuelEconomy_Test.cc
        Signal_DriveFuelEconomy_Test.cc
        Signal_InstantConsumption_Test.cc
        Signal_InstantFuelEconomy_Test.cc
        Signal_IsEngineStopStartEnabled_Test.cc
        Signal_IsFuelLevelEmpty_Test.cc
        Signal_IsFuelLevelLow_Test.cc
        Signal_IsFuelPortFlapOpen_Test.cc
        Signal_Range_Test.cc
        Signal_RefuelPortPosition_Test.cc
        Signal_RelativeLevel_Test.cc
        Signal_SupportedFuel_Test.cc
        Signal_TankCapacity_Test.cc
        Signal_TimeRemaining_Test.cc
)



