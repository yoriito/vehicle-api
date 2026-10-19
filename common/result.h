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

#ifndef COMMON_RESULT_H_
#define COMMON_RESULT_H_

#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <variant>

#include "error.h"

/**
 * @ingroup common
 * @namespace yoriito
 * @brief Namespace for yoriito common interfaces and types.
 */
namespace yoriito {
/**
 * @ingroup common
 * @class Result<T>
 * @brief A generic Result type that can hold either a success value (Ok) or an
 */
template <typename T>
class Result {
 public:
  using ErrorPtr = std::unique_ptr<yoriito::ErrorType>;

  /**
   * @ingroup common
   * @fn static Result<T>::Ok(U&& val)
   * @brief Create a Result object containing an Ok value.
   * @deprecated -
   * @pre -
   * @param val The value to store in Ok. Move semantics are used.
   * @retval Result<T> Ok or Err
   * @note -
   * @code -
   */
  template <typename U>
  static Result Ok(U&& val) {
    // Direct-initialize T so explicit single-argument constructors still apply.
    return Result(T(std::forward<U>(val)));
  }

  /**
   * @ingroup common
   * @fn static Result<T>::Err(ErrorPtr err)
   * @brief Create a Result object containing an Err value.
   * @deprecated -
   * @pre -
   * @param err The error to store in Err. Move semantics are used.
   * @retval Result<T> Ok or Err
   * @note -
   * @code -
   */
  static Result Err(ErrorPtr err) { return Result(std::move(err)); }

  /**
   * @ingroup common
   * @fn bool Result<T>::IsOk() const
   * @brief Check if the Result contains an Ok value.
   * @deprecated -
   * @pre -
   * @param -
   * @retval true Result is Ok
   * @retval false Result is Err
   * @note -
   * @code -
   */
  bool IsOk() const { return std::holds_alternative<T>(value_); }

  /**
   * @ingroup common
   * @fn bool Result<T>::IsErr() const
   * @brief Check if the Result contains an Err value.
   * @deprecated -
   * @pre -
   * @param -
   * @retval true Result is Err
   * @retval false Result is Ok
   * @note -
   * @code -
   */
  bool IsErr() const { return std::holds_alternative<ErrorPtr>(value_); }

  /**
   * @ingroup common
   * @fn std::optional<T> Result<T>::TakeOk()
   * @brief Return the contained Ok value, or std::nullopt if the value is Err.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::optional<T> Ok value
   * @retval std::nullopt No Ok value
   * @note -
   * @code -
   */
  std::optional<T> TakeOk() {
    if (IsOk()) {
      return std::move(std::get<T>(value_));
    }
    return std::nullopt;
  }

  /**
   * @ingroup common
   * @fn ErrorPtr Result<T>::TakeErr()
   * @brief Return the contained Err value, or nullptr if the value is Ok.
   * @deprecated -
   * @pre -
   * @param -
   * @retval ErrorPtr Err value
   * @retval nullptr No Err value
   * @note -
   * @code -
   */
  ErrorPtr TakeErr() {
    if (IsErr()) {
      return std::move(std::get<ErrorPtr>(value_));
    }
    return nullptr;
  }

 private:
  /**
   * @ingroup common
   * @brief Internal storage for Ok or Err value.
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::variant<T, ErrorPtr> Ok or Err value
   * @note -
   * @code -
   */
  std::variant<T, ErrorPtr> value_;

  /**
   * @ingroup common
   * @fn Result<T>::Result(T val)
   * @brief Construct a Result object with Ok value.
   * @deprecated -
   * @pre -
   * @param val The value to store in Ok. Move semantics are used.
   * @retval Result<T> Ok value
   * @note -
   * @code -
   */
  explicit Result(T val) : value_(std::move(val)) {}
  /**
   * @ingroup common
   * @fn Result<T>::Result(ErrorPtr err)
   * @brief Construct a Result object with Err value.
   * @deprecated -
   * @pre -
   * @param err The error to store in Err. Move semantics are used.
   * @retval Result<T> Err value
   * @note -
   * @code -
   */
  explicit Result(ErrorPtr err) : value_(std::move(err)) {}
};

/**
 * @ingroup common
 * @class Result<void>
 * @brief A specialization of the Result type for void, holding either an Ok or
 * an Err value.
 */

template <>
class Result<void> final {
 public:
  struct Dummy {};

