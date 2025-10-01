#include "first_mode_scene.h"
#include "milege_check.h"
#include "reflect_light_check.h"
#include "color_check.h"
#include "angle_check.h"
#include "Tracer.h"
#include <stdio.h>

// コンストラクタ
FirstModeScene::FirstModeScene(Tracer* tracer)
  : ISceneManager(tracer),drive_(tracer_),tracer_(tracer),angle_condition_1_(tracer,1.0f),angle_condition_2_(tracer,16.0f){//22 18
    
  scene_num_ = 0;
  milege_condition_1_ = 1600;
  milege_condition_2_ = 400;
  reflection_condition_ = 10;
  
  // 青色判定のしきい値を設定
  color_condition_.hue_min = 200.0;
  color_condition_.hue_max = 240.0;
  color_condition_.saturation_min = 30.0;
  color_condition_.saturation_max = 80.0;
  color_condition_.value_min = 30.0;
  color_condition_.value_max = 70.0;
}


//シナリオを実行する
bool FirstModeScene::ScenarioExe(){

  printf("シーン管理処理開始_シーン番号：%d\n", scene_num_);
  
  static int cnt=0;
  
  //走行距離判定
  MilegeCondition mileage1(tracer_, milege_condition_1_);
  MilegeCondition mileage2(tracer_, milege_condition_2_);

  //カラー判定
  ColorCondition color(tracer_, color_condition_);

  //反射光判定
  ReflectLightCondition::ReflectLightConditionData condition_data;
  condition_data.base_light = reflection_condition_;
  ReflectLightCondition reflect_light_condition(condition_data,tracer_);
  
  drive_.DriveSwitch(scene_num_);

  //判定を呼ぶ
  switch(scene_num_){
    case 0:
      //モーター初期化処理
      SceneEnd();
      break;

    case 1:
      // 距離判定
      if (mileage1.IsConditionMet()) {
        SceneEnd();
      }
      break;

    case 2:
      // 角度判定
      if (angle_condition_1_.IsConditionMet()) {
        SceneEnd();
      }
      break;

    case 3:
      // 距離判定
      if (mileage2.IsConditionMet()) {
        SceneEnd();
      }
      break;

    case 4:
      // 角度判定
      if (angle_condition_2_.IsConditionMet()) {
        SceneEnd();
      }
      break;

    case 5:
      // 反射光判定
      if (reflect_light_condition.IsConditionMet()) {
        SceneEnd();
      }
      break;
      
    case 6:
      // カラー判定
      if(color.IsConditionMet()){
        SceneEnd();
      }
      break;
      
    case 7:
      cnt++;
      if(cnt==20){
        cnt=0;
        // 停止処理
        SceneEnd();
      }
      break;
          
    default:
      // 何もしない
      break;
  }

  return (scene_num_ == 8);
}

// シーンの終了を判断する
void FirstModeScene::SceneEnd(){
  SceneSwitch();
}

// シーンを切り替える
void FirstModeScene::SceneSwitch(){
  tracer_->getLeftWheel().resetCount();
  tracer_->getRightWheel().resetCount();
  scene_num_++;
}


