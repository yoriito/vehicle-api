// SPDX-License-Identifier: Apache-2.0
//
// Copyright 2026 JASPAR
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gtest/gtest.h>

#include <memory>
#include <utility>
#include <vector>

#include "databroker/consumer_get_datapoint.h"
#include "databroker/consumer_get_response.h"
#include "databroker_type.h"
#include "result.h"

TEST(TestDataBrokerGetResponse, Normal) {
  auto datapoints = std::vector<yoriito::databroker::ConsumerGetDataPoint>{
      yoriito::databroker::ConsumerGetDataPoint("Vehicle.TraveledDistance",
                                                yoriito::ValueType(123.45f),
                                                true, false, 1622547800)};
  yoriito::databroker::ConsumerGetResponse get_response(std::move(datapoints));
  ASSERT_EQ(get_response.GetDataPoints().size(), 1);
  auto dp = get_response.GetDataPoints();
  ASSERT_EQ(dp.size(), 1);
  ASSERT_EQ(dp[0].GetPath(), "Vehicle.TraveledDistance");
  ASSERT_EQ(std::get<float>(dp[0].GetData()), 123.45f);
  ASSERT_EQ(dp[0].IsAvailableSensor(), true);
  ASSERT_EQ(dp[0].IsAvailableActuator(), false);
  ASSERT_EQ(dp[0].GetStoredTimestamp(), 1622547800);
}

TEST(TestDataBrokerGetResponse, Multi) {
  auto datapoints = std::vector<yoriito::databroker::ConsumerGetDataPoint>{
      yoriito::databroker::ConsumerGetDataPoint("Vehicle.TraveledDistance",
                                                yoriito::ValueType(123.45f),
                                                true, false, 1622547800),
      yoriito::databroker::ConsumerGetDataPoint(
          "Vehicle.Speed", yoriito::ValueType(0.45f), true, false, 1622547800)};
  yoriito::databroker::ConsumerGetResponse get_response(std::move(datapoints));
  auto dp = get_response.GetDataPoints();
  ASSERT_EQ(dp.size(), 2);
  ASSERT_EQ(dp[0].GetPath(), "Vehicle.TraveledDistance");
  ASSERT_EQ(std::get<float>(dp[0].GetData()), 123.45f);
  ASSERT_EQ(dp[0].IsAvailableSensor(), true);
  ASSERT_EQ(dp[0].IsAvailableActuator(), false);
  ASSERT_EQ(dp[0].GetStoredTimestamp(), 1622547800);
  ASSERT_EQ(dp[1].GetPath(), "Vehicle.Speed");
  ASSERT_EQ(std::get<float>(dp[1].GetData()), 0.45f);
  ASSERT_EQ(dp[1].IsAvailableSensor(), true);
  ASSERT_EQ(dp[1].IsAvailableActuator(), false);
  ASSERT_EQ(dp[1].GetStoredTimestamp(), 1622547800);
}

TEST(TestDataBrokerGetResponse, SingleStructDataPointIsPreserved) {
  yoriito::StructData location;
  location.SetProperty("Latitude", yoriito::ValueType(35.6812));
  location.SetProperty("Longitude", yoriito::ValueType(139.7671));
  yoriito::ValueType expected_data(
      std::make_unique<yoriito::StructData>(std::move(location)));

  auto datapoints = std::vector<yoriito::databroker::ConsumerGetDataPoint>{
      yoriito::databroker::ConsumerGetDataPoint(
          "Vehicle.Location", expected_data, true, false, 1622547800)};

  yoriito::databroker::ConsumerGetResponse get_response(std::move(datapoints));

  const auto& dp = get_response.GetDataPoints();
  ASSERT_EQ(dp.size(), 1U);
  EXPECT_EQ(dp[0].GetPath(), "Vehicle.Location");
  EXPECT_TRUE(dp[0].IsAvailableSensor());
  EXPECT_FALSE(dp[0].IsAvailableActuator());
  EXPECT_EQ(dp[0].GetStoredTimestamp(), 1622547800);
  EXPECT_TRUE(yoriito::ValueTypeEquals(dp[0].GetData(), expected_data));

  ASSERT_TRUE(std::holds_alternative<yoriito::StructDataPtr>(dp[0].GetData()));
  const auto& struct_ptr = std::get<yoriito::StructDataPtr>(dp[0].GetData());
  ASSERT_NE(struct_ptr, nullptr);
  const auto& properties = struct_ptr->GetProperties();
  ASSERT_EQ(properties.size(), 2U);
  EXPECT_EQ(std::get<double>(properties.at("Latitude")), 35.6812);
  EXPECT_EQ(std::get<double>(properties.at("Longitude")), 139.7671);
}

