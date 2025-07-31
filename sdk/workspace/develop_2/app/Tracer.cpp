#include "Tracer.h"
#include "mg_line_trace_scene.h"
#include "line_obstacle_scene.h"
#include "double_loop_scene.h"
#include "goal_scene.h"
#include <stdio.h>
#include <memory>

Tracer::Tracer():
  left_wheel_(EPort::PORT_B,Motor::EDirection::COUNTERCLOCKWISE,true),
  right_wheel_(EPort::PORT_A,Motor::EDirection::CLOCKWISE,true),  
  color_sensor_(EPort::PORT_E),
  ultrasonic_sensor_(EPort::PORT_F) {
    scenario_num_ = 6;
    counter_= 0;
}

void Tracer::init() {
  printf("Tracer_init\n");
}

void Tracer::terminate() {
  printf("Stopped.\n");
  left_wheel_.stop();
  right_wheel_.stop();
}

void Tracer::run() {
  // シーン管理クラス型のスマートポインタ
  static std::unique_ptr<ISceneManager> scenario_manager;

  printf("走行処理開始_シナリオ番号:%d\n", scenario_num_);
  bool result = false;

  // シナリオ番号を基にシーン管理をインスタンス化
  // すでにインスタンス化している場合は再インスタンス化は不要
  if (!scenario_manager) {
    switch (scenario_num_) {
      case 1:
      case 3: {
        // ライントレース
        printf("ライントレース実行\n");
        if (counter_ < 2) {
          counter_++;
          result = false;
        } else {
          result = true;
        }
        scenario_manager = std::unique_ptr<ISceneManager>(new MgLineTraceScene(this, scenario_num_));   
        break;
      }
      
      case 2: {
        // ラインオブスタクル
        printf("ラインオブスタクル実行\n");
        if (counter_  < 2) {
          counter_++;
          result = false;
        } else {
          result = true;
        }
        scenario_manager = std::unique_ptr<ISceneManager>(new LineObstacleScene(this));   
        break;
      }
      
      case 4: {
        // ダブルループ
        printf("ダブルループ実行\n");
        if (counter_  < 2) {
          counter_++;
          result = false;
        } else {
          result = true;
        }
        scenario_manager = std::unique_ptr<ISceneManager>(new DoubleLoopScene(this));   
        break;
      }
      
      case 5: {
        // スマートキャリー
        printf("スマートキャリー実行\n");
        if (counter_  < 2) {
          counter_++;
          result = false;
        } else {
          // terminate();
          // clock.sleep(duration);
          result = true;
        }
        //scenario_manager = std::unique_ptr<ISceneManager>(new SmartCarryScene(this));   
        break;
      }
      
      case 6: {
        // ゴール
        printf("ゴール実行\n");
        if (counter_  < 2) {
          counter_++;
          result = false;
        } else {
          result = true;
        }
        scenario_manager = std::unique_ptr<ISceneManager>(new GoalScene(this));
        break;
      }
      
      default:
        break;
    }
  }

  // シーン管理処理実行
  if (scenario_manager) {
    result = scenario_manager->ScenarioExe();
  }

  // シーン管理からシナリオ終了を受け取った場合、シナリオ番号をインクリメント
  if (result) {
    printf("シナリオ番号%d終了\n",scenario_num_);
    scenario_num_++;
    scenario_manager.reset();
    counter_ = 0;
  }

  printf("走行処理終了\n\n");
}
