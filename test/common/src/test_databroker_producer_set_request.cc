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
#include <optional>
#include <string>
#include <vector>

#include "databroker/producer_set_datapoint.h"
#include "databroker/producer_set_request.h"
#include "databroker_type.h"

TEST(TestDataBrokerProducerSetRequest, PrimitiveDataPointsArePreserved) {
  struct PrimitiveData {
    const char* path;
    yoriito::ValueType data;
    bool is_available_sensor;
    bool is_available_actuator;
    std::optional<int64_t> produced_timestamp;
  };

  std::vector<PrimitiveData> primitive_data;
  primitive_data.reserve(25);
  primitive_data.emplace_back(PrimitiveData{"Primitive.String",
                                            std::string("text"), true, false,
                                            static_cast<int64_t>(1710000001)});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Boolean", true, false, true, std::nullopt});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Int8", static_cast<int8_t>(-8), true, false,
                    static_cast<int64_t>(1710000003)});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Int16", static_cast<int16_t>(-16), false, true,
                    static_cast<int64_t>(1710000004)});
  primitive_data.emplace_back(PrimitiveData{
      "Primitive.Int32", static_cast<int32_t>(-32), true, false, std::nullopt});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Int64", static_cast<int64_t>(-64), false, true,
                    static_cast<int64_t>(1710000006)});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Uint8", static_cast<uint8_t>(8), true, false,
                    static_cast<int64_t>(1710000007)});
  primitive_data.emplace_back(PrimitiveData{"Primitive.Uint16",
                                            static_cast<uint16_t>(16), false,
                                            true, std::nullopt});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Uint32", static_cast<uint32_t>(32), true, false,
                    static_cast<int64_t>(1710000009)});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Uint64", static_cast<uint64_t>(64), false, true,
                    static_cast<int64_t>(1710000010)});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Float", 1.5f, true, false, std::nullopt});
  primitive_data.emplace_back(PrimitiveData{
      "Primitive.Double", 2.5, false, true, static_cast<int64_t>(1710000012)});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Timestamp", static_cast<uint64_t>(1710000000),
                    true, false, static_cast<int64_t>(1710000013)});
  primitive_data.emplace_back(PrimitiveData{"Primitive.StringArray",
                                            std::vector<std::string>{"a", "b"},
                                            false, true, std::nullopt});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.BooleanArray", std::vector<bool>{true, false},
                    true, false, static_cast<int64_t>(1710000015)});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Int8Array", std::vector<int8_t>{-1, 0, 1}, false,
                    true, static_cast<int64_t>(1710000016)});
  primitive_data.emplace_back(PrimitiveData{"Primitive.Int16Array",
                                            std::vector<int16_t>{-2, 0, 2},
                                            true, false, std::nullopt});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Int32Array", std::vector<int32_t>{-3, 0, 3},
                    false, true, static_cast<int64_t>(1710000018)});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Int64Array", std::vector<int64_t>{-4, 0, 4},
                    true, false, static_cast<int64_t>(1710000019)});
  primitive_data.emplace_back(PrimitiveData{"Primitive.Uint8Array",
                                            std::vector<uint8_t>{1, 2, 3},
                                            false, true, std::nullopt});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Uint16Array", std::vector<uint16_t>{4, 5, 6},
                    true, false, static_cast<int64_t>(1710000021)});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.Uint32Array", std::vector<uint32_t>{7, 8, 9},
                    false, true, static_cast<int64_t>(1710000022)});
  primitive_data.emplace_back(PrimitiveData{"Primitive.Uint64Array",
                                            std::vector<uint64_t>{10, 11, 12},
                                            true, false, std::nullopt});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.FloatArray", std::vector<float>{1.0f, 2.0f},
                    false, true, static_cast<int64_t>(1710000024)});
  primitive_data.emplace_back(
      PrimitiveData{"Primitive.DoubleArray", std::vector<double>{3.0, 4.0},
                    true, false, static_cast<int64_t>(1710000025)});

  std::vector<yoriito::databroker::ProducerSetDataPoint> data_points;
  data_points.reserve(primitive_data.size());

  for (const auto& data : primitive_data) {
    data_points.emplace_back(data.path, data.data, data.is_available_sensor,
                             data.is_available_actuator,
                             data.produced_timestamp);
  }

  yoriito::databroker::ProducerSetRequest request(std::move(data_points));

  const auto& points = request.GetDataPoints();
  ASSERT_EQ(points.size(), primitive_data.size());

  for (size_t i = 0; i < primitive_data.size(); ++i) {
    EXPECT_EQ(points[i].GetPath(), primitive_data[i].path);
    EXPECT_TRUE(yoriito::ValueTypeEquals(points[i].GetData(),
                                           primitive_data[i].data));
    EXPECT_EQ(points[i].IsAvailableSensor(),
              primitive_data[i].is_available_sensor);
    EXPECT_EQ(points[i].IsAvailableActuator(),
              primitive_data[i].is_available_actuator);
    EXPECT_EQ(points[i].GetProducedTimestamp(),
              primitive_data[i].produced_timestamp);
  }
}

