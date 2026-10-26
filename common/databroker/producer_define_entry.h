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

#ifndef COMMON_DATABROKER_PRODUCER_DEFINE_ENTRY_H_
#define COMMON_DATABROKER_PRODUCER_DEFINE_ENTRY_H_
#include <string>
#include <vector>

#include "databroker/base_inspect_data.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup producer
 * @class ProducerDefineEntry
 * @brief Class representing a datapoint definition entry for a DataBroker
 * producer.
 */
class ProducerDefineEntry : public yoriito::databroker::BaseInspectData {
 public:
  /**
   * @ingroup producer
   * @fn ProducerDefineEntry::ProducerDefineEntry(...)
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
   * @ingroup producer
   * @fn static ProducerDefineEntry
   * ProducerDefineEntry::CreateFromBuilder(Builder& builder)
   * @brief Create a ProducerDefineEntry object from a Builder.
   * @deprecated -
   * @pre -
   * @param builder Builder object to construct BaseInspectData.
   * @retval ProducerDefineEntry Created object
   * @note -
   * @code -
   * @endcode -
   */
  static ProducerDefineEntry CreateFromBuilder(const Builder& builder) {
    BaseInspectData base = builder.Build();
    return ProducerDefineEntry(base);
  }

  /**
   * @ingroup producer
   * @fn ProducerDefineEntry::ProducerDefineEntry(const BaseInspectData& base)
   * @brief Construct a ProducerDefineEntry object from BaseInspectData.
   * @deprecated -
   * @pre -
   * @param base BaseInspectData object.
   * @retval ProducerDefineEntry Created object
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerDefineEntry(const BaseInspectData& base)
      : BaseInspectData(base) {}

  /**
   * @ingroup producer
   * @fn bool operator==(const ProducerDefineEntry& lhs, const
   * ProducerDefineEntry& rhs)
   * @brief Compare two ProducerDefineEntry objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs Left-hand side object.
   * @param rhs Right-hand side object.
   * @retval true Objects are equal
   * @retval false Objects are not equal
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const ProducerDefineEntry& lhs,
                         const ProducerDefineEntry& rhs) {
    // Compare the base class part
    const BaseInspectData& lhs_base = lhs;
    const BaseInspectData& rhs_base = rhs;
    return lhs_base == rhs_base;
  }
};

}  // namespace yoriito::databroker
#endif  // COMMON_DATABROKER_PRODUCER_DEFINE_ENTRY_H_
