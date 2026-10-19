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

#ifndef SIGNAL_TYPES_STRUCT_ROADFRICTIONRANGE_H_
#define SIGNAL_TYPES_STRUCT_ROADFRICTIONRANGE_H_

// clang-format off
namespace yoriito::types {
// clang-format on

/**
 * @brief Road friction values reported by the ESC system.
 * @deprecated -
 */
struct RoadFrictionRange {
  /**
   * @brief Most probable road friction, as calculated by the ESC system. Exact
   * meaning of most probable is implementation specific. 0 = no friction, 100 =
   * maximum friction.
   */
  float most_probable;
  /**
   * @brief Lower bound road friction, as calculated by the ESC system. 5%
   * possibility that road friction is below this value. 0 = no friction, 100 =
   * maximum friction.
   */
  float lower_bound;
  /**
   * @brief Upper bound road friction, as calculated by the ESC system. 95%
   * possibility that road friction is below this value. 0 = no friction, 100 =
   * maximum friction.
   */
  float upper_bound;

  /**
   * @brief Default constructor.
   */
  RoadFrictionRange()
      : most_probable(0.0), lower_bound(0.0), upper_bound(0.0) {}

  /**
   * @brief Constructor with parameters.
   * @param most_probable Most probable road friction, as calculated by the ESC
   * system. Exact meaning of most probable is implementation specific. 0 = no
   * friction, 100 = maximum friction.
   * @param lower_bound Lower bound road friction, as calculated by the ESC
   * system. 5% possibility that road friction is below this value. 0 = no
   * friction, 100 = maximum friction.
   * @param upper_bound Upper bound road friction, as calculated by the ESC
   * system. 95% possibility that road friction is below this value. 0 = no
   * friction, 100 = maximum friction.
   */
  RoadFrictionRange(float most_probable, float lower_bound, float upper_bound)
      : most_probable(most_probable),
        lower_bound(lower_bound),
        upper_bound(upper_bound) {}
};

// clang-format off
}  // namespace yoriito::types
// clang-format on

#endif  // SIGNAL_TYPES_STRUCT_ROADFRICTIONRANGE_H_
