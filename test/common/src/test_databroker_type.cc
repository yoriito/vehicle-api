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
#include <variant>

#include "databroker_type.h"

TEST(TestDataBrokerType, monostate) {
  yoriito::ValueType test = std::monostate{};
  ASSERT_TRUE(std::holds_alternative<std::monostate>(test));
}
TEST(TestDataBrokerType, monostateAssignment) {
  yoriito::ValueType test = static_cast<bool>(true);
  test = std::monostate{};
  ASSERT_TRUE(std::holds_alternative<std::monostate>(test));
}

TEST(TestDataBrokerType, BoolType) {
  yoriito::ValueType test = static_cast<bool>(true);

  bool b = std::get<bool>(test);
  ASSERT_TRUE(std::holds_alternative<bool>(test));
  ASSERT_TRUE(b);
}

TEST(TestDataBrokerType, StringType) {
  yoriito::ValueType test = static_cast<std::string>("TEST");

  std::string b = std::get<std::string>(test);
  ASSERT_TRUE(std::holds_alternative<std::string>(test));
  ASSERT_EQ(b, "TEST");
}

TEST(TestDataBrokerType, StructType) {
  yoriito::StructData struct1;
  yoriito::StructData struct2;

  struct1.SetProperty("key0", std::string_view{"value0"});
  struct1.SetProperty("key1", std::string("value1"));
  struct1.SetProperty("key2", static_cast<int8_t>(42));
  struct1.SetProperty("key3", static_cast<int16_t>(-42));
  struct1.SetProperty("key4", true);
  struct1.SetProperty("key5", static_cast<int32_t>(42));
  struct1.SetProperty("key6", static_cast<int64_t>(-420));
  struct1.SetProperty("key7", static_cast<uint8_t>(8));
  struct1.SetProperty("key8", static_cast<uint16_t>(16));
  struct1.SetProperty("key9", static_cast<uint32_t>(32));
  struct1.SetProperty("key10", static_cast<uint64_t>(64));
  struct1.SetProperty("key11", 42.0f);
  struct1.SetProperty("key12", double(84.0));
  struct1.SetProperty("key13", std::vector<std::string>{"value1", "value2"});
  struct1.SetProperty("key14", std::vector<bool>{true, false, true});
  struct1.SetProperty("key15", std::vector<int8_t>{-1, 0, 1});
  struct1.SetProperty("key16", std::vector<int16_t>{-2, 0, 2});
  struct1.SetProperty("key17", std::vector<int32_t>{-3, 0, 3});
  struct1.SetProperty("key18", std::vector<int64_t>{-4, 0, 4});
  struct1.SetProperty("key19", std::vector<uint8_t>{0, 1, 2, 3});
  struct1.SetProperty("key20", std::vector<uint16_t>{4, 5, 6});
  struct1.SetProperty("key21", std::vector<uint32_t>{7, 8, 9});
  struct1.SetProperty("key22", std::vector<uint64_t>{10, 11, 12});
  struct1.SetProperty("key23", std::vector<float>{1.0f, 2.0f, 3.0f});
  struct1.SetProperty("key24", std::vector<double>{4.0, 5.0, 6.0});
  struct1.SetProperty("key25", std::monostate{});

  yoriito::StructData nested1;
  nested1.SetProperty("nested_key", std::string("nested_value"));
  struct1.SetProperty(
      "key26", std::make_unique<yoriito::StructData>(std::move(nested1)));

  struct2.SetProperty("key0", std::string_view{"value0"});
  struct2.SetProperty("key1", std::string("value1"));
  struct2.SetProperty("key2", static_cast<int8_t>(42));
  struct2.SetProperty("key3", static_cast<int16_t>(-42));
  struct2.SetProperty("key4", true);
  struct2.SetProperty("key5", static_cast<int32_t>(42));
  struct2.SetProperty("key6", static_cast<int64_t>(-420));
  struct2.SetProperty("key7", static_cast<uint8_t>(8));
  struct2.SetProperty("key8", static_cast<uint16_t>(16));
  struct2.SetProperty("key9", static_cast<uint32_t>(32));
  struct2.SetProperty("key10", static_cast<uint64_t>(64));
  struct2.SetProperty("key11", 42.0f);
  struct2.SetProperty("key12", double(84.0));
  struct2.SetProperty("key13", std::vector<std::string>{"value1", "value2"});
  struct2.SetProperty("key14", std::vector<bool>{true, false, true});
  struct2.SetProperty("key15", std::vector<int8_t>{-1, 0, 1});
  struct2.SetProperty("key16", std::vector<int16_t>{-2, 0, 2});
  struct2.SetProperty("key17", std::vector<int32_t>{-3, 0, 3});
  struct2.SetProperty("key18", std::vector<int64_t>{-4, 0, 4});
  struct2.SetProperty("key19", std::vector<uint8_t>{0, 1, 2, 3});
  struct2.SetProperty("key20", std::vector<uint16_t>{4, 5, 6});
  struct2.SetProperty("key21", std::vector<uint32_t>{7, 8, 9});
  struct2.SetProperty("key22", std::vector<uint64_t>{10, 11, 12});
  struct2.SetProperty("key23", std::vector<float>{1.0f, 2.0f, 3.0f});
  struct2.SetProperty("key24", std::vector<double>{4.0, 5.0, 6.0});
  struct2.SetProperty("key25", std::monostate{});

  yoriito::StructData nested2;
  nested2.SetProperty("nested_key", std::string("nested_value"));
  struct2.SetProperty(
      "key26", std::make_unique<yoriito::StructData>(std::move(nested2)));

  ASSERT_EQ(struct1, struct2);
}

