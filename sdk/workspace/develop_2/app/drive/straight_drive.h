#ifndef STRAIGHT_DRIVE_H_
#define STRAIGHT_DRIVE_H_

#include "i_drive.h"
#include "pwm_straight_controller.h"

class StraightDrive : public IDrive {
private:
    PWMStraightController pwm_straight_controller_;  // 固定のPWM計算クラスを直接持つ

public:
    StraightDrive(Tracer* tracer);
    void Drive(ControlMode mode) override;
};
#endif//STRAIGHT_DRIVE_H_
