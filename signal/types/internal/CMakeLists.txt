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


file(GLOB_RECURSE STRUCT_SRC LIST_DIRECTORIES false *.cc)
file(GLOB_RECURSE PUBLIC_STRUCT_HEADERS LIST_DIRECTORIES false *.h)

add_library(yoriito_vehicle_api_struct SHARED ${STRUCT_SRC})
target_include_directories(yoriito_vehicle_api_struct PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_precompile_headers(yoriito_vehicle_api_struct PRIVATE
  <string>
  <databroker/consumer_inspect_response.h>
  <result.h>
  <databroker_type.h>
  <error.h>
  <yoriito_log.h>
)

install(
  TARGETS yoriito_vehicle_api_struct LIBRARY DESTINATION ${LIBRARY_INSTALL_DIR}
)
