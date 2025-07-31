#ifndef I_DRIVE_MANAGER_H_
#define I_DRIVE_MANAGER_H_

class Tracer;

enum class ControlMode {
  STRAIGHT,
  TURN_LEFT,
  TURN_RIGHT,
  LINE_TRACE,
  LINE_TRACE_R,
  LINE_TRACE_L,
  STOP
};

class IDriveManager {
public:
  IDriveManager(Tracer* tracer) : tracer_(tracer) {}
  virtual void DriveSwitch(int scene_num) = 0;
  virtual ~IDriveManager() = default;

protected :
  Tracer* tracer_ = nullptr;
};

#endif  // I_DRIVE_MANAGER_H_