TEST(TestDataBrokerGetResponse, MultipleStructDataPointsArePreserved) {
  yoriito::StructData current_location;
  current_location.SetProperty("Latitude", yoriito::ValueType(35.6812));
  current_location.SetProperty("Longitude", yoriito::ValueType(139.7671));
  yoriito::ValueType expected_current_location(
      std::make_unique<yoriito::StructData>(std::move(current_location)));

  yoriito::StructData destination_location;
  destination_location.SetProperty("Latitude", yoriito::ValueType(34.6937));
  destination_location.SetProperty("Longitude", yoriito::ValueType(135.5023));
  yoriito::ValueType expected_destination_location(
      std::make_unique<yoriito::StructData>(std::move(destination_location)));

  auto datapoints = std::vector<yoriito::databroker::ConsumerGetDataPoint>{
      yoriito::databroker::ConsumerGetDataPoint("Vehicle.CurrentLocation",
                                                expected_current_location, true,
                                                false, 1622547800),
      yoriito::databroker::ConsumerGetDataPoint("Vehicle.DestinationLocation",
                                                expected_destination_location,
                                                true, false, 1622547801)};

  yoriito::databroker::ConsumerGetResponse get_response(std::move(datapoints));

  const auto& dp = get_response.GetDataPoints();
  ASSERT_EQ(dp.size(), 2U);
  EXPECT_EQ(dp[0].GetPath(), "Vehicle.CurrentLocation");
  EXPECT_TRUE(dp[0].IsAvailableSensor());
  EXPECT_FALSE(dp[0].IsAvailableActuator());
  EXPECT_EQ(dp[0].GetStoredTimestamp(), 1622547800);
  EXPECT_TRUE(
      yoriito::ValueTypeEquals(dp[0].GetData(), expected_current_location));
  EXPECT_EQ(dp[1].GetPath(), "Vehicle.DestinationLocation");
  EXPECT_TRUE(dp[1].IsAvailableSensor());
  EXPECT_FALSE(dp[1].IsAvailableActuator());
  EXPECT_EQ(dp[1].GetStoredTimestamp(), 1622547801);
  EXPECT_TRUE(yoriito::ValueTypeEquals(dp[1].GetData(),
                                         expected_destination_location));

  ASSERT_TRUE(std::holds_alternative<yoriito::StructDataPtr>(dp[1].GetData()));
  const auto& location_ptr = std::get<yoriito::StructDataPtr>(dp[1].GetData());
  ASSERT_NE(location_ptr, nullptr);
  const auto& properties = location_ptr->GetProperties();
  ASSERT_EQ(properties.size(), 2U);
  EXPECT_EQ(std::get<double>(properties.at("Latitude")), 34.6937);
  EXPECT_EQ(std::get<double>(properties.at("Longitude")), 135.5023);
}

TEST(TestDataBrokerGetResponse, PrimitiveAndStructDataPointsCanCoexist) {
  yoriito::StructData location;
  location.SetProperty("Latitude", yoriito::ValueType(35.6812));
  location.SetProperty("Longitude", yoriito::ValueType(139.7671));
  yoriito::ValueType expected_location(
      std::make_unique<yoriito::StructData>(std::move(location)));

  auto datapoints = std::vector<yoriito::databroker::ConsumerGetDataPoint>{
      yoriito::databroker::ConsumerGetDataPoint("Vehicle.Speed",
                                                yoriito::ValueType(123.45f),
                                                true, false, 1622547800),
      yoriito::databroker::ConsumerGetDataPoint(
          "Vehicle.Location", expected_location, true, true, 1622547801)};

  yoriito::databroker::ConsumerGetResponse get_response(std::move(datapoints));

  const auto& dp = get_response.GetDataPoints();
  ASSERT_EQ(dp.size(), 2U);
  EXPECT_EQ(dp[0].GetPath(), "Vehicle.Speed");
  EXPECT_EQ(std::get<float>(dp[0].GetData()), 123.45f);
  EXPECT_TRUE(dp[0].IsAvailableSensor());
  EXPECT_FALSE(dp[0].IsAvailableActuator());
  EXPECT_EQ(dp[0].GetStoredTimestamp(), 1622547800);
  EXPECT_EQ(dp[1].GetPath(), "Vehicle.Location");
  EXPECT_TRUE(yoriito::ValueTypeEquals(dp[1].GetData(), expected_location));
  EXPECT_TRUE(dp[1].IsAvailableSensor());
  EXPECT_TRUE(dp[1].IsAvailableActuator());
  EXPECT_EQ(dp[1].GetStoredTimestamp(), 1622547801);

  ASSERT_TRUE(std::holds_alternative<yoriito::StructDataPtr>(dp[1].GetData()));
  const auto& location_ptr = std::get<yoriito::StructDataPtr>(dp[1].GetData());
  ASSERT_NE(location_ptr, nullptr);
  const auto& properties = location_ptr->GetProperties();
  EXPECT_EQ(std::get<double>(properties.at("Latitude")), 35.6812);
  EXPECT_EQ(std::get<double>(properties.at("Longitude")), 139.7671);
}
