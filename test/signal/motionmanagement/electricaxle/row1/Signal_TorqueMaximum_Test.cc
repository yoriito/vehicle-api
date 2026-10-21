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

#include "signal/motionmanagement/electricaxle/row1/Signal_TorqueMaximum.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>
#include <string>

#include "consumer_get_response.h"
#include "error.h"
#include "mock_consumer_subscribe_context.h"
#include "mock_databroker_consumer.h"
#include "mock_databroker_consumer_factory.h"
#include "result.h"
namespace vss =
    yoriito::vehicle::motionmanagement::electricaxle::row1::torquemaximum;
using ::testing::Return;

namespace {
yoriito::databroker::MockDataBrokerConsumer* mock_consumer;

class
    GetNormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM
    : public ::testing::TestWithParam<int16_t> {
 protected:
  void SetUp() override {
    mock_consumer = new yoriito::databroker::MockDataBrokerConsumer();
    yoriito::databroker::MockDataBrokerConsumerFactory::instance =
        mock_consumer;
  }

  void TearDown() override {
    delete mock_consumer;
    yoriito::databroker::MockDataBrokerConsumerFactory::instance = nullptr;
  }
};
class
    SubscribeNormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM
    : public ::testing::TestWithParam<int16_t> {
 protected:
  void SetUp() override {
    mock_consumer = new yoriito::databroker::MockDataBrokerConsumer();
    yoriito::databroker::MockDataBrokerConsumerFactory::instance =
        mock_consumer;
  }

  void TearDown() override {
    delete mock_consumer;
    yoriito::databroker::MockDataBrokerConsumerFactory::instance = nullptr;
  }
};
class
    UnSubscribeNormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM
    : public ::testing::TestWithParam<int16_t> {
 protected:
  void SetUp() override {
    mock_consumer = new yoriito::databroker::MockDataBrokerConsumer();
    yoriito::databroker::MockDataBrokerConsumerFactory::instance =
        mock_consumer;
  }

  void TearDown() override {
    delete mock_consumer;
    yoriito::databroker::MockDataBrokerConsumerFactory::instance = nullptr;
  }
};
class
    InspectNormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM
    : public ::testing::Test {
 protected:
  void SetUp() override {
    mock_consumer = new yoriito::databroker::MockDataBrokerConsumer();
    yoriito::databroker::MockDataBrokerConsumerFactory::instance =
        mock_consumer;
  }

  void TearDown() override {
    delete mock_consumer;
    yoriito::databroker::MockDataBrokerConsumerFactory::instance = nullptr;
  }
};
}  // namespace

TEST_P(
    GetNormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    GetNormalTest_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM) {
  int16_t expected_value = GetParam();

  // mock request
  std::string current_path =
      vss::VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM;
  auto request =
      yoriito::databroker::ConsumerGetRequest(std::string(current_path));

  // mock response
  double timestamp = 0.0;
  bool is_available_sensor = true;
  bool is_available_actuator = true;
  double produced_timestamp = 1234567890;

  auto dp = yoriito::databroker::ConsumerGetDataPoint(
      current_path, expected_value, is_available_sensor, is_available_actuator,
      timestamp, produced_timestamp);

  std::vector<yoriito::databroker::ConsumerGetDataPoint> dps = {dp};
  auto response = yoriito::databroker::ConsumerGetResponse(std::move(dps));

  // setup mock
  EXPECT_CALL(*mock_consumer, Get(request))
      .WillOnce(
          Return(yoriito::Result<yoriito::databroker::ConsumerGetResponse>::Ok(
              response)));

  // execute
  auto result = vss::Get();

  // post_condition
  EXPECT_TRUE(result.IsOk());
  auto get_datapoint = result.TakeOk().value();

  EXPECT_EQ(get_datapoint.GetData(), expected_value);

  EXPECT_EQ(get_datapoint.GetPath(), current_path);
  EXPECT_EQ(get_datapoint.IsAvailableSensor(), is_available_sensor);
  EXPECT_EQ(get_datapoint.IsAvailableActuator(), is_available_actuator);
  EXPECT_EQ(get_datapoint.GetStoredTimestamp(), timestamp);
  ASSERT_TRUE(get_datapoint.GetProducedTimestamp().has_value());
  EXPECT_EQ(get_datapoint.GetProducedTimestamp().value(), produced_timestamp);
};

INSTANTIATE_TEST_SUITE_P(
    VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM_Sensor,
    GetNormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    ::testing::Values(-127, 127, 0));

TEST_P(
    SubscribeNormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    SubscribeNormalTest_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM) {
  // mock request for Subscribe
  std::string current_path =
      vss::VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM;
  auto request = yoriito::databroker::ConsumerSubscribeRequest(current_path);

  // mock response for Subscribe
  std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>
      expect_context =
          std::make_unique<yoriito::databroker::MockConsumerSubscribeContext>();

  // setup mock for Subscribe
  EXPECT_CALL(*mock_consumer, Subscribe(testing::_))
      .WillOnce(Return(
          yoriito::Result<
              std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>>::
              Ok(std::move(expect_context))));

  // execute
  auto result = vss::Subscribe();

  // post_condition
  EXPECT_TRUE(result.IsOk());
}

