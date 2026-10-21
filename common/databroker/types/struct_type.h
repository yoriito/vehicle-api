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

#ifndef COMMON_DATABROKER_TYPES_STRUCT_TYPE_H_
#define COMMON_DATABROKER_TYPES_STRUCT_TYPE_H_

#include <cstddef>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "databroker/types/property_type.h"

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup common
 * @class StructType
 * @brief Class representing a struct type definition in the DataBroker.
 */
class StructType {
 public:
  /**
   * @ingroup common
   * @class PropertiesView
   * @brief Read-only view of properties.
   * @note Provides an STL-compatible container interface for read-only
   * access.
   */
  class PropertiesView {
   public:
    /**
     * @ingroup common
     * @class const_iterator
     * @brief Forward iterator for read-only property traversal.
     * @note Wraps the underlying map const iterator.
     */
    class const_iterator {
     public:
      using iterator_category = std::forward_iterator_tag;
      using value_type = yoriito::databroker::PropertyType;
      using difference_type = std::ptrdiff_t;
      using pointer = const yoriito::databroker::PropertyType*;
      using reference = const yoriito::databroker::PropertyType&;

      /**
       * @ingroup common
       * @fn reference const_iterator::operator*() const
       * @brief Dereference iterator.
       * @deprecated -
       * @pre -
       * @param -
       * @retval reference Referenced property.
       * @note -
       * @code -
       * @endcode -
       */
      reference operator*() const { return properties_it_->second; }

      /**
       * @ingroup common
       * @fn pointer const_iterator::operator->() const
       * @brief Access member of referenced property.
       * @deprecated -
       * @pre -
       * @param -
       * @retval pointer Pointer to referenced property.
       * @note -
       * @code -
       * @endcode -
       */
      pointer operator->() const { return &(**this); }

      /**
       * @ingroup common
       * @fn const_iterator& const_iterator::operator++()
       * @brief Advance iterator to next property.
       * @deprecated -
       * @pre -
       * @param -
       * @retval const_iterator& Advanced iterator.
       * @note Pre-increment operator.
       * @code -
       * @endcode -
       */
      const_iterator& operator++() & {
        ++properties_it_;
        return *this;
      }

      /**
       * @ingroup common
       * @fn bool const_iterator::operator==(const const_iterator& other) const
       * @brief Compare iterator equality.
       * @deprecated -
       * @pre -
       * @param other Iterator to compare.
       * @retval bool True if iterators point to the same position.
       * @note -
       * @code -
       * @endcode -
       */
      friend bool operator==(const const_iterator& lhs,
                             const const_iterator& rhs) {
        return lhs.properties_it_ == rhs.properties_it_;
      }

      /**
       * @ingroup common
       * @fn bool const_iterator::operator!=(const const_iterator& other) const
       * @brief Compare iterator inequality.
       * @deprecated -
       * @pre -
       * @param other Iterator to compare.
       * @retval bool True if iterators point to different positions.
       * @note -
       * @code -
       * @endcode -
       */
      friend bool operator!=(const const_iterator& lhs,
                             const const_iterator& rhs) {
        return !(lhs == rhs);
      }

     private:
      friend class PropertiesView;

      const_iterator(
        std::map<std::string, yoriito::databroker::PropertyType>::const_iterator
          properties_it)
          : properties_it_(properties_it) {}

      std::map<std::string, yoriito::databroker::PropertyType>::const_iterator
        properties_it_;
    };

    /**
     * @ingroup common
     * @fn const_iterator PropertiesView::begin() const
     * @brief Get iterator to the beginning of properties.
     * @deprecated -
     * @pre -
     * @param -
     * @retval const_iterator Iterator to first property.
     * @note STL-compatible container API.
     * @code -
     * @endcode -
     */
    const_iterator begin() const {
      return const_iterator(properties_->begin());
    }

    /**
     * @ingroup common
     * @fn const_iterator PropertiesView::end() const
     * @brief Get iterator to one-past-last property.
     * @deprecated -
     * @pre -
     * @param -
     * @retval const_iterator End iterator.
     * @note STL-compatible container API.
     * @code -
     * @endcode -
     */
    const_iterator end() const { return const_iterator(properties_->end()); }

    /**
     * @ingroup common
     * @fn std::size_t PropertiesView::size() const
     * @brief Get number of properties.
     * @deprecated -
     * @pre -
     * @param -
     * @retval std::size_t Number of properties.
     * @note -
     * @code -
     * @endcode -
     */
    std::size_t size() const { return properties_->size(); }

    /**
     * @ingroup common
     * @fn bool PropertiesView::empty() const
     * @brief Check whether properties are empty.
     * @deprecated -
     * @pre -
     * @param -
     * @retval bool True if no properties are defined.
     * @note -
     * @code -
     * @endcode -
     */
    bool empty() const { return properties_->empty(); }

    /**
     * @ingroup common
     * @fn const yoriito::databroker::PropertyType*
     * PropertiesView::at(const std::string& key) const noexcept
     * @brief Get property pointer by key.
     * @deprecated -
     * @pre -
     * @param key Property key(path).
     * @retval const yoriito::databroker::PropertyType* Found property pointer.
     * @retval nullptr Property not found.
     * @note -
     * @code -
     * @endcode -
     */
    const yoriito::databroker::PropertyType* at(
      const std::string& key) const noexcept {
      auto it = properties_->find(key);
      return it == properties_->end() ? nullptr : &(it->second);
    }

   private:
    friend class StructType;

    explicit PropertiesView(
      const std::map<std::string, yoriito::databroker::PropertyType>&
        properties)
        : properties_(&properties) {}

    const std::map<std::string, yoriito::databroker::PropertyType>* properties_;
  };

