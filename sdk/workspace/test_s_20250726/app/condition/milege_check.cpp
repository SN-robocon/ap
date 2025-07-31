#include "milege_check.h"
#include <stdio.h>

// MilegeCondition::MilegeCondition(Motor& left, Motor& right, double reached_milege) : left_motor_(left), right_motor_(right), target_milege_(reached_milege), wheel_distance_manager_(right, left) {}
MilegeCondition::MilegeCondition(Tracer* tracer, double reached_milege)
 : ICondition(tracer), target_milege_(reached_milege), wheel_distance_manager_(tracer_) {}

bool MilegeCondition::IsConditionMet() {
  printf("走行距離条件（受取）：%.2f\n", target_milege_);
  // 角度を取得
  printf("走行距離取得処理呼出し\n");
  double milege_ = wheel_distance_manager_.getAverageDistance();
  printf("取得走行距離：%.2f\n", milege_);

  // 角度を判定
  // 引数で受け取った角度条件 <= 角度計算関数から取得した角度
  return target_milege_ <= milege_;
}
