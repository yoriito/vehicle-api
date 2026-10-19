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

#ifndef COMMON_DATABROKER_PRODUCER_INSPECT_DATA_H_
#define COMMON_DATABROKER_PRODUCER_INSPECT_DATA_H_

#include "databroker/base_inspect_data.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {
/**
 * @ingroup producer
 * @class ProducerInspectData
 * @brief Class representing inspection data for a DataBroker producer.
 */
class ProducerInspectData : public yoriito::databroker::BaseInspectData {
 public:
  using BaseInspectData::BaseInspectData;

  /**
   * @ingroup producer
   * @fn static ProducerInspectData CreateFromBuilder(Builder& builder)
   * @brief Creates a ProducerInspectData object from a Builder instance.
   * @deprecated -
   * @pre -
   * @param builder The Builder instance used to construct the object.
   * @retval ProducerInspectData object constructed from the builder.
   * @note -
   * @code -
   * @endcode -
   */
  static ProducerInspectData CreateFromBuilder(const Builder& builder) {
    BaseInspectData base = builder.Build();
    return ProducerInspectData(base);
  }

  /**
   * @ingroup producer
   * @fn explicit ProducerInspectData(const BaseInspectData& base)
   * @brief Constructs a ProducerInspectData from a BaseInspectData object.
   * @deprecated -
   * @pre -
   * @param base The BaseInspectData object to copy from.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerInspectData(const BaseInspectData& base)
      : BaseInspectData(base) {}
};
}  // namespace yoriito::databroker
#endif  // COMMON_DATABROKER_PRODUCER_INSPECT_DATA_H_
