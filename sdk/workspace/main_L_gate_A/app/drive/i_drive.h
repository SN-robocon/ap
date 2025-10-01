#ifndef I_DRIVE_H
#define I_DRIVE_H
#include "i_drive_manager.h"

class Tracer;

class IDrive {
public:
    // コンストラクタにTracer*を渡す
    IDrive(Tracer* tracer) : tracer_(tracer) {}
    virtual ~IDrive() = default;
    virtual void Drive(ControlMode mode,int pwm) = 0;
    
protected :
    Tracer* tracer_ = nullptr;
};

#endif  