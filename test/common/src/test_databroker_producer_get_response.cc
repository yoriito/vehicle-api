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
#include <string>
#include <vector>

#include "databroker/producer_get_datapoint.h"
#include "databroker/producer_get_response.h"
#include "databroker_type.h"

TEST(TestDataBrokerProducerGetResponse, PrimitiveDataPointsArePreserved) {
  struct PrimitiveDataPoint {
    const char* path;
    yoriito::ValueType data;
  };

  std::vector<PrimitiveDataPoint> primitive_data;
  primitive_data.reserve(25);
  primitive_data.emplace_back(
      PrimitiveDataPoint{"Primitive.String", std::string("text")});
  primitive_data.emplace_back(PrimitiveDataPoint{"Primitive.Boolean", true});
  primitive_data.emplace_back(
      PrimitiveDataPoint{"Primitive.Int8", static_cast<int8_t>(-8)});
  primitive_data.emplace_back(
      PrimitiveDataPoint{"Primitive.Int16", static_cast<int16_t>(-16)});
  primitive_data.emplace_back(
      PrimitiveDataPoint{"Primitive.Int32", static_cast<int32_t>(-32)});
  primitive_data.emplace_back(
      PrimitiveDataPoint{"Primitive.Int64", static_cast<int64_t>(-64)});
  primitive_data.emplace_back(
      PrimitiveDataPoint{"Primitive.Uint8", static_cast<uint8_t>(8)});
  primitive_data.emplace_back(
      PrimitiveDataPoint{"Primitive.Uint16", static_cast<uint16_t>(16)});
  primitive_data.emplace_back(
      PrimitiveDataPoint{"Primitive.Uint32", static_cast<uint32_t>(32)});
  primitive_data.emplace_back(
      PrimitiveDataPoint{"Primitive.Uint64", static_cast<uint64_t>(64)});
  primitive_data.emplace_back(PrimitiveDataPoint{"Primitive.Float", 1.5f});
  primitive_data.emplace_back(PrimitiveDataPoint{"Primitive.Double", 2.5});
  primitive_data.emplace_back(PrimitiveDataPoint{
      "Primitive.Timestamp", static_cast<uint64_t>(1710000000)});
  primitive_data.emplace_back(PrimitiveDataPoint{
      "Primitive.StringArray", std::vector<std::string>{"a", "b"}});
  primitive_data.emplace_back(PrimitiveDataPoint{
      "Primitive.BooleanArray", std::vector<bool>{true, false}});
  primitive_data.emplace_back(
      PrimitiveDataPoint{"Primitive.Int8Array", std::vector<int8_t>{-1, 0, 1}});
  primitive_data.emplace_back(PrimitiveDataPoint{
      "Primitive.Int16Array", std::vector<int16_t>{-2, 0, 2}});
  primitive_data.emplace_back(PrimitiveDataPoint{
      "Primitive.Int32Array", std::vector<int32_t>{-3, 0, 3}});
  primitive_data.emplace_back(PrimitiveDataPoint{
      "Primitive.Int64Array", std::vector<int64_t>{-4, 0, 4}});
  primitive_data.emplace_back(PrimitiveDataPoint{
      "Primitive.Uint8Array", std::vector<uint8_t>{1, 2, 3}});
  primitive_data.emplace_back(PrimitiveDataPoint{
      "Primitive.Uint16Array", std::vector<uint16_t>{4, 5, 6}});
  primitive_data.emplace_back(PrimitiveDataPoint{
      "Primitive.Uint32Array", std::vector<uint32_t>{7, 8, 9}});
  primitive_data.emplace_back(PrimitiveDataPoint{
      "Primitive.Uint64Array", std::vector<uint64_t>{10, 11, 12}});
  primitive_data.emplace_back(PrimitiveDataPoint{
      "Primitive.FloatArray", std::vector<float>{1.0f, 2.0f}});
  primitive_data.emplace_back(PrimitiveDataPoint{
      "Primitive.DoubleArray", std::vector<double>{3.0, 4.0}});

  std::vector<yoriito::databroker::ProducerGetDataPoint> data_points;
  data_points.reserve(primitive_data.size());

  for (const auto& metadata : primitive_data) {
    data_points.emplace_back(metadata.path, metadata.data);
  }

  yoriito::databroker::ProducerGetResponse response(std::move(data_points));

  const auto& points = response.GetDataPoints();
  ASSERT_EQ(points.size(), primitive_data.size());

  for (size_t i = 0; i < primitive_data.size(); ++i) {
    EXPECT_EQ(points[i].GetPath(), primitive_data[i].path);
    EXPECT_TRUE(yoriito::ValueTypeEquals(points[i].GetData(),
                                           primitive_data[i].data));
  }
}

