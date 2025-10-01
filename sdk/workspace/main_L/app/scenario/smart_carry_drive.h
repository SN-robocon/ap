#ifndef SMARTCARRYDRIVE_H_
#define SMARTCARRYDRIVE_H_

#include "i_drive_manager.h"
#include "line_trace_drive.h"
#include "straight_drive.h"
#include "turn_drive.h"
#include "stop_drive.h"

class SmartCarryDrive : public IDriveManager {
	public:
		SmartCarryDrive(Tracer* tracer);
		void DriveSwitch(int scene_num) override;

	private:
		Tracer* tracer_;
		TurnDrive turn_drive_;
		StraightDrive straight_drive_;
		LineTraceDrive line_trace_drive_r_;
		LineTraceDrive line_trace_drive_l_;
		StopDrive stop_drive_;
};

#endif  // SMARTCARRYDRIVE_H_
