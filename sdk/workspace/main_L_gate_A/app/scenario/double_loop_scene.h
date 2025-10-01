#ifndef DOUBLE_LOOP_SCENE_H_
#define DOUBLE_LOOP_SCENE_H_

#include "i_scene_manager.h"
#include "angle_check.h"
#include "double_loop_drive.h"
#include "color_check.h"             // ← ColorCondition
#include "milege_check.h"            // ← MilegeCondition
#include "reflect_light_check.h"     // ← ReflectLightCondition

class DoubleLoopScene : public ISceneManager {
 public:
  DoubleLoopScene();
    explicit DoubleLoopScene(Tracer* tracer);  // ← この行を追加
    ~DoubleLoopScene() noexcept override = default;
    bool ScenarioExe() override;  // シナリオを実行する

 private:
    ColorCondition::LineColorConditionData color_condition_;
    ReflectLightCondition::ReflectLightConditionData light_target_;
    float reached_angle_;
    double base_mileage_0_;
    double base_mileage_1_;
    double base_mileage_2_;
    double base_mileage_3_;
    double base_mileage_4_;
    double base_mileage_5_;
    double base_mileage_6_;

    void SceneSwitch(); // シーンを切り替える
    void SceneEnd();  // シーン終了を判断する

    DoubleLoopDrive drive_;
    Tracer* tracer_;
    AngleCondition angle_condition_r1_;
    AngleCondition angle_condition_r2_;
    AngleCondition angle_condition_r3_;
    AngleCondition angle_condition_r4_;
    MilegeCondition mileage_condition_0_;
    MilegeCondition mileage_condition_1_;
    MilegeCondition mileage_condition_2_;
    MilegeCondition mileage_condition_3_;
    MilegeCondition mileage_condition_4_;
    MilegeCondition mileage_condition_5_;
    MilegeCondition mileage_condition_6_;
    int scene_num_;
};

#endif  // DOUBLE_LOOP_SCENE_H_
