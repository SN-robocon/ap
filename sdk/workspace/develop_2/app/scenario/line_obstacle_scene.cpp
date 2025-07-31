#include "line_obstacle_scene.h"
#include "angle_check.h"
#include "reflect_light_check.h"
#include "milege_check.h"
#include "Tracer.h"
#include <cstdio>


// コンストラクタ
LineObstacleScene::LineObstacleScene(Tracer* tracer):
ISceneManager(tracer), tracer_(tracer),drive_(tracer),angle_condition_(tracer,45.0f),double_angle_condition_(tracer,60.0f){
  scene_num_ = 1;
  distance_condition_ = 200;
  reflection_condition_ = 12;
}

// シナリオを実行する
bool LineObstacleScene::ScenarioExe() {

  // 走行距離判定
  MilegeCondition mileage(tracer_, distance_condition_);

  // 反射光判定
  ReflectLightCondition::ReflectLightConditionData condition_data;
  condition_data.base_light = reflection_condition_;
  ReflectLightCondition reflect_light_condition(condition_data,tracer_);

  // 走行管理を呼ぶ
  drive_.DriveSwitch(scene_num_);

  // 判定呼ぶ
  switch (scene_num_) {
    case 1:
      printf("NOW:SCENE 1\n");
      // 角度判定
      if (angle_condition_.IsConditionMet()) {
        SceneEnd();
      }
      break;

    case 2:
      printf("NOW:SCENE 2\n");

      // 距離判定
      if (mileage.IsConditionMet()) {
        SceneEnd();
      }
      break;

    case 3:
      printf("NOW:SCENE 3\n");

      // 角度判定（2倍）
      if (double_angle_condition_.IsConditionMet()) {
        SceneEnd();
      }
      break;

    case 4:
      printf("NOW:SCENE 4\n");

      // 反射光判定
      if (reflect_light_condition.IsConditionMet()) {
        SceneEnd();
      }
      break;

    default:
      printf("NOW:SCENE 5\n");
      // 何もしない
      break;
  }
  return (scene_num_ == 5);
}

// シーン終了を判断する
void LineObstacleScene::SceneEnd() {
  SceneSwitch();
}

// シーンを切り替える
void LineObstacleScene::SceneSwitch() {
  tracer_->getLeftWheel().resetCount();
  tracer_->getRightWheel().resetCount();
  scene_num_++;
}
