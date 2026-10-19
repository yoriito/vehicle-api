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


yoriito_add_library(
    NAME
        "yoriito_vehicle_api_vehicleidentification"
    SOURCES
        Signal_AcrissCode.cc
        Signal_BodyType.cc
        Signal_Brand.cc
        Signal_DateVehicleFirstRegistered.cc
        Signal_KnownVehicleDamages.cc
        Signal_LicensePlate.cc
        Signal_MeetsEmissionStandard.cc
        Signal_Model.cc
        Signal_OptionalExtras.cc
        Signal_ProductionDate.cc
        Signal_PurchaseDate.cc
        Signal_VIN.cc
        Signal_VehicleConfiguration.cc
        Signal_VehicleExteriorColor.cc
        Signal_VehicleInteriorColor.cc
        Signal_VehicleInteriorType.cc
        Signal_VehicleModelDate.cc
        Signal_VehicleSeatingCapacity.cc
        Signal_VehicleSpecialUsage.cc
        Signal_WMI.cc
        Signal_Year.cc
    INSTALL_SUBDIR
        "signal/vehicleidentification"
)


