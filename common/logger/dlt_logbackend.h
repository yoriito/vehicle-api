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

#ifndef COMMON_LOGGER_DLT_LOGBACKEND_H_
#define COMMON_LOGGER_DLT_LOGBACKEND_H_

#include <dlt/dlt.h>
#include <unistd.h>

#include <memory>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>
#include <unordered_map>

#include "logger/base_logbackend.h"

namespace yoriito {
static constexpr std::string::size_type kDltIdMaxLength{
  4U};                                              // Max length for DLT IDs
constexpr std::string_view kDefaultDltID = "----";  // Default DLT ID

// Backend that outputs logs to DLT.
class DltLogBackend final : public BaseLogBackend {
 public:
  DltLogBackend() = default;
  ~DltLogBackend() noexcept override {
    // Safe cleanup in destructor
    try {
      // Avoid finalization if not initialized
      if (BaseLogBackend::IsInitialized()) {
        CleanupDltResources();
      }
    } catch (...) {
      // Suppress exceptions in destructor
    }
  }
  DltLogBackend(const DltLogBackend&) = delete;
  DltLogBackend& operator=(const DltLogBackend&) = delete;
  DltLogBackend(DltLogBackend&&) = delete;
  DltLogBackend& operator=(DltLogBackend&&) = delete;

 protected:
  void DoInitialize(const char* name) override {
    name_ = name ? std::string(name) : "";
    // Adjusts the APID to fit DLT's size restrictions
    std::string standardized_app_id = ConvertToDltId(name_);
    DLT_REGISTER_APP(standardized_app_id.c_str(), name_.c_str());
  }

  void DoFinalize() override { CleanupDltResources(); }

  void DoOutput(std::string_view tag, std::string_view msg,
                LogLevel level) override {
    DltContext& context = EnsureContext(std::string(tag));

    pid_t pid = getpid();
    std::ostringstream tid_stream;
    tid_stream << std::this_thread::get_id();
    std::string tid_str = tid_stream.str();

    DLT_LOG(context, ConvertToDltLevel(level),
            DLT_UINT32(static_cast<std::uint32_t>(pid));
            DLT_CSTRING(tid_str.c_str()); DLT_CSTRING(name_.c_str());
            DLT_SIZED_CSTRING(tag.data(), ConvertSizeToDltUint16(tag.size()));
            DLT_SIZED_CSTRING(msg.data(), ConvertSizeToDltUint16(msg.size())));
  }

  void DoSetLogLevel(LogLevel level) override {
    DLT_SET_APPLICATION_LL_TS_LIMIT(ConvertToDltLevel(level),
                                    DLT_TRACE_STATUS_OFF);
  }

 private:
  std::string name_ = "";
  void CleanupDltResources() {
    name_ = "";
    for (auto& context_entry : context_map_) {
      DLT_UNREGISTER_CONTEXT(*(context_entry.second));
    }
    context_map_.clear();
    DLT_UNREGISTER_APP();
  }

  // Convert LogLevel to DltLogLevelType
  static DltLogLevelType ConvertToDltLevel(LogLevel level) {
    switch (level) {
      case LogLevel::kFatal:
        return DLT_LOG_FATAL;
      case LogLevel::kError:
        return DLT_LOG_ERROR;
      case LogLevel::kWarn:
        return DLT_LOG_WARN;
      case LogLevel::kInfo:
        return DLT_LOG_INFO;
      case LogLevel::kDebug:
        return DLT_LOG_DEBUG;
      default:
        return DLT_LOG_INFO;
    }
  }

  // DLT requires context ID and APID to be max characters
  static std::string ConvertToDltId(const std::string& input_id) {
    // Return default ID for empty string as-is
    if (input_id.empty()) {
      return std::string(kDefaultDltID);
    }
    if (input_id.size() <= kDltIdMaxLength) {
      return input_id;
    }
    return input_id.substr(0, kDltIdMaxLength);
  }

  DltContext& EnsureContext(const std::string& tag) {
    const std::string context_id = ConvertToDltId(tag);
    auto it = context_map_.find(context_id);
    if (it != context_map_.end()) {
      return *(it->second);
    }

    // Insert before registration to ensure cleanup on exception
    auto context = std::make_unique<DltContext>();
    auto emplace_result =
      context_map_.try_emplace(context_id, std::move(context));
    auto iter = emplace_result.first;
    const bool inserted = emplace_result.second;
    if (!inserted) {
      return *(iter->second);
    }

    DLT_REGISTER_CONTEXT_LL_TS(
      *(iter->second), context_id.c_str(), tag.c_str(),
      static_cast<int32_t>(ConvertToDltLevel(GetLogLevelThreshold())),
      DLT_TRACE_STATUS_OFF);  // Full tag in description
    return *(iter->second);
  }

  static std::uint16_t ConvertSizeToDltUint16(std::size_t value) {
    constexpr std::size_t max_value =
      static_cast<std::size_t>(std::numeric_limits<std::uint16_t>::max());
    if (value > max_value) {
      return std::numeric_limits<std::uint16_t>::max();
    }
    return static_cast<std::uint16_t>(value);
  }

  std::unordered_map<std::string, std::unique_ptr<DltContext>> context_map_;
};

}  // namespace yoriito
#endif  // COMMON_LOGGER_DLT_LOGBACKEND_H_
