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

cmake_minimum_required(VERSION 3.28)
project(yoriito_vehicle_api)

include("${CMAKE_SOURCE_DIR}/cmake/yoriito_common.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/options.cmake")
include("${CMAKE_SOURCE_DIR}/cmake/yoriito_utl.cmake")

if(BUILD_COMMON)
  add_subdirectory(common)
endif()

if(BUILD_SIGNAL)
  add_subdirectory(signal)

  add_library(yoriito_vehicle_api INTERFACE)
  add_library(yoriito::api ALIAS yoriito_vehicle_api)

  target_include_directories(yoriito_vehicle_api INTERFACE
      ${INTERFACE_INCLUDE_DIR}
      ${INTERFACE_INCLUDE_DIR}/databroker
      ${INTERFACE_INCLUDE_DIR}/signal
      ${CMAKE_CURRENT_SOURCE_DIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/common
      ${CMAKE_CURRENT_SOURCE_DIR}/common/databroker
      ${CMAKE_CURRENT_SOURCE_DIR}/common/signal
  )

  target_link_libraries(yoriito_vehicle_api INTERFACE
        yoriito_vehicle_api_vehicle
  )
  
  foreach(_domain IN LISTS _YORIITO_API_DOMAINS)
    if(ENABLE_${_domain})
      string(TOLOWER "${_domain}" _domain_lower)
      target_link_libraries(yoriito_vehicle_api INTERFACE
        yoriito_vehicle_api_${_domain_lower}
      )
    endif()
  endforeach()

  target_link_libraries(yoriito_vehicle_api INTERFACE
        logger
  )
  if(TARGET yoriito_vehicle_api_struct)
    target_link_libraries(yoriito_vehicle_api INTERFACE yoriito_vehicle_api_struct)
  endif()
endif() 

if(ENABLE_DOCS)
  add_subdirectory(docs)
endif()

if(ENABLE_TESTS)
  enable_testing()
  include(FetchContent)

  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  )

  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

  get_directory_property(_yoriito_compile_options COMPILE_OPTIONS)
  set_directory_properties(PROPERTIES COMPILE_OPTIONS "")
  FetchContent_MakeAvailable(googletest)
  set_directory_properties(PROPERTIES COMPILE_OPTIONS "${_yoriito_compile_options}")

  add_subdirectory(test)
endif()

if(ENABLE_FUZZ_TESTS)
  add_subdirectory(test_fuzz)
endif()
