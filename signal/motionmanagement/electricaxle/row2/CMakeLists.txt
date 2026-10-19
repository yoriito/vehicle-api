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



target_sources(yoriito_vehicle_api_motionmanagement
    PRIVATE
        Signal_RotationalSpeed.cc
        Signal_RotationalSpeedMaximumLimit.cc
        Signal_RotationalSpeedMinimumLimit.cc
        Signal_Torque.cc
        Signal_TorqueMaximum.cc
        Signal_TorqueMaximumLimit.cc
        Signal_TorqueMinimum.cc
        Signal_TorqueMinimumLimit.cc
)



