/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright 2026 JASPAR
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SIGNAL_TYPES_STRUCT_VEHICLELOCATION_H_
#define SIGNAL_TYPES_STRUCT_VEHICLELOCATION_H_
#include <string>

// clang-format off
namespace yoriito::types {
// clang-format on

/**
 * @brief Information for vehicle location. An IEEE 754‑compliant NaN value
 * shall indicate an invalid or unsupported value. When dead reckoning is not
 * enabled, all values shall be set to NaN.
 * @deprecated -
 */
struct VehicleLocation {
  /**
   * @brief Timestamp for current location, formatted according to ISO 8601 with
   * UTC time zone.
   */
  std::string timestamp;
  /**
   * @brief Current latitude of vehicle in WGS 84 geodetic coordinates.
   */
  double latitude;
  /**
   * @brief Current longitude of vehicle in WGS 84 geodetic coordinates.
   */
  double longitude;
  /**
   * @brief Accuracy of the latitude and longitude coordinates.
   */
  double horizontal_accuracy;
  /**
   * @brief Current altitude relative to WGS 84 reference ellipsoid.
   */
  double altitude;
  /**
   * @brief Accuracy of altitude.
   */
  double vertical_accuracy;
  /**
   * @brief Current heading relative to geographic north. 0 = North, 90 = East,
   * 180 = South, 270 = West.
   */
  double heading;

  /**
   * @brief Default constructor.
   */
  VehicleLocation()
      : timestamp(""),
        latitude(0.0),
        longitude(0.0),
        horizontal_accuracy(0.0),
        altitude(0.0),
        vertical_accuracy(0.0),
        heading(0.0) {}

  /**
   * @brief Constructor with parameters.
   * @param timestamp Timestamp for current location, formatted according to ISO
   * 8601 with UTC time zone.
   * @param latitude Current latitude of vehicle in WGS 84 geodetic coordinates.
   * @param longitude Current longitude of vehicle in WGS 84 geodetic
   * coordinates.
   * @param horizontal_accuracy Accuracy of the latitude and longitude
   * coordinates.
   * @param altitude Current altitude relative to WGS 84 reference ellipsoid.
   * @param vertical_accuracy Accuracy of altitude.
   * @param heading Current heading relative to geographic north. 0 = North, 90
   * = East, 180 = South, 270 = West.
   */
  VehicleLocation(std::string timestamp, double latitude, double longitude,
                  double horizontal_accuracy, double altitude,
                  double vertical_accuracy, double heading)
      : timestamp(std::move(timestamp)),
        latitude(latitude),
        longitude(longitude),
        horizontal_accuracy(horizontal_accuracy),
        altitude(altitude),
        vertical_accuracy(vertical_accuracy),
        heading(heading) {}
};

// clang-format off
}  // namespace yoriito::types
// clang-format on

#endif  // SIGNAL_TYPES_STRUCT_VEHICLELOCATION_H_
