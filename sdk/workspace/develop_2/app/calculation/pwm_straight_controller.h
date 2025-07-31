#ifndef PWM_STRAIGHT_CONTROLLER_H
#define PWM_STRAIGHT_CONTROLLER_H

#include "i_drive_manager.h"

class Tracer;

class PWMStraightController {
public:
    PWMStraightController(Tracer* tracer);
    void setBasePWM(int pwm);
    void run(ControlMode mode);

private:
    double Kp_ = 0.83;
    int base_pwm_left_ = 50;
    int base_pwm_right_= 50;
    Tracer* tracer_;
};

#endif  // PWM_STRAIGHT_CONTROLLER_H