TEST(TestDataBrokerType, StructTypeGetProperties) {
  yoriito::StructData struct1;
  yoriito::StructData struct2;

  struct1.SetProperty("key0", std::string_view{"value0"});
  struct1.SetProperty("key1", std::string("value1"));
  struct1.SetProperty("key2", static_cast<int8_t>(42));
  struct1.SetProperty("key3", static_cast<int16_t>(-42));
  struct1.SetProperty("key4", true);
  struct1.SetProperty("key5", static_cast<int32_t>(42));
  struct1.SetProperty("key6", static_cast<int64_t>(-420));
  struct1.SetProperty("key7", static_cast<uint8_t>(8));
  struct1.SetProperty("key8", static_cast<uint16_t>(16));
  struct1.SetProperty("key9", static_cast<uint32_t>(32));
  struct1.SetProperty("key10", static_cast<uint64_t>(64));
  struct1.SetProperty("key11", 42.0f);
  struct1.SetProperty("key12", double(84.0));
  struct1.SetProperty("key13", std::vector<std::string>{"value1", "value2"});
  struct1.SetProperty("key14", std::vector<bool>{true, false, true});
  struct1.SetProperty("key15", std::vector<int8_t>{-1, 0, 1});
  struct1.SetProperty("key16", std::vector<int16_t>{-2, 0, 2});
  struct1.SetProperty("key17", std::vector<int32_t>{-3, 0, 3});
  struct1.SetProperty("key18", std::vector<int64_t>{-4, 0, 4});
  struct1.SetProperty("key19", std::vector<uint8_t>{0, 1, 2, 3});
  struct1.SetProperty("key20", std::vector<uint16_t>{4, 5, 6});
  struct1.SetProperty("key21", std::vector<uint32_t>{7, 8, 9});
  struct1.SetProperty("key22", std::vector<uint64_t>{10, 11, 12});
  struct1.SetProperty("key23", std::vector<float>{1.0f, 2.0f, 3.0f});
  struct1.SetProperty("key24", std::vector<double>{4.0, 5.0, 6.0});
  struct1.SetProperty("key25", std::monostate{});

  yoriito::StructData nested1;
  nested1.SetProperty("nested_key", std::string("nested_value"));
  struct1.SetProperty(
      "key26", std::make_unique<yoriito::StructData>(std::move(nested1)));

  struct2.SetProperty("key0", std::string_view{"value0"});
  struct2.SetProperty("key1", std::string("value1"));
  struct2.SetProperty("key2", static_cast<int8_t>(42));
  struct2.SetProperty("key3", static_cast<int16_t>(-42));
  struct2.SetProperty("key4", true);
  struct2.SetProperty("key5", static_cast<int32_t>(42));
  struct2.SetProperty("key6", static_cast<int64_t>(-420));
  struct2.SetProperty("key7", static_cast<uint8_t>(8));
  struct2.SetProperty("key8", static_cast<uint16_t>(16));
  struct2.SetProperty("key9", static_cast<uint32_t>(32));
  struct2.SetProperty("key10", static_cast<uint64_t>(64));
  struct2.SetProperty("key11", 42.0f);
  struct2.SetProperty("key12", double(84.0));
  struct2.SetProperty("key13", std::vector<std::string>{"value1", "value2"});
  struct2.SetProperty("key14", std::vector<bool>{true, false, true});
  struct2.SetProperty("key15", std::vector<int8_t>{-1, 0, 1});
  struct2.SetProperty("key16", std::vector<int16_t>{-2, 0, 2});
  struct2.SetProperty("key17", std::vector<int32_t>{-3, 0, 3});
  struct2.SetProperty("key18", std::vector<int64_t>{-4, 0, 4});
  struct2.SetProperty("key19", std::vector<uint8_t>{0, 1, 2, 3});
  struct2.SetProperty("key20", std::vector<uint16_t>{4, 5, 6});
  struct2.SetProperty("key21", std::vector<uint32_t>{7, 8, 9});
  struct2.SetProperty("key22", std::vector<uint64_t>{10, 11, 12});
  struct2.SetProperty("key23", std::vector<float>{1.0f, 2.0f, 3.0f});
  struct2.SetProperty("key24", std::vector<double>{4.0, 5.0, 6.0});
  struct2.SetProperty("key25", std::monostate{});

  yoriito::StructData nested2;
  nested2.SetProperty("nested_key", std::string("nested_value"));
  struct2.SetProperty(
      "key26", std::make_unique<yoriito::StructData>(std::move(nested2)));

  const auto& properties1 = struct1.GetProperties();
  const auto& properties2 = struct2.GetProperties();

  ASSERT_EQ(properties1.size(), properties2.size());
  for (const auto& [key, value] : properties1) {
    auto it = properties2.find(key);
    ASSERT_NE(it, properties2.end());

    if (std::holds_alternative<yoriito::StructDataPtr>(value)) {
      ASSERT_TRUE(std::holds_alternative<yoriito::StructDataPtr>(it->second));

      const auto& nested_properties1 =
          std::get<yoriito::StructDataPtr>(value)->GetProperties();
      const auto& nested_properties2 =
          std::get<yoriito::StructDataPtr>(it->second)->GetProperties();

      ASSERT_EQ(nested_properties1.size(), nested_properties2.size());
      for (const auto& [nested_key, nested_value] : nested_properties1) {
        auto nested_it = nested_properties2.find(nested_key);
        ASSERT_NE(nested_it, nested_properties2.end());
        ASSERT_EQ(nested_value, nested_it->second);
      }
    } else {
      ASSERT_EQ(value, it->second);
    }
  }
}

