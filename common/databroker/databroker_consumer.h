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

#ifndef COMMON_DATABROKER_DATABROKER_CONSUMER_H_
#define COMMON_DATABROKER_DATABROKER_CONSUMER_H_

#include <memory>
#include <string>

#include "databroker/consumer_get_datapoint.h"
#include "databroker/consumer_get_request.h"
#include "databroker/consumer_get_response.h"
#include "databroker/consumer_inspect_request.h"
#include "databroker/consumer_inspect_response.h"
#include "databroker/consumer_set_request.h"
#include "databroker/consumer_subscribe_context.h"
#include "databroker/consumer_subscribe_request.h"
#include "result.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {
/**
 * @ingroup consumer
 * @class DataBrokerConsumer
 * @brief Interface for a DataBroker consumer.
 */
class DataBrokerConsumer {
 public:
  /**
   * @ingroup consumer
   * @fn virtual Result<yoriito::databroker::ConsumerGetResponse>
   * DataBrokerConsumer::Get(const yoriito::databroker::ConsumerGetRequest&
   * request)
   * @brief Get a datapoint from the DataBroker.
   * @deprecated -
   * @pre -
   * @param request The request specifying which datapoint to get.
   * @retval Result<ConsumerGetResponse> Ok: response, Err: error
   * @note -
   * @code -
   * @endcode -
   */
  virtual Result<yoriito::databroker::ConsumerGetResponse> Get(
      const yoriito::databroker::ConsumerGetRequest& request) = 0;

  /**
   * @ingroup consumer
   * @fn virtual Result<yoriito::databroker::ConsumerInspectResponse>
   * DataBrokerConsumer::Inspect(const
   * yoriito::databroker::ConsumerInspectRequest& request)
   * @brief Inspect a datapoint in the DataBroker.
   * @deprecated -
   * @pre -
   * @param request The request specifying which datapoint to inspect.
   * @retval Result<ConsumerInspectResponse> Ok: response, Err: error
   * @note -
   * @code -
   * @endcode -
   */
  virtual Result<yoriito::databroker::ConsumerInspectResponse> Inspect(
      const yoriito::databroker::ConsumerInspectRequest& request) = 0;

  /**
   * @ingroup consumer
   * @fn virtual Result<void> DataBrokerConsumer::Set(const
   * yoriito::databroker::ConsumerSetRequest& data)
   * @brief Set a datapoint value in the DataBroker.
   * @deprecated -
   * @pre -
   * @param data The request containing the datapoint and value to set.
   * @retval Result<void> Ok: success, Err: error
   * @note -
   * @code -
   * @endcode -
   */
  virtual Result<void> Set(
      const yoriito::databroker::ConsumerSetRequest& data) = 0;

  /**
   * @ingroup consumer
   * @fn virtual Result<std::unique_ptr<ConsumerSubscribeContext>>
   * DataBrokerConsumer::Subscribe(const
   * yoriito::databroker::ConsumerSubscribeRequest& data)
   * @brief Subscribe to a datapoint in the DataBroker.
   * @deprecated -
   * @pre -
   * @param data The request specifying the datapoint to subscribe to.
   * @retval Result<std::unique_ptr<ConsumerSubscribeContext>> Ok: subscription
   * context, Err: error
   * @note -
   * @code -
   * @endcode -
   */
  virtual Result<std::unique_ptr<ConsumerSubscribeContext>> Subscribe(
      const yoriito::databroker::ConsumerSubscribeRequest& data) = 0;

  /**
   * @ingroup consumer
   * @fn virtual Result<void>
   * DataBrokerConsumer::UnSubscribe(std::unique_ptr<ConsumerSubscribeContext>
   * subscription_id)
   * @brief Unsubscribe from a datapoint in the DataBroker.
   * @deprecated -
   * @pre -
   * @param subscription_id The subscription context to unsubscribe.
   * @retval Result<void> Ok: success, Err: error
   * @note -
   * @code -
   * @endcode -
   */
  virtual Result<void> UnSubscribe(
      std::unique_ptr<ConsumerSubscribeContext> subscription_id) = 0;
};

}  // namespace yoriito::databroker
#endif  // COMMON_DATABROKER_DATABROKER_CONSUMER_H_
