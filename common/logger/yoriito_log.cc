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
#include <memory>
#include <mutex>
#include "yoriito_log.h"
#include "logger/base_logbackend.h"

namespace yoriito {

struct Log::LoggerBackendManager {
  std::shared_ptr<ILogBackend> backend_;
  mutable std::mutex backend_mutex_;
};

Log::LoggerBackendManager& Log::BackendManager() {
  static LoggerBackendManager backend_manager;
  return backend_manager;
}

void Log::Initialize(const char* name) {
  std::lock_guard<std::mutex> lock(BackendManager().backend_mutex_);
  if (!BackendManager().backend_) {
    BackendManager().backend_ = ILogBackend::GetLogBackend();
  }
  if (BackendManager().backend_->IsInitialized()) {
    return;  // Already initialized
  }
  BackendManager().backend_->Initialize(name);
}

void Log::Finalize() {
  std::lock_guard<std::mutex> lock(BackendManager().backend_mutex_);
  if (!BackendManager().backend_) {
    return;
  }
  if (!BackendManager().backend_->IsInitialized()) {
    return;
  }
  BackendManager().backend_->Finalize();
}

void Log::SetLogLevel(LogLevel level) {
  std::lock_guard<std::mutex> lock(BackendManager().backend_mutex_);
  if (!BackendManager().backend_) {
    return;
  }
  if (!BackendManager().backend_->IsInitialized()) {
    return;
  }
  BackendManager().backend_->SetLogLevel(level);
}

void Log::Output(std::string_view tag, std::string_view msg,
                     LogLevel level) {
  // Do not output logs if not initialized or backend is not created
  std::lock_guard<std::mutex> lock(BackendManager().backend_mutex_);
  if (!BackendManager().backend_) {
    return;
  }
  if (!BackendManager().backend_->IsInitialized()) {
    return;
  }
  BackendManager().backend_->Output(tag, msg, level);
}

}  // namespace yoriito