TEST(TestDataBrokerType, StructTypeInequality) {
  yoriito::StructData struct1;
  struct1.SetProperty("key1", std::string("value1"));
  struct1.SetProperty("key2", 42);

  yoriito::StructData struct2;
  struct2.SetProperty("key1", std::string("value1"));
  struct2.SetProperty("key2", 43);

  ASSERT_NE(struct1, struct2);
}

TEST(TestDataBrokerType, StructTypeGetPropertiesInequality) {
  yoriito::StructData struct1;
  struct1.SetProperty("key1", std::string("value1"));
  struct1.SetProperty("key2", 42);

  yoriito::StructData struct2;
  struct2.SetProperty("key1", std::string("value1"));
  struct2.SetProperty("key2", 43);

  const auto& properties1 = struct1.GetProperties();
  const auto& properties2 = struct2.GetProperties();

  ASSERT_EQ(properties1.size(), properties2.size());

  bool found_difference = false;
  for (const auto& [key, value] : properties1) {
    auto it = properties2.find(key);
    ASSERT_NE(it, properties2.end());
    if (value != it->second) {
      found_difference = true;
      break;
    }
  }

  ASSERT_TRUE(found_difference);
}

TEST(TestDataBrokerType, StructTypeKeyInequality) {
  yoriito::StructData struct1;
  struct1.SetProperty("key1", std::string("value1"));
  struct1.SetProperty("key2", 42);

  yoriito::StructData struct2;
  struct2.SetProperty("key1", std::string("value1"));
  struct2.SetProperty("key3", 42);

  ASSERT_NE(struct1, struct2);
}

TEST(TestDataBrokerType, StructTypeGetPropertiesKeyInequality) {
  yoriito::StructData struct1;
  struct1.SetProperty("key1", std::string("value1"));
  struct1.SetProperty("key2", 42);

  yoriito::StructData struct2;
  struct2.SetProperty("key1", std::string("value1"));
  struct2.SetProperty("key3", 42);

  const auto& properties1 = struct1.GetProperties();
  const auto& properties2 = struct2.GetProperties();

  ASSERT_EQ(properties1.size(), properties2.size());
  ASSERT_EQ(properties2.find("key2"), properties2.end());

  bool has_same_keys = true;
  for (const auto& [key, value] : properties1) {
    auto it = properties2.find(key);
    if (it == properties2.end() || value != it->second) {
      has_same_keys = false;
      break;
    }
  }

  ASSERT_FALSE(has_same_keys);
}

