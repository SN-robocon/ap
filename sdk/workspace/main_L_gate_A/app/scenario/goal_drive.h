#ifndef GOAL_DRIVE_H_
#define GOAL_DRIVE_H_

#include "i_drive_manager.h"
#include "line_trace_drive.h"
#include "straight_drive.h"
#include "stop_drive.h"

class GoalDrive : public IDriveManager{
    public:
     GoalDrive(Tracer* tracer);
     void DriveSwitch(int scene_num) override;

    private:
     LineTraceDrive line_trace_drive_r_;
     StraightDrive straight_drive_;
     StopDrive stop_drive_;
};

#endif // GOAL_DRIVE_H_
