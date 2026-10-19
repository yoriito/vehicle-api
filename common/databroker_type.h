/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright 2026 JASPAR
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef COMMON_DATABROKER_TYPE_H_
#define COMMON_DATABROKER_TYPE_H_

#include <algorithm>
#include <cstdint>
#include <memory>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <variant>
#include <vector>

/**
 * @ingroup common
 * @namespace yoriito
 * @brief Namespace for yoriito common interfaces and types.
 */
namespace yoriito {

class StructData;
using StructDataPtr = std::unique_ptr<StructData>;
using StructDataArray = std::vector<StructDataPtr>;

using ValueType = std::variant<std::monostate,            //
                               std::string,               //
                               std::string_view,          //
                               bool,                      //
                               int8_t,                    //
                               int16_t,                   //
                               int32_t,                   //
                               int64_t,                   //
                               uint8_t,                   //
                               uint16_t,                  //
                               uint32_t,                  //
                               uint64_t,                  //
                               float,                     //
                               double,                    //
                               std::vector<std::string>,  //
                               std::vector<bool>,         //
                               std::vector<int8_t>,       //
                               std::vector<int16_t>,      //
                               std::vector<int32_t>,      //
                               std::vector<int64_t>,      //
                               std::vector<uint8_t>,      //
                               std::vector<uint16_t>,     //
                               std::vector<uint32_t>,     //
                               std::vector<uint64_t>,     //
                               std::vector<float>,        //
                               std::vector<double>,       //
                               StructDataPtr,             //
                               StructDataArray>;

inline ValueType CloneValueType(const ValueType& v);
inline bool ValueTypeEquals(const ValueType& lhs, const ValueType& rhs);

/**
 * @ingroup common
 * @class StructData
 * @brief Property container for structured data.
 *
 * Stores key-value pairs where each value is represented by ValueType.
 */
class StructData {
 public:
  /**
   * @ingroup common
   * @class PropertiesView
   * @brief Read-only properties view with STL container-compatible interface.
   * @note Provides `begin`, `end`, `size`, `empty`, `find`, and `at` for
   *       container-like access.
   */
  class PropertiesView {
   public:
    using MapType = std::unordered_map<std::string, ValueType>;
    using const_iterator = MapType::const_iterator;
    using size_type = MapType::size_type;

    /**
     * @ingroup common
     * @fn begin
     * @brief Returns an iterator to the beginning of the properties.
     * @deprecated -
     * @pre -
     * @retval const_iterator Constant iterator to the first element.
     * @note This method provides STL container-compatible iteration access.
     * @code
     * -
     * @endcode
     */
    const_iterator begin() const { return map_->begin(); }

    /**
     * @ingroup common
     * @fn end
     * @brief Returns an iterator to the end of the properties.
     * @deprecated -
     * @pre -
     * @retval const_iterator Constant iterator to one past the last element.
     * @note This method provides STL container-compatible iteration access.
     * @code
     * -
     * @endcode
     */
    const_iterator end() const { return map_->end(); }

    /**
     * @ingroup common
     * @fn size
     * @brief Returns the number of stored properties.
     * @deprecated -
     * @pre -
     * @retval size_type Number of key-value pairs.
     * @note The returned value matches the underlying map size.
     * @code
     * -
     * @endcode
     */
    size_type size() const { return map_->size(); }

    /**
     * @ingroup common
     * @fn empty
     * @brief Checks whether the properties are empty.
     * @deprecated -
     * @pre -
     * @retval bool True if there are no properties, false otherwise.
     * @note Equivalent to checking whether size is zero.
     * @code
     * -
     * @endcode
     */
    bool empty() const { return map_->empty(); }

    /**
     * @ingroup common
     * @fn find
     * @brief Finds a property by key.
     * @deprecated -
     * @pre -
     * @param key The property key to search for.
     * @retval const_iterator Iterator to the found element, or end if not
     * found.
     * @note This method does not modify the underlying property map.
     * @code
     * -
     * @endcode
     */
    const_iterator find(const std::string& key) const {
      return map_->find(key);
    }

    /**
     * @ingroup common
     * @fn at
     * @brief Retrieves the value of a property by key.
     * @deprecated -
     * @pre The specified key exists in the properties.
     * @param key The property key to access.
     * @retval const ValueType& Reference to the stored property value.
     * @note Behaves like std::unordered_map::at and throws if key is missing.
     * @code
     * -
     * @endcode
     */
    const ValueType& at(const std::string& key) const { return map_->at(key); }

   private:
    friend class StructData;

    /**
     * @ingroup common
     * @fn PropertiesView
     * @brief Constructs a read-only properties view from an existing map.
     * @deprecated -
     * @pre map is valid for the lifetime of this view.
     * @param map Source properties map to reference.
     * @retval -
     * @note This constructor is private and used by StructData.
     * @code
     * -
     * @endcode
     */
    explicit PropertiesView(const MapType& map) : map_(&map) {}

    const MapType* map_;
  };

  StructData() = default;

