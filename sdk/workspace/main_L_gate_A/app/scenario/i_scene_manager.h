#ifndef I_SCENE_MANAGER_H_
#define I_SCENE_MANAGER_H_

#include "color_check.h"

class Tracer;

class ISceneManager {
public:
  ISceneManager(Tracer* tracer) : tracer_(tracer) {}
  virtual bool ScenarioExe() = 0;
  virtual ~ISceneManager() = default;

protected :
  Tracer* tracer_ = nullptr;
  int scene_num_;                 // 現在のシーン番号
  double distance_condition_;     // 距離条件
  float angle_condition_;         // 角度条件
  int reflection_condition_;      // 反射光条件
  float rotation_condition_;      // 回転数条件
  double milege_condition_;      // 走行距離条件
  ColorCondition::LineColorConditionData color_condition_;  // カラー条件
};

#endif  // I_SCENE_MANAGER_H_