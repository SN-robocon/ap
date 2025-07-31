#pragma once

#include "i_drive.h"
#include "pwm_straight_controller.h"

class TurnDrive : public IDrive {
private:
  PWMStraightController pwm_straight_controller_;  // 固定のPWM計算クラスを直接持つ

public:
  TurnDrive(Tracer* tracer);
  void Drive(ControlMode mode) override;
};

