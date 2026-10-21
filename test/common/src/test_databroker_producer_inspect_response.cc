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

#include "databroker/producer_inspect_response.h"
#include "databroker/types/struct_type.h"
#include "databroker/types/struct_type_ref.h"

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

TEST(TestProducerInspectResponse, StructTypeDataPointIsPreserved) {
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

  yoriito::databroker::ProducerInspectData delivery_data_point =
      yoriito::databroker::ProducerInspectData::CreateFromBuilder(
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

  yoriito::databroker::ProducerInspectData return_data_point =
      yoriito::databroker::ProducerInspectData::CreateFromBuilder(
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

  std::vector<yoriito::databroker::ProducerInspectData> data_points;
  data_points.push_back(delivery_data_point);
  data_points.push_back(return_data_point);

  std::vector<std::shared_ptr<yoriito::databroker::StructType>> struct_types;
  struct_types.push_back(delivery_info_type);

  // Construct response with data points and struct types
  yoriito::databroker::ProducerInspectResponse response(
      std::move(data_points), std::move(struct_types));

  const auto& points = response.GetDataPoints();
  ASSERT_EQ(points.size(), 2U);

  EXPECT_EQ(points[0].GetPath(), "Delivery");
  EXPECT_EQ(points[0].GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRUCT);
  EXPECT_EQ(points[0].GetEntryType(),
            yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_SENSOR);
  ASSERT_TRUE(points[0].GetDataTypeRef().has_value());
  ASSERT_TRUE(points[0].GetDataTypeRef()->IsResolved());
  ASSERT_NE(points[0].GetDataTypeRef()->Resolved(), nullptr);
  EXPECT_EQ(points[0].GetDataTypeRef()->Resolved().get(),
            delivery_info_type.get());

  EXPECT_EQ(points[1].GetPath(), "ReturnAddress");
  EXPECT_EQ(points[1].GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRUCT);
  EXPECT_EQ(
      points[1].GetEntryType(),
      yoriito::databroker::BaseInspectData::EntryType::ENTRY_TYPE_ATTRIBUTE);
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
TEST(TestProducerInspectResponse,
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

  yoriito::databroker::ProducerInspectData struct_data_point =
      yoriito::databroker::ProducerInspectData::CreateFromBuilder(builder);

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

  std::vector<yoriito::databroker::ProducerInspectData> data_points;
  data_points.push_back(struct_data_point);

  std::vector<std::shared_ptr<yoriito::databroker::StructType>> struct_types;
  struct_types.push_back(delivery_info_type);
  struct_types.push_back(open_hours_type);
  // Construct response with data points and struct types
  yoriito::databroker::ProducerInspectResponse response(
      std::move(data_points), std::move(struct_types));

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
  // struct
  EXPECT_EQ(response.GetStructTypes()[0]->GetPath(), "DeliveryInfo");
  const auto& struct_properties = response.GetStructTypes()[0]->GetProperties();
  ASSERT_EQ(struct_properties.size(), 3U);
  const auto* struct_address = struct_properties.at("DeliveryInfo.Address");
  ASSERT_NE(struct_address, nullptr);
  EXPECT_EQ(struct_address->GetPath(), "DeliveryInfo.Address");
  EXPECT_EQ(struct_address->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRING);
  const auto* struct_receiver = struct_properties.at("DeliveryInfo.Receiver");
  ASSERT_NE(struct_receiver, nullptr);
  EXPECT_EQ(struct_receiver->GetPath(), "DeliveryInfo.Receiver");
  EXPECT_EQ(struct_receiver->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRING);
  const auto* struct_open = struct_properties.at("DeliveryInfo.Open");
  ASSERT_NE(struct_open, nullptr);
  EXPECT_EQ(struct_open->GetPath(), "DeliveryInfo.Open");
  EXPECT_EQ(struct_open->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_STRUCT);
  EXPECT_EQ(struct_open->GetDataTypeRef().Resolved().get(),
            open_hours_type.get());
  // nested struct
  EXPECT_EQ(response.GetStructTypes()[1]->GetPath(), "OpenHours");
  const auto& nested_struct_properties =
      response.GetStructTypes()[1]->GetProperties();
  ASSERT_EQ(nested_struct_properties.size(), 2U);
  const auto* nested_open = nested_struct_properties.at("OpenHours.Open");
  ASSERT_NE(nested_open, nullptr);
  EXPECT_EQ(nested_open->GetPath(), "OpenHours.Open");
  EXPECT_EQ(nested_open->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_UINT8);
  const auto* nested_close = nested_struct_properties.at("OpenHours.Close");
  ASSERT_NE(nested_close, nullptr);
  EXPECT_EQ(nested_close->GetPath(), "OpenHours.Close");
  EXPECT_EQ(nested_close->GetDataType(),
            yoriito::databroker::DataType::DATA_TYPE_UINT8);
}
