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

#include "signal/currentlocation/gnssreceiver/Signal_GNSSLocationType.h"

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
    yoriito::vehicle::currentlocation::gnssreceiver::gnsslocationtype;
using ::testing::Return;

namespace {
yoriito::databroker::MockDataBrokerConsumer* mock_consumer;

yoriito::StructDataPtr ToStructData(const vss::GNSSLocation& data) {
  auto struct_data = std::make_unique<yoriito::StructData>();
  struct_data->SetProperty("Timestamp", yoriito::ValueType{data.timestamp});
  struct_data->SetProperty("Latitude", yoriito::ValueType{data.latitude});
  struct_data->SetProperty("Longitude", yoriito::ValueType{data.longitude});
  struct_data->SetProperty("HorizontalAccuracy",
                           yoriito::ValueType{data.horizontal_accuracy});
  struct_data->SetProperty("Altitude", yoriito::ValueType{data.altitude});
  struct_data->SetProperty("VerticalAccuracy",
                           yoriito::ValueType{data.vertical_accuracy});
  struct_data->SetProperty("FixType", yoriito::ValueType{data.fix_type});
  return struct_data;
}

class GetNormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE
    : public ::testing::TestWithParam<vss::GNSSLocation> {
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
    SubscribeNormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE
    : public ::testing::TestWithParam<vss::GNSSLocation> {
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
    UnSubscribeNormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE
    : public ::testing::TestWithParam<vss::GNSSLocation> {
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
    InspectNormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE
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
    GetNormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    GetNormalTest_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE) {
  vss::GNSSLocation expected_value = GetParam();

  // mock request
  std::string current_path =
      vss::VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE;
  auto request =
      yoriito::databroker::ConsumerGetRequest(std::string(current_path));

  // mock response
  double timestamp = 0.0;
  bool is_available_sensor = true;
  bool is_available_actuator = true;
  double produced_timestamp = 1234567890;

  yoriito::ValueType struct_value = ToStructData(expected_value);
  auto dp = yoriito::databroker::ConsumerGetDataPoint(
      current_path, struct_value, is_available_sensor, is_available_actuator,
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

  const auto& actual_value = get_datapoint.GetData();
  EXPECT_EQ(actual_value.timestamp, expected_value.timestamp);
  EXPECT_EQ(actual_value.latitude, expected_value.latitude);
  EXPECT_EQ(actual_value.longitude, expected_value.longitude);
  EXPECT_EQ(actual_value.horizontal_accuracy,
            expected_value.horizontal_accuracy);
  EXPECT_EQ(actual_value.altitude, expected_value.altitude);
  EXPECT_EQ(actual_value.vertical_accuracy, expected_value.vertical_accuracy);
  EXPECT_EQ(actual_value.fix_type, expected_value.fix_type);

  EXPECT_EQ(get_datapoint.GetPath(), current_path);
  EXPECT_EQ(get_datapoint.IsAvailableSensor(), is_available_sensor);
  EXPECT_EQ(get_datapoint.IsAvailableActuator(), is_available_actuator);
  EXPECT_EQ(get_datapoint.GetStoredTimestamp(), timestamp);
  ASSERT_TRUE(get_datapoint.GetProducedTimestamp().has_value());
  EXPECT_EQ(get_datapoint.GetProducedTimestamp().value(), produced_timestamp);
};

INSTANTIATE_TEST_SUITE_P(
    VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE_Sensor,
    GetNormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    ::testing::Values(vss::GNSSLocation{}));

TEST_P(
    SubscribeNormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    SubscribeNormalTest_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE) {
  // mock request for Subscribe
  std::string current_path =
      vss::VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE;
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
    VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE_Sensor,
    SubscribeNormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    ::testing::Values(vss::GNSSLocation{}));

TEST_P(
    UnSubscribeNormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    UnSubscribeNormalTest_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE) {
  // mock request for Subscribe
  std::string current_path =
      vss::VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE;
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
    VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE_Sensor,
    UnSubscribeNormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    ::testing::Values(vss::GNSSLocation{}));

TEST_F(
    InspectNormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    InspectNormalTest_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE) {
  // mock request for Inspect
  std::string current_path =
      vss::VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE;
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
    GetAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE
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
    SubscribeAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE
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
    UnSubscribeAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE
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
    InspectAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE
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
    GetAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    Get_ReturnsErr_WhenConsumerGetFails) {
  // mock request
  std::string current_path =
      vss::VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE;
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
    GetAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    Get_ReturnsErr_WhenDataPointsEmpty) {
  // mock request
  std::string current_path =
      vss::VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE;
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

TEST_F(
    GetAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    Get_ReturnsErr_WhenDataIsNotStructDataPtr) {
  std::string current_path =
      vss::VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE;
  auto request =
      yoriito::databroker::ConsumerGetRequest(std::string(current_path));
  double timestamp = 0.0;
  bool is_available_sensor = true;
  bool is_available_actuator = true;
  yoriito::ValueType invalid_value = int8_t{1};
  auto dp = yoriito::databroker::ConsumerGetDataPoint(
      current_path, invalid_value, is_available_sensor, is_available_actuator,
      timestamp);
  std::vector<yoriito::databroker::ConsumerGetDataPoint> dps = {dp};
  auto response = yoriito::databroker::ConsumerGetResponse(std::move(dps));
  EXPECT_CALL(*mock_consumer, Get(request))
      .WillOnce(
          Return(yoriito::Result<yoriito::databroker::ConsumerGetResponse>::Ok(
              response)));
  auto result = vss::Get();
  EXPECT_TRUE(result.IsErr());
}
TEST_F(
    GetAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    Get_ReturnsErr_WhenStructDataPtrIsNull) {
  std::string current_path =
      vss::VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE;
  auto request =
      yoriito::databroker::ConsumerGetRequest(std::string(current_path));
  double timestamp = 0.0;
  bool is_available_sensor = true;
  bool is_available_actuator = true;
  yoriito::StructDataPtr null_struct = nullptr;
  yoriito::ValueType value = std::move(null_struct);
  auto dp = yoriito::databroker::ConsumerGetDataPoint(
      current_path, std::move(value), is_available_sensor,
      is_available_actuator, timestamp);
  std::vector<yoriito::databroker::ConsumerGetDataPoint> dps = {dp};
  auto response = yoriito::databroker::ConsumerGetResponse(std::move(dps));
  EXPECT_CALL(*mock_consumer, Get(request))
      .WillOnce(
          Return(yoriito::Result<yoriito::databroker::ConsumerGetResponse>::Ok(
              response)));
  auto result = vss::Get();
  EXPECT_TRUE(result.IsErr());
}
TEST_F(
    GetAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    Get_ReturnsErr_WhenFailedToExtractData) {
  std::string current_path =
      vss::VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE;
  auto request =
      yoriito::databroker::ConsumerGetRequest(std::string(current_path));
  double timestamp = 0.0;
  bool is_available_sensor = true;
  bool is_available_actuator = true;
  auto sd = std::make_unique<yoriito::StructData>();
  yoriito::ValueType value = std::move(sd);
  auto dp = yoriito::databroker::ConsumerGetDataPoint(
      current_path, std::move(value), is_available_sensor,
      is_available_actuator, timestamp);
  std::vector<yoriito::databroker::ConsumerGetDataPoint> dps = {dp};
  auto response = yoriito::databroker::ConsumerGetResponse(std::move(dps));
  EXPECT_CALL(*mock_consumer, Get(request))
      .WillOnce(
          Return(yoriito::Result<yoriito::databroker::ConsumerGetResponse>::Ok(
              response)));
  auto result = vss::Get();
  EXPECT_TRUE(result.IsErr());
}

// Subscribe
TEST_F(
    SubscribeAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
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
    UnSubscribeAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    UnSubscribe_ReturnsErr_WhenContextIsNull) {
  yoriito::signal::SignalSubscribeContext<vss::GNSSLocation> null_ctx;
  auto result = vss::UnSubscribe(std::move(null_ctx));
  EXPECT_TRUE(result.IsErr());
}
TEST_F(
    UnSubscribeAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
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
    UnSubscribeAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
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
  yoriito::signal::SignalSubscribeContext<vss::GNSSLocation> empty;
  auto second = vss::UnSubscribe(std::move(empty));
  EXPECT_TRUE(second.IsErr());
}

// Inspect
TEST_F(
    InspectAbnormalTestFixture_VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE,
    Inspect_ReturnsErr_WhenBrokerReturnsErr) {
  std::string current_path =
      vss::VEHICLE_CURRENTLOCATION_GNSSRECEIVER_GNSSLOCATIONTYPE;
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