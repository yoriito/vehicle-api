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
        test_powertrain_electricmotor_number3_enginecoolant
    LIBS
        yoriito_vehicle_api_powertrain
    SOURCES
        Signal_Capacity_Test.cc
        Signal_Level_Test.cc
        Signal_LifeRemaining_Test.cc
        Signal_Temperature_Test.cc
)



