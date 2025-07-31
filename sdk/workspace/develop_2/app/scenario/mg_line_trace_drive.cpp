#include "mg_line_trace_drive.h"
#include <stdio.h>

// コンストラクタ
MgLineTraceDrive::MgLineTraceDrive(Tracer* tracer)
 : IDriveManager(tracer), line_trace_drive_(tracer_){
}
// MgLineTraceDrive::MgLineTraceDrive(){}
 
// 走行
void MgLineTraceDrive::DriveSwitch(int scene_num) {

  printf("ライントレース走行管理開始\n");
  line_trace_drive_.Drive(ControlMode::LINE_TRACE);
  printf("ライントレース走行管理終了\n");

}
