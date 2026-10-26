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
        Signal_ClutchEngagement.cc
        Signal_ClutchWear.cc
        Signal_CurrentGear.cc
        Signal_CurrentPhysicalGear.cc
        Signal_DiffLockCenterEngagement.cc
        Signal_DiffLockFrontEngagement.cc
        Signal_DiffLockRearEngagement.cc
        Signal_DriveType.cc
        Signal_GearChangeMode.cc
        Signal_GearCount.cc
        Signal_IsElectricalPowertrainEngaged.cc
        Signal_IsLowRangeEngaged.cc
        Signal_IsParkLockEngaged.cc
        Signal_PerformanceMode.cc
        Signal_SelectedGear.cc
        Signal_Temperature.cc
        Signal_TorqueDistribution.cc
        Signal_TravelledDistance.cc
        Signal_Type.cc
)



