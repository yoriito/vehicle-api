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
        test_powertrain_transmission
    LIBS
        yoriito_vehicle_api_powertrain
    SOURCES
        Signal_ClutchEngagement_Test.cc
        Signal_ClutchWear_Test.cc
        Signal_CurrentGear_Test.cc
        Signal_CurrentPhysicalGear_Test.cc
        Signal_DiffLockCenterEngagement_Test.cc
        Signal_DiffLockFrontEngagement_Test.cc
        Signal_DiffLockRearEngagement_Test.cc
        Signal_DriveType_Test.cc
        Signal_GearChangeMode_Test.cc
        Signal_GearCount_Test.cc
        Signal_IsElectricalPowertrainEngaged_Test.cc
        Signal_IsLowRangeEngaged_Test.cc
        Signal_IsParkLockEngaged_Test.cc
        Signal_PerformanceMode_Test.cc
        Signal_SelectedGear_Test.cc
        Signal_Temperature_Test.cc
        Signal_TorqueDistribution_Test.cc
        Signal_TravelledDistance_Test.cc
        Signal_Type_Test.cc
)



