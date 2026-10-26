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
        test_body_windshield_front_wiping_system
    LIBS
        yoriito_vehicle_api_body
    SOURCES
        Signal_DriveCurrent_Test.cc
        Signal_Frequency_Test.cc
        Signal_IsBlocked_Test.cc
        Signal_IsEndingWipeCycle_Test.cc
        Signal_IsOverheated_Test.cc
        Signal_IsPositionReached_Test.cc
        Signal_IsWiperError_Test.cc
        Signal_IsWiping_Test.cc
        Signal_Mode_Test.cc
        Signal_Position_Test.cc
)



