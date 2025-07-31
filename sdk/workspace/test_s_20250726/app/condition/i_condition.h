#ifndef I_CONDITION_H_
#define I_CONDITION_H_

class Tracer;

class ICondition {
public:
  ICondition(Tracer* tracer) : tracer_(tracer) {}
  virtual bool IsConditionMet() = 0;
  virtual ~ICondition() = default;

protected :
  Tracer* tracer_ = nullptr;
};

#endif  // CONDITION_H_
