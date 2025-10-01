#ifndef PID_CONTROLLER_H_
#define PID_CONTROLLER_H_


class Tracer;

class PidController {
 public:
  PidController(Tracer* tracer);            // コンストラクタ
  void PidControl(int pwm);          // PID制御の実行
  void PidControl_L(int pwm);          // PID制御の実行
  void PidControl_R(int pwm);          // PID制御の実行

 private:

  Tracer* tracer_;

 // const int pwm_ = 70;

  int pwm_l_;
  int pwm_r_;
};

#endif  // PID_CONTROLLER_H_
