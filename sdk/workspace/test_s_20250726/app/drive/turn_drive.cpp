#include "turn_drive.h"

TurnDrive::TurnDrive(Tracer* tracer)
 : IDrive(tracer), pwm_straight_controller_(tracer_) {
}

void TurnDrive::Drive(ControlMode mode) {
  pwm_straight_controller_.run(mode);  // 旋回のPWM値を計算する処理を呼ぶ
}
