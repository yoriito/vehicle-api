// SPDX-License-Identifier: Apache-2.0
//
// Copyright 2026 JASPAR
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// mock_databroker_consumer.h
// Lightweight AFL++-compatible mock — no gMock dependency.
// Callers set get_value / inspect_data before each AFL++ loop iteration.

#pragma once

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "databroker/base_inspect_data.h"
#include "databroker/consumer_get_datapoint.h"
#include "databroker/consumer_get_request.h"
#include "databroker/consumer_get_response.h"
#include "databroker/consumer_inspect_data.h"
#include "databroker/consumer_inspect_request.h"
#include "databroker/consumer_inspect_response.h"
#include "databroker/consumer_set_request.h"
#include "databroker/consumer_subscribe_context.h"
#include "databroker/consumer_subscribe_request.h"
#include "databroker/databroker_consumer.h"
#include "databroker/databroker_consumer_factory.h"
#include "error.h"
#include "result.h"

namespace fuzz_mock {

  class MockDataBrokerConsumer
      : public yoriito::databroker::DataBrokerConsumer {
    public:
      yoriito::ValueType get_value{std::monostate{}};
      yoriito::databroker::ConsumerInspectData* inspect_data{nullptr};
      yoriito::StructData* struct_get_data{nullptr};

      void Reset() {
        get_value = std::monostate{};
        inspect_data = nullptr;
        struct_get_data = nullptr;
      }

      yoriito::Result<yoriito::databroker::ConsumerGetResponse> Get(
        const yoriito::databroker::ConsumerGetRequest& request) override {
        if (struct_get_data != nullptr) {
          yoriito::ValueType struct_val =
            std::make_unique<yoriito::StructData>(*struct_get_data);
          auto dp = yoriito::databroker::ConsumerGetDataPoint(
            "path", std::move(struct_val), /*is_available_sensor=*/true,
            /*is_available_actuator=*/true, /*stored_timestamp=*/0);
          std::vector<yoriito::databroker::ConsumerGetDataPoint> dps;
          dps.push_back(std::move(dp));
          return yoriito::Result<yoriito::databroker::ConsumerGetResponse>::Ok(
            yoriito::databroker::ConsumerGetResponse(std::move(dps)));
        }
        auto dp = yoriito::databroker::ConsumerGetDataPoint(
          "path", get_value, /*is_available_sensor=*/true,
          /*is_available_actuator=*/true, /*stored_timestamp=*/0);
        std::vector<yoriito::databroker::ConsumerGetDataPoint> dps{dp};
        return yoriito::Result<yoriito::databroker::ConsumerGetResponse>::Ok(
          yoriito::databroker::ConsumerGetResponse(std::move(dps)));
      }

      yoriito::Result<yoriito::databroker::ConsumerInspectResponse> Inspect(
        const yoriito::databroker::ConsumerInspectRequest& request)
        override {
        if (inspect_data == nullptr) {
          return yoriito::Result<yoriito::databroker::ConsumerInspectResponse>::
            Err(std::make_unique<yoriito::CommonError>(
              yoriito::ErrorCode::ERROR_NODATA));
        }
        std::vector<yoriito::databroker::ConsumerInspectData> datas{
          *inspect_data};
        return yoriito::Result<yoriito::databroker::ConsumerInspectResponse>::
          Ok(yoriito::databroker::ConsumerInspectResponse(std::move(datas)));
      }

      yoriito::Result<void> Set(
        const yoriito::databroker::ConsumerSetRequest& request) override {
        return yoriito::Result<void>::Ok();
      }

      yoriito::Result<
        std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>>
      Subscribe(const yoriito::databroker::ConsumerSubscribeRequest& request)
        override {
        return yoriito::Result<
          std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>>::
          Err(std::make_unique<yoriito::CommonError>(
            yoriito::ErrorCode::ERROR_UNKNOWN));
      }

      yoriito::Result<void> UnSubscribe(
        std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>
        subscription_id) override {
        return yoriito::Result<void>::Ok();
      }
  };

  // Singleton accessor — replaces DataBrokerConsumerFactory::GetInstance()
  inline MockDataBrokerConsumer& GetMock() {
    static MockDataBrokerConsumer instance;
    return instance;
  }

}  // namespace fuzz_mock

// DataBrokerConsumerFactory::GetInstance() override is in
// mock/mock_databroker_consumer_factory.cc — compiled as a strong symbol so
// it wins over the shared library's weak definition.
