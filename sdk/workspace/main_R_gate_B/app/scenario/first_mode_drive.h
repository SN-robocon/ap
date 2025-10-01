#ifndef FIRST_MODE_DRIVE_H
#define FIRST_MODE_DRIVE_H

#include "i_drive_manager.h"
#include "straight_drive.h"
#include "turn_drive.h"
#include "line_trace_drive.h"
#include "stop_drive.h"

class FirstModeDrive : public IDriveManager {
  public:
    FirstModeDrive(Tracer* tracer);
    void DriveSwitch(int scene_num) override;

  private:
    Tracer* tracer_;
    StraightDrive straight_drive_;
    TurnDrive turn_drive_;
    LineTraceDrive line_trace_drive_;
    StopDrive stop_drive_;
};

#endif

