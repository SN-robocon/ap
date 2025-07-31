#ifndef GOAL_SCENE_H_
#define GOAL_SCENE_H_

#include "i_scene_manager.h"
#include "goal_drive.h"

class GoalScene : public ISceneManager{
  public:
    GoalScene(Tracer* tracer);

    bool ScenarioExe() override; // シナリオを実行する

  private:
    void SceneSwitch();              // シーンを切り替える
    void SceneEnd();   // シーン終了を判断する
    GoalDrive drive_;    
};

#endif // GOAL_SCENE_H_
