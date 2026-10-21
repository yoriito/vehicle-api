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

#ifndef SIGNAL_TYPES_STRUCT_ELECTRICITY_H_
#define SIGNAL_TYPES_STRUCT_ELECTRICITY_H_

// clang-format off
namespace yoriito::types {
// clang-format on

/**
 * @brief Electrical conditions of the circuits, including voltage and current.
 * @deprecated -
 */
struct Electricity {
  /**
   * @brief Voltage of the circuits.
   */
  float voltage;
  /**
   * @brief Current flowing in/out of circuits. Positive = Current flowing in to
   * circuits. Negative = Current flowing out of circuits.
   */
  float current;

  /**
   * @brief Default constructor.
   */
  Electricity() : voltage(0.0), current(0.0) {}

  /**
   * @brief Constructor with parameters.
   * @param voltage Voltage of the circuits.
   * @param current Current flowing in/out of circuits. Positive = Current
   * flowing in to circuits. Negative = Current flowing out of circuits.
   */
  Electricity(float voltage, float current)
      : voltage(voltage), current(current) {}
};

// clang-format off
}  // namespace yoriito::types
// clang-format on

#endif  // SIGNAL_TYPES_STRUCT_ELECTRICITY_H_
