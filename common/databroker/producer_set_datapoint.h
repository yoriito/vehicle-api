/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright 2026 JASPAR
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef COMMON_DATABROKER_PRODUCER_SET_DATAPOINT_H_
#define COMMON_DATABROKER_PRODUCER_SET_DATAPOINT_H_

#include <optional>
#include <string>

#include "databroker/base_set_datapoint.h"
#include "databroker_type.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {
/**
 * @ingroup producer
 * @class ProducerSetDataPoint
 * @brief Class representing a datapoint to be set by a DataBroker producer.
 */
class ProducerSetDataPoint : public BaseSetDataPoint {
 public:
  ProducerSetDataPoint() = delete;

  /**
   * @ingroup producer
   * @fn ProducerSetDataPoint(const std::string& path, const ValueType& data,
   * const bool is_available_sensor, const bool is_available_actuator, const
   * std::optional<int64_t>& produced_timestamp = std::nullopt)
   * @brief Constructs a ProducerSetDataPoint with the specified parameters.
   * @deprecated -
   * @pre -
   * @param path The datapoint path as a string.
   * @param data The value to be set for the datapoint.
   * @param is_available_sensor Availability status for the sensor.
   * @param is_available_actuator Availability status for the actuator.
   * @param produced_timestamp Optional produced timestamp (int64_t).
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ProducerSetDataPoint(
      const std::string& path, const ValueType& data,
      const bool is_available_sensor, const bool is_available_actuator,
      const std::optional<int64_t>& produced_timestamp = std::nullopt)
      : BaseSetDataPoint(path, data),
        is_available_sensor_(is_available_sensor),
        is_available_actuator_(is_available_actuator),
        produced_timestamp_(produced_timestamp) {}

  /**
   * @ingroup producer
   * @fn bool IsAvailableSensor() const
   * @brief Checks if the datapoint is available as a sensor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval true if available as a sensor; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  bool IsAvailableSensor() const { return is_available_sensor_; }

  /**
   * @ingroup producer
   * @fn bool IsAvailableActuator() const
   * @brief Checks if the datapoint is available as an actuator.
   * @deprecated -
   * @pre -
   * @param -
   * @retval true if available as an actuator; false otherwise.
   * @note -
   * @code -
   * @endcode -
   */
  bool IsAvailableActuator() const { return is_available_actuator_; }

  /**
   * @ingroup producer
   * @fn const std::optional<int64_t>& GetProducedTimestamp() const
   * @brief Gets the produced timestamp for this datapoint, if any.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Reference to the optional produced timestamp (int64_t).
   * @note -
   * @code -
   * @endcode -
   */
  const std::optional<int64_t>& GetProducedTimestamp() const {
    return produced_timestamp_;
  }

 private:
  bool is_available_sensor_;
  bool is_available_actuator_;
  std::optional<int64_t> produced_timestamp_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_PRODUCER_SET_DATAPOINT_H_
