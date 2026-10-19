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



target_sources(yoriito_vehicle_api_cabin
    PRIVATE
        Signal_BottomLumbarSupport.cc
        Signal_HeatingCooling.cc
        Signal_LumbarHeight.cc
        Signal_LumbarSupport.cc
        Signal_MidLumbarSupport.cc
        Signal_Recline.cc
        Signal_SideBolsterSupport.cc
        Signal_SideBolsterSupportLeft.cc
        Signal_SideBolsterSupportRight.cc
        Signal_TopLumbarSupport.cc
        Signal_UpperShoulderSupport.cc
        Signal_Ventilator.cc
)



