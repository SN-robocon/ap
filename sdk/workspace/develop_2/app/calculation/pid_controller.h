#ifndef PID_CONTROLLER_H_
#define PID_CONTROLLER_H_

// #include "Motor.h"
// #include "ColorSensor.h"
class Tracer;

class PidController {
 public:
  // PidController();            // コンストラクタ
  PidController(Tracer* tracer);            // コンストラクタ
  void PidControl();          // PID制御の実行

 private:
  // spikeapi::Motor left_wheel_;
  // spikeapi::Motor right_wheel_;
  // spikeapi::ColorSensor color_sensor_;
  Tracer* tracer_;

  const int pwm_ = 60;

  int pwm_l_;
  int pwm_r_;
};

#endif  // PID_CONTROLLER_H_
