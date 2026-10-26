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

# AFL_COMPILER is derived from CMAKE_CXX_COMPILER automatically.
#
# Build with gcc (afl-g++, GCC plugin instrumentation, default):
#   cmake -DCMAKE_CXX_COMPILER=afl-g++ -DENABLE_FUZZ_TESTS=ON ..
#
# Build with clang (afl-clang-fast++, LTO instrumentation, faster):
#   cmake -DCMAKE_CXX_COMPILER=afl-clang-fast++ -DENABLE_FUZZ_TESTS=ON ..
if(CMAKE_CXX_COMPILER MATCHES "afl-clang")
    message(STATUS "Building fuzz harnesses for AFL++ (afl-clang-fast++)")
elseif(CMAKE_CXX_COMPILER MATCHES "afl-g\\+\\+")
    message(STATUS "Building fuzz harnesses for AFL++ (afl-g++)")
else()
    message(WARNING
        "CXX is '${CMAKE_CXX_COMPILER}', which does not look like an AFL++ wrapper. "
        "Set -DCMAKE_CXX_COMPILER=afl-g++ or afl-clang-fast++ for correct instrumentation.")
endif()

function(add_fuzz_harness TARGET_NAME)
    add_executable(${TARGET_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET_NAME}.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/FuzzHelpers.cc
    )
    target_include_directories(${TARGET_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/inc
        ${PROJECT_SOURCE_DIR}/common
        ${CMAKE_CURRENT_SOURCE_DIR}/..
    )
    target_link_libraries(${TARGET_NAME} PRIVATE
        $<LINK_LIBRARY:WHOLE_ARCHIVE,fuzz_mock>
        yoriito_vehicle_api
    )
    target_link_directories(${TARGET_NAME} PRIVATE
        ${INTERFACE_LIBRARY_DIR}
    )
    target_link_options(${TARGET_NAME} PRIVATE -Wl,--export-dynamic)
endfunction()

add_fuzz_harness(FuzzGet_Acceleration)
add_fuzz_harness(FuzzGet_AngularVelocity)
add_fuzz_harness(FuzzGet_Bool)
add_fuzz_harness(FuzzGet_Electricity)
add_fuzz_harness(FuzzGet_Float)
add_fuzz_harness(FuzzGet_GNSSLocation)
add_fuzz_harness(FuzzGet_Int8)
add_fuzz_harness(FuzzGet_Int16)
add_fuzz_harness(FuzzGet_Int32)
add_fuzz_harness(FuzzGet_Location)
add_fuzz_harness(FuzzGet_PointingDirection)
add_fuzz_harness(FuzzGet_Pose)
add_fuzz_harness(FuzzGet_RoadFrictionRange)
add_fuzz_harness(FuzzGet_String)
add_fuzz_harness(FuzzGet_ThreePhaseCurrentMeasurements)
add_fuzz_harness(FuzzGet_ThreePhaseVoltageMeasurements)
add_fuzz_harness(FuzzGet_Uint8)
add_fuzz_harness(FuzzGet_Uint16)
add_fuzz_harness(FuzzGet_Uint32)
add_fuzz_harness(FuzzGet_VehicleLocation)
add_fuzz_harness(FuzzSet_Float)
add_fuzz_harness(FuzzSet_Int8)
add_fuzz_harness(FuzzSet_String)
add_fuzz_harness(FuzzSet_Uint8)
add_fuzz_harness(FuzzSet_Uint16)