TEST(TestDataBrokerProducerGetResponse, SingleStructDataPointIsPreserved) {
  yoriito::StructData location;
  location.SetProperty("Latitude", yoriito::ValueType(35.6812));
  location.SetProperty("Longitude", yoriito::ValueType(139.7671));
  yoriito::ValueType expected_data(
      std::make_unique<yoriito::StructData>(std::move(location)));

  std::vector<yoriito::databroker::ProducerGetDataPoint> data_points;
  data_points.emplace_back("Vehicle.Location", expected_data);

  yoriito::databroker::ProducerGetResponse response(std::move(data_points));

  const auto& points = response.GetDataPoints();
  ASSERT_EQ(points.size(), 1U);
  EXPECT_EQ(points[0].GetPath(), "Vehicle.Location");
  EXPECT_TRUE(yoriito::ValueTypeEquals(points[0].GetData(), expected_data));

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

TEST(TestDataBrokerProducerGetResponse, MultipleStructDataPointsArePreserved) {
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

  std::vector<yoriito::databroker::ProducerGetDataPoint> data_points;
  data_points.emplace_back("Vehicle.CurrentLocation",
                           expected_current_location);
  data_points.emplace_back("Vehicle.DestinationLocation",
                           expected_destination_location);

  yoriito::databroker::ProducerGetResponse response(std::move(data_points));

  const auto& points = response.GetDataPoints();
  ASSERT_EQ(points.size(), 2U);
  EXPECT_EQ(points[0].GetPath(), "Vehicle.CurrentLocation");
  EXPECT_TRUE(yoriito::ValueTypeEquals(points[0].GetData(),
                                         expected_current_location));
  EXPECT_EQ(points[1].GetPath(), "Vehicle.DestinationLocation");
  EXPECT_TRUE(yoriito::ValueTypeEquals(points[1].GetData(),
                                         expected_destination_location));

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

TEST(TestDataBrokerProducerGetResponse,
     PrimitiveAndStructDataPointsCanCoexist) {
  yoriito::StructData location;
  location.SetProperty("Latitude", yoriito::ValueType(35.6812));
  location.SetProperty("Longitude", yoriito::ValueType(139.7671));
  yoriito::ValueType expected_location(
      std::make_unique<yoriito::StructData>(std::move(location)));

  std::vector<yoriito::databroker::ProducerGetDataPoint> data_points;
  data_points.emplace_back("Vehicle.Speed", yoriito::ValueType(123.45f));
  data_points.emplace_back("Vehicle.Location", expected_location);

  yoriito::databroker::ProducerGetResponse response(std::move(data_points));

  const auto& points = response.GetDataPoints();
  ASSERT_EQ(points.size(), 2U);
  EXPECT_EQ(points[0].GetPath(), "Vehicle.Speed");
  EXPECT_EQ(std::get<float>(points[0].GetData()), 123.45f);
  EXPECT_EQ(points[1].GetPath(), "Vehicle.Location");
  EXPECT_TRUE(
      yoriito::ValueTypeEquals(points[1].GetData(), expected_location));

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