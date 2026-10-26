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
        Signal_EngineCode.cc
        Signal_MaxPower.cc
        Signal_MaxRegenPower.cc
        Signal_MaxRegenTorque.cc
        Signal_MaxTorque.cc
        Signal_Power.cc
        Signal_Speed.cc
        Signal_Temperature.cc
        Signal_TimeInUse.cc
        Signal_Torque.cc
)



# ---- subdomains ----
add_subdirectory(enginecoolant)



