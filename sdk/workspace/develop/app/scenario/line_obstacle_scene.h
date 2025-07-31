#ifndef LINE_OBSTACLE_SCENE_H_
#define LINE_OBSTACLE_SCENE_H_

#include "i_scene_manager.h"
#include "line_obstacle_drive.h"
#include "angle_check.h"

class LineObstacleScene : public ISceneManager {
 public:
  LineObstacleScene(Tracer* tracer);

  bool ScenarioExe() override;  // シナリオを実行する

 private:
  void SceneSwitch();              // シーンを切り替える
  void SceneEnd();   // シーン終了を判断する
  LineObstacleDrive drive_;
  Tracer* tracer_;
  AngleCondition angle_condition_;
  AngleCondition double_angle_condition_;
};

#endif  // LINE_OBSTACLE_SCENE_H_