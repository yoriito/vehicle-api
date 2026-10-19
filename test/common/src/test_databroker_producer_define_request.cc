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
#include <variant>
#include <vector>

#include "databroker/producer_define_entry.h"
#include "databroker/producer_define_request.h"
#include "databroker/types/struct_type.h"
#include "databroker/types/struct_type_ref.h"

TEST(TestDataBrokerProducerDefineRequest,
     AllPrimitiveMetadataEntriesAreRegistered) {
  struct PrimitiveMetadata {
    const char* path;
    yoriito::databroker::DataType type;
    yoriito::ValueType default_value;
  };

  std::vector<PrimitiveMetadata> primitive_metadata;
  primitive_metadata.reserve(25);
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.String", yoriito::databroker::DataType::DATA_TYPE_STRING,
      std::string("text")});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Boolean", yoriito::databroker::DataType::DATA_TYPE_BOOLEAN,
      true});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Int8", yoriito::databroker::DataType::DATA_TYPE_INT8,
      static_cast<int8_t>(-8)});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Int16", yoriito::databroker::DataType::DATA_TYPE_INT16,
      static_cast<int16_t>(-16)});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Int32", yoriito::databroker::DataType::DATA_TYPE_INT32,
      static_cast<int32_t>(-32)});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Int64", yoriito::databroker::DataType::DATA_TYPE_INT64,
      static_cast<int64_t>(-64)});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Uint8", yoriito::databroker::DataType::DATA_TYPE_UINT8,
      static_cast<uint8_t>(8)});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Uint16", yoriito::databroker::DataType::DATA_TYPE_UINT16,
      static_cast<uint16_t>(16)});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Uint32", yoriito::databroker::DataType::DATA_TYPE_UINT32,
      static_cast<uint32_t>(32)});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Uint64", yoriito::databroker::DataType::DATA_TYPE_UINT64,
      static_cast<uint64_t>(64)});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Float", yoriito::databroker::DataType::DATA_TYPE_FLOAT, 1.5f});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Double",
                        yoriito::databroker::DataType::DATA_TYPE_DOUBLE, 2.5});
  primitive_metadata.emplace_back(PrimitiveMetadata{
      "Primitive.Timestamp", yoriito::databroker::DataType::DATA_TYPE_TIMESTAMP,
      static_cast<uint64_t>(1710000000)});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.StringArray",
                        yoriito::databroker::DataType::DATA_TYPE_STRING_ARRAY,
                        std::vector<std::string>{"a", "b"}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.BooleanArray",
                        yoriito::databroker::DataType::DATA_TYPE_BOOLEAN_ARRAY,
                        std::vector<bool>{true, false}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Int8Array",
                        yoriito::databroker::DataType::DATA_TYPE_INT8_ARRAY,
                        std::vector<int8_t>{-1, 0, 1}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Int16Array",
                        yoriito::databroker::DataType::DATA_TYPE_INT16_ARRAY,
                        std::vector<int16_t>{-2, 0, 2}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Int32Array",
                        yoriito::databroker::DataType::DATA_TYPE_INT32_ARRAY,
                        std::vector<int32_t>{-3, 0, 3}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Int64Array",
                        yoriito::databroker::DataType::DATA_TYPE_INT64_ARRAY,
                        std::vector<int64_t>{-4, 0, 4}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Uint8Array",
                        yoriito::databroker::DataType::DATA_TYPE_UINT8_ARRAY,
                        std::vector<uint8_t>{1, 2, 3}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Uint16Array",
                        yoriito::databroker::DataType::DATA_TYPE_UINT16_ARRAY,
                        std::vector<uint16_t>{4, 5, 6}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Uint32Array",
                        yoriito::databroker::DataType::DATA_TYPE_UINT32_ARRAY,
                        std::vector<uint32_t>{7, 8, 9}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.Uint64Array",
                        yoriito::databroker::DataType::DATA_TYPE_UINT64_ARRAY,
                        std::vector<uint64_t>{10, 11, 12}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.FloatArray",
                        yoriito::databroker::DataType::DATA_TYPE_FLOAT_ARRAY,
                        std::vector<float>{1.0f, 2.0f}});
  primitive_metadata.emplace_back(
      PrimitiveMetadata{"Primitive.DoubleArray",
                        yoriito::databroker::DataType::DATA_TYPE_DOUBLE_ARRAY,
                        std::vector<double>{3.0, 4.0}});

  std::vector<yoriito::databroker::ProducerDefineEntry> entries;
  entries.reserve(primitive_metadata.size());

  for (const auto& metadata : primitive_metadata) {
    auto builder = yoriito::databroker::BaseInspectData::CreateBuilder();
    builder.SetPath(metadata.path)
        .SetDataType(metadata.type)
        .SetEntryType(
            yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_SENSOR)
        .SetDescription("")
        .SetComment("")
        .SetDeprecation("")
        .SetUnit("")
        .SetMin(yoriito::ValueType())
        .SetMax(yoriito::ValueType())
        .SetAllowed(std::vector<std::string>{})
        .SetDefaultValue(metadata.default_value)
        .SetArraySize(0)
        .SetPattern("")
        .SetCustomAttributes({});

    entries.push_back(
        yoriito::databroker::ProducerDefineEntry::CreateFromBuilder(builder));
  }

  yoriito::databroker::ProducerDefineRequest request(std::move(entries));

  const auto& defined_entries = request.GetDefineEntries();
  ASSERT_EQ(defined_entries.size(), primitive_metadata.size());

  for (size_t i = 0; i < primitive_metadata.size(); ++i) {
    EXPECT_EQ(defined_entries[i].GetPath(), primitive_metadata[i].path);
    EXPECT_EQ(defined_entries[i].GetDataType(), primitive_metadata[i].type);
    EXPECT_EQ(
        defined_entries[i].GetEntryType(),
        yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_SENSOR);
    EXPECT_TRUE(
        yoriito::ValueTypeEquals(defined_entries[i].GetDefaultValue(),
                                   primitive_metadata[i].default_value));
  }
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

