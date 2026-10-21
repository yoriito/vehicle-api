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

#ifndef SIGNAL_TYPES_STRUCT_POSE_H_
#define SIGNAL_TYPES_STRUCT_POSE_H_

// clang-format off
namespace yoriito::types {
// clang-format on

/**
 * @brief The current position of the object reference point on vehicle axis
 * according to ISO 23150:2023.
 * @deprecated -
 */
struct Pose {
  /**
   * @brief Longitudinal position of object reference point measured on the
   * X-axis of the vehicle rear-axle coordinate system as defined by ISO
   * 23150:2023. The object reference point refers to a representative point of
   * the object. Positive values = forward of (first) rear- axle. Negative
   * values = backward of (first) rear-axle.
   */
  int16_t x;
  /**
   * @brief Lateral position of object reference point measured on the Y-axis of
   * the vehicle rear-axle coordinate system as defined by ISO 23150:2023. The
   * object reference point refers to a representative point of the object.
   * Positive values = left of rear-axle center. Negative values = right of
   * rear-axle center.
   */
  int16_t y;
  /**
   * @brief Height position of object reference point measured on the Z-axis of
   * the vehicle rear-axle coordinate system as defined by ISO 23150:2023. The
   * object reference point refers to a representative point of the object.
   * Positive values = above center of rear-axle reference point. Negative
   * values = below center of rear-axle reference point.
   */
  int16_t z;
  /**
   * @brief Object yaw angle, measured from the vehicle sprung mass X-axis as
   * defined by ISO 23150:2023 to the object X-axis, around the vehicle Z-axis
   * (right-hand rule). 0 = Object in nominal orientation. Positive values =
   * Object rotated left. Negative values = Object rotated right.
   */
  float yaw;
  /**
   * @brief Object pitch angle, measured as angle from vehicle sprung mass
   * XY-plane as defined by ISO 23150:2023 to the object X-axis. 0 = Object in
   * nominal orientation. Positive values = Object tilted up. Negative values =
   * Object tilted down.
   */
  float pitch;
  /**
   * @brief Object roll angle about the object X-axis (right-hand rule). 0 =
   * Object in nominal orientation. Positive values = Object tilted to the
   * right. Negative values = Object tilted to the left.
   */
  float roll;

  /**
   * @brief Default constructor.
   */
  Pose() : x(0), y(0), z(0), yaw(0.0), pitch(0.0), roll(0.0) {}

  /**
   * @brief Constructor with parameters.
   * @param x Longitudinal position of object reference point measured on the
   * X-axis of the vehicle rear-axle coordinate system as defined by ISO
   * 23150:2023. The object reference point refers to a representative point of
   * the object. Positive values = forward of (first) rear- axle. Negative
   * values = backward of (first) rear-axle.
   * @param y Lateral position of object reference point measured on the Y-axis
   * of the vehicle rear-axle coordinate system as defined by ISO 23150:2023.
   * The object reference point refers to a representative point of the object.
   * Positive values = left of rear-axle center. Negative values = right of
   * rear-axle center.
   * @param z Height position of object reference point measured on the Z-axis
   * of the vehicle rear-axle coordinate system as defined by ISO 23150:2023.
   * The object reference point refers to a representative point of the object.
   * Positive values = above center of rear-axle reference point. Negative
   * values = below center of rear-axle reference point.
   * @param yaw Object yaw angle, measured from the vehicle sprung mass X-axis
   * as defined by ISO 23150:2023 to the object X-axis, around the vehicle
   * Z-axis (right-hand rule). 0 = Object in nominal orientation. Positive
   * values = Object rotated left. Negative values = Object rotated right.
   * @param pitch Object pitch angle, measured as angle from vehicle sprung mass
   * XY-plane as defined by ISO 23150:2023 to the object X-axis. 0 = Object in
   * nominal orientation. Positive values = Object tilted up. Negative values =
   * Object tilted down.
   * @param roll Object roll angle about the object X-axis (right-hand rule). 0
   * = Object in nominal orientation. Positive values = Object tilted to the
   * right. Negative values = Object tilted to the left.
   */
  Pose(int16_t x, int16_t y, int16_t z, float yaw, float pitch, float roll)
      : x(x), y(y), z(z), yaw(yaw), pitch(pitch), roll(roll) {}
};

// clang-format off
}  // namespace yoriito::types
// clang-format on

#endif  // SIGNAL_TYPES_STRUCT_POSE_H_
