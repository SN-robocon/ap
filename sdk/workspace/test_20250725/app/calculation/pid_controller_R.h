#ifndef PID_CONTROLLER_R_H_
#define PID_CONTROLLER_R_H_

class Tracer;

class PidController_R {
 public:
  PidController_R(Tracer* tracer);               // コンストラクタ
  void PidControl();          // PID制御の実行

 private:
  const int pwm_ = 60;
  Tracer* tracer_; 
  int pwm_l_;
  int pwm_r_;
};

#endif  // PID_CONTROLLER_R_H_