TEST(TestDataBrokerProducerSetRequest, SingleStructDataPointIsPreserved) {
  yoriito::StructData location;
  location.SetProperty("Latitude", yoriito::ValueType(35.6812));
  location.SetProperty("Longitude", yoriito::ValueType(139.7671));
  yoriito::ValueType expected_data(
      std::make_unique<yoriito::StructData>(std::move(location)));

  std::vector<yoriito::databroker::ProducerSetDataPoint> data_points;
  data_points.emplace_back("Vehicle.Location", expected_data, true, false,
                           static_cast<int64_t>(1710000101));

  yoriito::databroker::ProducerSetRequest request(std::move(data_points));

  const auto& points = request.GetDataPoints();
  ASSERT_EQ(points.size(), 1U);
  EXPECT_EQ(points[0].GetPath(), "Vehicle.Location");
  EXPECT_TRUE(yoriito::ValueTypeEquals(points[0].GetData(), expected_data));
  EXPECT_TRUE(points[0].IsAvailableSensor());
  EXPECT_FALSE(points[0].IsAvailableActuator());
  ASSERT_TRUE(points[0].GetProducedTimestamp().has_value());
  EXPECT_EQ(points[0].GetProducedTimestamp().value(), 1710000101);

  ASSERT_TRUE(
      std::holds_alternative<yoriito::StructDataPtr>(points[0].GetData()));
  const auto& location_ptr =
      std::get<yoriito::StructDataPtr>(points[0].GetData());
  ASSERT_NE(location_ptr, nullptr);
  const auto& properties = location_ptr->GetProperties();
  ASSERT_EQ(properties.size(), 2U);
  EXPECT_EQ(std::get<double>(properties.at("Latitude")), 35.6812);
  EXPECT_EQ(std::get<double>(properties.at("Longitude")), 139.7671);
}

TEST(TestDataBrokerProducerSetRequest, MultipleStructDataPointsArePreserved) {
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

  std::vector<yoriito::databroker::ProducerSetDataPoint> data_points;
  data_points.emplace_back("Vehicle.CurrentLocation", expected_current_location,
                           true, false, static_cast<int64_t>(1710000201));
  data_points.emplace_back("Vehicle.DestinationLocation",
                           expected_destination_location, false, true,
                           static_cast<int64_t>(1710000202));

  yoriito::databroker::ProducerSetRequest request(std::move(data_points));

  const auto& points = request.GetDataPoints();
  ASSERT_EQ(points.size(), 2U);
  EXPECT_EQ(points[0].GetPath(), "Vehicle.CurrentLocation");
  EXPECT_TRUE(yoriito::ValueTypeEquals(points[0].GetData(),
                                         expected_current_location));
  EXPECT_TRUE(points[0].IsAvailableSensor());
  EXPECT_FALSE(points[0].IsAvailableActuator());
  ASSERT_TRUE(points[0].GetProducedTimestamp().has_value());
  EXPECT_EQ(points[0].GetProducedTimestamp().value(), 1710000201);

  EXPECT_EQ(points[1].GetPath(), "Vehicle.DestinationLocation");
  EXPECT_TRUE(yoriito::ValueTypeEquals(points[1].GetData(),
                                         expected_destination_location));
  EXPECT_FALSE(points[1].IsAvailableSensor());
  EXPECT_TRUE(points[1].IsAvailableActuator());
  ASSERT_TRUE(points[1].GetProducedTimestamp().has_value());
  EXPECT_EQ(points[1].GetProducedTimestamp().value(), 1710000202);

  ASSERT_TRUE(
      std::holds_alternative<yoriito::StructDataPtr>(points[1].GetData()));
  const auto& location_ptr =
      std::get<yoriito::StructDataPtr>(points[1].GetData());
  ASSERT_NE(location_ptr, nullptr);
  const auto& properties = location_ptr->GetProperties();
  ASSERT_EQ(properties.size(), 2U);
  EXPECT_EQ(std::get<double>(properties.at("Latitude")), 34.6937);
  EXPECT_EQ(std::get<double>(properties.at("Longitude")), 135.5023);
}

TEST(TestDataBrokerProducerSetRequest, PrimitiveAndStructDataPointsCanCoexist) {
  yoriito::StructData location;
  location.SetProperty("Latitude", yoriito::ValueType(35.6812));
  location.SetProperty("Longitude", yoriito::ValueType(139.7671));
  yoriito::ValueType expected_location(
      std::make_unique<yoriito::StructData>(std::move(location)));

  std::vector<yoriito::databroker::ProducerSetDataPoint> data_points;
  data_points.emplace_back("Vehicle.Speed", yoriito::ValueType(123.45f), true,
                           false, std::nullopt);
  data_points.emplace_back("Vehicle.Location", expected_location, true, true,
                           static_cast<int64_t>(1710000302));

  yoriito::databroker::ProducerSetRequest request(std::move(data_points));

  const auto& points = request.GetDataPoints();
  ASSERT_EQ(points.size(), 2U);
  EXPECT_EQ(points[0].GetPath(), "Vehicle.Speed");
  EXPECT_EQ(std::get<float>(points[0].GetData()), 123.45f);
  EXPECT_TRUE(points[0].IsAvailableSensor());
  EXPECT_FALSE(points[0].IsAvailableActuator());
  EXPECT_FALSE(points[0].GetProducedTimestamp().has_value());

  EXPECT_EQ(points[1].GetPath(), "Vehicle.Location");
  EXPECT_TRUE(
      yoriito::ValueTypeEquals(points[1].GetData(), expected_location));
  EXPECT_TRUE(points[1].IsAvailableSensor());
  EXPECT_TRUE(points[1].IsAvailableActuator());
  ASSERT_TRUE(points[1].GetProducedTimestamp().has_value());
  EXPECT_EQ(points[1].GetProducedTimestamp().value(), 1710000302);

  ASSERT_TRUE(
      std::holds_alternative<yoriito::StructDataPtr>(points[1].GetData()));
  const auto& location_ptr =
      std::get<yoriito::StructDataPtr>(points[1].GetData());
  ASSERT_NE(location_ptr, nullptr);
  const auto& properties = location_ptr->GetProperties();
  ASSERT_EQ(properties.size(), 2U);
  EXPECT_EQ(std::get<double>(properties.at("Latitude")), 35.6812);
  EXPECT_EQ(std::get<double>(properties.at("Longitude")), 139.7671);
}