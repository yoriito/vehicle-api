# SPDX-License-Identifier: Apache-2.0
#
# Copyright 2026 JASPAR
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

function(yoriito_create_vehicle_api_includes)
  if(TARGET yoriito_vehicle_api_includes)
    return()  
  endif()

  add_library(yoriito_vehicle_api_includes INTERFACE)
  target_include_directories(yoriito_vehicle_api_includes INTERFACE 
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/common
    ${PROJECT_SOURCE_DIR}/signal)

  add_library(pch_common INTERFACE)
  target_precompile_headers(pch_common INTERFACE 
    <vector>
    <algorithm>
    <cstdint>
    <memory>
    <set>
    <string>
    <variant>
    <databroker/databroker_consumer.h>
    <databroker/databroker_consumer_factory.h>
    <result.h>
  )
endfunction()

function(yoriito_test_helper)
  set(ONE_VAL_ARGS TARGET)
  set(MULT_VAL_ARGS LIBS)

  cmake_parse_arguments(ARG
        ""
        "${ONE_VAL_ARGS}"
        "${MULT_VAL_ARGS}"
        ${ARGN}
  )

  if(NOT ARG_TARGET)
        message(FATAL_ERROR "yoriito_test_helper: TARGET parameter is required")
  endif()

  target_include_directories(
        ${ARG_TARGET} AFTER
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/common
        ${PROJECT_SOURCE_DIR}/common/databroker
        ${PROJECT_SOURCE_DIR}/signal
        ${PROJECT_SOURCE_DIR}/mock/databroker/inc
  )

  target_link_libraries(${ARG_TARGET}
        PRIVATE
        GTest::gtest_main
        gmock
        logger
        ${ARG_LIBS}
  )
endfunction()

function(yoriito_add_library)
  set(ONE_VAL_ARGS NAME INSTALL_SUBDIR)
  set(MULT_VAL_ARGS SOURCES PREHEADER LIBS)

  cmake_parse_arguments(
        API
        ""
        "${ONE_VAL_ARGS}"
        "${MULT_VAL_ARGS}"
        ${ARGN}
  )

  if(NOT API_NAME)
        message(FATAL_ERROR "yoriito_add_library: NAME parameter is required")
  endif()
  if(NOT API_INSTALL_SUBDIR)
        message(FATAL_ERROR "yoriito_add_library: INSTALL_SUBDIR parameter is required")
  endif()

  yoriito_create_vehicle_api_includes()
  
  add_library(${API_NAME} SHARED ${API_SOURCES})

  target_include_directories(${API_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

  list(APPEND API_LIBS yoriito_vehicle_api_includes)
  target_link_libraries(${API_NAME} PRIVATE ${API_LIBS} pch_common)

  if(API_PREHEADER)
        target_precompile_headers(${API_NAME} PRIVATE
          ${API_PREHEADER}
        )
  endif()

  if(CCACHE_PROGRAM)
        set_property(
          TARGET ${API_NAME}
          PROPERTY RULE_LAUNCH_COMPILE
          "CCACHE_SLOPPINESS=pch_defines,time_macros ${CCACHE_PROGRAM}"
        )
  endif()

  install(
        TARGETS ${API_NAME}
        EXPORT yoriito_vehicle_apiTargets
        LIBRARY DESTINATION ${LIBRARY_INSTALL_DIR}
  )

  install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
        DESTINATION "${INCLUDE_INSTALL_DIR}/${API_INSTALL_SUBDIR}"
        FILES_MATCHING PATTERN "*.h"
  )

endfunction()

function(yoriito_create_test_includes)
  if(TARGET yoriito_test_includes)
        return()  
  endif()

  add_library(yoriito_test_includes OBJECT
        ${PROJECT_SOURCE_DIR}/mock/databroker/src/mock_databroker_consumer_factory.cc
  )

  yoriito_test_helper(TARGET yoriito_test_includes)

  target_precompile_headers(yoriito_test_includes PUBLIC
        <gmock/gmock.h>
        <gtest/gtest.h>
        <memory>
        <string>
  )

  if(CCACHE_PROGRAM)
        set_property(
          TARGET yoriito_test_includes
          PROPERTY RULE_LAUNCH_COMPILE
          "CCACHE_SLOPPINESS=pch_defines,time_macros ${CCACHE_PROGRAM}"
        )
  endif()
endfunction()

function(yoriito_add_test)
  set(ONE_VAL_ARGS NAME)
  set(MULT_VAL_ARGS SOURCES LIBS)
  cmake_parse_arguments(
        TEST
        ""
        "${ONE_VAL_ARGS}"
        "${MULT_VAL_ARGS}"
        ${ARGN}
  )
  if(NOT TEST_NAME)
        message(FATAL_ERROR "yoriito_add_test: NAME parameter is required")
  endif()
  if(NOT TEST_SOURCES)
        message(FATAL_ERROR "yoriito_add_test: SOURCES parameter is required")
  endif()
  if(NOT TEST_LIBS)
        message(FATAL_ERROR "yoriito_add_test: LIBS parameter is required")
  endif()

  yoriito_create_test_includes()

  add_executable(
        ${TEST_NAME} 
        ${TEST_SOURCES} 
  ) 

  target_precompile_headers(${TEST_NAME} REUSE_FROM yoriito_test_includes)

  if(CCACHE_PROGRAM)
        set_property(
          TARGET ${TEST_NAME}
          PROPERTY RULE_LAUNCH_COMPILE
          "CCACHE_SLOPPINESS=pch_defines,time_macros ${CCACHE_PROGRAM}"
        )
  endif()

  if(TARGET yoriito_vehicle_api_struct)
        list(APPEND TEST_LIBS yoriito_vehicle_api_struct)
  endif()

  target_link_directories(
        ${TEST_NAME}
        PRIVATE ${LIBRARY_INSTALL_DIR}
  )
  yoriito_test_helper(
        TARGET ${TEST_NAME}
        LIBS yoriito_test_includes ${TEST_LIBS}
  )
  add_test(
        NAME ${TEST_NAME}
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME}
  )
  message(STATUS "SRC_FILES = ${TEST_SOURCES}")
endfunction()

