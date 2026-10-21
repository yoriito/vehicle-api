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

#ifndef COMMON_DATABROKER_DATABROKER_PRODUCER_H_
#define COMMON_DATABROKER_DATABROKER_PRODUCER_H_

#include <memory>
#include <string>

#include "databroker/producer_define_request.h"
#include "databroker/producer_delete_request.h"
#include "databroker/producer_get_datapoint.h"
#include "databroker/producer_get_request.h"
#include "databroker/producer_get_response.h"
#include "databroker/producer_inspect_data.h"
#include "databroker/producer_inspect_request.h"
#include "databroker/producer_inspect_response.h"
#include "databroker/producer_set_request.h"
#include "databroker/producer_subscribe_context.h"
#include "databroker/producer_subscribe_request.h"
#include "result.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup producer
 * @class DataBrokerProducer
 * @brief Interface for a DataBroker producer.
 */
class DataBrokerProducer {
 public:
  /**
   * @ingroup producer
   * @fn virtual Result<yoriito::databroker::ProducerGetResponse>
   * DataBrokerProducer::Get(const yoriito::databroker::ProducerGetRequest&
   * request)
   * @brief Get a datapoint from the DataBroker.
   * @deprecated -
   * @pre -
   * @param request The request specifying which datapoint to get.
   * @retval Result<ProducerGetResponse> Ok: response, Err: error
   * @note -
   * @code -
   * @endcode -
   */
  virtual Result<yoriito::databroker::ProducerGetResponse> Get(
      const yoriito::databroker::ProducerGetRequest& request) = 0;

  /**
   * @ingroup producer
   * @fn virtual Result<yoriito::databroker::ProducerInspectResponse>
   * DataBrokerProducer::Inspect(const
   * yoriito::databroker::ProducerInspectRequest& request)
   * @brief Inspect a datapoint in the DataBroker.
   * @deprecated -
   * @pre -
   * @param request The request specifying which datapoint to inspect.
   * @retval Result<ProducerInspectResponse> Ok: response, Err: error
   * @note -
   * @code -
   * @endcode -
   */
  virtual Result<yoriito::databroker::ProducerInspectResponse> Inspect(
      const yoriito::databroker::ProducerInspectRequest& request) = 0;

  /**
   * @ingroup producer
   * @fn virtual Result<void> DataBrokerProducer::Set(const
   * yoriito::databroker::ProducerSetRequest& data)
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
      const yoriito::databroker::ProducerSetRequest& data) = 0;

  /**
   * @ingroup producer
   * @fn virtual Result<std::unique_ptr<ProducerSubscribeContext>>
   * DataBrokerProducer::Subscribe(const
   * yoriito::databroker::ProducerSubscribeRequest& data)
   * @brief Subscribe to a datapoint in the DataBroker.
   * @deprecated -
   * @pre -
   * @param data The request specifying the datapoint to subscribe to.
   * @retval Result<std::unique_ptr<ProducerSubscribeContext>> Ok: subscription
   * context, Err: error
   * @note -
   * @code -
   * @endcode -
   */
  virtual Result<std::unique_ptr<ProducerSubscribeContext>> Subscribe(
      const yoriito::databroker::ProducerSubscribeRequest& data) = 0;

  /**
   * @ingroup producer
   * @fn virtual Result<void>
   * DataBrokerProducer::UnSubscribe(std::unique_ptr<ProducerSubscribeContext>
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
      std::unique_ptr<ProducerSubscribeContext> subscription_id) = 0;

  /**
   * @ingroup producer
   * @fn virtual Result<void> DataBrokerProducer::Define(const
   * yoriito::databroker::ProducerDefineRequest& data)
   * @brief Define a new datapoint in the DataBroker.
   * @deprecated -
   * @pre -
   * @param data The request containing the datapoint definition.
   * @retval Result<void> Ok: success, Err: error
   * @note -
   * @code -
   * @endcode -
   */
  virtual Result<void> Define(
      const yoriito::databroker::ProducerDefineRequest& data) = 0;

  /**
   * @ingroup producer
   * @fn virtual Result<void> DataBrokerProducer::Delete(const
   * yoriito::databroker::ProducerDeleteRequest& data)
   * @brief Delete a datapoint in the DataBroker.
   * @deprecated -
   * @pre -
   * @param data The request containing the datapoint to delete.
   * @retval Result<void> Ok: success, Err: error
   * @note -
   * @code -
   * @endcode -
   */
  virtual Result<void> Delete(
      const yoriito::databroker::ProducerDeleteRequest& data) = 0;
};
}  // namespace yoriito::databroker
#endif  // COMMON_DATABROKER_DATABROKER_PRODUCER_H_
