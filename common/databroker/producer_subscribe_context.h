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

#ifndef COMMON_DATABROKER_PRODUCER_SUBSCRIBE_CONTEXT_H_
#define COMMON_DATABROKER_PRODUCER_SUBSCRIBE_CONTEXT_H_

#include <string>

#include "databroker/producer_get_response.h"
#include "result.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */

namespace yoriito::databroker {

/**
 * @ingroup producer
 * @class ProducerSubscribeContext
 * @brief Interface for managing subscription context for a DataBroker producer.
 */
class ProducerSubscribeContext {
 public:
  /**
   * @ingroup producer
   * @fn virtual Result<ProducerGetResponse> Messages()
   * @brief Retrieves messages for the current subscription context.
   * @deprecated -
   * @pre -
   * @param -
   * @retval Result containing ProducerGetResponse on success, or error
   * information on failure.
   * @note -
   * @code -
   * @endcode -
   */
  virtual Result<ProducerGetResponse> Messages() = 0;

  /**
   * @ingroup producer
   * @fn virtual ~ProducerSubscribeContext()
   * @brief Virtual destructor for ProducerSubscribeContext.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  virtual ~ProducerSubscribeContext() = default;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_PRODUCER_SUBSCRIBE_CONTEXT_H_
