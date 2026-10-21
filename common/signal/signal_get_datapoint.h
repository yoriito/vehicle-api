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

#ifndef COMMON_SIGNAL_SIGNAL_GET_DATAPOINT_H_
#define COMMON_SIGNAL_SIGNAL_GET_DATAPOINT_H_

#include <optional>
#include <string>
#include <vector>

#include "databroker/base_get_datapoint.h"
#include "databroker/consumer_get_datapoint.h"

/**
 * @ingroup common
 * @namespace yoriito::signal
 * @brief Namespace for Signal API common interfaces and types.
 */
namespace yoriito::signal {

/**
 * @ingroup signal_api
 * @class SignalGetDataPoint
 * @brief Class representing a datapoint retrieved by a Signal API.
 */
template <typename T>
class SignalGetDataPoint {
 public:
  /**
   * @ingroup signal_api
   * @fn SignalGetDataPoint::SignalGetDataPoint(const
   * yoriito::databroker::ConsumerGetDataPoint& dp)
   * @brief Construct a SignalGetDataPoint object.
   * @deprecated -
   * @pre -
   * @param dp The ConsumerGetDataPoint object.
   * @retval SignalGetDataPoint<T> The constructed SignalGetDataPoint object.
   * @note -
   * @code -
   * @endcode -
   */
  explicit SignalGetDataPoint(
    const yoriito::databroker::ConsumerGetDataPoint& dp)
      : path_(dp.GetPath()),
        data_(std::get<T>(dp.GetData())),
        is_available_sensor_(dp.IsAvailableSensor()),
        is_available_actuator_(dp.IsAvailableActuator()),
        stored_timestamp_(dp.GetStoredTimestamp()),
        produced_timestamp_(dp.GetProducedTimestamp()) {}

  /**
   * @ingroup signal_api
   * @fn SignalGetDataPoint::SignalGetDataPoint(const std::string path,
   * T&& data, bool is_available_sensor, bool
   * is_available_actuator, int64_t stored_timestamp,
   * std::optional<int64_t> produced_timestamp)
   * @brief Construct a SignalGetDataPoint object.
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
  SignalGetDataPoint(const std::string path, T&& data, bool is_available_sensor,
                     bool is_available_actuator, int64_t stored_timestamp,
                     std::optional<int64_t> produced_timestamp = std::nullopt)
      : path_(std::move(path)),
        data_(std::move(data)),
        is_available_sensor_(is_available_sensor),
        is_available_actuator_(is_available_actuator),
        stored_timestamp_(stored_timestamp),
        produced_timestamp_(std::move(produced_timestamp)) {}

  /**
   * @ingroup signal_api
   * @fn SignalGetDataPoint::SignalGetDataPoint(const std::string& path,
   * const T& data, bool is_available_sensor, bool
   * is_available_actuator, int64_t stored_timestamp, const
   * std::optional<int64_t>& produced_timestamp)
   * @brief Construct a SignalGetDataPoint object.
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
  SignalGetDataPoint(
    const std::string& path, const T& data, bool is_available_sensor,
    bool is_available_actuator, int64_t stored_timestamp,
    const std::optional<int64_t>& produced_timestamp = std::nullopt)
      : path_(path),
        data_(data),
        is_available_sensor_(is_available_sensor),
        is_available_actuator_(is_available_actuator),
        stored_timestamp_(stored_timestamp),
        produced_timestamp_(produced_timestamp) {}

  /**
   * @ingroup signal_api
   * @fn SignalGetDataPoint::SignalGetDataPoint()
   * @brief Deleted default constructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  SignalGetDataPoint() = delete;

  /**
   * @ingroup signal_api
   * @fn const std::string& SignalGetDataPoint::GetPath() const
   * @brief Get the datapoint path.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::string Datapoint path
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetPath() const { return path_; }

  /**
   * @ingroup signal_api
   * @fn const T& SignalGetDataPoint::GetData() const
   * @brief Get the datapoint value.
   * @deprecated -
   * @pre -
   * @param -
   * @retval T Datapoint value
   * @note -
   * @code -
   * @endcode -
   */
  const T& GetData() const { return data_; }

  /**
   * @ingroup signal_api
   * @fn bool SignalGetDataPoint::IsAvailableSensor() const
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
   * @ingroup signal_api
   * @fn bool SignalGetDataPoint::IsAvailableActuator() const
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
   * @ingroup signal_api
   * @fn int64_t SignalGetDataPoint::GetStoredTimestamp() const
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
   * @ingroup signal_api
   * @fn const std::optional<int64_t>&
   * SignalGetDataPoint::GetProducedTimestamp() const
   * @brief Get the optional timestamp when the datapoint was produced.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::optional<int64_t> Produced timestamp or nullopt
   * @note -
   * @code -
   * @endcode -
   */
  const std::optional<int64_t>& GetProducedTimestamp() const {
    return produced_timestamp_;
  }

 private:
  std::string path_;
  T data_;
  bool is_available_sensor_;
  bool is_available_actuator_;
  int64_t stored_timestamp_;
  std::optional<int64_t> produced_timestamp_;
};

}  // namespace yoriito::signal

#endif  // COMMON_SIGNAL_SIGNAL_GET_DATAPOINT_H_
