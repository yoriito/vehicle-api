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

#ifndef SIGNAL_TYPES_STRUCT_ACCELERATION_H_
#define SIGNAL_TYPES_STRUCT_ACCELERATION_H_

// clang-format off
namespace yoriito::types {
// clang-format on

/**
 * @brief Spatial acceleration. Axis definitions according to ISO 8855.
 * @deprecated -
 */
struct Acceleration {
  /**
   * @brief Vehicle acceleration in X (longitudinal acceleration). An IEEE
   * 754-compliant NaN value shall indicate an invalid or unsupported value,
   * e.g., when the vehicle does not support a particular axis.
   */
  float longitudinal;
  /**
   * @brief Vehicle acceleration in Y (lateral acceleration). An IEEE
   * 754-compliant NaN value shall indicate an invalid or unsupported value,
   * e.g., when the vehicle does not support a particular axis.
   */
  float lateral;
  /**
   * @brief Vehicle acceleration in Z (vertical acceleration). An IEEE
   * 754-compliant NaN value shall indicate an invalid or unsupported value,
   * e.g., when the vehicle does not support a particular axis.
   */
  float vertical;

  /**
   * @brief Default constructor.
   */
  Acceleration() : longitudinal(0.0), lateral(0.0), vertical(0.0) {}

  /**
   * @brief Constructor with parameters.
   * @param longitudinal Vehicle acceleration in X (longitudinal acceleration).
   * An IEEE 754-compliant NaN value shall indicate an invalid or unsupported
   * value, e.g., when the vehicle does not support a particular axis.
   * @param lateral Vehicle acceleration in Y (lateral acceleration). An IEEE
   * 754-compliant NaN value shall indicate an invalid or unsupported value,
   * e.g., when the vehicle does not support a particular axis.
   * @param vertical Vehicle acceleration in Z (vertical acceleration). An IEEE
   * 754-compliant NaN value shall indicate an invalid or unsupported value,
   * e.g., when the vehicle does not support a particular axis.
   */
  Acceleration(float longitudinal, float lateral, float vertical)
      : longitudinal(longitudinal), lateral(lateral), vertical(vertical) {}
};

// clang-format off
}  // namespace yoriito::types
// clang-format on

#endif  // SIGNAL_TYPES_STRUCT_ACCELERATION_H_
