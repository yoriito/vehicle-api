# SPDX-License-Identifier: Apache-2.0
#
# Copyright 2026 JASPAR
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# For common/
option(BUILD_COMMON "Build common library" ON)

# For common/logger
# Enable this option to use log output via dlt-daemon.
# If the dlt-daemon development package(automotive-dlt) is not installed, the build will fail.
# Tested with dlt-daemon version 3.0.0. See: https://github.com/COVESA/dlt-daemon
# If this option is disabled, logs will be output to standard output (stdout) without using the DLT library.
option(ENABLE_LOG_BACKEND_DLT "Enable DLT library" ON)

# For signal/
option(BUILD_SIGNAL "Build signal library" ON)

# For documentation
option(ENABLE_DOCS "Enable building documentation" OFF)

# For Unit Tests
option(ENABLE_TESTS "Enable building tests" OFF)
if(ENABLE_TESTS AND NOT BUILD_COMMON)
  message(FATAL_ERROR
          "ENABLE_TESTS requires BUILD_COMMON=ON, but, this flag is disabled.")
endif()
if(ENABLE_TESTS AND NOT BUILD_SIGNAL)
  message(FATAL_ERROR
          "ENABLE_TESTS requires BUILD_SIGNAL=ON, but, this flag is disabled.")
endif()

# For Division Build
set(_YORIITO_API_DOMAINS
    ADAS
    BODY
    CABIN
    CHASSIS
    CURRENTLOCATION
    DRIVER
    EXTERIOR
    LOWVOLTAGEBATTERY
    MOTIONMANAGEMENT
    OCCUPANT
    POWERTRAIN
    TRAILER
    TRIPMETER
    VEHICLEIDENTIFICATION
    VERSIONVSS
    VERSIONYORIITOVSS
)

set(_ANY_DOMAIN_SPECIFIED OFF)
foreach(_domain IN LISTS _YORIITO_API_DOMAINS)
  if(ENABLE_${_domain})
    set(_ANY_DOMAIN_SPECIFIED ON)
    break()
  endif()
endforeach()

if(NOT _ANY_DOMAIN_SPECIFIED)
  message(STATUS "No domain specified. Enabling all domains.")
  foreach(_domain IN LISTS _YORIITO_API_DOMAINS)
    set(ENABLE_${_domain} ON)
  endforeach()
endif()

# For Fuzz Tests (AFL++ + AddressSanitizer)
option(ENABLE_FUZZ_TESTS "Enable building fuzz test harnesses" OFF)
if(ENABLE_FUZZ_TESTS AND NOT BUILD_SIGNAL)
  message(FATAL_ERROR
          "ENABLE_FUZZ_TESTS requires BUILD_SIGNAL=ON, but, this flag is disabled.")
endif()

if(ENABLE_FUZZ_TESTS)
  if(NOT CMAKE_CXX_COMPILER MATCHES "afl-clang-fast\\+\\+" AND
     NOT CMAKE_CXX_COMPILER MATCHES "afl-g\\+\\+(-fast)?" AND
     NOT CMAKE_CXX_COMPILER MATCHES "afl-gcc-fast\\+\\+")
    message(FATAL_ERROR
            "ENABLE_FUZZ_TESTS requires an AFL++ C++ compiler wrapper (e.g. afl-clang-fast++ or afl-g++[-fast]) "
            "(got: ${CMAKE_CXX_COMPILER}).")
  endif()
endif()

