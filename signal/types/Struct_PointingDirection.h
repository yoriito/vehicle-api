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

#ifndef SIGNAL_TYPES_STRUCT_POINTINGDIRECTION_H_
#define SIGNAL_TYPES_STRUCT_POINTINGDIRECTION_H_

// clang-format off
namespace yoriito::types {
// clang-format on

/**
 * @brief Direction from object reference point to the target point indicated by
 * the object.
 * @deprecated -
 */
struct PointingDirection {
  /**
   * @brief Object azimuth pointing angle (right-hand rule) on vehicle sprung
   * mass Z-axis as defined by ISO 23150:2023. 0 = Object pointing forward.
   * Positive values = Object pointing toward the left side of the vehicle.
   * Negative values = Object pointing toward the right side of the vehicle.
   */
  float azimuth;
  /**
   * @brief Elevation to target point measured as angle between the vehicle
   * sprung mass XY-plane as defined by ISO 23150:2023 at the object reference
   * point and the direction to the target point. 0 = Object pointing at a
   * target at the same height as the object reference point. Positive values =
   * Object pointing at a target above the object reference point. Negative
   * values = Object pointing at a target below the object reference point.
   */
  float elevation;

  /**
   * @brief Default constructor.
   */
  PointingDirection() : azimuth(0.0), elevation(0.0) {}

  /**
   * @brief Constructor with parameters.
   * @param azimuth Object azimuth pointing angle (right-hand rule) on vehicle
   * sprung mass Z-axis as defined by ISO 23150:2023. 0 = Object pointing
   * forward. Positive values = Object pointing toward the left side of the
   * vehicle. Negative values = Object pointing toward the right side of the
   * vehicle.
   * @param elevation Elevation to target point measured as angle between the
   * vehicle sprung mass XY-plane as defined by ISO 23150:2023 at the object
   * reference point and the direction to the target point. 0 = Object pointing
   * at a target at the same height as the object reference point. Positive
   * values = Object pointing at a target above the object reference point.
   * Negative values = Object pointing at a target below the object reference
   * point.
   */
  PointingDirection(float azimuth, float elevation)
      : azimuth(azimuth), elevation(elevation) {}
};

// clang-format off
}  // namespace yoriito::types
// clang-format on

#endif  // SIGNAL_TYPES_STRUCT_POINTINGDIRECTION_H_
