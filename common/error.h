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

#ifndef COMMON_ERROR_H_
#define COMMON_ERROR_H_

#include <cstdint>
#include <string>
#include <string_view>

/**
 * @namespace yoriito
 * @brief Defines common error codes used across the system.
 */
namespace yoriito {

/**
 * @enum ErrorCode
 * @brief Definition of common error codes
 */
enum class ErrorCode : uint32_t {
  ERROR_PERM = 1,   /* Operation not permitted                                */
  ERROR_NOMEM = 12, /* Insufficient free memory space                         */
  ERROR_ACCES = 13, /* Permission denied                                      */
  ERROR_INVAL = 22, /* Invalid value                                          */
  ERROR_NODATA = 61,        /* No data        */
  ERROR_BADMSG = 74,        /* Bad message        */
  ERROR_TIMEDOUT = 110,     /* Operation timed out     */
  ERROR_CONNREFUSED = 111,  /* Connection refused  */
  ERROR_CANCELED = 125,     /* Operation canceled     */
  ERROR_UNAVAILABLE = 1000, /* Data is unavailable */
  ERROR_UNSUBSCRIBE = 1001, /* No subscription to unsubscribe */

  ERROR_BAD_REQUEST = 400,     /* The request is malformed     */
  ERROR_UNAUTHORIZED = 401,    /* Access token is invalid    */
  ERROR_FORBIDDEN = 403,      /* The server refuses to carry out the request */
  ERROR_NOT_FOUND = 404,       /* The requested data was not found       */
  ERROR_REQUEST_TIMEOUT = 408, /* Subscribe duration limit exceeded */
  ERROR_UNSPECIFIED = 409,     /* Parameter is unspecified     */
  ERROR_TOO_MANY_REQUESTS = 429, /* Rate-limiting due to too many requests */
  ERROR_INTERNAL_SERVER_ERROR =
    500, /* The server encountered an internal error               */
  ERROR_BAD_GATEWAY = 502, /* The upstream server response was invalid */
  ERROR_SERVICE_UNAVAILABLE =
    503, /* The server is temporarily unable to handle the request */
  ERROR_GATEWAY_TIMEOUT =
    504, /* The upstream server took too long to respond           */

  ERROR_UNKNOWN = 9999, /* Unknown error */
};

/**
 * @class ErrorType
 * @brief Abstract base class for error types.
 */
class ErrorType {
 public:
  /**
   * @brief Destructor
   */
  virtual ~ErrorType() = default;

  /**
   * @brief Get the error message.
   * @return std::string Error message
   */
  virtual std::string Message() const = 0;

  /**
   * @brief Get the error code.
   * @return uint32_t Error code
   */
  virtual uint32_t ErrorCode() const = 0;

  /**
   * @brief Return the error message corresponding to the given error code.
   * @param e Error code
   * @return std::string_view Error message
   */
  static constexpr std::string_view to_msg(yoriito::ErrorCode e) noexcept {
    switch (e) {
      case yoriito::ErrorCode::ERROR_PERM:
        return "Operation not permitted.";
      case yoriito::ErrorCode::ERROR_NOMEM:
        return "Insufficient free memory space.";
      case yoriito::ErrorCode::ERROR_ACCES:
        return "Permission denied.";
      case yoriito::ErrorCode::ERROR_INVAL:
        return "Invalid value:";
      case yoriito::ErrorCode::ERROR_BADMSG:
        return "Bad message.";
      case yoriito::ErrorCode::ERROR_NODATA:
        return "No data.";
      case yoriito::ErrorCode::ERROR_TIMEDOUT:
        return "Operation timed out.";
      case yoriito::ErrorCode::ERROR_CONNREFUSED:
        return "Connection refused.";
      case yoriito::ErrorCode::ERROR_CANCELED:
        return "Operation canceled.";
      case yoriito::ErrorCode::ERROR_UNAVAILABLE:
        return "Data is unavailable.";
      case yoriito::ErrorCode::ERROR_UNSUBSCRIBE:
        return "No subscription to unsubscribe.";

      case yoriito::ErrorCode::ERROR_BAD_REQUEST:
        return "The request is malformed.";
      case yoriito::ErrorCode::ERROR_UNAUTHORIZED:
        return "Access token is invalid.";
      case yoriito::ErrorCode::ERROR_FORBIDDEN:
        return "The server refuses to carry out the request.";
      case yoriito::ErrorCode::ERROR_NOT_FOUND:
        return "The requested data was not found.";
      case yoriito::ErrorCode::ERROR_REQUEST_TIMEOUT:
        return "Subscribe duration limit exceeded.";
      case yoriito::ErrorCode::ERROR_UNSPECIFIED:
        return "Parameter is unspecified.";
      case yoriito::ErrorCode::ERROR_TOO_MANY_REQUESTS:
        return "Rate-limiting due to too many requests.";
      case yoriito::ErrorCode::ERROR_BAD_GATEWAY:
        return "The upstream server response was invalid.";
      case yoriito::ErrorCode::ERROR_SERVICE_UNAVAILABLE:
        return "The server is temporarily unable to handle the request.";
      case yoriito::ErrorCode::ERROR_GATEWAY_TIMEOUT:
        return "The upstream server took too long to respond.";

      default:
        return "Unknown error.";
    }
  }
};

/**
 * @class CommonError
 * @brief Common error class derived from ErrorType.
 */
class CommonError : public ErrorType {
 public:
  /**
   * @brief Constructor with error code and message.
   * @param code Error code
   * @param msg Error message
   */
  explicit CommonError(yoriito::ErrorCode code, std::string msg)
      : ErrorType(), code_(static_cast<uint32_t>(code)), msg_(std::move(msg)) {}

  /**
   * @brief Constructor with only error code. Message is set from code.
   * @param code Error code
   */
  explicit CommonError(yoriito::ErrorCode code)
      : ErrorType(),
        code_(static_cast<uint32_t>(code)),
        msg_(std::string(yoriito::ErrorType::to_msg(code))) {}

  CommonError() = delete;

  std::string Message() const override { return msg_; }
  uint32_t ErrorCode() const override { return code_; }

 private:
  uint32_t code_;
  std::string msg_;
};

}  // namespace yoriito

#endif  // COMMON_ERROR_H_
