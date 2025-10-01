#include "pid_controller.h"
#include "Tracer.h"
#include <stdio.h>


PidController::PidController(Tracer* tracer)
 : tracer_(tracer) {
}

//PID制御
void PidController::PidControl(int pwm) {
  const float kp = 0.40;    //比例ゲイン(1より小さい値で検討)
  const float ki = 0.008;   //積分ゲイン
  const float kd = 0.002;    //微分ゲイン
  

  const int target = 20;    //目標値
  const float dt = 0.001;   //測定時間(1ms)

  static int diff_prev = 0; //前回偏差
  static float diff_sum = 0;  //偏差の累計

  float p_value;    //比例項
  float i_value;    //積分項
  float d_value;    //微分項
  float pid_value;  //調整値

  int diff = target - tracer_->getColorSensor().getReflection();  //今回偏差

  printf("反射光:%d\n",target - diff);
  printf("今回偏差:%d\n",diff);
  printf("前回偏差:%d\n",diff_prev);
  printf("測定時間:%f\n\n",dt);

  
  //比例項計算
  p_value = kp * diff;
  printf("比例項:%f\n",p_value);

  //積分項計算
  diff_sum += diff * dt;  // 偏差の累計更新
  i_value = ki * diff_sum ;
  printf("積分項:%f\n",i_value);

  //微分項計算 
  d_value = kd * (diff - diff_prev) / dt;

  printf("微分項:%f\n",d_value);

  //調整値の計算
  pid_value = p_value + i_value + d_value;


  printf("調整値:%f\n",pid_value);

  diff_prev = diff;//偏差更新

  //調整値をもとにモーターの出力を修正
  pwm_l_ = pwm + pid_value;         
  pwm_r_ = pwm - pid_value;
  
  //モーターの制限
  if(pwm_l_ >100){
    pwm_l_ = 100;
  }else if(pwm_l_ < -100){
    pwm_l_ = -100;

  }

  if(pwm_r_ >100){
    pwm_r_ = 100;
  }else if(pwm_r_ < -100){
    pwm_r_ = -100;
  }

  printf("左モーター：%d\n右モーター：%d\n\n",pwm_l_,pwm_r_);

  tracer_->getLeftWheel().setPower(pwm_l_);
  tracer_->getRightWheel().setPower(pwm_r_ );
}

//左用
void PidController::PidControl_L(int pwm) {
  //const float kp = 0.27;    //比例ゲイン(1より小さい値で検討)
  const float ki = 0.008;   //積分ゲイン
 // const float kd = 0.002;     //微分ゲイン

  //const float kp = 0.35;    //比例ゲイン(1より小さい値で検討)
  const float kp = 0.36;
  const float kd = 0.002;     //微分ゲイン
  

  const int target = 20;    //目標値
  const float dt = 0.001;   //測定時間(1ms)

  static int diff_prev = 0; //前回偏差
  static float diff_sum = 0;  //偏差の累計

  float p_value;    //比例項
  float i_value;    //積分項
  float d_value;    //微分項
  float pid_value;  //調整値

  int diff = target - tracer_->getColorSensor().getReflection();  //今回偏差

  printf("反射光:%d\n",target - diff);
  printf("今回偏差:%d\n",diff);

  
  //比例項計算
  p_value = kp * diff;
  printf("比例項:%f\n",p_value);

  //積分項計算
  diff_sum += diff * dt;  // 偏差の累計更新
  i_value = ki * diff_sum ;
  printf("積分項:%f\n",i_value);

  //微分項計算 
  d_value = kd * (diff - diff_prev) / dt;
  printf("kd=%f diff-diff_prev=%f dt=%f\n",kd,diff - diff_prev,dt);
  
  printf("微分項:%f\n",d_value);

  //調整値の計算
  pid_value = p_value + i_value + d_value;


  printf("調整値:%f\n",pid_value);

  diff_prev = diff;//偏差更新

  //調整値をもとにモーターの出力を修正
  pwm_l_ = pwm + pid_value;         
  pwm_r_ = pwm - pid_value;
  
  
  //モーターの制限
  if(pwm_l_ >100){
    pwm_l_ = 80;
  }else if(pwm_l_ < -100){
    pwm_l_ = -80;

  }

  if(pwm_r_ >100){
    pwm_r_ = 80;
  }else if(pwm_r_ < -100){
    pwm_r_ = -80;
  }

  printf("左モーター：%d\n右モーター：%d\n\n",pwm_l_,pwm_r_);

  tracer_->getLeftWheel().setPower(pwm_l_);
  tracer_->getRightWheel().setPower(pwm_r_ );
}

//右用
void PidController::PidControl_R(int pwm) {
  const float kp = 0.36;    //比例ゲイン(1より小さい値で検討)
  const float ki = 0.008;   //積分ゲイン

  // const float kp = 0.35;    //比例ゲイン(1より小さい値で検討)
  // const float kd = 0.003;     //微分ゲイン
  const float kd = 0.002;     //微分ゲイン


  const int target = 20;    //目標値
  const float dt = 0.001;   //測定時間(1ms)

  static int diff_prev = 0; //前回偏差
  static float diff_sum = 0;  //偏差の累計

  float p_value;    //比例項
  float i_value;    //積分項
  float d_value;    //微分項
  float pid_value;  //調整値

  int diff = target - tracer_->getColorSensor().getReflection();  //今回偏差

  printf("反射光:%d\n",target - diff);
  printf("今回偏差:%d\n",diff);

  
  //比例項計算
  p_value = kp * diff;
  printf("比例項:%f\n",p_value);

  //積分項計算
  diff_sum += diff * dt;  // 偏差の累計更新
  i_value = ki * diff_sum ;
  printf("積分項:%f\n",i_value);

  //微分項計算 
  d_value = kd * (diff - diff_prev) / dt;
  printf("微分項:%f\n",d_value);

  //調整値の計算
  pid_value = p_value + i_value + d_value;


  printf("調整値:%f\n",pid_value);

  diff_prev = diff;//偏差更新

  //調整値をもとにモーターの出力を修正
  pwm_l_ = pwm - pid_value;         
  pwm_r_ = pwm + pid_value;
  
  //モーターの制限
  if(pwm_l_ >100){
    pwm_l_ = 80;
  }else if(pwm_l_ < -100){
    pwm_l_ = -80;

  }

  if(pwm_r_ >100){
    pwm_r_ = 80;
  }else if(pwm_r_ < -100){
    pwm_r_ = -80;
  }

  printf("左モーター：%d\n右モーター：%d\n\n",pwm_l_,pwm_r_);

  tracer_->getLeftWheel().setPower(pwm_l_);
  tracer_->getRightWheel().setPower(pwm_r_ );
}
