#include "line_trace_drive.h"
#include <stdio.h>

LineTraceDrive::LineTraceDrive(Tracer* tracer)
 : IDrive(tracer), pid_controller_(tracer_){}

void LineTraceDrive::Drive(ControlMode mode,int pwm) {
    printf("ライントレース走行開始\n");
	if(mode == ControlMode::LINE_TRACE_R) {
        pid_controller_.PidControl_R(pwm);  // ライントレースのPID制御する処理を呼ぶ
    }else if(mode == ControlMode::LINE_TRACE_L) {
        pid_controller_.PidControl_L(pwm);  // ライントレースのPID制御する処理を呼ぶ
    } else {
   		pid_controller_.PidControl(pwm);  // ライントレースのPID制御する処理を呼ぶ
    }
    printf("ライントレース走行中\n");
}
