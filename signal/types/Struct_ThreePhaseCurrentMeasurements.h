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

#ifndef SIGNAL_TYPES_STRUCT_THREEPHASECURRENTMEASUREMENTS_H_
#define SIGNAL_TYPES_STRUCT_THREEPHASECURRENTMEASUREMENTS_H_

// clang-format off
namespace yoriito::types {
// clang-format on

/**
 * @brief AC current (rms) measurements for Phase 1, Phase 2, and Phase 3.
 * @deprecated -
 */
struct ThreePhaseCurrentMeasurements {
  /**
   * @brief AC current (rms) for Phase 1.
   */
  float phase1;
  /**
   * @brief AC current (rms) for Phase 2.
   */
  float phase2;
  /**
   * @brief AC current (rms) for Phase 3.
   */
  float phase3;

  /**
   * @brief Default constructor.
   */
  ThreePhaseCurrentMeasurements() : phase1(0.0), phase2(0.0), phase3(0.0) {}

  /**
   * @brief Constructor with parameters.
   * @param phase1 AC current (rms) for Phase 1.
   * @param phase2 AC current (rms) for Phase 2.
   * @param phase3 AC current (rms) for Phase 3.
   */
  ThreePhaseCurrentMeasurements(float phase1, float phase2, float phase3)
      : phase1(phase1), phase2(phase2), phase3(phase3) {}
};

// clang-format off
}  // namespace yoriito::types
// clang-format on

#endif  // SIGNAL_TYPES_STRUCT_THREEPHASECURRENTMEASUREMENTS_H_
