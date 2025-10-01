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
double base_mileage_0;
double base_mileage_1;
double base_mileage_2;
double base_mileage_3;
double base_mileage_4;
double base_mileage_5;
double base_mileage_6;


DoubleLoopScene::DoubleLoopScene(Tracer* tracer)
 : ISceneManager(tracer),
      drive_(tracer),
      tracer_(tracer),
      base_mileage_0_(50),
      base_mileage_1_(240),
      base_mileage_2_(350),
      base_mileage_3_(180),
      base_mileage_4_(60),
      base_mileage_5_(300),
      base_mileage_6_(200),
      angle_condition_r1_(tracer_,2.0f),
      angle_condition_r2_(tracer_,4.0f),
      angle_condition_r3_(tracer_,22.0f),
      angle_condition_r4_(tracer_,24.5f),
      mileage_condition_0_(tracer_, base_mileage_0_),
      mileage_condition_1_(tracer_, base_mileage_1_),
      mileage_condition_2_(tracer_, base_mileage_2_),
      mileage_condition_3_(tracer_, base_mileage_3_),
      mileage_condition_4_(tracer_, base_mileage_4_),
      mileage_condition_5_(tracer_, base_mileage_5_),
      mileage_condition_6_(tracer_, base_mileage_6_)

{
    reflection_condition_ = 10;
    scene_num_ = 0;

	// 青色判定のしきい値を設定
      color_condition_.hue_min = 200.0;
      color_condition_.hue_max = 240.0;
      color_condition_.saturation_min = 30.0;
      color_condition_.saturation_max = 80.0;
      color_condition_.value_min = 30.0;
      color_condition_.value_max = 70.0;
}


// シナリオを実行する
bool DoubleLoopScene::ScenarioExe() {

    // カラー判定
    ColorCondition color(tracer_,color_condition_);

    // 走行距離判定
    MilegeCondition mileage0(mileage_condition_0_);    
    MilegeCondition mileage1(mileage_condition_1_);
    MilegeCondition mileage2(mileage_condition_2_);
    MilegeCondition mileage3(mileage_condition_3_);
    MilegeCondition mileage4(mileage_condition_4_);
    MilegeCondition mileage5(mileage_condition_5_);
    MilegeCondition mileage6(mileage_condition_6_);

    // 反射光判定
    ReflectLightCondition::ReflectLightConditionData light_target;
    light_target.base_light = reflection_condition_;
    ReflectLightCondition light(light_target,tracer_);

    // 走行管理を呼ぶ
    drive_.DriveSwitch(scene_num_);

    // 判定呼ぶ
    switch (scene_num_) {
	  
    case 0:
      //モーター初期化処理
      printf("NOW:SCENE 0\n");
      SceneEnd();
      break;

    case 1:
      printf("NOW:SCENE 1\n");
      // 角度判定
      if (angle_condition_r1_.IsConditionMet()) {
        SceneEnd();
      }
      break;

    case 2:
      printf("NOW:SCENE 2\n");
     // 走行距離判定
      if (mileage_condition_1_.IsConditionMet() && light.IsConditionMet()) {
        SceneEnd();
      }
      break;

    case 3:
      printf("NOW:SCENE 3\n");

      // カラー判定
      if(color.IsConditionMet()){
        printf("<青色検出>シーン切り替え\n");
        SceneEnd();
      }
      break;

    case 4:
      printf("NOW:SCENE 4\n");
      // 角度判定
      if (angle_condition_r2_.IsConditionMet()) {
        SceneEnd();
      }
      break;

    case 5:
      printf("NOW:SCENE 5\n");
      // 走行距離AND反射光判定
      if (mileage_condition_2_.IsConditionMet() && light.IsConditionMet())  {
        SceneEnd();
      }
      break;

	case 6:
      printf("NOW:SCENE 6\n");

      // カラー判定
      if(color.IsConditionMet()){
        printf("<青色検出>シーン切り替え\n");
        SceneEnd();
      }
      break;

	case 7:
      printf("NOW:SCENE 7\n");

      // 走行距離判定
      if (mileage_condition_3_.IsConditionMet()) {
        SceneEnd();
      }
      break;

	case 8:
      printf("NOW:SCENE 8\n");
      // 角度判定
      if (angle_condition_r3_.IsConditionMet()) {
        SceneEnd();
      }
		break;

	case 9:
      printf("NOW:SCENE 9\n");

      // 走行距離AND反射光判定
      if (mileage_condition_4_.IsConditionMet() && light.IsConditionMet())  {
        SceneEnd();
      }
      break;

	case 10:
      printf("NOW:SCENE 10\n");

      // カラー判定
      if(color.IsConditionMet()){
        printf("<青色検出>シーン切り替え\n");
        SceneEnd();
      }
      break;

	case 11:
      printf("NOW:SCENE 11\n");

      // 走行距離判定
      if (mileage_condition_5_.IsConditionMet()) {
        SceneEnd();
      }
      break;

	case 12:
      printf("NOW:SCENE 12\n");
      // 角度判定
      
      if (angle_condition_r4_.IsConditionMet()) {
        SceneEnd();
      }
      break;

	case 13:
      printf("NOW:SCENE 13\n");

      // 走行距離AND反射光判定
      if (mileage_condition_6_.IsConditionMet() && light.IsConditionMet()) {
        SceneEnd();
      }
      break;
		
    default:
      // 何もしない
      break;
  }
  return (scene_num_ == 14);
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
