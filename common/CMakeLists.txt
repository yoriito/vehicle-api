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

include("${CMAKE_SOURCE_DIR}/cmake/yoriito_common.cmake")

file(GLOB PUBLIC_HEADERS LIST_DIRECTORIES false *.h)

add_subdirectory(databroker)
add_subdirectory(logger)
add_subdirectory(signal)

# install
install(FILES ${PUBLIC_HEADERS} DESTINATION ${INCLUDE_INSTALL_DIR})
