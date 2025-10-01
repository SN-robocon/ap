#include "goal_drive.h"
#include <stdio.h>

// コンストラクタ
GoalDrive::GoalDrive(Tracer* tracer)
 : IDriveManager(tracer),line_trace_drive_r_(tracer), straight_drive_(tracer_), stop_drive_(tracer_){
}

// シーンごとの走行切り替え
void GoalDrive::DriveSwitch(int scene_num){
  printf("走行管理処理開始_シーン番号：%d\n", scene_num);
  switch(scene_num){
    case 1:
      printf("ライントレース走行呼び出し\n");
      line_trace_drive_r_.Drive(ControlMode::LINE_TRACE_R,70);
      break;

    case 2:
      printf("直進走行呼出し\n");
      straight_drive_.Drive(ControlMode::STRAIGHT,70);
      break;

    case 3:
      printf("停止呼出し\n");
      stop_drive_.Drive(ControlMode::STOP,0);
      break;

    default:
      // 何も動作しない
      break;
  }

  printf("走行管理処理終了\n");
}
