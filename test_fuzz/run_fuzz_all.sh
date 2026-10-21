#!/usr/bin/env bash
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

# Run all AFL++ fuzz harnesses in parallel.
# Usage: ./test_fuzz/run_fuzz_all.sh [SECONDS]
#   SECONDS: fuzzing duration per harness (default: 60)

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build_fuzz"
HARNESS_DIR="${BUILD_DIR}/test_fuzz/harness"
CORPUS_DIR="${SCRIPT_DIR}/corpus"
FINDINGS_DIR="${ROOT_DIR}/findings"
DURATION="${1:-60}"

# Detect ASAN-instrumented harnesses and disable AFL++ memory limit
AFL_MEM_FLAG=""
FIRST_HARNESS=$(find "${HARNESS_DIR}" -maxdepth 1 -type f -executable 2>/dev/null | head -1)
if [ -n "${FIRST_HARNESS}" ] && nm "${FIRST_HARNESS}" 2>/dev/null | grep -q "__asan"; then
  AFL_MEM_FLAG="-m none"
fi

# harness -> corpus directory mapping
declare -A CORPUS_MAP=(
  [FuzzGet_Acceleration]="struct_acceleration"
  [FuzzGet_AngularVelocity]="struct_angular_velocity"
  [FuzzGet_Bool]="boolean"
  [FuzzGet_Electricity]="struct_electricity"
  [FuzzGet_Float]="float"
  [FuzzGet_GNSSLocation]="struct_gnss_location"
  [FuzzGet_Int16]="int16"
  [FuzzGet_Int32]="int32"
  [FuzzGet_Int8]="int8"
  [FuzzGet_Location]="struct_location"
  [FuzzGet_PointingDirection]="struct_pointing_direction"
  [FuzzGet_Pose]="struct_pose"
  [FuzzGet_RoadFrictionRange]="struct_road_friction_range"
  [FuzzGet_String]="string"
  [FuzzGet_ThreePhaseCurrentMeasurements]="struct_three_phase_current_measurements"
  [FuzzGet_ThreePhaseVoltageMeasurements]="struct_three_phase_voltage_measurements"
  [FuzzGet_Uint16]="uint16"
  [FuzzGet_Uint32]="uint32"
  [FuzzGet_Uint8]="uint8"
  [FuzzGet_VehicleLocation]="struct_vehicle_location"
  [FuzzSet_Float]="float"
  [FuzzSet_Int8]="int8"
  [FuzzSet_String]="string"
  [FuzzSet_Uint16]="uint16"
  [FuzzSet_Uint8]="uint8"
)

PIDS=()

for TARGET in "${!CORPUS_MAP[@]}"; do
  HARNESS="${HARNESS_DIR}/${TARGET}"
  if [[ ! -x "${HARNESS}" ]]; then
    echo "[SKIP] ${TARGET}: binary not found at ${HARNESS}"
    continue
  fi

  CORPUS="${CORPUS_DIR}/${CORPUS_MAP[$TARGET]}"
  if [[ ! -d "${CORPUS}" ]]; then
    echo "[SKIP] ${TARGET}: corpus not found at ${CORPUS}"
    continue
  fi

  OUT_DIR="${FINDINGS_DIR}/${TARGET}"
  mkdir -p "${OUT_DIR}"

  echo "[START] ${TARGET} (corpus: ${CORPUS_MAP[$TARGET]}, duration: ${DURATION}s)"
  AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 AFL_CRASH_EXITCODE=42 \
    UBSAN_OPTIONS=halt_on_error=1 \
    afl-fuzz \
      -i "${CORPUS}" \
      -o "${OUT_DIR}" \
      -V "${DURATION}" \
      ${AFL_MEM_FLAG} \
      -- "${HARNESS}" \
    > "${OUT_DIR}/afl.log" 2>&1 &
  PIDS+=($!)
done

echo ""
echo "Started ${#PIDS[@]} harnesses. Waiting up to $((DURATION + 30))s..."
for PID in "${PIDS[@]}"; do
  wait "${PID}" || true
done

echo ""
echo "=== Results ==="
for TARGET in "${!CORPUS_MAP[@]}"; do
  OUT_DIR="${FINDINGS_DIR}/${TARGET}/default"
  if [[ ! -d "${OUT_DIR}" ]]; then
    continue
  fi
  CRASHES=$(ls "${OUT_DIR}/crashes/" 2>/dev/null | grep "^id:" | wc -l || true)
  HANGS=$(ls "${OUT_DIR}/hangs/"    2>/dev/null | grep "^id:" | wc -l || true)
  echo "  ${TARGET}: crashes=${CRASHES}, hangs=${HANGS}"
done
