#ifndef PID_CONTROLLER_L_H_
#define PID_CONTROLLER_L_H_

class Tracer;

class PidController_L {
 public:
  PidController_L(Tracer* tracer);               // コンストラクタ
  void PidControl();          // PID制御の実行

 private:
  const int pwm_ = 50;
  Tracer* tracer_; 
  int pwm_l_;
  int pwm_r_;
};

#endif  // PID_CONTROLLER_L_H_