INSTANTIATE_TEST_SUITE_P(
    VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM_Sensor,
    SubscribeNormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    ::testing::Values(-127, 127, 0));

TEST_P(
    UnSubscribeNormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    UnSubscribeNormalTest_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM) {
  // mock request for Subscribe
  std::string current_path =
      vss::VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM;
  auto request = yoriito::databroker::ConsumerSubscribeRequest(current_path);

  // mock response for Subscribe
  std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>
      expect_context =
          std::make_unique<yoriito::databroker::MockConsumerSubscribeContext>();

  // setup mock for Subscribe and UnSubscribe
  EXPECT_CALL(*mock_consumer, Subscribe(testing::_))
      .WillOnce(Return(
          yoriito::Result<
              std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>>::
              Ok(std::move(expect_context))));
  EXPECT_CALL(*mock_consumer, UnSubscribe(testing::_))
      .WillOnce(Return(yoriito::Result<void>::Ok()));

  // execute
  auto subscribe_ret = vss::Subscribe();

  // post_condition
  EXPECT_TRUE(subscribe_ret.IsOk());
  auto context = subscribe_ret.TakeOk().value();

  // execute
  auto result = vss::UnSubscribe(std::move(context));
  EXPECT_TRUE(result.IsOk());
}

INSTANTIATE_TEST_SUITE_P(
    VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM_Sensor,
    UnSubscribeNormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    ::testing::Values(-127, 127, 0));

TEST_F(
    InspectNormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    InspectNormalTest_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM) {
  // mock request for Inspect
  std::string current_path =
      vss::VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM;
  auto inspect_request =
      yoriito::databroker::ConsumerInspectRequest(std::move(current_path));

  // mock response for Inspect
  auto builder = yoriito::databroker::ConsumerInspectData::CreateBuilder();
  auto data =
      yoriito::databroker::ConsumerInspectData::CreateFromBuilder(builder);
  std::vector<yoriito::databroker::ConsumerInspectData> data_ = {data};
  auto inspect_response =
      yoriito::databroker::ConsumerInspectResponse(std::move(data_));

  // setup mock for Inspect
  EXPECT_CALL(*mock_consumer, Inspect(inspect_request))
      .WillOnce(Return(
          yoriito::Result<yoriito::databroker::ConsumerInspectResponse>::Ok(
              inspect_response)));

  // execute
  auto inspect_ret = vss::Inspect();

  // post_condition
  EXPECT_TRUE(inspect_ret.IsOk());
}

// Abnormal Test
// Fixture
namespace {
class
    GetAbnormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM
    : public ::testing::Test {
 protected:
  void SetUp() override {
    mock_consumer = new yoriito::databroker::MockDataBrokerConsumer();
    yoriito::databroker::MockDataBrokerConsumerFactory::instance =
        mock_consumer;
  }
  void TearDown() override {
    delete mock_consumer;
    yoriito::databroker::MockDataBrokerConsumerFactory::instance = nullptr;
  }
};
class
    SubscribeAbnormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM
    : public ::testing::Test {
 protected:
  void SetUp() override {
    mock_consumer = new yoriito::databroker::MockDataBrokerConsumer();
    yoriito::databroker::MockDataBrokerConsumerFactory::instance =
        mock_consumer;
  }
  void TearDown() override {
    delete mock_consumer;
    yoriito::databroker::MockDataBrokerConsumerFactory::instance = nullptr;
  }
};
class
    UnSubscribeAbnormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM
    : public ::testing::Test {
 protected:
  void SetUp() override {
    mock_consumer = new yoriito::databroker::MockDataBrokerConsumer();
    yoriito::databroker::MockDataBrokerConsumerFactory::instance =
        mock_consumer;
  }
  void TearDown() override {
    delete mock_consumer;
    yoriito::databroker::MockDataBrokerConsumerFactory::instance = nullptr;
  }
};
class
    InspectAbnormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM
    : public ::testing::Test {
 protected:
  void SetUp() override {
    mock_consumer = new yoriito::databroker::MockDataBrokerConsumer();
    yoriito::databroker::MockDataBrokerConsumerFactory::instance =
        mock_consumer;
  }
  void TearDown() override {
    delete mock_consumer;
    yoriito::databroker::MockDataBrokerConsumerFactory::instance = nullptr;
  }
};
}  // namespace
   // Get
