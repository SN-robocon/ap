#include "pwm_straight_controller.h"
#include "Tracer.h"
#include <cmath>
#include <cstdio>

PWMStraightController::PWMStraightController(Tracer* tracer)
    : tracer_(tracer){}

// 基本PWM設定
void PWMStraightController::setBasePWM(int pwm) {
    base_pwm_left_ = pwm;
    base_pwm_right_ = pwm;
}

void PWMStraightController::run(ControlMode mode,int pwm) {
    int left_count = tracer_->getLeftWheel().getCount();
    int right_count = tracer_->getRightWheel().getCount();
    double pwm_left = 0.0;
    double pwm_right = 0.0;

    base_pwm_left_ = pwm;
    base_pwm_right_= pwm;
    switch (mode) {
        case ControlMode::STRAIGHT: {
            double diff = static_cast<double>(left_count - right_count);
            double correction = Kp_ * diff;

            pwm_left = static_cast<double>(base_pwm_left_) - correction - 2;
            pwm_right = static_cast<double>(base_pwm_right_) + correction;

            printf("[STRAIGHT] L:%d R:%d Diff=%.2f Corr=%.2f => PWM_L=%.2f, PWM_R=%.2f\n",
                   left_count, right_count, diff, correction, pwm_left, pwm_right);
            break;
        }
        case ControlMode::TURN_LEFT:
            pwm_left = -base_pwm_left_;
            pwm_right = base_pwm_right_;
            printf("[TURN_LEFT] => PWM_L=%.2f, PWM_R=%.2f\n", pwm_left, pwm_right);
            break;

        case ControlMode::TURN_RIGHT:
            pwm_left = base_pwm_left_;
            pwm_right = -base_pwm_right_;
            printf("[TURN_RIGHT] => PWM_L=%.2f, PWM_R=%.2f\n", pwm_left, pwm_right);
            break;

        case ControlMode::TURN_LEFT_2:
            pwm_left = 0;
            pwm_right = base_pwm_right_;
            printf("[TURN_LEFT_2] => PWM_L=%.2f, PWM_R=%.2f\n", pwm_left, pwm_right);
            break;

        case ControlMode::TURN_RIGHT_2:
            pwm_left = base_pwm_left_;
            pwm_right = 0;
            printf("[TURN_RIGHT_2] => PWM_L=%.2f, PWM_R=%.2f\n", pwm_left, pwm_right);
            break;
    }

    tracer_->getLeftWheel().setPower(static_cast<int>(pwm_left));
    tracer_->getRightWheel().setPower(static_cast<int>(pwm_right));
}
