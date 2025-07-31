#ifndef MG_LINE_TRACE_DRIVE_H_
#define MG_LINE_TRACE_DRIVE_H_

#include "i_drive_manager.h"
#include "line_trace_drive.h"

class MgLineTraceDrive : public IDriveManager{
  public:
    MgLineTraceDrive(Tracer* tracer);
    void DriveSwitch(int scene_num) override;

  private:
    LineTraceDrive line_trace_drive_;
};

#endif // MG_LINE_TRACE_DRIVE_H_