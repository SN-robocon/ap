#include "line_trace_drive.h"
#include <stdio.h>

LineTraceDrive::LineTraceDrive(Tracer* tracer)
 : IDrive(tracer), pid_controller_(tracer_), pid_controller_r(tracer), pid_controller_l(tracer){}

void LineTraceDrive::Drive(ControlMode mode) {
    printf("ライントレース走行開始\n");
    // pid_controller_.SetTracer(tracer_);
	if(mode == ControlMode::LINE_TRACE_R) {
    pid_controller_r.PidControl();  // ライントレースのPID制御する処理を呼ぶ
    }else if(mode == ControlMode::LINE_TRACE_L) {
        pid_controller_l.PidControl();  // ライントレースのPID制御する処理を呼ぶ
    } else {
   		pid_controller_.PidControl();  // ライントレースのPID制御する処理を呼ぶ
    }
    printf("ライントレース走行中\n");
}