TEST(TestDataBrokerType, StructTypeNestedInequality) {
  yoriito::StructData struct1;
  yoriito::StructData struct2;
  struct2.SetProperty("key1", std::string("value1"));
  struct2.SetProperty("key2", 42);
  struct1.SetProperty("key1", std::string("value1"));
  struct1.SetProperty(
      "key2", std::make_unique<yoriito::StructData>(std::move(struct2)));

  yoriito::StructData struct3;
  yoriito::StructData struct4;
  struct4.SetProperty("key1", std::string("value1"));
  struct4.SetProperty("key2", 43);
  struct3.SetProperty("key1", std::string("value1"));
  struct3.SetProperty(
      "key2", std::make_unique<yoriito::StructData>(std::move(struct4)));

  ASSERT_NE(struct1, struct3);
}

TEST(TestDataBrokerType, StructTypeGetPropertiesNestedInequality) {
  yoriito::StructData struct1;
  yoriito::StructData struct2;
  struct2.SetProperty("key1", std::string("value1"));
  struct2.SetProperty("key2", 42);
  struct1.SetProperty("key1", std::string("value1"));
  struct1.SetProperty(
      "key2", std::make_unique<yoriito::StructData>(std::move(struct2)));

  yoriito::StructData struct3;
  yoriito::StructData struct4;
  struct4.SetProperty("key1", std::string("value1"));
  struct4.SetProperty("key2", 43);
  struct3.SetProperty("key1", std::string("value1"));
  struct3.SetProperty(
      "key2", std::make_unique<yoriito::StructData>(std::move(struct4)));

  const auto& properties1 = struct1.GetProperties();
  const auto& properties3 = struct3.GetProperties();

  ASSERT_EQ(properties1.size(), properties3.size());

  bool found_difference = false;
  for (const auto& [key, value] : properties1) {
    auto it = properties3.find(key);
    ASSERT_NE(it, properties3.end());

    if (std::holds_alternative<yoriito::StructDataPtr>(value)) {
      ASSERT_TRUE(std::holds_alternative<yoriito::StructDataPtr>(it->second));

      const auto& nested_properties1 =
          std::get<yoriito::StructDataPtr>(value)->GetProperties();
      const auto& nested_properties3 =
          std::get<yoriito::StructDataPtr>(it->second)->GetProperties();

      if (nested_properties1.size() != nested_properties3.size()) {
        found_difference = true;
        break;
      }

      for (const auto& [nested_key, nested_value] : nested_properties1) {
        auto nested_it = nested_properties3.find(nested_key);
        if (nested_it == nested_properties3.end() ||
            nested_value != nested_it->second) {
          found_difference = true;
          break;
        }
      }
    } else if (value != it->second) {
      found_difference = true;
      break;
    }

    if (found_difference) {
      break;
    }
  }

  ASSERT_TRUE(found_difference);
}

TEST(TestDataBrokerType, StructArrayTypeEquals) {
  yoriito::StructData location1;
  location1.SetProperty("Latitude", 35.681236);
  location1.SetProperty("Longitude", 139.767125);

  yoriito::StructData location2;
  location2.SetProperty("Latitude", 34.693738);
  location2.SetProperty("Longitude", 135.502165);

  yoriito::StructDataArray values;
  values.push_back(std::make_unique<yoriito::StructData>(location1));
  values.push_back(std::make_unique<yoriito::StructData>(location2));

  yoriito::ValueType lhs = yoriito::StructDataArray{};
  std::get<yoriito::StructDataArray>(lhs) = std::move(values);

  yoriito::ValueType rhs = yoriito::CloneValueType(lhs);
  ASSERT_TRUE(yoriito::ValueTypeEquals(lhs, rhs));
}

TEST(TestDataBrokerType, StructArrayTypeCloneIsDeepCopy) {
  yoriito::StructData location;
  location.SetProperty("Latitude", 35.681236);
  location.SetProperty("Longitude", 139.767125);

  yoriito::StructDataArray values;
  values.push_back(std::make_unique<yoriito::StructData>(location));

  yoriito::ValueType original = yoriito::StructDataArray{};
  std::get<yoriito::StructDataArray>(original) = std::move(values);

  yoriito::ValueType cloned = yoriito::CloneValueType(original);
  ASSERT_TRUE(yoriito::ValueTypeEquals(original, cloned));

  auto& original_array = std::get<yoriito::StructDataArray>(original);
  original_array[0]->SetProperty("Latitude", 35.0);

  ASSERT_FALSE(yoriito::ValueTypeEquals(original, cloned));
}
