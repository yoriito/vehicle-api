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

#ifndef COMMON_LOGGER_STDOUT_LOGBACKEND_H_
#define COMMON_LOGGER_STDOUT_LOGBACKEND_H_

#include <unistd.h>

#include <chrono>
#include <cstdio>
#include <iostream>
#include <string>
#include <thread>

#include "logger/base_logbackend.h"

namespace yoriito {

// Backend that outputs logs to stdout.
class StdoutLogBackend final : public BaseLogBackend {
 public:
  StdoutLogBackend() = default;

  ~StdoutLogBackend() {
    // Safe cleanup in destructor
    try {
      if (IsInitialized()) {
        DoFinalize();
      }
    } catch (...) {
      // Suppress exceptions in destructor
    }
  }

 protected:
  std::string name_ = "";
  // In STDOUT_BACKEND, DoInitialize() just stores the name
  void DoInitialize(const char* name) override { name_ = name ? name : ""; }

  // In STDOUT_BACKEND, DoFinalize() does nothing
  void DoFinalize() override { name_ = ""; }

  // DoOutput received log as a single line to stdout
  // Format: yyyy-MM-ddTHH:mm:ss.SSSZ,PID,TID,LEVEL,name,TAG,msg
  void DoOutput(std::string_view tag, std::string_view msg,
                LogLevel level) override {
    // Do not output logs below the minimum log level
    if (level > GetLogLevelThreshold()) return;

    // Initialization check is performed by BaseLogBackend::Output before
    // calling DoOutput.
    std::cout << Timestamp() << ',';
    std::cout << getpid() << "," << std::this_thread::get_id() << ","
              << LevelToString(level) << "," << name_ << "," << tag << ","
              << msg << std::endl;
  }

  void DoSetLogLevel(LogLevel) override {}

 private:
  // Convert LogLevel to string
  static const char* LevelToString(LogLevel level) {
    switch (level) {
      case LogLevel::kFatal:
        return "FATAL";
      case LogLevel::kError:
        return "ERROR";
      case LogLevel::kWarn:
        return "WARN";
      case LogLevel::kInfo:
        return "INFO";
      case LogLevel::kDebug:
        return "DEBUG";
      default:
        return "UNKNOWN";
    }
  }

  // Simple timestamp (utc time): "yyyy-MM-ddTHH:mm:ss.SSSZ"
  std::string Timestamp() const {
    auto now = std::chrono::system_clock::now();
    std::time_t epochtime = std::chrono::system_clock::to_time_t(now);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                now.time_since_epoch()) %
              1000;

    std::tm tm{};
    gmtime_r(&epochtime, &tm);

    char buffer[sizeof("yyyy-MM-ddTHH:mm:ss.SSSZ")];
    int len =
      snprintf(buffer, sizeof(buffer), "%04d-%02d-%02dT%02d:%02d:%02d.%03dZ",
               tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
               tm.tm_min, tm.tm_sec, static_cast<int>(ms.count()));
    return std::string(buffer, len);
  }
};

}  // namespace yoriito
#endif  // COMMON_LOGGER_STDOUT_LOGBACKEND_H_
