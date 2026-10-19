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

#ifndef SIGNAL_TYPES_STRUCT_ANGULARVELOCITY_H_
#define SIGNAL_TYPES_STRUCT_ANGULARVELOCITY_H_

// clang-format off
namespace yoriito::types {
// clang-format on

/**
 * @brief Spatial rotation. Axis definitions according to ISO 8855.
 * @deprecated -
 */
struct AngularVelocity {
  /**
   * @brief Vehicle rotation rate along X (longitudinal). An IEEE 754-compliant
   * NaN value shall indicate an invalid or unsupported value, e.g., when the
   * vehicle does not support a particular axis.
   */
  float roll;
  /**
   * @brief Vehicle rotation rate along Y (lateral). An IEEE 754-compliant NaN
   * value shall indicate an invalid or unsupported value, e.g., when the
   * vehicle does not support a particular axis.
   */
  float pitch;
  /**
   * @brief Vehicle rotation rate along Z (vertical). An IEEE 754-compliant NaN
   * value shall indicate an invalid or unsupported value, e.g., when the
   * vehicle does not support a particular axis.
   */
  float yaw;

  /**
   * @brief Default constructor.
   */
  AngularVelocity() : roll(0.0), pitch(0.0), yaw(0.0) {}

  /**
   * @brief Constructor with parameters.
   * @param roll Vehicle rotation rate along X (longitudinal). An IEEE
   * 754-compliant NaN value shall indicate an invalid or unsupported value,
   * e.g., when the vehicle does not support a particular axis.
   * @param pitch Vehicle rotation rate along Y (lateral). An IEEE 754-compliant
   * NaN value shall indicate an invalid or unsupported value, e.g., when the
   * vehicle does not support a particular axis.
   * @param yaw Vehicle rotation rate along Z (vertical). An IEEE 754-compliant
   * NaN value shall indicate an invalid or unsupported value, e.g., when the
   * vehicle does not support a particular axis.
   */
  AngularVelocity(float roll, float pitch, float yaw)
      : roll(roll), pitch(pitch), yaw(yaw) {}
};

// clang-format off
}  // namespace yoriito::types
// clang-format on

#endif  // SIGNAL_TYPES_STRUCT_ANGULARVELOCITY_H_
