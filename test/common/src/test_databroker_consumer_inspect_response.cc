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

#include <map>
#include <memory>
#include <string>
#include <variant>
#include <vector>

#include "databroker/consumer_inspect_response.h"
#include "databroker/types/struct_type.h"
#include "databroker/types/struct_type_ref.h"

TEST(TestConsumerInspectResponse, AllPrimitiveDataPointsArePreserved) {
  struct PrimitiveMetadata {
    const char* path;
    yoriito::databroker::DataType type;
    yoriito::ValueType default_value;
    std::string description;
    std::string comment;
    std::string unit;
    std::map<std::string, std::string> custom_attributes;
  };

  std::vector<PrimitiveMetadata> primitive_metadata;
  primitive_metadata.reserve(25);
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.String",
                        yoriito::databroker::DataType::DATA_TYPE_STRING,
                        std::string("text"),
                        "string description",
                        "string comment",
                        "km",
                        {{"source", "primitive-string"}, {"format", "utf-8"}}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Boolean",
                        yoriito::databroker::DataType::DATA_TYPE_BOOLEAN,
                        true,
                        "boolean description",
                        "boolean comment",
                        "flag",
                        {{"source", "primitive-boolean"}, {"format", "bool"}}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Int8",
                        yoriito::databroker::DataType::DATA_TYPE_INT8,
                        static_cast<int8_t>(-8),
                        "int8 description",
                        "int8 comment",
                        "A",
                        {{"source", "primitive-int8"}, {"range", "small"}}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Int16",
                        yoriito::databroker::DataType::DATA_TYPE_INT16,
                        static_cast<int16_t>(-16),
                        "int16 description",
                        "int16 comment",
                        "deg",
                        {{"source", "primitive-int16"}, {"range", "medium"}}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Int32",
                        yoriito::databroker::DataType::DATA_TYPE_INT32,
                        static_cast<int32_t>(-32),
                        "int32 description",
                        "int32 comment",
                        "m",
                        {{"source", "primitive-int32"}, {"range", "large"}}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Int64",
                        yoriito::databroker::DataType::DATA_TYPE_INT64,
                        static_cast<int64_t>(-64),
                        "int64 description",
                        "int64 comment",
                        "ms",
                        {{"source", "primitive-int64"}, {"range", "wide"}}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Uint8",
                        yoriito::databroker::DataType::DATA_TYPE_UINT8,
                        static_cast<uint8_t>(8),
                        "uint8 description",
                        "uint8 comment",
                        "%",
                        {{"source", "primitive-uint8"}, {"range", "small"}}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Uint16",
                        yoriito::databroker::DataType::DATA_TYPE_UINT16,
                        static_cast<uint16_t>(16),
                        "uint16 description",
                        "uint16 comment",
                        "rpm",
                        {{"source", "primitive-uint16"}, {"range", "medium"}}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Uint32",
                        yoriito::databroker::DataType::DATA_TYPE_UINT32,
                        static_cast<uint32_t>(32),
                        "uint32 description",
                        "uint32 comment",
                        "Pa",
                        {{"source", "primitive-uint32"}, {"range", "large"}}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Uint64",
                        yoriito::databroker::DataType::DATA_TYPE_UINT64,
                        static_cast<uint64_t>(64),
                        "uint64 description",
                        "uint64 comment",
                        "ns",
                        {{"source", "primitive-uint64"}, {"range", "wide"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Float",
      yoriito::databroker::DataType::DATA_TYPE_FLOAT,
      1.5f,
      "float description",
      "float comment",
      "V",
      {{"source", "primitive-float"}, {"precision", "single"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Double",
      yoriito::databroker::DataType::DATA_TYPE_DOUBLE,
      2.5,
      "double description",
      "double comment",
      "kWh",
      {{"source", "primitive-double"}, {"precision", "double"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Timestamp",
      yoriito::databroker::DataType::DATA_TYPE_TIMESTAMP,
      static_cast<uint64_t>(1710000000),
      "timestamp description",
      "timestamp comment",
      "epoch",
      {{"source", "primitive-timestamp"}, {"clock", "unix"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.StringArray",
      yoriito::databroker::DataType::DATA_TYPE_STRING_ARRAY,
      std::vector<std::string>{"a", "b"},
      "string array description",
      "string array comment",
      "items",
      {{"source", "primitive-string-array"}, {"shape", "list"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.BooleanArray",
      yoriito::databroker::DataType::DATA_TYPE_BOOLEAN_ARRAY,
      std::vector<bool>{true, false},
      "boolean array description",
      "boolean array comment",
      "flags",
      {{"source", "primitive-boolean-array"}, {"shape", "list"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Int8Array",
      yoriito::databroker::DataType::DATA_TYPE_INT8_ARRAY,
      std::vector<int8_t>{-1, 0, 1},
      "int8 array description",
      "int8 array comment",
      "A",
      {{"source", "primitive-int8-array"}, {"shape", "list"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Int16Array",
      yoriito::databroker::DataType::DATA_TYPE_INT16_ARRAY,
      std::vector<int16_t>{-2, 0, 2},
      "int16 array description",
      "int16 array comment",
      "deg",
      {{"source", "primitive-int16-array"}, {"shape", "list"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Int32Array",
      yoriito::databroker::DataType::DATA_TYPE_INT32_ARRAY,
      std::vector<int32_t>{-3, 0, 3},
      "int32 array description",
      "int32 array comment",
      "m",
      {{"source", "primitive-int32-array"}, {"shape", "list"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Int64Array",
      yoriito::databroker::DataType::DATA_TYPE_INT64_ARRAY,
      std::vector<int64_t>{-4, 0, 4},
      "int64 array description",
      "int64 array comment",
      "ms",
      {{"source", "primitive-int64-array"}, {"shape", "list"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Uint8Array",
      yoriito::databroker::DataType::DATA_TYPE_UINT8_ARRAY,
      std::vector<uint8_t>{1, 2, 3},
      "uint8 array description",
      "uint8 array comment",
      "%",
      {{"source", "primitive-uint8-array"}, {"shape", "list"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Uint16Array",
      yoriito::databroker::DataType::DATA_TYPE_UINT16_ARRAY,
      std::vector<uint16_t>{4, 5, 6},
      "uint16 array description",
      "uint16 array comment",
      "rpm",
      {{"source", "primitive-uint16-array"}, {"shape", "list"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Uint32Array",
      yoriito::databroker::DataType::DATA_TYPE_UINT32_ARRAY,
      std::vector<uint32_t>{7, 8, 9},
      "uint32 array description",
      "uint32 array comment",
      "Pa",
      {{"source", "primitive-uint32-array"}, {"shape", "list"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Uint64Array",
      yoriito::databroker::DataType::DATA_TYPE_UINT64_ARRAY,
      std::vector<uint64_t>{10, 11, 12},
      "uint64 array description",
      "uint64 array comment",
      "ns",
      {{"source", "primitive-uint64-array"}, {"shape", "list"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.FloatArray",
      yoriito::databroker::DataType::DATA_TYPE_FLOAT_ARRAY,
      std::vector<float>{1.0f, 2.0f},
      "float array description",
      "float array comment",
      "V",
      {{"source", "primitive-float-array"}, {"shape", "list"}}});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.DoubleArray",
      yoriito::databroker::DataType::DATA_TYPE_DOUBLE_ARRAY,
      std::vector<double>{3.0, 4.0},
      "double array description",
      "double array comment",
      "kWh",
      {{"source", "primitive-double-array"}, {"shape", "list"}}});

  std::vector<yoriito::databroker::ConsumerInspectData> data_points;
  data_points.reserve(primitive_metadata.size());

  for (const auto& metadata : primitive_metadata) {
    auto builder = yoriito::databroker::BaseInspectData::CreateBuilder();
    builder.SetPath(metadata.path)
        .SetDataType(metadata.type)
        .SetEntryType(yoriito::databroker::ConsumerInspectData::EntryType::
                          ENTRY_TYPE_SENSOR)
        .SetDescription(metadata.description)
        .SetComment(metadata.comment)
        .SetDeprecation("")
        .SetUnit(metadata.unit)
        .SetMin(yoriito::ValueType())
        .SetMax(yoriito::ValueType())
        .SetAllowed(std::vector<std::string>{})
        .SetDefaultValue(metadata.default_value)
        .SetArraySize(0)
        .SetPattern("")
        .SetCustomAttributes(metadata.custom_attributes);

    data_points.push_back(
        yoriito::databroker::ConsumerInspectData::CreateFromBuilder(builder));
  }

  yoriito::databroker::ConsumerInspectResponse response(std::move(data_points),
                                                        {});

  const auto& points = response.GetDataPoints();
  ASSERT_EQ(points.size(), primitive_metadata.size());

  for (size_t i = 0; i < primitive_metadata.size(); ++i) {
    EXPECT_EQ(points[i].GetPath(), primitive_metadata[i].path);
    EXPECT_EQ(points[i].GetDataType(), primitive_metadata[i].type);
    EXPECT_EQ(
        points[i].GetEntryType(),
        yoriito::databroker::ConsumerInspectData::EntryType::ENTRY_TYPE_SENSOR);
    EXPECT_EQ(points[i].GetDescription(), primitive_metadata[i].description);
    EXPECT_EQ(points[i].GetComment(), primitive_metadata[i].comment);
    EXPECT_EQ(points[i].GetUnit(), primitive_metadata[i].unit);
    EXPECT_EQ(points[i].GetCustomAttributes(),
              primitive_metadata[i].custom_attributes);
    EXPECT_TRUE(yoriito::ValueTypeEquals(
        points[i].GetDefaultValue(), primitive_metadata[i].default_value));
  }

  EXPECT_TRUE(response.GetStructTypes().empty());
}

//  Types:
//   type: branch
// Types.DeliveryInfo:
//   type: struct
//   description: A struct datatype containing info for each delivery
// Types.DeliveryInfo.Address:
//   datatype: string
//   type: property
//   description: Destination address
// Types.DeliveryInfo.Receiver:
//   datatype: string
//   type: property
//   description: Name of receiver
// Delivery:
//   datatype: Types.DeliveryInfo
//   type: sensor
// ReturnAddress:
//   datatype: Types.DeliveryInfo
//   type: attribute
//   description: Where to send returns
//   default:
//     Address: "221B Baker Street"
//     Receiver: "Sherlock Holmes"

TEST(TestConsumerInspectResponse, StructTypeDataPointIsPreserved) {
  auto delivery_builder = yoriito::databroker::BaseInspectData::CreateBuilder();
  delivery_builder.SetPath("Delivery")
      .SetDataType(yoriito::databroker::DataType::DATA_TYPE_STRUCT)
      .SetEntryType(yoriito::databroker::ConsumerInspectData::EntryType::
                        ENTRY_TYPE_SENSOR)
      .SetDescription("")
      .SetComment("")
      .SetDeprecation("")
      .SetUnit("")
      .SetMin(yoriito::ValueType())
      .SetMax(yoriito::ValueType())
      .SetAllowed(std::vector<std::string>{})
      .SetDefaultValue(yoriito::ValueType())
      .SetArraySize(0)
      .SetPattern("")
      .SetCustomAttributes({});

  yoriito::databroker::ConsumerInspectData delivery_data_point =
      yoriito::databroker::ConsumerInspectData::CreateFromBuilder(
          delivery_builder);

  auto return_builder = yoriito::databroker::BaseInspectData::CreateBuilder();
  yoriito::StructData return_default;
  return_default.SetProperty("Address", std::string("221B Baker Street"));
  return_default.SetProperty("Receiver", std::string("Sherlock Holmes"));

  return_builder.SetPath("ReturnAddress")
      .SetDataType(yoriito::databroker::DataType::DATA_TYPE_STRUCT)
      .SetEntryType(yoriito::databroker::ConsumerInspectData::EntryType::
                        ENTRY_TYPE_ATTRIBUTE)
      .SetDescription("Where to send returns")
      .SetComment("")
      .SetDeprecation("")
      .SetUnit("")
      .SetMin(yoriito::ValueType())
      .SetMax(yoriito::ValueType())
      .SetAllowed(std::vector<std::string>{})
      .SetDefaultValue(
          std::make_unique<yoriito::StructData>(std::move(return_default)))
      .SetArraySize(0)
      .SetPattern("")
      .SetCustomAttributes({});

  yoriito::databroker::ConsumerInspectData return_data_point =
      yoriito::databroker::ConsumerInspectData::CreateFromBuilder(
          return_builder);

  auto delivery_info_type =
      std::make_shared<yoriito::databroker::StructType>("Types.DeliveryInfo");
  delivery_info_type->AddProperty(yoriito::databroker::PropertyType(
      "Types.DeliveryInfo.Address",
      yoriito::databroker::DataType::DATA_TYPE_STRING));
  delivery_info_type->AddProperty(yoriito::databroker::PropertyType(
      "Types.DeliveryInfo.Receiver",
      yoriito::databroker::DataType::DATA_TYPE_STRING));

  delivery_data_point.SetDataTypeRef(
      yoriito::databroker::StructTypeRef(delivery_info_type));
  return_data_point.SetDataTypeRef(
      yoriito::databroker::StructTypeRef(delivery_info_type));

  std::vector<yoriito::databroker::ConsumerInspectData> data_points;
  data_points.push_back(delivery_data_point);
  data_points.push_back(return_data_point);

  std::vector<std::shared_ptr<yoriito::databroker::StructType>> struct_types;
  struct_types.push_back(delivery_info_type);

  // Construct response with data points and struct types
  yoriito::databroker::ConsumerInspectResponse response(
      std::move(data_points), std::move(struct_types));

  const auto& points = response.GetDataPoints();
  ASSERT_EQ(points.size(), 2U);

  EXPECT_EQ(points[0].GetPath(), "Delivery");
  EXPECT_EQ(points[0].GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRUCT);
  EXPECT_EQ(
      points[0].GetEntryType(),
      yoriito::databroker::ConsumerInspectData::EntryType::ENTRY_TYPE_SENSOR);
  ASSERT_TRUE(points[0].GetDataTypeRef().has_value());
  ASSERT_TRUE(points[0].GetDataTypeRef()->IsResolved());
  ASSERT_NE(points[0].GetDataTypeRef()->Resolved(), nullptr);
  EXPECT_EQ(points[0].GetDataTypeRef()->Resolved().get(),
            delivery_info_type.get());

  EXPECT_EQ(points[1].GetPath(), "ReturnAddress");
  EXPECT_EQ(points[1].GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRUCT);
  EXPECT_EQ(points[1].GetEntryType(), yoriito::databroker::ConsumerInspectData::
                                          EntryType::ENTRY_TYPE_ATTRIBUTE);
  EXPECT_EQ(points[1].GetDescription(), "Where to send returns");
  ASSERT_TRUE(points[1].GetDataTypeRef().has_value());
  ASSERT_TRUE(points[1].GetDataTypeRef()->IsResolved());

  ASSERT_TRUE(std::holds_alternative<yoriito::StructDataPtr>(
      points[1].GetDefaultValue()));
  const auto& default_ptr =
      std::get<yoriito::StructDataPtr>(points[1].GetDefaultValue());
  ASSERT_NE(default_ptr, nullptr);
  const auto& default_props = default_ptr->GetProperties();
  ASSERT_EQ(default_props.size(), 2U);
  ASSERT_NE(default_props.find("Address"), default_props.end());
  ASSERT_NE(default_props.find("Receiver"), default_props.end());
  EXPECT_EQ(std::get<std::string>(default_props.at("Address")),
            "221B Baker Street");
  EXPECT_EQ(std::get<std::string>(default_props.at("Receiver")),
            "Sherlock Holmes");

  const auto& properties = delivery_info_type->GetProperties();
  ASSERT_EQ(properties.size(), 2U);
  const auto* delivery_address = properties.at("Types.DeliveryInfo.Address");
  ASSERT_NE(delivery_address, nullptr);
  EXPECT_EQ(delivery_address->GetPath(), "Types.DeliveryInfo.Address");
  EXPECT_EQ(delivery_address->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRING);
  const auto* delivery_receiver = properties.at("Types.DeliveryInfo.Receiver");
  ASSERT_NE(delivery_receiver, nullptr);
  EXPECT_EQ(delivery_receiver->GetPath(), "Types.DeliveryInfo.Receiver");
  EXPECT_EQ(delivery_receiver->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRING);

  // struct
  EXPECT_EQ(response.GetStructTypes().size(), 1U);
  EXPECT_EQ(response.GetStructTypes()[0]->GetPath(), "Types.DeliveryInfo");
  const auto& struct_properties = response.GetStructTypes()[0]->GetProperties();

  // foreach property.
  for (const auto& property : struct_properties) {
    if (property.GetPath() == "Types.DeliveryInfo.Address") {
      EXPECT_EQ(property.GetPath(), "Types.DeliveryInfo.Address");
      EXPECT_EQ(property.GetDataType(),
                yoriito::databroker::DataType::DATA_TYPE_STRING);
    } else if (property.GetPath() == "Types.DeliveryInfo.Receiver") {
      EXPECT_EQ(property.GetPath(), "Types.DeliveryInfo.Receiver");
      EXPECT_EQ(property.GetDataType(),
                yoriito::databroker::DataType::DATA_TYPE_STRING);
    } else {
      FAIL() << "Unexpected property key: " << property.GetPath();
    }
  }
  ASSERT_EQ(struct_properties.size(), 2U);
  const auto* struct_address =
      struct_properties.at("Types.DeliveryInfo.Address");
  ASSERT_NE(struct_address, nullptr);
  EXPECT_EQ(struct_address->GetPath(), "Types.DeliveryInfo.Address");
  EXPECT_EQ(struct_address->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRING);
  const auto* struct_receiver =
      struct_properties.at("Types.DeliveryInfo.Receiver");
  ASSERT_NE(struct_receiver, nullptr);
  EXPECT_EQ(struct_receiver->GetPath(), "Types.DeliveryInfo.Receiver");
  EXPECT_EQ(struct_receiver->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRING);
}

//
// OpenHours:
//   type: struct
//   description: A struct datatype containing information on open hours

// OpenHours.Open:
//   datatype: uint8
//   type: property
//   max: 24
//   description: Time the address opens

// OpenHours.Close:
//   datatype: uint8
//   type: property
//   max: 24
//   description: Time the address close

// DeliveryInfo:
//   type: struct
//   description: A struct datatype containing info for each delivery

// DeliveryInfo.Address:
//   datatype: string
//   type: property
//   description: Destination address

// DeliveryInfo.Receiver:
//   datatype: string
//   type: property
//   description: Name of receiver

// DeliveryInfo.Open:
//   datatype: OpenHours
//   type: property
//   description: When is receiver available

// ReturnAddress:
//   datatype: Types.DeliveryInfo
//   type: attribute
//   description: Where to send returns
//   default:
//     Address: "221B Baker Street"
//     Receiver: "Sherlock Holmes"
//     Open:
//         Open: 9
//         Close: 17
//
TEST(TestConsumerInspectResponse,
     StructTypeTwoLevelNestedDataPointIsPreserved) {
  auto builder = yoriito::databroker::BaseInspectData::CreateBuilder();
  yoriito::StructData open_default;
  open_default.SetProperty("Open", static_cast<uint8_t>(9));
  open_default.SetProperty("Close", static_cast<uint8_t>(17));

  yoriito::StructData return_default;
  return_default.SetProperty("Address", std::string("221B Baker Street"));
  return_default.SetProperty("Receiver", std::string("Sherlock Holmes"));
  return_default.SetProperty(
      "Open", std::make_unique<yoriito::StructData>(std::move(open_default)));

  builder.SetPath("ReturnAddress")
      .SetDataType(yoriito::databroker::DataType::DATA_TYPE_STRUCT)
      .SetEntryType(yoriito::databroker::ConsumerInspectData::EntryType::
                        ENTRY_TYPE_ATTRIBUTE)
      .SetDescription("Where to send returns")
      .SetComment("")
      .SetDeprecation("")
      .SetUnit("")
      .SetMin(yoriito::ValueType())
      .SetMax(yoriito::ValueType())
      .SetAllowed(std::vector<std::string>{})
      .SetDefaultValue(
          std::make_unique<yoriito::StructData>(std::move(return_default)))
      .SetArraySize(0)
      .SetPattern("")
      .SetCustomAttributes({});

  yoriito::databroker::ConsumerInspectData struct_data_point =
      yoriito::databroker::ConsumerInspectData::CreateFromBuilder(builder);

  auto open_hours_type =
      std::make_shared<yoriito::databroker::StructType>("OpenHours");
  open_hours_type->AddProperty(yoriito::databroker::PropertyType(
      "OpenHours.Open", yoriito::databroker::DataType::DATA_TYPE_UINT8));
  open_hours_type->AddProperty(yoriito::databroker::PropertyType(
      "OpenHours.Close", yoriito::databroker::DataType::DATA_TYPE_UINT8));

  auto delivery_info_type =
      std::make_shared<yoriito::databroker::StructType>("DeliveryInfo");
  delivery_info_type->AddProperty(yoriito::databroker::PropertyType(
      "DeliveryInfo.Address", yoriito::databroker::DataType::DATA_TYPE_STRING));
  delivery_info_type->AddProperty(yoriito::databroker::PropertyType(
      "DeliveryInfo.Receiver",
      yoriito::databroker::DataType::DATA_TYPE_STRING));
  delivery_info_type->AddProperty(yoriito::databroker::PropertyType(
      "DeliveryInfo.Open", yoriito::databroker::DataType::DATA_TYPE_STRUCT,
      yoriito::databroker::StructTypeRef(open_hours_type)));

  struct_data_point.SetDataTypeRef(
      yoriito::databroker::StructTypeRef(delivery_info_type));

  std::vector<yoriito::databroker::ConsumerInspectData> data_points;
  data_points.push_back(struct_data_point);

  std::vector<std::shared_ptr<yoriito::databroker::StructType>> struct_types;
  struct_types.push_back(delivery_info_type);
  struct_types.push_back(open_hours_type);

  yoriito::databroker::ConsumerInspectResponse response(
      std::move(data_points), std::move(struct_types));

  // inspect response
  const auto& points = response.GetDataPoints();
  ASSERT_EQ(points.size(), 1U);
  EXPECT_EQ(points[0].GetPath(), "ReturnAddress");
  EXPECT_EQ(points[0].GetDescription(), "Where to send returns");
  ASSERT_TRUE(points[0].GetDataTypeRef().has_value());
  ASSERT_TRUE(points[0].GetDataTypeRef()->IsResolved());

  const auto root_struct = points[0].GetDataTypeRef()->Resolved();
  ASSERT_NE(root_struct, nullptr);
  EXPECT_EQ(root_struct->GetPath(), "DeliveryInfo");

  const auto& root_properties = root_struct->GetProperties();
  ASSERT_EQ(root_properties.size(), 3U);
  const auto* delivery_open = root_properties.at("DeliveryInfo.Open");
  ASSERT_NE(delivery_open, nullptr);
  EXPECT_EQ(delivery_open->GetPath(), "DeliveryInfo.Open");
  EXPECT_EQ(delivery_open->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRUCT);
  ASSERT_TRUE(delivery_open->GetDataTypeRef().IsResolved());

  const auto nested_struct = delivery_open->GetDataTypeRef().Resolved();
  ASSERT_NE(nested_struct, nullptr);
  EXPECT_EQ(nested_struct->GetPath(), "OpenHours");

  const auto& nested_properties = nested_struct->GetProperties();
  ASSERT_EQ(nested_properties.size(), 2U);
  const auto* nested_open = nested_properties.at("OpenHours.Open");
  ASSERT_NE(nested_open, nullptr);
  EXPECT_EQ(nested_open->GetPath(), "OpenHours.Open");
  EXPECT_EQ(nested_open->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_UINT8);
  const auto* nested_close = nested_properties.at("OpenHours.Close");
  ASSERT_NE(nested_close, nullptr);
  EXPECT_EQ(nested_close->GetPath(), "OpenHours.Close");
  EXPECT_EQ(nested_close->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_UINT8);

  ASSERT_TRUE(std::holds_alternative<yoriito::StructDataPtr>(
      points[0].GetDefaultValue()));
  const auto& default_ptr =
      std::get<yoriito::StructDataPtr>(points[0].GetDefaultValue());
  ASSERT_NE(default_ptr, nullptr);
  const auto& default_props = default_ptr->GetProperties();
  ASSERT_NE(default_props.find("Open"), default_props.end());
  ASSERT_TRUE(
      std::holds_alternative<yoriito::StructDataPtr>(default_props.at("Open")));
  const auto& open_ptr =
      std::get<yoriito::StructDataPtr>(default_props.at("Open"));
  ASSERT_NE(open_ptr, nullptr);
  const auto& open_props = open_ptr->GetProperties();
  EXPECT_EQ(std::get<uint8_t>(open_props.at("Open")), static_cast<uint8_t>(9));
  EXPECT_EQ(std::get<uint8_t>(open_props.at("Close")),
            static_cast<uint8_t>(17));

  const auto& response_structs = response.GetStructTypes();
  ASSERT_EQ(response_structs.size(), 2U);
  EXPECT_EQ(response_structs[0].get(), delivery_info_type.get());
  EXPECT_EQ(response_structs[1].get(), open_hours_type.get());

  // struct
  EXPECT_EQ(response.GetStructTypes()[0]->GetPath(), "DeliveryInfo");
  const auto& struct_properties = response.GetStructTypes()[0]->GetProperties();
  ASSERT_EQ(struct_properties.size(), 3U);
  const auto* struct_address_nested =
      struct_properties.at("DeliveryInfo.Address");
  ASSERT_NE(struct_address_nested, nullptr);
  EXPECT_EQ(struct_address_nested->GetPath(), "DeliveryInfo.Address");
  EXPECT_EQ(struct_address_nested->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRING);
  const auto* struct_receiver_nested =
      struct_properties.at("DeliveryInfo.Receiver");
  ASSERT_NE(struct_receiver_nested, nullptr);
  EXPECT_EQ(struct_receiver_nested->GetPath(), "DeliveryInfo.Receiver");
  EXPECT_EQ(struct_receiver_nested->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRING);
  const auto* struct_open_nested = struct_properties.at("DeliveryInfo.Open");
  ASSERT_NE(struct_open_nested, nullptr);
  EXPECT_EQ(struct_open_nested->GetPath(), "DeliveryInfo.Open");
  EXPECT_EQ(struct_open_nested->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRUCT);
  EXPECT_EQ(struct_open_nested->GetDataTypeRef().Resolved().get(),
            open_hours_type.get());
  // nested struct
  EXPECT_EQ(response.GetStructTypes()[1]->GetPath(), "OpenHours");
  const auto& nested_struct_properties =
      response.GetStructTypes()[1]->GetProperties();
  ASSERT_EQ(nested_struct_properties.size(), 2U);
  const auto* nested_open_struct =
      nested_struct_properties.at("OpenHours.Open");
  ASSERT_NE(nested_open_struct, nullptr);
  EXPECT_EQ(nested_open_struct->GetPath(), "OpenHours.Open");
  EXPECT_EQ(nested_open_struct->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_UINT8);
  const auto* nested_close_struct =
      nested_struct_properties.at("OpenHours.Close");
  ASSERT_NE(nested_close_struct, nullptr);
  EXPECT_EQ(nested_close_struct->GetPath(), "OpenHours.Close");
  EXPECT_EQ(nested_close_struct->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_UINT8);
}
