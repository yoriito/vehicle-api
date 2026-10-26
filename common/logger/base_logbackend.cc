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

#include "logger/base_logbackend.h"

#ifdef ENABLE_LOG_BACKEND_DLT
#include "logger/dlt_logbackend.h"
#else
#include "logger/stdout_logbackend.h"
#endif
#include <mutex>

namespace yoriito {

// Factory method implementation with mutex protection
std::shared_ptr<ILogBackend> ILogBackend::GetLogBackend() {
  static std::shared_ptr<ILogBackend> backend_instance;
  if (!backend_instance) {
#ifdef ENABLE_LOG_BACKEND_DLT
    backend_instance = std::make_shared<DltLogBackend>();
#else
    backend_instance = std::make_shared<StdoutLogBackend>();
#endif
  }
  return backend_instance;
}

void BaseLogBackend::Initialize(const char* name) {
  if (initialized_) {
    return;
  }
  DoInitialize(name);
  initialized_ = true;
}

void BaseLogBackend::Finalize() {
  if (!initialized_) {
    return;
  }
  DoFinalize();
  initialized_ = false;
}

void BaseLogBackend::Output(std::string_view tag, std::string_view msg,
                            LogLevel level) {
  if (!initialized_) {
    return;  // Do not output log if not initialized
  }
  DoOutput(tag, msg, level);
}

bool BaseLogBackend::IsInitialized() const { return initialized_; }

void BaseLogBackend::SetLogLevel(LogLevel level) {
  if (!initialized_) {
    return;  // Do not set log level if not initialized
  }
  log_level_threshold_ = level;
  DoSetLogLevel(level);
}
}  // namespace yoriito
