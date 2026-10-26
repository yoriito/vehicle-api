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

#include "FuzzHelpers.h"

#include <algorithm>
#include <cstring>
#include <string>
#include <variant>
#include <vector>

#include "databroker_type.h"

namespace {

static std::vector<std::string> make_vector_string(const uint8_t* data,
                                                   size_t len) {
  std::vector<std::string> v;
  if (len > 0) {
    v.push_back(std::string(reinterpret_cast<const char*>(data),
                            std::min(len, size_t{32})));
  }
  return v;
}

static std::vector<bool> make_vector_bool(const uint8_t* data, size_t len) {
  std::vector<bool> v;
  for (size_t i = 0; i < std::min(len, size_t{8}); ++i) {
    v.push_back(data[i] != 0);
  }
  return v;
}

template <typename T>
static std::vector<T> make_vector(const uint8_t* data, size_t len) {
  std::vector<T> v;
  size_t count = std::min(len / sizeof(T), size_t{8});
  for (size_t i = 0; i < count; ++i) {
    T elem{};
    memcpy(&elem, data + i * sizeof(T), sizeof(T));
    v.push_back(elem);
  }
  return v;
}

static yoriito::ValueType make_scalar_value(uint8_t index, const uint8_t* data,
                                            size_t len) {
  switch (index) {
    case 0:
      return std::monostate{};
    case 1:
      return std::string(reinterpret_cast<const char*>(data),
                         std::min(len, size_t{64}));
    case 2:
      return (len > 0) ? (data[0] != 0) : false;
    case 3: {
      int8_t v{};
      if (len >= sizeof(v)) memcpy(&v, data, sizeof(v));
      return v;
    }
    case 4: {
      int16_t v{};
      if (len >= sizeof(v)) memcpy(&v, data, sizeof(v));
      return v;
    }
    case 5: {
      int32_t v{};
      if (len >= sizeof(v)) memcpy(&v, data, sizeof(v));
      return v;
    }
    case 6: {
      int64_t v{};
      if (len >= sizeof(v)) memcpy(&v, data, sizeof(v));
      return v;
    }
    case 7:
      return (len >= sizeof(uint8_t)) ? data[0] : uint8_t{0};
    case 8: {
      uint16_t v{};
      if (len >= sizeof(v)) memcpy(&v, data, sizeof(v));
      return v;
    }
    case 9: {
      uint32_t v{};
      if (len >= sizeof(v)) memcpy(&v, data, sizeof(v));
      return v;
    }
    case 10: {
      uint64_t v{};
      if (len >= sizeof(v)) memcpy(&v, data, sizeof(v));
      return v;
    }
    case 11: {
      float v{};
      if (len >= sizeof(v)) memcpy(&v, data, sizeof(v));
      return v;
    }
    case 12: {
      double v{};
      if (len >= sizeof(v)) memcpy(&v, data, sizeof(v));
      return v;
    }
    default:
      return std::monostate{};
  }
}

static yoriito::ValueType make_vector_value(uint8_t index, const uint8_t* data,
                                            size_t len) {
  switch (index) {
    case 0:
      return make_vector_string(data, len);
    case 1:
      return make_vector_bool(data, len);
    case 2:
      return make_vector<int8_t>(data, len);
    case 3:
      return make_vector<int16_t>(data, len);
    case 4:
      return make_vector<int32_t>(data, len);
    case 5:
      return make_vector<int64_t>(data, len);
    case 6:
      return make_vector<uint8_t>(data, len);
    case 7:
      return make_vector<uint16_t>(data, len);
    case 8:
      return make_vector<uint32_t>(data, len);
    case 9:
      return make_vector<uint64_t>(data, len);
    case 10:
      return make_vector<float>(data, len);
    case 11:
      return make_vector<double>(data, len);
    default:
      return std::monostate{};
  }
}

}  // namespace

yoriito::ValueType make_value_from_index(uint8_t index, const uint8_t* data,
                                         size_t len) {
  constexpr uint8_t kScalarCount = 13;
  constexpr uint8_t kVariantCount =
    static_cast<uint8_t>(std::variant_size_v<yoriito::ValueType>);
  uint8_t i = index % kVariantCount;
  if (i < kScalarCount) {
    return make_scalar_value(i, data, len);
  }
  return make_vector_value(static_cast<uint8_t>(i - kScalarCount), data, len);
}
