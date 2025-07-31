#include "goal_scene.h"
#include "milege_check.h"
#include "Tracer.h"
#include <stdio.h>

// コンストラクタ
GoalScene::GoalScene(Tracer* tracer) : ISceneManager(tracer), drive_(tracer_)
{
  scene_num_ = 1;
  milege_condition_ = 100;
  
  // 青色判定のしきい値を設定
  color_condition_.hue_min = 200.0;
  color_condition_.hue_max = 220.0;
  color_condition_.saturation_min = 70.0;
  color_condition_.saturation_max = 90.0;
  color_condition_.value_min = 45.0;
  color_condition_.value_max = 65.0;
}

// シナリオを実行する
bool GoalScene::ScenarioExe(){

  printf("シーン管理処理開始_シーン番号：%d\n", scene_num_);
    
  // 走行距離判定
  MilegeCondition mileage(tracer_, milege_condition_);

  // メンバ変数color_condition_を初期化
  ColorCondition color(tracer_, color_condition_);

  // 走行管理を呼ぶ
  drive_.DriveSwitch(scene_num_);

  // 判定を呼ぶ
  switch(scene_num_){
    case 1:
      // カラー判定
      if(color.IsConditionMet()){
        printf("<青色検出>シーン切り替え\n");
        SceneEnd();
      }
      break;

    case 2:
      // 走行距離判定
      if(mileage.IsConditionMet()){
        printf("<距離条件達成>シーンの切り替え\n");
        SceneEnd();
      }
      break;

    case 3:
        SceneEnd();
      break;
    
    default:
      break;
  }

  return (scene_num_ == 4);
}

// シーンの終了を判断する
void GoalScene::SceneEnd(){
  SceneSwitch();
}

// シーンを切り替える
void GoalScene::SceneSwitch(){
  tracer_->getLeftWheel().resetCount();
  tracer_->getRightWheel().resetCount();
  scene_num_++;
}

