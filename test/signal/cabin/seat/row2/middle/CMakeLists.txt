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
        test_cabin_seat_row2_middle
    LIBS
        yoriito_vehicle_api_cabin
    SOURCES
        Signal_HeatingCooling_Test.cc
        Signal_Height_Test.cc
        Signal_IsBelted_Test.cc
        Signal_OccupancyStatus_Test.cc
        Signal_Position_Test.cc
        Signal_SeatBeltHeight_Test.cc
        Signal_Tilt_Test.cc
        Signal_Ventilator_Test.cc
)



# ---- subdomains ----
add_subdirectory(massage)

add_subdirectory(backrest)

add_subdirectory(seating)

add_subdirectory(headrest)

add_subdirectory(airbag)

add_subdirectory(neckscarf)



