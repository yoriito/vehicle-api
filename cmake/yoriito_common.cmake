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

include_guard(GLOBAL)

set(YORIITO "yoriito")

if(DEFINED ENV{SDKTARGETSYSROOT} AND NOT "$ENV{SDKTARGETSYSROOT}" STREQUAL "")
    # For Yocto SDK
    message(STATUS "Using SDKTARGETSYSROOT as SYSROOT: $ENV{SDKTARGETSYSROOT}")
    set(SYSROOT "$ENV{SDKTARGETSYSROOT}")
elseif(DEFINED CMAKE_SYSROOT AND NOT "${CMAKE_SYSROOT}" STREQUAL "")
    # For Yocto build
    message(STATUS "Using CMAKE_SYSROOT as SYSROOT: ${CMAKE_SYSROOT}")
    set(SYSROOT "${CMAKE_SYSROOT}")
else()
    message(STATUS "No SYSROOT defined, using default system paths")
    set(SYSROOT "")
endif()

set(SDKTARGETSYSROOT ${SYSROOT})
set(INTERFACE_INCLUDE_DIR ${SYSROOT}/usr/include/${YORIITO})
set(INTERFACE_LIBRARY_DIR ${SYSROOT}/usr/lib/${YORIITO})
# Generally, link_directories should not be used in modern CMake,
# but it is necessary here to ensure that the libraries are found
# when building with a Yocto SDK or sysroot.
# the added path is used by the yoriito library only,
# so it is reasonable to use it here.
link_directories(${SYSROOT}/usr/lib/${YORIITO})

# install directories
include(GNUInstallDirs)
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX /usr CACHE PATH "Installation prefix" FORCE)
endif()
set(INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_INCLUDEDIR}/${YORIITO})
set(LIBRARY_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/${YORIITO})
set(BIN_INSTALL_DIR ${CMAKE_INSTALL_BINDIR})
set(DATA_INSTALL_DIR ${CMAKE_INSTALL_DATADIR}/${YORIITO})

# Compile Option
add_compile_options(
    -std=c++17
    -Wall
    -Wextra
    -Wconversion
    -Wzero-as-null-pointer-constant
    -Wcast-qual
    -Wswitch-default
    -Wimplicit-fallthrough
    -Wvla
    -Wsuggest-override
    -Wundef
    -Wformat=2
    -Wfloat-equal
)
# add_compile_options(-g)

# Absl and gRPC use __FILE__ macro a lot,
# so resulting binary will include local file paths.
# This can cause issues with reproducible builds.
# We can use -fmacro-prefix-map to replace local paths with a generic one.
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    if(SYSROOT)
        add_compile_options(-fmacro-prefix-map=${SYSROOT}=/usr)
    endif()

    add_compile_options(-fmacro-prefix-map=${CMAKE_SOURCE_DIR}=.)
    add_compile_options(-fmacro-prefix-map=${CMAKE_BINARY_DIR}=.)
endif()

option(CODE_COVERAGE "Enable coverage reporting" OFF)

if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Building with code coverage flags")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  add_compile_options(-fpch-preprocess)
  set(CMAKE_C_COMPILER_LAUNCHER   ${CCACHE_PROGRAM})
  set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
endif()