TEST_F(
    GetAbnormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    Get_ReturnsErr_WhenConsumerGetFails) {
  // mock request
  std::string current_path =
      vss::VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM;
  auto request =
      yoriito::databroker::ConsumerGetRequest(std::string(current_path));
  // setup mock
  EXPECT_CALL(*mock_consumer, Get(request))
      .WillOnce(
          Return(yoriito::Result<yoriito::databroker::ConsumerGetResponse>::Err(
              std::make_unique<yoriito::CommonError>(
                  yoriito::ErrorCode::ERROR_UNKNOWN))));
  // execute
  auto result = vss::Get();
  // post_condition
  EXPECT_TRUE(result.IsErr());
}
TEST_F(
    GetAbnormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    Get_ReturnsErr_WhenDataPointsEmpty) {
  // mock request
  std::string current_path =
      vss::VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM;
  auto request =
      yoriito::databroker::ConsumerGetRequest(std::string(current_path));
  std::vector<yoriito::databroker::ConsumerGetDataPoint> dps;
  auto response = yoriito::databroker::ConsumerGetResponse(std::move(dps));
  // setup mock
  EXPECT_CALL(*mock_consumer, Get(request))
      .WillOnce(
          Return(yoriito::Result<yoriito::databroker::ConsumerGetResponse>::Ok(
              response)));
  // execute
  auto result = vss::Get();
  // post_condition
  EXPECT_TRUE(result.IsErr());
}

// Subscribe
TEST_F(
    SubscribeAbnormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    Subscribe_ReturnsErr_WhenConsumerSubscribeFails) {
  // Subscribe Failed
  EXPECT_CALL(*mock_consumer, Subscribe(testing::_))
      .WillOnce(Return(
          yoriito::Result<
              std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>>::
              Err(std::make_unique<yoriito::CommonError>(
                  yoriito::ErrorCode::ERROR_UNAVAILABLE))));
  auto result = vss::Subscribe();
  EXPECT_TRUE(result.IsErr());
}
// Unsubscribe
TEST_F(
    UnSubscribeAbnormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    UnSubscribe_ReturnsErr_WhenContextIsNull) {
  yoriito::signal::SignalSubscribeContext<int16_t> null_ctx;
  auto result = vss::UnSubscribe(std::move(null_ctx));
  EXPECT_TRUE(result.IsErr());
}
TEST_F(
    UnSubscribeAbnormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    UnSubscribe_ReturnsErr_WhenConsumerUnsubscribeFails) {
  std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>
      expect_context =
          std::make_unique<yoriito::databroker::MockConsumerSubscribeContext>();
  EXPECT_CALL(*mock_consumer, Subscribe(testing::_))
      .WillOnce(Return(
          yoriito::Result<
              std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>>::
              Ok(std::move(expect_context))));
  auto sub_ret = vss::Subscribe();
  ASSERT_TRUE(sub_ret.IsOk());
  auto ctx = sub_ret.TakeOk().value();
  // UnSubscribe Failed
  EXPECT_CALL(*mock_consumer, UnSubscribe(testing::_))
      .WillOnce(Return(
          yoriito::Result<void>::Err(std::make_unique<yoriito::CommonError>(
              yoriito::ErrorCode::ERROR_UNSUBSCRIBE))));
  auto result = vss::UnSubscribe(std::move(ctx));
  EXPECT_TRUE(result.IsErr());
}
TEST_F(
    UnSubscribeAbnormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    UnSubscribe_ReturnsErr_WhenCalledTwice) {
  std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>
      expect_context =
          std::make_unique<yoriito::databroker::MockConsumerSubscribeContext>();
  EXPECT_CALL(*mock_consumer, Subscribe(testing::_))
      .WillOnce(Return(
          yoriito::Result<
              std::unique_ptr<yoriito::databroker::ConsumerSubscribeContext>>::
              Ok(std::move(expect_context))));
  auto sub_ret = vss::Subscribe();
  ASSERT_TRUE(sub_ret.IsOk());
  auto ctx = sub_ret.TakeOk().value();
  EXPECT_CALL(*mock_consumer, UnSubscribe(testing::_))
      .WillOnce(Return(yoriito::Result<void>::Ok()));
  auto first = vss::UnSubscribe(std::move(ctx));
  EXPECT_TRUE(first.IsOk());
  yoriito::signal::SignalSubscribeContext<int16_t> empty;
  auto second = vss::UnSubscribe(std::move(empty));
  EXPECT_TRUE(second.IsErr());
}

// Inspect
TEST_F(
    InspectAbnormalTestFixture_VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM,
    Inspect_ReturnsErr_WhenBrokerReturnsErr) {
  std::string current_path =
      vss::VEHICLE_MOTIONMANAGEMENT_ELECTRICAXLE_ROW1_TORQUEMAXIMUM;
  yoriito::databroker::ConsumerInspectRequest inspect_request(
      std::move(current_path));
  auto broker_err =
      std::make_unique<yoriito::CommonError>(yoriito::ErrorCode::ERROR_UNKNOWN);
  EXPECT_CALL(*mock_consumer, Inspect(inspect_request))
      .WillOnce(Return(
          yoriito::Result<yoriito::databroker::ConsumerInspectResponse>::Err(
              std::move(broker_err))));
  auto ret = vss::Inspect();
  EXPECT_TRUE(ret.IsErr());
}