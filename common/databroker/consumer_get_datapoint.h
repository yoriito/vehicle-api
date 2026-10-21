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

#ifndef COMMON_DATABROKER_CONSUMER_GET_DATAPOINT_H_
#define COMMON_DATABROKER_CONSUMER_GET_DATAPOINT_H_

#include <optional>
#include <string>
#include <vector>
//
#include "databroker_type.h"
#include "databroker/base_get_datapoint.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup consumer
 * @class ConsumerGetDataPoint
 * @brief Class representing a datapoint retrieved by a DataBroker consumer.
 */
class ConsumerGetDataPoint : public BaseGetDataPoint {
 public:
  /**
   * @ingroup consumer
   * @fn ConsumerGetDataPoint::ConsumerGetDataPoint(const std::string& path,
   * const ValueType& data, bool is_available_sensor, bool
   * is_available_actuator, int64_t stored_timestamp, const
   * std::optional<int64_t>& produced_timestamp)
   * @brief Construct a ConsumerGetDataPoint object.
   * @deprecated -
   * @pre -
   * @param path The datapoint path.
   * @param data The datapoint value.
   * @param is_available_sensor Availability as sensor.
   * @param is_available_actuator Availability as actuator.
   * @param stored_timestamp Timestamp when stored.
   * @param produced_timestamp Optional timestamp when produced.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ConsumerGetDataPoint(
    const std::string& path, const ValueType& data, bool is_available_sensor,
    bool is_available_actuator, int64_t stored_timestamp,
    const std::optional<int64_t>& produced_timestamp = std::nullopt)
      : BaseGetDataPoint(path, data),
        is_available_sensor_(is_available_sensor),
        is_available_actuator_(is_available_actuator),
        stored_timestamp_(stored_timestamp),
        produced_timestamp_(produced_timestamp) {}

  /**
   * @ingroup consumer
   * @fn bool ConsumerGetDataPoint::IsAvailableSensor() const
   * @brief Check if the datapoint is available as a sensor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval true Available as sensor
   * @retval false Not available as sensor
   * @note -
   * @code -
   * @endcode -
   */
  bool IsAvailableSensor() const { return is_available_sensor_; }

  /**
   * @ingroup consumer
   * @fn bool ConsumerGetDataPoint::IsAvailableActuator() const
   * @brief Check if the datapoint is available as an actuator.
   * @deprecated -
   * @pre -
   * @param -
   * @retval true Available as actuator
   * @retval false Not available as actuator
   * @note -
   * @code -
   * @endcode -
   */
  bool IsAvailableActuator() const { return is_available_actuator_; }

  /**
   * @ingroup consumer
   * @fn int64_t ConsumerGetDataPoint::GetStoredTimestamp() const
   * @brief Get the timestamp when the datapoint was stored.
   * @deprecated -
   * @pre -
   * @param -
   * @retval int64_t Stored timestamp
   * @note -
   * @code -
   * @endcode -
   */
  int64_t GetStoredTimestamp() const { return stored_timestamp_; }
  /**
   * @ingroup consumer
   * @fn const std::optional<int64_t>&
   * ConsumerGetDataPoint::GetProducedTimestamp() const
   * @brief Get the optional timestamp when the datapoint was produced.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::optional<int64_t> Produced timestamp or nullopt
   * @note -
   * @code -
   * @endcode -
   */
  const std::optional<int64_t>& GetProducedTimestamp() const& {
    return produced_timestamp_;
  }
  std::optional<int64_t> GetProducedTimestamp() const&& {
    return produced_timestamp_;
  }

 private:
  bool is_available_sensor_;
  bool is_available_actuator_;
  int64_t stored_timestamp_;
  std::optional<int64_t> produced_timestamp_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_CONSUMER_GET_DATAPOINT_H_
