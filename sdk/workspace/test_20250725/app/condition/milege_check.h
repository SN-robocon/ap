#ifndef MILEGE_CHECK_H_
#define MILEGE_CHECK_H_

#include "i_condition.h"
#include "distance_calculator.h"
#include "Motor.h"

class MilegeCondition : public ICondition {
public:
  // MilegeCondition(Motor& left, Motor& right, double reached_milege);
  MilegeCondition(Tracer* tracer, double reached_milege);
  bool IsConditionMet() override;

private:
  double target_milege_;
  WheelDistanceManager wheel_distance_manager_;
  // Motor& left_motor_;
  // Motor& right_motor_;
};

#endif  // MILEGE_CHECK_H_