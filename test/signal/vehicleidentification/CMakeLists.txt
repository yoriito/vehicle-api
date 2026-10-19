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
        test_vehicleidentification
    LIBS
        yoriito_vehicle_api_vehicleidentification
    SOURCES
        Signal_AcrissCode_Test.cc
        Signal_BodyType_Test.cc
        Signal_Brand_Test.cc
        Signal_DateVehicleFirstRegistered_Test.cc
        Signal_KnownVehicleDamages_Test.cc
        Signal_LicensePlate_Test.cc
        Signal_MeetsEmissionStandard_Test.cc
        Signal_Model_Test.cc
        Signal_OptionalExtras_Test.cc
        Signal_ProductionDate_Test.cc
        Signal_PurchaseDate_Test.cc
        Signal_VIN_Test.cc
        Signal_VehicleConfiguration_Test.cc
        Signal_VehicleExteriorColor_Test.cc
        Signal_VehicleInteriorColor_Test.cc
        Signal_VehicleInteriorType_Test.cc
        Signal_VehicleModelDate_Test.cc
        Signal_VehicleSeatingCapacity_Test.cc
        Signal_VehicleSpecialUsage_Test.cc
        Signal_WMI_Test.cc
        Signal_Year_Test.cc
)



