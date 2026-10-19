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

#ifndef COMMON_DATABROKER_TYPES_STRUCT_TYPE_REF_H_
#define COMMON_DATABROKER_TYPES_STRUCT_TYPE_REF_H_

#include <memory>
#include <string>

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */

namespace yoriito::databroker {

class StructType;

/**
 * @ingroup common
 * @class StructTypeRef
 * @brief Class representing a reference to StructType.
 */
class StructTypeRef {
 public:
  /**
   * @ingroup common
   * @fn StructTypeRef::StructTypeRef()
   * @brief Default constructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  StructTypeRef() = default;

  /**
   * @ingroup common
   * @fn explicit StructTypeRef::StructTypeRef(std::shared_ptr<StructType>
   * target)
   * @brief Construct a resolved StructTypeRef.
   * @deprecated -
   * @pre -
   * @param target Target StructType object.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit StructTypeRef(std::shared_ptr<StructType> target)
      : target_(std::move(target)) {}

  /**
   * @ingroup common
   * @fn explicit StructTypeRef::StructTypeRef(std::string path)
   * @brief Construct an unresolved StructTypeRef with path.
   * @deprecated -
   * @pre -
   * @param path StructType path.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit StructTypeRef(std::string path) : path_(std::move(path)) {}

  /**
   * @ingroup common
   * @fn bool StructTypeRef::isResolved() const noexcept
   * @brief Check whether this reference is resolved.
   * @deprecated -
   * @pre -
   * @param -
   * @retval true Reference is resolved
   * @retval false Reference is not resolved
   * @note -
   * @code -
   * @endcode -
   */
  bool IsResolved() const noexcept { return static_cast<bool>(target_); }

  /**
   * @ingroup common
   * @fn std::shared_ptr<StructType> StructTypeRef::Resolved() const
   * @brief Get resolved StructType target.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::shared_ptr<StructType> Resolved target.
   * @note -
   * @code -
   * @endcode -
   */
  std::shared_ptr<StructType> Resolved() const { return target_; }

  /**
   * @ingroup common
   * @fn std::string StructTypeRef::GetPath() const
   * @brief Get unresolved path.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::string StructType path.
   * @note -
   * @code -
   * @endcode -
   */
  std::string GetPath() const { return path_; }

 private:
  std::string path_;
  std::shared_ptr<StructType> target_;
};

}  // namespace yoriito::databroker
#endif  // COMMON_DATABROKER_TYPES_STRUCT_TYPE_REF_H_
