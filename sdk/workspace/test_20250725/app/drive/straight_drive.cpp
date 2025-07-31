#include "straight_drive.h"
#include <stdio.h>

StraightDrive::StraightDrive(Tracer* tracer)
 : IDrive(tracer), pwm_straight_controller_(tracer_) {}

void StraightDrive::Drive(ControlMode mode) {
    printf("直進走行開始\n");
    pwm_straight_controller_.run(mode);  // 直進のPWM値を計算する処理を呼ぶ
    printf("直進走行中\n");
}