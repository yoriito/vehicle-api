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

#ifndef COMMON_YORIITO_LOG_H_
#define COMMON_YORIITO_LOG_H_

#include <cstdint>
#include <string_view>

/**
 * @ingroup common
 * @namespace yoriito
 * @brief -
 */
namespace yoriito {

/**
 * @ingroup common
 * @class LogLevel
 */
enum class LogLevel : int32_t {
  /**
   * @brief Fatal error. Should be extremely rare.
   */
  kFatal,
  /**
   * @brief Error affecting correct functionality.
   */
  kError,
  /**
   * @brief Warning when correct operation cannot be guaranteed.
   */
  kWarn,
  /**
   * @brief Important information to help overall understanding.
   */
  kInfo,
  /**
   * @brief Detailed debug information for programmers.
   */
  kDebug
};

/**
 * @ingroup common
 * @class Log
 */
class Log final {
 public:
  /**
   * @ingroup common
   * @fn Log::Initialize
   * @brief Declare the start of using the YORIITO logging system for the
   * process. Logging output will be enabled from this point.
   * @deprecated -
   * @pre -
   * @param name Process identifier name. Any string with at least one
   * character.
   * @retval void
   * @note If name is an empty string, "----" will be used as the DLT APID.
   * @code
   * -
   * @endcode
   */
  static void Initialize(const char* name);

  /**
   * @ingroup common
   * @fn Log::Finalize
   * @brief Declare the end of using the YORIITO logging system for the process.
   * Logging output will be disabled from this point.
   * @deprecated -
   * @pre -
   * @param -
   * @retval void
   * @note -
   * @code
   * -
   * @endcode
   */
  static void Finalize();

  /**
   * @ingroup common
   * @fn Log::Output
   * @brief Output a log message
   * @deprecated -
   * @pre Effective between Initialize and Finalize
   * @param tag Tag information. Any string with at least one character.
   * @param msg Message content. Any string with at least one character.
   * @param level Log level
   * @retval void
   * @note If tag is an empty string, "----" will be used as the DLT Context ID.
   * @code
   * -
   * @endcode
   */
  static void Output(std::string_view tag, std::string_view msg,
                     LogLevel level);

  /**
   * @ingroup common
   * @fn Log::SetLogLevel
   * @brief Set the current log level. If not set, the default current log level
   * is "INFO".
   * @deprecated -
   * @pre Effective between Initialize and Finalize
   * @param level Log level to set
   * @retval void
   * @note -
   * @code
   * -
   * @endcode
   */
  static void SetLogLevel(LogLevel level);

 private:
  struct LoggerBackendManager;
  static LoggerBackendManager& BackendManager();
};

}  // namespace yoriito

/**
 * @ingroup common
 * @fn YORIITO_LOG_FATAL
 * @brief Output a fatal level log message
 * @deprecated -
 * @pre Effective between Initialize and Finalize
 * @param tag Tag information. Any string with at least one character.
 * @param msg Message content. Any string with at least one character.
 * @retval void
 * @note If tag is an empty string, "----" will be used as the DLT Context ID.
 * @code
 * -
 * @endcode
 */
#define YORIITO_LOG_FATAL(tag, msg)                                  \
  do {                                                               \
    ::yoriito::Log::Output((tag), (msg), yoriito::LogLevel::kFatal); \
  } while (false)

/**
 * @ingroup common
 * @fn YORIITO_LOG_ERROR
 * @brief Output an error level log message
 * @deprecated -
 * @pre Effective between Initialize and Finalize
 * @param tag Tag information. Any string with at least one character.
 * @param msg Message content. Any string with at least one character.
 * @retval void
 * @note If tag is an empty string, "----" will be used as the DLT Context ID.
 * @code
 * -
 * @endcode
 */
#define YORIITO_LOG_ERROR(tag, msg)                                  \
  do {                                                               \
    ::yoriito::Log::Output((tag), (msg), yoriito::LogLevel::kError); \
  } while (false)

/**
 * @ingroup common
 * @fn YORIITO_LOG_WARN
 * @brief Output a warning level log message
 * @deprecated -
 * @pre Effective between Initialize and Finalize
 * @param tag Tag information. Any string with at least one character.
 * @param msg Message content. Any string with at least one character.
 * @retval void
 * @note If tag is an empty string, "----" will be used as the DLT Context ID.
 * @code
 * -
 * @endcode
 */
#define YORIITO_LOG_WARN(tag, msg)                                  \
  do {                                                              \
    ::yoriito::Log::Output((tag), (msg), yoriito::LogLevel::kWarn); \
  } while (false)

/**
 * @ingroup common
 * @fn YORIITO_LOG_INFO
 * @brief Output an info level log message
 * @deprecated -
 * @pre Effective between Initialize and Finalize
 * @param tag Tag information. Any string with at least one character.
 * @param msg Message content. Any string with at least one character.
 * @retval void
 * @note If tag is an empty string, "----" will be used as the DLT Context ID.
 * @code
 * -
 * @endcode
 */
#define YORIITO_LOG_INFO(tag, msg)                                  \
  do {                                                              \
    ::yoriito::Log::Output((tag), (msg), yoriito::LogLevel::kInfo); \
  } while (false)

/**
 * @ingroup common
 * @fn YORIITO_LOG_DEBUG
 * @brief Output a debug level log message
 * @deprecated -
 * @pre Effective between Initialize and Finalize
 * @param tag Tag information. Any string with at least one character.
 * @param msg Message content. Any string with at least one character.
 * @retval void
 * @note If tag is an empty string, "----" will be used as the DLT Context ID.
 * @code
 * -
 * @endcode
 */
#define YORIITO_LOG_DEBUG(tag, msg)                                  \
  do {                                                               \
    ::yoriito::Log::Output((tag), (msg), yoriito::LogLevel::kDebug); \
  } while (false)

/**
 * @ingroup common
 * @fn Log::Initialize
 * @brief Declare the start of using the YORIITO logging system for the process.
 * Logging output will be enabled from this point.
 * @deprecated -
 * @pre -
 * @param name Process identifier name. Any string with at least one character.
 * @retval void
 * @note If name is an empty string, "----" will be used as the DLT Application
 * ID.
 * @code
 * -
 * @endcode
 */
#define YORIITO_LOG_INITIALIZE(name)    \
  do {                                  \
    ::yoriito::Log::Initialize((name)); \
  } while (false)

/**
 * @ingroup common
 * @fn Log::Finalize
 * @brief Declare the end of using the YORIITO logging system for the process.
 * Logging output will be disabled from this point.
 * @deprecated -
 * @pre -
 * @param -
 * @retval void
 * @note -
 * @code
 * -
 * @endcode
 */
#define YORIITO_LOG_FINALIZE()  \
  do {                          \
    ::yoriito::Log::Finalize(); \
  } while (false)

/**
 * @def YORIITO_LOG_SET_LEVEL
 * @brief Set the current log level. If not set, the default current log level
 * is "INFO".
 * @deprecated -
 * @pre  Effective between Initialize and Finalize
 * @param level Log level to set
 * @retval void
 * @note -
 * @code
 * -
 * @endcode
 */
#define YORIITO_LOG_SET_LEVEL(level)      \
  do {                                    \
    ::yoriito::Log::SetLogLevel((level)); \
  } while (false)

#endif  // COMMON_YORIITO_LOG_H_
