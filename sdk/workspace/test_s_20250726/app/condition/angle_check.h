#ifndef ANGLE_CHECK_H_
#define ANGLE_CHECK_H_

#include "i_condition.h"
#include "imu_integrator.h"

class AngleCondition : public ICondition {
public:
  AngleCondition(Tracer* tracer,float reached_angle);
  bool IsConditionMet() override;

private:
  float target_angle_;
  IMUIntegrator imu_integrator_;

};

#endif  // ANGLE_CHECK_H_
