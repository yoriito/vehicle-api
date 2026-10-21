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

#ifndef COMMON_DATABROKER_CONSUMER_INSPECT_DATA_H_
#define COMMON_DATABROKER_CONSUMER_INSPECT_DATA_H_

#include "databroker/base_inspect_data.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup consumer
 * @class ConsumerInspectData
 * @brief Class representing inspection data for a DataBroker consumer.
 */
class ConsumerInspectData : public yoriito::databroker::BaseInspectData {
 public:
  /**
   * @ingroup consumer
   * @fn ConsumerInspectData::ConsumerInspectData(...)
   * @brief Inherit constructors from BaseInspectData.
   * @deprecated -
   * @pre -
   * @param ... Parameters as defined in BaseInspectData.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  using BaseInspectData::BaseInspectData;

  /**
   * @ingroup consumer
   * @fn static ConsumerInspectData
   * ConsumerInspectData::CreateFromBuilder(Builder& builder)
   * @brief Create a ConsumerInspectData object from a Builder.
   * @deprecated -
   * @pre -
   * @param builder Builder object to construct BaseInspectData.
   * @retval ConsumerInspectData Created object
   * @note -
   * @code -
   * @endcode -
   */
  static ConsumerInspectData CreateFromBuilder(const Builder& builder) {
    BaseInspectData base = builder.Build();
    return ConsumerInspectData(base);
  }

  /**
   * @ingroup consumer
   * @fn ConsumerInspectData::ConsumerInspectData(const BaseInspectData& base)
   * @brief Construct a ConsumerInspectData object from BaseInspectData.
   * @deprecated -
   * @pre -
   * @param base BaseInspectData object.
   * @retval ConsumerInspectData Created object
   * @note -
   * @code -
   * @endcode -
   */
  explicit ConsumerInspectData(const BaseInspectData& base)
      : BaseInspectData(base) {}
};
}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_CONSUMER_INSPECT_DATA_H_
