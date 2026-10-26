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
        test_powertrain_tractionbattery_number1_batteryconditioning
    LIBS
        yoriito_vehicle_api_powertrain
    SOURCES
        Signal_IsActive_Test.cc
        Signal_IsOngoing_Test.cc
        Signal_RequestedMode_Test.cc
        Signal_StartTime_Test.cc
        Signal_TargetTemperature_Test.cc
        Signal_TargetTime_Test.cc
)



