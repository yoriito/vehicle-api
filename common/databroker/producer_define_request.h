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

#ifndef COMMON_DATABROKER_PRODUCER_DEFINE_REQUEST_H_
#define COMMON_DATABROKER_PRODUCER_DEFINE_REQUEST_H_

#include <vector>

#include "databroker/producer_define_entry.h"
/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup producer
 * @class ProducerDefineRequest
 * @brief Class representing a request to define datapoints for a DataBroker
 * producer.
 */
class ProducerDefineRequest {
 public:
  /**
   * @ingroup producer
   * @fn ProducerDefineRequest::ProducerDefineRequest()
   * @brief Deleted default constructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ProducerDefineRequest() = delete;

  /**
   * @ingroup producer
   * @fn
   * ProducerDefineRequest::ProducerDefineRequest(std::vector<yoriito::databroker::ProducerDefineEntry>&&
   * define_entries)
   * @brief Construct a ProducerDefineRequest object with define entries.
   * @deprecated -
   * @pre -
   * @param define_entries Vector of ProducerDefineEntry objects.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerDefineRequest(
      std::vector<yoriito::databroker::ProducerDefineEntry>&& define_entries)
      : define_entries_(std::move(define_entries)) {}

  /**
   * @ingroup producer
   * @fn
   * ProducerDefineRequest::ProducerDefineRequest(std::vector<yoriito::databroker::ProducerDefineEntry>&&
   * define_entries, std::vector<std::shared_ptr<StructType>>&& struct_types)
   * @brief Construct a ProducerDefineRequest object with define entries and
   * struct types.
   * @deprecated -
   * @pre -
   * @param define_entries Vector of ProducerDefineEntry objects.
   * @param struct_types Vector of shared pointers to StructType objects.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerDefineRequest(
      std::vector<yoriito::databroker::ProducerDefineEntry>&& define_entries,
      std::vector<std::shared_ptr<StructType>>&& struct_types)
      : define_entries_(std::move(define_entries)),
        struct_types_(std::move(struct_types)) {}

  /**
   * @ingroup producer
   * @fn const std::vector<yoriito::databroker::ProducerDefineEntry>&
   * ProducerDefineRequest::GetDefineEntries() const
   * @brief Get the vector of ProducerDefineEntry objects.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::vector<ProducerDefineEntry> Vector of define entries
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<yoriito::databroker::ProducerDefineEntry>&
  GetDefineEntries() const {
    return define_entries_;
  }

  /**
   * @ingroup producer
   * @fn const std::vector<std::shared_ptr<StructType>>&
   * ProducerDefineRequest::GetStructTypes() const
   * @brief Get the vector of shared pointers to StructType objects.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::vector<std::shared_ptr<StructType>> Vector of shared pointers
   * to StructType objects
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<std::shared_ptr<StructType>>& GetStructTypes() const {
    return struct_types_;
  }

  /**
   * @ingroup producer
   * @fn bool operator==(const ProducerDefineRequest& lhs, const
   * ProducerDefineRequest& rhs)
   * @brief Compare two ProducerDefineRequest objects for equality.
   * @deprecated -
   * @pre -
   * @param lhs Left-hand side object.
   * @param rhs Right-hand side object.
   * @retval true Objects are equal
   * @retval false Objects are not equal
   * @note -
   * @code -
   * @endcode -
   */
  friend bool operator==(const ProducerDefineRequest& lhs,
                         const ProducerDefineRequest& rhs) {
    return (lhs.define_entries_ == rhs.define_entries_ &&
            lhs.struct_types_ == rhs.struct_types_);
  }

 private:
  std::vector<ProducerDefineEntry> define_entries_;
  std::vector<std::shared_ptr<StructType>> struct_types_;
};
}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_PRODUCER_DEFINE_REQUEST_H_
