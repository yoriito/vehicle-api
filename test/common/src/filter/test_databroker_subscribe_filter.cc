// SPDX-License-Identifier: Apache-2.0
//
// Copyright 2026 JASPAR
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gtest/gtest.h>

#include <memory>
#include <utility>
#include <vector>

#include "databroker/filter/subscribe_filter.h"
#include "result.h"

namespace dbf = yoriito::databroker::filter;
using OperatorType = dbf::OperatorType;
using LogicalOperatorType = dbf::LogicalOperatorType;
using RangeConditionWithOp = dbf::RangeConditionWithOp;
using RangeFilter = dbf::RangeFilter;
using ChangeFilter = dbf::ChangeFilter;
using TimeBasedFilter = dbf::TimeBasedFilter;
using SubscribeFilter = dbf::SubscribeFilter;
TEST(TestSubscribeFilter, Normal) {
  yoriito::databroker::filter::SubscribeFilter request(
      yoriito::databroker::filter::PathsFilter(
          {"/api/data", "/api/settings", "/api/config"}));
}

TEST(TestSubscribeFilter_Misc_Range, Normal) {
  yoriito::databroker::filter::SubscribeFilter request(
      yoriito::databroker::filter::PathsFilter(
          {"/api/data", "/api/settings", "/api/config"}),
      RangeFilter(OperatorType::OPERATOR_GT, 100));
}

TEST(TestSubscribeFilter_Misc_Range_Array, Normal) {
  std::vector<RangeConditionWithOp> temp_conditions = {
      RangeConditionWithOp(OperatorType::OPERATOR_LT, 0, std::nullopt),
      RangeConditionWithOp(OperatorType::OPERATOR_GT, 40,
                           LogicalOperatorType::LOGICAL_OPERATOR_OR)};

  RangeFilter temp_filter(temp_conditions);
  SubscribeFilter subscribe_filter(std::nullopt, std::move(temp_filter));
  ASSERT_EQ(std::get<RangeFilter>(subscribe_filter.GetMiscFilter())
                .GetConditionArray()
                ->Size(),
            2);
  ASSERT_EQ(std::get<RangeFilter>(subscribe_filter.GetMiscFilter())
                .GetConditionArray()
                ->GetConditions()[0]
                .GetBoundary(),
            0.0);
  ASSERT_EQ(std::get<RangeFilter>(subscribe_filter.GetMiscFilter())
                .GetConditionArray()
                ->GetConditions()[1]
                .GetBoundaryOperator(),
            OperatorType::OPERATOR_GT);
}

TEST(TestSubscribeFilter_Misc_Change, Normal) {
  yoriito::databroker::filter::SubscribeFilter request(
      yoriito::databroker::filter::PathsFilter(
          {"/api/data", "/api/settings", "/api/config"}),
      ChangeFilter(OperatorType::OPERATOR_EQ, 100));

  ASSERT_EQ(std::get<ChangeFilter>(request.GetMiscFilter()).GetDiff(), 100);
  ASSERT_EQ(std::get<ChangeFilter>(request.GetMiscFilter()).GetLogicOperator(),
            OperatorType::OPERATOR_EQ);
}

TEST(TestSubscribeFilter_Misc_TimedBase, Normal) {
  yoriito::databroker::filter::SubscribeFilter request(
      yoriito::databroker::filter::PathsFilter(
          {"/api/data", "/api/settings", "/api/config"}),
      TimeBasedFilter(100));

  ASSERT_EQ(std::get<TimeBasedFilter>(request.GetMiscFilter()).GetPeriod(),
            100);
}