  using T = Dummy;
  using ErrorPtr = std::unique_ptr<yoriito::ErrorType>;

  /**
   * @ingroup common
   * @fn static Result<void>::Ok()
   * @brief Create a Result object containing an Ok value (void specialization).
   * @deprecated -
   * @pre -
   * @param -
   * @retval Result<void> Ok or Err
   * @note -
   * @code -
   */
  static Result Ok() { return Result(Dummy{}); }

  /**
   * @ingroup common
   * @fn static Result<void>::Err(ErrorPtr err)
   * @brief Create a Result object containing an Err value (void
   * specialization).
   * @deprecated -
   * @pre -
   * @param err The error to store in Err. Move semantics are used.
   * @retval Result<void> Ok or Err
   * @note -
   * @code -
   */
  static Result Err(ErrorPtr err) { return Result(std::move(err)); }

  /**
   * @ingroup common
   * @fn bool Result<void>::IsOk() const
   * @brief Check if the Result contains an Ok value (void specialization).
   * @deprecated -
   * @pre -
   * @param -
   * @retval true Result is Ok
   * @retval false Result is Err
   * @note -
   * @code -
   */
  bool IsOk() const { return std::holds_alternative<Dummy>(value_); }
  /**
   * @ingroup consumer
   * @fn bool Result<void>::IsErr() const
   * @brief Check if the Result contains an Err value (void specialization).
   * @deprecated -
   * @pre -
   * @param -
   * @retval true Result is Err
   * @retval false Result is Ok
   * @note -
   * @code -
   */
  bool IsErr() const { return std::holds_alternative<ErrorPtr>(value_); }

  /**
   * @ingroup common
   * @fn std::optional<T> Result<void>::TakeOk()
   * @brief Return the contained Ok value, or std::nullopt if the value is Err
   * (void specialization).
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::optional<T> Ok value
   * @retval std::nullopt No Ok value
   * @note -
   * @code -
   */
  std::optional<T> TakeOk() {
    if (IsOk()) {
      return std::move(std::get<T>(value_));
    }
    return std::nullopt;
  }

  /**
   * @ingroup common
   * @fn ErrorPtr Result<void>::TakeErr()
   * @brief Return the contained Err value, or nullptr if the value is Ok (void
   * specialization).
   * @deprecated -
   * @pre -
   * @param -
   * @retval ErrorPtr Err value
   * @retval nullptr No Err value
   * @note -
   * @code -
   */
  ErrorPtr TakeErr() {
    if (IsErr()) {
      return std::move(std::get<ErrorPtr>(value_));
    }
    return nullptr;
  }

 private:
  /**
   * @ingroup common
   * @brief Internal storage for Ok or Err value (void specialization).
   * @deprecated -
   * @pre -
   * @param -
   * @retval std::variant<Dummy, ErrorPtr> Ok or Err value
   * @note -
   * @code -
   */
  std::variant<Dummy, ErrorPtr> value_;
  /**
   * @ingroup common
   * @fn Result<void>::Result(Dummy val)
   * @brief Construct a Result object with Ok value (void specialization).
   * @deprecated -
   * @pre -
   * @param val The value to store in Ok. Move semantics are used.
   * @retval Result<void> Ok value
   * @note -
   * @code -
   */
  explicit Result(Dummy val) : value_(val) {}
  /**
   * @ingroup common
   * @fn Result<void>::Result(ErrorPtr err)
   * @brief Construct a Result object with Err value (void specialization).
   * @deprecated -
   * @pre -
   * @param err The error to store in Err. Move semantics are used.
   * @retval Result<void> Err value
   * @note -
   * @code -
   */
  explicit Result(ErrorPtr err) : value_(std::move(err)) {}
};

}  // namespace yoriito

#endif  // COMMON_RESULT_H_
