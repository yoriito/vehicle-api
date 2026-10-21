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
        test_motionmanagement_suspension_axle_row2_wheel_left
    LIBS
        yoriito_vehicle_api_motionmanagement
    SOURCES
        Signal_DampingForceTarget_Test.cc
        Signal_DampingForce_Test.cc
        Signal_DampingRateTarget_Test.cc
        Signal_DampingRate_Test.cc
)



