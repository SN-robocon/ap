#include "mg_line_trace_scene.h"
#include "milege_check.h"
#include <stdio.h>

// コンストラクタ
MgLineTraceScene::MgLineTraceScene(Tracer* tracer, int scenario_num)
 : ISceneManager(tracer), scenario_num_(scenario_num), drive_(tracer_) {
  milege_condition_ = 1900;

  // 青色判定のしきい値を設定
  color_condition_.hue_min = 200.0;
  color_condition_.hue_max = 220.0;
  color_condition_.saturation_min = 70.0;
  color_condition_.saturation_max = 90.0;
  color_condition_.value_min = 45.0;
  color_condition_.value_max = 65.0;
}

// シナリオを実行する
bool MgLineTraceScene::ScenarioExe(){

  bool result = false;
  printf("ライントレースシーン管理開始\n");

  // 判定処理の初期化
  MilegeCondition milege(tracer_, milege_condition_);
  ColorCondition color(tracer_, color_condition_);

  // 走行管理を呼ぶ
  drive_.DriveSwitch(scene_num_);

  // シナリオ番号で分岐し判定処理を呼ぶ
  switch(scenario_num_) {
    case 1:
      // 距離判定
      printf("距離判定呼び出し");
      result = milege.IsConditionMet();
      break;
    
    case 3:
      // カラー判定
      printf("カラー判定呼び出し\n");
      result = color.IsConditionMet();
      break;
    
    default:
      break;
  }

  printf("ライントレースシーン管理終了\n");     
  return result;  
}


