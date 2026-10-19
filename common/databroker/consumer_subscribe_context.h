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

#ifndef COMMON_DATABROKER_CONSUMER_SUBSCRIBE_CONTEXT_H_
#define COMMON_DATABROKER_CONSUMER_SUBSCRIBE_CONTEXT_H_

#include <string>

#include "databroker/consumer_get_response.h"
#include "result.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup consumer
 * @class ConsumerSubscribeContext
 * @brief Interface for managing subscription context for a DataBroker consumer.
 */
class ConsumerSubscribeContext {
 public:
  /**
   * @ingroup consumer
   * @fn virtual Result<ConsumerGetResponse>
   * ConsumerSubscribeContext::Messages()
   * @brief Retrieve subscription messages from the DataBroker.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Result<ConsumerGetResponse> Ok: response, Err: error
   * @note -
   * @code -
   * @endcode -
   */
  virtual Result<ConsumerGetResponse> Messages() = 0;
  /**
   * @ingroup consumer
   * @fn ConsumerSubscribeContext::ConsumerSubscribeContext()
   * @brief Default constructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ConsumerSubscribeContext() = default;
  /**
   * @ingroup consumer
   * @fn ConsumerSubscribeContext::~ConsumerSubscribeContext()
   * @brief Virtual destructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  virtual ~ConsumerSubscribeContext() = default;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_CONSUMER_SUBSCRIBE_CONTEXT_H_
