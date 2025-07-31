#include <cstdio>
#include "double_loop_scene.h"
#include "color_check.h"
#include "angle_check.h"
#include "reflect_light_check.h"
#include "milege_check.h"
#include "Tracer.h"

ReflectLightCondition::ReflectLightConditionData light_target;
ColorCondition::LineColorConditionData color_condition;
float reached_angle;
double base_mileage;


DoubleLoopScene::DoubleLoopScene(Tracer* tracer)
 : ISceneManager(tracer), // ← ここが重要
      drive_(tracer),
      tracer_(tracer),
      base_mileage_(240),
      angle_condition_(tracer_,5.0f),
      double_angle_condition_(tracer_,21.0f),
      mileage_condition_(tracer_, base_mileage_)

{
    reflection_condition_ = 10;
    scene_num_ = 1;

	// 青色判定のしきい値を設定
      color_condition_.hue_min = 200.0;
      color_condition_.hue_max = 240.0;
      color_condition_.saturation_min = 50.0;
      color_condition_.saturation_max = 90.0;
      color_condition_.value_min = 25.0;
      color_condition_.value_max = 65.0;
}


// シナリオを実行する
bool DoubleLoopScene::ScenarioExe() {

	// カラー判定
	ColorCondition color(tracer_,color_condition_);

	// 走行距離判定
	MilegeCondition mileage(mileage_condition_);

	// 反射光判定
	ReflectLightCondition::ReflectLightConditionData light_target;
	light_target.base_light = reflection_condition_;
	ReflectLightCondition light(light_target,tracer_);


	// 走行管理を呼ぶ
	drive_.DriveSwitch(scene_num_);

	// 判定呼ぶ
	switch (scene_num_) {

	case 1:
      printf("NOW:SCENE 2\n");
      // 角度判定
      if (angle_condition_.IsConditionMet()) {
        SceneEnd();
      }
		break;

    case 2:
      printf("NOW:SCENE 3\n");
     // 走行距離判定
      if (mileage_condition_.IsConditionMet() && light.IsConditionMet()) {
        SceneEnd();
      }
      break;

    case 3:
      printf("NOW:SCENE 4\n");

      // カラー判定
      if(color.IsConditionMet()){
        printf("<青色検出>シーン切り替え\n");
        SceneEnd();
      }
      break;

    case 4:
      printf("NOW:SCENE 5\n");
      // 走行距離AND反射光判定
      if (mileage_condition_.IsConditionMet() && light.IsConditionMet())  {
        SceneEnd();
      }
      break;

	case 5:
      printf("NOW:SCENE 6\n");

      // カラー判定
      if(color.IsConditionMet()){
        printf("<青色検出>シーン切り替え\n");
        SceneEnd();
      }
      break;

	case 6:
      printf("NOW:SCENE 7\n");

      // 走行距離判定
      if (mileage_condition_.IsConditionMet()) {
        SceneEnd();
      }
      break;

	case 7:
      printf("NOW:SCENE 8\n");
      // 角度判定
      if (angle_condition_.IsConditionMet()) {
        SceneEnd();
      }
		break;

	case 8:
      printf("NOW:SCENE 9\n");

      // 走行距離AND反射光判定
      if (light.IsConditionMet()) {
        SceneEnd();
      }
      break;

	case 9:
      printf("NOW:SCENE 10\n");

      // カラー判定
      if(color.IsConditionMet()){
        printf("<青色検出>シーン切り替え\n");
        SceneEnd();
      }
      break;

	case 10:
      printf("NOW:SCENE 11\n");

      // 走行距離判定
      if (mileage_condition_.IsConditionMet()) {
        SceneEnd();
      }
      break;

	case 11:
      printf("NOW:SCENE 12\n");
      // 角度判定
      
      if (double_angle_condition_.IsConditionMet()) {
        SceneEnd();
      }
      break;

	case 12:
      printf("NOW:SCENE 13\n");

      // 走行距離AND反射光判定
      if (mileage_condition_.IsConditionMet() && light.IsConditionMet()) {
        SceneEnd();
      }
      break;
		
    default:
      // 何もしない
      break;
  }
  return (scene_num_ == 13);
}

// シーン終了を判断する
void DoubleLoopScene::SceneEnd() {
	SceneSwitch();
}

// シーンを切り替える
void DoubleLoopScene::SceneSwitch() {
  tracer_->getLeftWheel().resetCount();
  tracer_->getRightWheel().resetCount();
  scene_num_++;
}
