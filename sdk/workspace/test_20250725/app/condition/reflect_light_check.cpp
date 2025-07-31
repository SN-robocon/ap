#include "reflect_light_check.h"
#include "Tracer.h"
#include <stdio.h>
  
ReflectLightCondition::ReflectLightCondition(ReflectLightConditionData target,Tracer* tracer)
 : ICondition(tracer), target_(target),tracer_(tracer){}

bool ReflectLightCondition::IsConditionMet(){
  int reflect_light = 0;
  printf("ベース値: %d\n",target_.base_light);
  // 反射光を取得
  reflect_light = tracer_->getColorSensor().getReflection();

  printf("取得した反射光: %d\n", reflect_light);
  // 反射光を判定
  // 引数で受け取った反射光条件 >= カラーセンサーから取得した反射光
  return target_.base_light >= reflect_light;
}
