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

find_package(Doxygen REQUIRED)

function(add_doxygen_target TARGET_NAME SOURCE_DIR DST_DIR)
  set(DOXYGEN_PROJECT_NAME "Yoriito Vehicle API - ${TARGET_NAME}")
  set(DOXYGEN_PROJECT_VERSION "${PROJECT_VERSION}")
  set(DOXYGEN_PROJECT_BRIEF "Yoriito Vehicle API Reference for module ${TARGET_NAME}")
  set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${DST_DIR}")
  set(DOXYGEN_INPUT "${SOURCE_DIR}")

  set(DOXYGEN_GENERATE_HTML YES)
  set(DOXYGEN_HTML_OUTPUT ".")
  set(DOXYGEN_EXTRACT_ALL YES)
  set(DOXYGEN_RECURSIVE YES)

  set(DOXYFILE_IN "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in")
  set(DOXYFILE_OUT "${CMAKE_BINARY_DIR}/Doxyfile_${TARGET_NAME}")

  configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

  file(MAKE_DIRECTORY "${DOXYGEN_OUTPUT_DIRECTORY}")

  add_custom_target("docs_${TARGET_NAME}"
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    COMMENT "Generating Doxygen documentation for ${TARGET_NAME}"
    VERBATIM
  )
endfunction()

add_doxygen_target(common
  "${PROJECT_SOURCE_DIR}/common"
  "docs/html/common"
)

add_doxygen_target(signal
  "${PROJECT_SOURCE_DIR}/signal"
  "docs/html/signal"
)

add_custom_target(docs)
add_dependencies(docs docs_common docs_signal)