TEST(TestDataBrokerProducerDefineRequest, StructEntryIsPreserved) {
  auto delivery_builder = yoriito::databroker::BaseInspectData::CreateBuilder();
  delivery_builder.SetPath("Delivery")
      .SetDataType(yoriito::databroker::DataType::DATA_TYPE_STRUCT)
      .SetEntryType(
          yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_SENSOR)
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

  yoriito::databroker::ProducerDefineEntry delivery_entry =
      yoriito::databroker::ProducerDefineEntry::CreateFromBuilder(
          delivery_builder);

  auto return_builder = yoriito::databroker::BaseInspectData::CreateBuilder();
  yoriito::StructData return_default;
  return_default.SetProperty("Address", std::string("221B Baker Street"));
  return_default.SetProperty("Receiver", std::string("Sherlock Holmes"));

  return_builder.SetPath("ReturnAddress")
      .SetDataType(yoriito::databroker::DataType::DATA_TYPE_STRUCT)
      .SetEntryType(
          yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_ATTRIBUTE)
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

  yoriito::databroker::ProducerDefineEntry return_entry =
      yoriito::databroker::ProducerDefineEntry::CreateFromBuilder(
          return_builder);

  auto delivery_info_type =
      std::make_shared<yoriito::databroker::StructType>("Types.DeliveryInfo");
  delivery_info_type->AddProperty(yoriito::databroker::PropertyType(
      "Types.DeliveryInfo.Address",
      yoriito::databroker::DataType::DATA_TYPE_STRING));
  delivery_info_type->AddProperty(yoriito::databroker::PropertyType(
      "Types.DeliveryInfo.Receiver",
      yoriito::databroker::DataType::DATA_TYPE_STRING));

  delivery_entry.SetDataTypeRef(
      yoriito::databroker::StructTypeRef(delivery_info_type));
  return_entry.SetDataTypeRef(
      yoriito::databroker::StructTypeRef(delivery_info_type));

  std::vector<yoriito::databroker::ProducerDefineEntry> entries;
  entries.push_back(delivery_entry);
  entries.push_back(return_entry);

  yoriito::databroker::ProducerDefineRequest request(std::move(entries));

  const auto& defined_entries = request.GetDefineEntries();
  ASSERT_EQ(defined_entries.size(), 2U);
  EXPECT_EQ(defined_entries[0].GetPath(), "Delivery");
  EXPECT_EQ(defined_entries[0].GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRUCT);
  ASSERT_TRUE(defined_entries[0].GetDataTypeRef().has_value());
  ASSERT_TRUE(defined_entries[0].GetDataTypeRef()->IsResolved());
  ASSERT_NE(defined_entries[0].GetDataTypeRef()->Resolved(), nullptr);
  EXPECT_EQ(defined_entries[0].GetDataTypeRef()->Resolved().get(),
            delivery_info_type.get());

  EXPECT_EQ(defined_entries[1].GetPath(), "ReturnAddress");
  EXPECT_EQ(defined_entries[1].GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRUCT);
  EXPECT_EQ(
      defined_entries[1].GetEntryType(),
      yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_ATTRIBUTE);
  EXPECT_EQ(defined_entries[1].GetDescription(), "Where to send returns");
  ASSERT_TRUE(defined_entries[1].GetDataTypeRef().has_value());
  ASSERT_TRUE(defined_entries[1].GetDataTypeRef()->IsResolved());
  ASSERT_TRUE(std::holds_alternative<yoriito::StructDataPtr>(
      defined_entries[1].GetDefaultValue()));

  const auto& default_ptr =
      std::get<yoriito::StructDataPtr>(defined_entries[1].GetDefaultValue());
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
TEST(TestDataBrokerProducerDefineRequest,
     StructTwoLevelNestedEntryIsPreserved) {
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
      .SetEntryType(
          yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_ATTRIBUTE)
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

  yoriito::databroker::ProducerDefineEntry entry =
      yoriito::databroker::ProducerDefineEntry::CreateFromBuilder(builder);

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

  entry.SetDataTypeRef(yoriito::databroker::StructTypeRef(delivery_info_type));

  std::vector<yoriito::databroker::ProducerDefineEntry> entries;
  entries.push_back(entry);

  yoriito::databroker::ProducerDefineRequest request(std::move(entries));

  const auto& defined_entries = request.GetDefineEntries();
  ASSERT_EQ(defined_entries.size(), 1U);
  EXPECT_EQ(defined_entries[0].GetPath(), "ReturnAddress");
  EXPECT_EQ(
      defined_entries[0].GetEntryType(),
      yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_ATTRIBUTE);
  EXPECT_EQ(defined_entries[0].GetDescription(), "Where to send returns");
  ASSERT_TRUE(defined_entries[0].GetDataTypeRef().has_value());
  ASSERT_TRUE(defined_entries[0].GetDataTypeRef()->IsResolved());

  const auto root_struct = defined_entries[0].GetDataTypeRef()->Resolved();
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
  const auto* open_hours_open = nested_properties.at("OpenHours.Open");
  ASSERT_NE(open_hours_open, nullptr);
  EXPECT_EQ(open_hours_open->GetPath(), "OpenHours.Open");
  EXPECT_EQ(open_hours_open->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_UINT8);
  const auto* open_hours_close = nested_properties.at("OpenHours.Close");
  ASSERT_NE(open_hours_close, nullptr);
  EXPECT_EQ(open_hours_close->GetPath(), "OpenHours.Close");
  EXPECT_EQ(open_hours_close->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_UINT8);

  ASSERT_TRUE(std::holds_alternative<yoriito::StructDataPtr>(
      defined_entries[0].GetDefaultValue()));
  const auto& default_ptr =
      std::get<yoriito::StructDataPtr>(defined_entries[0].GetDefaultValue());
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
}

TEST(TestDataBrokerProducerDefineRequest,
     PrimitiveUint8SingleSignalIsPreserved) {
  auto builder = yoriito::databroker::BaseInspectData::CreateBuilder();
  builder.SetPath("Vehicle.SpeedLevel")
      .SetDataType(yoriito::databroker::DataType::DATA_TYPE_UINT8)
      .SetEntryType(
          yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_SENSOR)
      .SetDescription("Speed level")
      .SetComment("")
      .SetDeprecation("")
      .SetUnit("")
      .SetMin(static_cast<uint8_t>(0))
      .SetMax(static_cast<uint8_t>(255))
      .SetAllowed(std::vector<std::string>{})
      .SetDefaultValue(static_cast<uint8_t>(42))
      .SetArraySize(0)
      .SetPattern("")
      .SetCustomAttributes({});

  std::vector<yoriito::databroker::ProducerDefineEntry> entries;
  entries.push_back(
      yoriito::databroker::ProducerDefineEntry::CreateFromBuilder(builder));

  yoriito::databroker::ProducerDefineRequest request(std::move(entries));

  const auto& defined_entries = request.GetDefineEntries();
  ASSERT_EQ(defined_entries.size(), 1U);
  EXPECT_EQ(defined_entries[0].GetPath(), "Vehicle.SpeedLevel");
  EXPECT_EQ(defined_entries[0].GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_UINT8);
  EXPECT_EQ(defined_entries[0].GetEntryType(),
            yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_SENSOR);
  EXPECT_EQ(std::get<uint8_t>(defined_entries[0].GetMin()),
            static_cast<uint8_t>(0));
  EXPECT_EQ(std::get<uint8_t>(defined_entries[0].GetMax()),
            static_cast<uint8_t>(255));
  EXPECT_EQ(std::get<uint8_t>(defined_entries[0].GetDefaultValue()),
            static_cast<uint8_t>(42));
}

TEST(TestDataBrokerProducerDefineRequest,
     PrimitiveAndStructSignalsMixedArePreserved) {
  auto primitive_builder =
      yoriito::databroker::BaseInspectData::CreateBuilder();
  primitive_builder.SetPath("Vehicle.Speed")
      .SetDataType(yoriito::databroker::DataType::DATA_TYPE_UINT16)
      .SetEntryType(
          yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_SENSOR)
      .SetDescription("Vehicle speed")
      .SetComment("")
      .SetDeprecation("")
      .SetUnit("km/h")
      .SetMin(static_cast<uint16_t>(0))
      .SetMax(static_cast<uint16_t>(300))
      .SetAllowed(std::vector<std::string>{})
      .SetDefaultValue(static_cast<uint16_t>(120))
      .SetArraySize(0)
      .SetPattern("")
      .SetCustomAttributes({});

  auto struct_builder = yoriito::databroker::BaseInspectData::CreateBuilder();
  yoriito::StructData position_default;
  position_default.SetProperty("Latitude", 35.681236);
  position_default.SetProperty("Longitude", 139.767125);

  struct_builder.SetPath("Vehicle.Position")
      .SetDataType(yoriito::databroker::DataType::DATA_TYPE_STRUCT)
      .SetEntryType(
          yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_SENSOR)
      .SetDescription("Vehicle position")
      .SetComment("")
      .SetDeprecation("")
      .SetUnit("")
      .SetMin(yoriito::ValueType())
      .SetMax(yoriito::ValueType())
      .SetAllowed(std::vector<std::string>{})
      .SetDefaultValue(
          std::make_unique<yoriito::StructData>(std::move(position_default)))
      .SetArraySize(0)
      .SetPattern("")
      .SetCustomAttributes({});

  yoriito::databroker::ProducerDefineEntry primitive_entry =
      yoriito::databroker::ProducerDefineEntry::CreateFromBuilder(
          primitive_builder);
  yoriito::databroker::ProducerDefineEntry struct_entry =
      yoriito::databroker::ProducerDefineEntry::CreateFromBuilder(
          struct_builder);

  auto position_type =
      std::make_shared<yoriito::databroker::StructType>("Types.Position");
  position_type->AddProperty(yoriito::databroker::PropertyType(
      "Types.Position.Latitude",
      yoriito::databroker::DataType::DATA_TYPE_DOUBLE));
  position_type->AddProperty(yoriito::databroker::PropertyType(
      "Types.Position.Longitude",
      yoriito::databroker::DataType::DATA_TYPE_DOUBLE));

  struct_entry.SetDataTypeRef(
      yoriito::databroker::StructTypeRef(position_type));

  std::vector<yoriito::databroker::ProducerDefineEntry> entries;
  entries.push_back(primitive_entry);
  entries.push_back(struct_entry);

  yoriito::databroker::ProducerDefineRequest request(std::move(entries));

  const auto& defined_entries = request.GetDefineEntries();
  ASSERT_EQ(defined_entries.size(), 2U);

  EXPECT_EQ(defined_entries[0].GetPath(), "Vehicle.Speed");
  EXPECT_EQ(defined_entries[0].GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_UINT16);
  EXPECT_EQ(defined_entries[0].GetEntryType(),
            yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_SENSOR);
  EXPECT_EQ(std::get<uint16_t>(defined_entries[0].GetDefaultValue()),
            static_cast<uint16_t>(120));
  EXPECT_FALSE(defined_entries[0].GetDataTypeRef().has_value());

  EXPECT_EQ(defined_entries[1].GetPath(), "Vehicle.Position");
  EXPECT_EQ(defined_entries[1].GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRUCT);
  EXPECT_EQ(defined_entries[1].GetEntryType(),
            yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_SENSOR);
  ASSERT_TRUE(defined_entries[1].GetDataTypeRef().has_value());
  ASSERT_TRUE(defined_entries[1].GetDataTypeRef()->IsResolved());
  EXPECT_EQ(defined_entries[1].GetDataTypeRef()->Resolved().get(),
            position_type.get());
  ASSERT_TRUE(std::holds_alternative<yoriito::StructDataPtr>(
      defined_entries[1].GetDefaultValue()));

  const auto& position_default_ptr =
      std::get<yoriito::StructDataPtr>(defined_entries[1].GetDefaultValue());
  ASSERT_NE(position_default_ptr, nullptr);
  const auto& position_props = position_default_ptr->GetProperties();
  ASSERT_EQ(position_props.size(), 2U);
  EXPECT_DOUBLE_EQ(std::get<double>(position_props.at("Latitude")), 35.681236);
  EXPECT_DOUBLE_EQ(std::get<double>(position_props.at("Longitude")),
                   139.767125);
}

TEST(TestDataBrokerProducerDefineRequest, StructTypeGetPropertyByName) {
  auto info_type =
      std::make_shared<yoriito::databroker::StructType>("Types.Info");
  info_type->AddProperty(yoriito::databroker::PropertyType(
      "Types.Info.Address", yoriito::databroker::DataType::DATA_TYPE_STRING));
  info_type->AddProperty(yoriito::databroker::PropertyType(
      "Types.Info.Receiver", yoriito::databroker::DataType::DATA_TYPE_STRING));

  const auto properties = info_type->GetProperties();

  const auto* address_property = properties.at("Types.Info.Address");
  ASSERT_NE(address_property, nullptr);
  EXPECT_EQ(address_property->GetPath(), "Types.Info.Address");
  EXPECT_EQ(address_property->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRING);

  const auto* receiver_property = properties.at("Types.Info.Receiver");
  ASSERT_NE(receiver_property, nullptr);
  EXPECT_EQ(receiver_property->GetPath(), "Types.Info.Receiver");
  EXPECT_EQ(receiver_property->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRING);

  EXPECT_EQ(properties.at("Types.Info.Unknown"), nullptr);
}
