#include "i_drive_manager.h"
#include "first_mode_drive.h"
#include <stdio.h>

FirstModeDrive::FirstModeDrive(Tracer* tracer)
  :IDriveManager(tracer),straight_drive_(tracer),turn_drive_(tracer),line_trace_drive_(tracer),stop_drive_(tracer){
  }

//シーンごとの走行切り替え
void FirstModeDrive::DriveSwitch(int scene_num){
  switch(scene_num){
    case 1:
      straight_drive_.Drive(ControlMode::STRAIGHT,100);
      break;

    case 2:
      turn_drive_.Drive(ControlMode::TURN_LEFT,60);
      break;
    
    case 3:
      straight_drive_.Drive(ControlMode::STRAIGHT,100);
      break;

    case 4:
      turn_drive_.Drive(ControlMode::TURN_RIGHT,60);
      break;

    case 5:
      straight_drive_.Drive(ControlMode::STRAIGHT,80);
      break;

    case 6:
      line_trace_drive_.Drive(ControlMode::LINE_TRACE,70);
      break;
      
    case 7:
      straight_drive_.Drive(ControlMode::STRAIGHT,0);
      break;
    
    default:
      break;
  }
}
