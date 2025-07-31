#ifndef LINE_OBSTACLE_DRIVE_H_
#define LINE_OBSTACLE_DRIVE_H_

#include "i_drive_manager.h"
#include "straight_drive.h"
#include "turn_drive.h"

class LineObstacleDrive : public IDriveManager {
 public:
  LineObstacleDrive(Tracer* tracer);
  void DriveSwitch(int scene_num) override;

 private:
  Tracer* tracer_;
  TurnDrive turn_drive_;
  StraightDrive straight_drive_;
};

#endif  // LINE_OBSTACLE_DRIVE_H_