  StructData(const StructData& other) {
    for (const auto& [key, value] : other.properties_) {
      // suppress unused return value warning (MISRA C++-2023 Rule 0.1.2) by
      // casting to void
      static_cast<void>(properties_.emplace(key, CloneValueType(value)));
    }
  }

  StructData(StructData&&) noexcept = default;
  StructData& operator=(StructData&&) noexcept = default;

  /**
   * @ingroup common
   * @fn SetProperty
   * @brief Sets a property in the structured data.
   * @deprecated -
   * @pre -
   * @param key The key for the property.
   * @param value The value for the property, which can be of various types.
   * @retval void
   * @note This method allows setting properties with various types, including
   * nested struct data. The value is stored as a variant, and the key is stored
   * as a string.
   * @code
   * -
   * @endcode
   */
  void SetProperty(std::string key, ValueType value) {
    // suppress unused return value warning (MISRA C++-2023 Rule 0.1.2) by
    // casting to void
    static_cast<void>(
      properties_.insert_or_assign(std::move(key), std::move(value)));
  }

  /**
   * @ingroup common
   * @fn GetProperties
   * @brief Retrieves all properties in the structured data.
   * @deprecated -
   * @pre -
   * @retval PropertiesView A map-like read-only view of the properties.
   * @note The returned map contains all key-value pairs stored in the
   * structured data.
   * @code
   * -
   * @endcode
   */
  PropertiesView GetProperties() const { return PropertiesView(properties_); }

  /**
   * @ingroup common
   * @fn operator==
   * @brief Compares two StructData objects for equality.
   * @deprecated -
   * @pre -
   * @param other The other StructData object to compare with.
   * @retval bool True if the objects are equal, false otherwise.
   * @note The comparison is based on the properties stored in the structured
   * data.
   * @code
   * -
   * @endcode
   */
  friend bool operator==(const StructData& lhs, const StructData& rhs) {
    if (lhs.properties_.size() != rhs.properties_.size()) {
      return false;
    }

    return std::all_of(lhs.properties_.begin(), lhs.properties_.end(),
                       [&rhs](const auto& pair) {
                         auto it = rhs.properties_.find(pair.first);
                         return it != rhs.properties_.end() &&
                                ValueTypeEquals(it->second, pair.second);
                       });
  }

  /**
   * @ingroup common
   * @fn operator!=
   * @brief Compares two StructData objects for inequality.
   * @deprecated -
   * @pre -
   * @param other The other StructData object to compare with.
   * @retval bool True if the objects are not equal, false otherwise.
   * @note The comparison is based on the properties stored in the structured
   * data.
   * @code
   * -
   * @endcode
   */
  friend bool operator!=(const StructData& lhs, const StructData& rhs) {
    return !(lhs == rhs);
  }

 private:
  std::unordered_map<std::string, ValueType> properties_;
};

namespace detail {
struct CloneVisitor {
  ValueType operator()(const StructDataPtr& arg) const {
    if (!arg) {
      return StructDataPtr{};
    }

    return std::make_unique<StructData>(*arg);
  }

  ValueType operator()(const StructDataArray& arg) const {
    StructDataArray cloned;
    cloned.reserve(arg.size());

    for (const auto& elem : arg) {
      if (!elem) {
        cloned.push_back(StructDataPtr{});
      } else {
        cloned.push_back(std::make_unique<StructData>(*elem));
      }
    }

    return cloned;
  }

  template <typename T>
  ValueType operator()(const T& arg) const {
    return arg;
  }
};
}  // namespace detail

inline ValueType CloneValueType(const ValueType& v) {
  return std::visit(detail::CloneVisitor{}, v);
}

inline bool ValueTypeEquals(const ValueType& lhs, const ValueType& rhs) {
  if (lhs.index() != rhs.index()) {
    return false;
  }

  if (std::holds_alternative<StructDataPtr>(lhs)) {
    const auto& left_ptr = std::get<StructDataPtr>(lhs);
    const auto& right_ptr = std::get<StructDataPtr>(rhs);
    if (!left_ptr || !right_ptr) {
      return !left_ptr && !right_ptr;
    }
    return *left_ptr == *right_ptr;
  }

  if (std::holds_alternative<StructDataArray>(lhs)) {
    const auto& left_array = std::get<StructDataArray>(lhs);
    const auto& right_array = std::get<StructDataArray>(rhs);
    if (left_array.size() != right_array.size()) {
      return false;
    }

    const size_t array_size = left_array.size();
    for (size_t i = 0; i < array_size; ++i) {
      const auto& left_ptr = left_array[i];
      const auto& right_ptr = right_array[i];
      if (!left_ptr || !right_ptr) {
        if (left_ptr || right_ptr) {
          return false;
        }
        continue;
      }

      if (*left_ptr != *right_ptr) {
        return false;
      }
    }

    return true;
  }

  return lhs == rhs;
}

inline ValueType string_view_then_copy(const ValueType& v) {
  // string_view is just a view to a real string.
  // So, it should be stored as string.
  if (std::holds_alternative<std::string_view>(v)) {
    return std::string(std::get<std::string_view>(v));
  } else {
    return CloneValueType(v);
  }
}

}  // namespace yoriito

#endif  // COMMON_DATABROKER_TYPE_H_
