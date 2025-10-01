#ifndef FIRST_MODE_SCENE_H
#define FIRST_MODE_SCENE_H

#include "i_scene_manager.h"
#include "first_mode_drive.h"
#include "angle_check.h"

class FirstModeScene : public ISceneManager{
  public:
    FirstModeScene(Tracer* tracer);

    bool ScenarioExe() override;

  private:
    void SceneSwitch();
    void SceneEnd();
    Tracer* tracer_;
    FirstModeDrive drive_;
    AngleCondition angle_condition_1_;
    AngleCondition angle_condition_2_;
    double milege_condition_1_;
    double milege_condition_2_;
};

#endif
