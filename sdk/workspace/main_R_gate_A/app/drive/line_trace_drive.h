#ifndef LINE_TRACE_DRIVE_H_
#define LINE_TRACE_DRIVE_H_

#include "i_drive.h"
#include "pid_controller.h"
//#include "pid_controller_L.h"
//#include "pid_controller_R.h"

class LineTraceDrive : public IDrive {
private:
    PidController pid_controller_;  // 固定のPID制御クラスを直接持つ
//	PidController_L pid_controller_l;  // 固定のPID制御クラスを直接持つ
//    PidController_R pid_controller_r;  // 固定のPID制御クラスを直接持つ

public:
    LineTraceDrive(Tracer* tracer);
    void Drive(ControlMode mode,int pwm) override;
};

#endif // LINE_TRACE_DRIVE_H_