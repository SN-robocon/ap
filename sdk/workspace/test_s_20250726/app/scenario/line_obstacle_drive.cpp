#include "i_drive_manager.h"
#include "line_obstacle_drive.h"

// コンストラクタ
LineObstacleDrive::LineObstacleDrive(Tracer* tracer)
    :IDriveManager(tracer), turn_drive_(tracer), straight_drive_(tracer) {
}

// シーンごとの走行切り替え
void LineObstacleDrive::DriveSwitch(int scene_num) {

  switch (scene_num) {
    case 1:  // FIRST_ROTATE
      turn_drive_.Drive(ControlMode::TURN_RIGHT);
      break;
    case 3:  // SECOND_ROTATE
      turn_drive_.Drive(ControlMode::TURN_LEFT);
      break;

    case 2:  // STRAIGHT_MOVE
    case 4:  // BLACKLINE_SEARCH
      straight_drive_.Drive(ControlMode::STRAIGHT);
      break;

    default:
      // 何もしない
      break;
  }
}
