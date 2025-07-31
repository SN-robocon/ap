#ifndef STOP_DRIVE_H_
#define STOP_DRIVE_H_

#include "i_drive.h"

class StopDrive : public IDrive {

public:
    StopDrive(Tracer* tracer);
    void Drive(ControlMode mode) override;
};

#endif // STOP_DRIVE_H_