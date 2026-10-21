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

#ifndef COMMON_DATABROKER_DATABROKER_CONSUMER_FACTORY_H_
#define COMMON_DATABROKER_DATABROKER_CONSUMER_FACTORY_H_

#include "databroker/databroker_consumer.h"

/** 
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup consumer
 * @class DataBrokerConsumerFactory
 * @brief Factory class to obtain instances of DataBrokerConsumer.
 */
class DataBrokerConsumerFactory {
 public:
  /**
   * @ingroup consumer
   * @fn static DataBrokerConsumer* DataBrokerConsumerFactory::GetInstance()
   * @brief Get the singleton instance of DataBrokerConsumer.
   * @deprecated -
   * @pre -
   * @param -
   * @retval DataBrokerConsumer* Pointer to the consumer instance
   * @note -
   * @code -
   * @endcode -
   */
  static DataBrokerConsumer* GetInstance();
};
}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_DATABROKER_CONSUMER_FACTORY_H_