  /**
   * @ingroup common
   * @fn explicit StructType(std::string path)
   * @brief Construct a StructType object with path.
   * @deprecated -
   * @pre -
   * @param path Struct type path.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit StructType(std::string path) : path_(std::move(path)) {}

  /**
   * @ingroup common
   * @fn PropertiesView StructType::GetProperties() const noexcept
   * @brief Get a read-only view of this struct type's properties.
   * @deprecated -
   * @pre -
   * @param -
   * @retval PropertiesView Read-only property view.
   * @note -
   * @code -
   * @endcode -
   */
  PropertiesView GetProperties() const noexcept {
    return PropertiesView(properties_);
  }

  /**
   * @ingroup common
   * @fn const yoriito::databroker::PropertyType*
   * StructType::GetPropertyByName(const std::string& name) const noexcept
   * @brief Find a property by its name(path).
   * @deprecated -
   * @pre -
   * @param name Property name(path).
   * @retval const yoriito::databroker::PropertyType* Found property pointer.
   * @retval nullptr Property not found.
   * @note -
   * @code -
   * @endcode -
   */
  const yoriito::databroker::PropertyType* GetPropertyByName(
    const std::string& name) const noexcept {
    auto it = properties_.find(name);
    return it == properties_.end() ? nullptr : &(it->second);
  }

  /**
   * @ingroup common
   * @fn yoriito::databroker::PropertyType*
   * StructType::GetMutableProperty(const std::string& name) noexcept
   * @brief Find a mutable property by its name(path).
   * @deprecated -
   * @pre -
   * @param name Property name(path).
   * @retval yoriito::databroker::PropertyType* Found property pointer.
   * @retval nullptr Property not found.
   * @note -
   * @code -
   * @endcode -
   */
  yoriito::databroker::PropertyType* GetMutableProperty(
    const std::string& name) noexcept {
    auto it = properties_.find(name);
    return it == properties_.end() ? nullptr : &(it->second);
  }

  /**
   * @ingroup common
   * @fn const std::string& StructType::GetPath() const noexcept
   * @brief Get struct type path.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Struct type path.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetPath() const& noexcept { return path_; }
  std::string GetPath() const&& { return path_; }

  /**
   * @ingroup common
   * @fn const std::string& StructType::GetDescription() const noexcept
   * @brief Get description.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Description string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetDescription() const& noexcept { return description_; }
  std::string GetDescription() const&& { return description_; }

  /**
   * @ingroup common
   * @fn const std::string& StructType::GetComment() const noexcept
   * @brief Get comment.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Comment string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetComment() const& noexcept { return comment_; }
  std::string GetComment() const&& { return comment_; }

  /**
   * @ingroup common
   * @fn const std::string& StructType::GetDeprecation() const noexcept
   * @brief Get deprecation message.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::string& Deprecation string.
   * @note -
   * @code -
   * @endcode -
   */
  const std::string& GetDeprecation() const& noexcept { return deprecation_; }
  std::string GetDeprecation() const&& { return deprecation_; }

  /**
   * @ingroup common
   * @fn const std::map<std::string, std::string>&
   * StructType::GetCustomAttributes() const noexcept
   * @brief Get custom attributes.
   * @deprecated -
   * @pre -
   * @param -
   * @retval const std::map<std::string, std::string>& Custom attribute map.
   * @note -
   * @code -
   * @endcode -
   */
  const std::map<std::string, std::string>& GetCustomAttributes()
    const& noexcept {
    return custom_attributes_;
  }
  std::map<std::string, std::string> GetCustomAttributes() const&& {
    return custom_attributes_;
  }

  /**
   * @ingroup common
   * @fn void StructType::AddProperty(yoriito::databroker::PropertyType p)
   * @brief Add a property definition.
   * @deprecated -
   * @pre -
   * @param p Property definition to add.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void AddProperty(yoriito::databroker::PropertyType p) {
    const std::string key = p.GetPath();
    // suppress unused return value warning (MISRA C++-2023 Rule 0.1.2) by
    // casting to void
    static_cast<void>(properties_.insert_or_assign(key, std::move(p)));
  }

  /**
   * @ingroup common
   * @fn void StructType::SetComment(std::string comment)
   * @brief Set comment.
   * @deprecated -
   * @pre -
   * @param comment Comment string.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetComment(std::string comment) { comment_ = std::move(comment); }

  /**
   * @ingroup common
   * @fn void StructType::SetDeprecation(std::string deprecation)
   * @brief Set deprecation message.
   * @deprecated -
   * @pre -
   * @param deprecation Deprecation string.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetDeprecation(std::string deprecation) {
    deprecation_ = std::move(deprecation);
  }

  /**
   * @ingroup common
   * @fn void StructType::SetDescription(std::string description)
   * @brief Set description.
   * @deprecated -
   * @pre -
   * @param description Description string.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void SetDescription(std::string description) {
    description_ = std::move(description);
  }

  /**
   * @ingroup common
   * @fn void StructType::AddCustomAttribute(std::string key, std::string value)
   * @brief Add a custom attribute.
   * @deprecated -
   * @pre -
   * @param key Attribute key.
   * @param value Attribute value.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  void AddCustomAttribute(std::string key, std::string value) {
    custom_attributes_[std::move(key)] = std::move(value);
  }

 private:
  std::string path_;
  std::string description_;
  std::string deprecation_;
  std::string comment_;
  std::map<std::string, std::string> custom_attributes_;
  std::map<std::string, yoriito::databroker::PropertyType> properties_;
};

}  // namespace yoriito::databroker
#endif  // COMMON_DATABROKER_TYPES_STRUCT_TYPE_H_
