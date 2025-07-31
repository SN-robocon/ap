#ifndef DOUBLE_LOOP_DRIVE_H_
#define DOUBLE_LOOP_DRIVE_H_

#include "i_drive_manager.h"
#include "line_trace_drive.h"
#include "straight_drive.h"
#include "turn_drive.h"

class DoubleLoopDrive : public IDriveManager {
	public:
		DoubleLoopDrive(Tracer* tracer);
		void DriveSwitch(int scene_num) override;

	private:
		Tracer* tracer_;
		TurnDrive turn_drive_;
		StraightDrive straight_drive_;
		LineTraceDrive line_trace_drive_r_;
		LineTraceDrive line_trace_drive_l_;
};

#endif  // DOUBLE_LOOP_DRIVE_H_
