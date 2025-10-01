#ifndef SMART_CARRY_SCENE_H_
#define SMART_CARRY_SCENE_H_

#include "i_scene_manager.h"
#include "angle_check.h"
#include "smart_carry_drive.h"
#include "color_check.h"             // ColorCondition
#include "milege_check.h"            // MilegeCondition
#include "reflect_light_check.h"     // ReflectLightCondition

class SmartCarryScene : public ISceneManager {
public:
    SmartCarryScene();                       // デフォルトコンストラクタ
    explicit SmartCarryScene(Tracer* tracer);  // Tracer付きコンストラクタ
    ~SmartCarryScene() noexcept override = default;

    bool ScenarioExe() override;             // シナリオを実行

private:
    // 条件データ
    ColorCondition::LineColorConditionData color_condition_blue_;
    ColorCondition::LineColorConditionData color_condition_red_;
    ReflectLightCondition::ReflectLightConditionData light_target_;
    float reached_angle_;

    // シーン制御
    void SceneSwitch();    // シーン切り替え
    void SceneEnd();       // シーン終了判定

    // ドライブ・条件オブジェクト
    SmartCarryDrive drive_;
    Tracer* tracer_;
    AngleCondition angle_condition_r1_;
    AngleCondition angle_condition_r2_;
    AngleCondition angle_condition_r3_;
    AngleCondition angle_condition_r4_;
    AngleCondition angle_condition_r5_;
    AngleCondition angle_condition_r6_;
    AngleCondition angle_condition_r7_;
    AngleCondition angle_condition_r8_;
    AngleCondition angle_condition_r9_;

    MilegeCondition mileage_condition_1_;
    MilegeCondition mileage_condition_2_;
    MilegeCondition mileage_condition_3_;
    MilegeCondition mileage_condition_4_;
    MilegeCondition mileage_condition_5_;
    MilegeCondition mileage_condition_6_;
    MilegeCondition mileage_condition_7_;
    MilegeCondition mileage_condition_8_;
    MilegeCondition mileage_condition_9_;


    int scene_num_;
};

#endif  // SMART_CARRY_SCENE_H_
