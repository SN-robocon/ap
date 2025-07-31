#include "angle_check.h"
#include <stdio.h>

AngleCondition::AngleCondition(Tracer* tracer,float reached_angle) : ICondition(tracer),target_angle_(reached_angle) {}

bool AngleCondition::IsConditionMet() {
  bool check = false;
  static bool init_state = false;
  printf("角度条件（受取）：%.2f\n", target_angle_);
 
  printf("init_state = %d\n",init_state);
  // 角度を取得
  printf("角度取得処理呼出し\n");
  float angle_ = imu_integrator_.update();
  printf("取得角度：%.2f\n", angle_);
  
  if(init_state == false && target_angle_== 60) {
    imu_integrator_.reset();
    angle_ = 0;
    init_state = true;
  }
  if(init_state == false && target_angle_== 21) {
    imu_integrator_.reset();
    angle_ = 0;
    init_state = true;
  }
    
  if(target_angle_ <= angle_){
    check = true;
    init_state = false;
  }
  // 角度を判定
  // 引数で受け取った角度条件 <= 角度計算関数から取得した角度
  return check;
}
