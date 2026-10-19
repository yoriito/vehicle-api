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

#ifndef COMMON_DATABROKER_PRODUCER_DELETE_REQUEST_H_
#define COMMON_DATABROKER_PRODUCER_DELETE_REQUEST_H_

#include <string>
#include <utility>
#include <vector>

/**
 * @ingroup common
 * @namespace yoriito::databroker
 * @brief Namespace for DataBroker common interfaces and types.
 */
namespace yoriito::databroker {

/**
 * @ingroup producer
 * @class ProducerDeleteRequest
 * @brief Class representing a request to delete datapoints for a DataBroker
 * producer.
 */
class ProducerDeleteRequest {
 public:
  /**
   * @ingroup producer
   * @fn ProducerDeleteRequest::ProducerDeleteRequest()
   * @brief Deleted default constructor.
   * @deprecated -
   * @pre -
   * @param -
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  ProducerDeleteRequest() = delete;

  /**
   * @ingroup producer
   * @fn
   * ProducerDeleteRequest::ProducerDeleteRequest(const
   * std::vector<std::string>& paths)
   * @brief Construct a ProducerDeleteRequest object with paths.
   * @deprecated -
   * @pre -
   * @param paths Vector of paths to delete.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerDeleteRequest(const std::vector<std::string>& paths)
      : paths_(paths) {}
  /**
   * @ingroup producer
   * @fn
   * ProducerDeleteRequest::ProducerDeleteRequest(std::vector<std::string>&&
   * paths)
   * @brief Construct a ProducerDeleteRequest object with paths.
   * @deprecated -
   * @pre -
   * @param paths Vector of paths to delete.
   * @retval -
   * @note -
   * @code -
   * @endcode -
   */
  explicit ProducerDeleteRequest(std::vector<std::string>&& paths)
      : paths_(std::move(paths)) {}

  /**
   * @ingroup producer
   * @fn bool operator==(const ProducerDeleteRequest& lhs, const
   * ProducerDeleteRequest& rhs)
   * @brief Compare two ProducerDeleteRequest objects for equality.
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
  friend bool operator==(const ProducerDeleteRequest& lhs,
                         const ProducerDeleteRequest& rhs) {
    return lhs.paths_ == rhs.paths_;
  }

  /**
   * @ingroup producer
   * @fn const std::vector<std::string>& ProducerDeleteRequest::GetPaths() const
   * @brief Get the datapoint paths.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::vector<std::string> request paths
   * @note -
   * @code -
   * @endcode -
   */
  const std::vector<std::string>& GetPaths() const { return paths_; }

 private:
  std::vector<std::string> paths_;
};

}  // namespace yoriito::databroker

#endif  // COMMON_DATABROKER_PRODUCER_DELETE_REQUEST_H_
