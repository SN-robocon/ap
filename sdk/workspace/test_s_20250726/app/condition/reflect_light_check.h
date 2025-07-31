#ifndef REFLECT_LIGHT_CHECK_H_
#define REFLECT_LIGHT_CHECK_H_

#include "i_condition.h"

class Tracer;

class ReflectLightCondition : public ICondition {
public:
  struct ReflectLightConditionData {
    int base_light;  // 反射光の条件値
  };
    
  ReflectLightCondition(ReflectLightConditionData target,Tracer* tracer);
    // 条件を満たすかどうかを判定する
  bool IsConditionMet() override;

private:
  ReflectLightConditionData target_;  // 反射光の条件値
  Tracer* tracer_; 

};

#endif  // REFLECT_LIGHT_CHECK_H_
