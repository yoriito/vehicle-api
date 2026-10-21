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

#ifndef COMMON_DATABROKER_PRODUCER_INSPECT_RESPONSE_H_
#define COMMON_DATABROKER_PRODUCER_INSPECT_RESPONSE_H_

#include <iostream>
#include <optional>
#include <string>
#include <utility>
#include <vector>

#include "databroker/producer_inspect_data.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {
/**
 * @ingroup producer
 * @class ProducerInspectResponse
 * @brief Response class for inspecting datapoint metadata in the DataBroker.
 */
class ProducerInspectResponse {
 public:
  ProducerInspectResponse() = delete;
  /**
   * @ingroup producer
   * @fn explicit ProducerInspectResponse(std::vector<ProducerInspectData>&&
   * datas)
   * @brief Constructs a ProducerInspectResponse with the given datapoint
   * metadata.
   * @deprecated -
   * @pre -
   * @param datas The vector of ProducerInspectData objects.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerInspectResponse(std::vector<ProducerInspectData>&& datas)
      : datas_(std::move(datas)) {}

  /**
   * @ingroup producer
   * @fn explicit ProducerInspectResponse(std::vector<ProducerInspectData>&&
   * datas, std::vector<std::shared_ptr<StructType>>&& struct_types)
   * @brief Constructs a ProducerInspectResponse with the given datapoint
   * metadata and struct types.
   * @deprecated -
   * @pre -
   * @param datas The vector of ProducerInspectData objects.
   * @param struct_types The vector of StructType objects.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerInspectResponse(
      std::vector<ProducerInspectData>&& datas,
      std::vector<std::shared_ptr<StructType>>&& struct_types)
      : datas_(std::move(datas)), struct_types_(std::move(struct_types)) {}

  /**
   * @ingroup producer
   * @fn const std::vector<ProducerInspectData>& GetDataPoints() const
   * @brief Gets the datapoint metadata contained in this response.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Reference to the vector of ProducerInspectData.
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<ProducerInspectData>& GetDataPoints() const {
    return datas_;
  }

  /**
   * @ingroup producer
   * @fn const std::vector<StructType>& GetStructTypes() const
   * @brief Gets the struct types contained in this response.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Reference to the vector of StructType.
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<std::shared_ptr<StructType>>& GetStructTypes() const {
    return struct_types_;
  }

 private:
  std::vector<ProducerInspectData> datas_;
  std::vector<std::shared_ptr<StructType>> struct_types_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_PRODUCER_INSPECT_RESPONSE_H_
