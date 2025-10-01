#include <cstdio>
#include "smart_carry_scene.h"
#include "color_check.h"
#include "angle_check.h"
#include "reflect_light_check.h"
#include "milege_check.h"
#include "Tracer.h"

SmartCarryScene::SmartCarryScene(Tracer* tracer)
    : ISceneManager(tracer),
      drive_(tracer),
      tracer_(tracer),
      angle_condition_r1_(tracer_, 15.0f),
      angle_condition_r2_(tracer_, 24.0f),//追加
      angle_condition_r3_(tracer_, 50.0f),//追加
      angle_condition_r4_(tracer_, 52.0f),//追加
      angle_condition_r5_(tracer_, 20.0f), // 38 25
      angle_condition_r6_(tracer_, 20.0f), // 54
      angle_condition_r7_(tracer_, 55.0f),//50
      angle_condition_r8_(tracer_, 13.0f), // 30
      angle_condition_r9_(tracer_, 55.0f),
      
      mileage_condition_1_(tracer_, 550), // ゲート正面まで
      mileage_condition_2_(tracer_, 810), // ゲート通過
      mileage_condition_3_(tracer_, 410), // サークル前まで
      mileage_condition_4_(tracer_, 90), // サークル中央まで
      
      mileage_condition_5_(tracer_, 80),  // 1回目　後退
      mileage_condition_6_(tracer_, 380),  // 後退→旋回後の直進 450 420 370
      mileage_condition_7_(tracer_, 820),  // 2個目のサークルまでの直進
      mileage_condition_8_(tracer_, 60),  // 2回目の後退 80
      mileage_condition_9_(tracer_, 800)   // 後退→旋回後の直進

//      mileage_condition_5_(tracer_, 80),  // 1回目　後退
//      mileage_condition_6_(tracer_, 550),  // 後退→旋回後の直進 450
//      mileage_condition_7_(tracer_, 820),  // 2個目のサークルまでの直進
//      mileage_condition_8_(tracer_, 60),  // 2回目の後退 80
//      mileage_condition_9_(tracer_, 800)   // 後退→旋回後の直進
{
    reflection_condition_ = 10;
    scene_num_ = 0;

    // 青色判定のしきい値を設定
    color_condition_blue_.hue_min = 200.0;
    color_condition_blue_.hue_max = 240.0;
    color_condition_blue_.saturation_min = 30.0;
    color_condition_blue_.saturation_max = 80.0;
    color_condition_blue_.value_min = 30.0;
    color_condition_blue_.value_max = 70.0;

    // 赤色判定のしきい値を設定
    color_condition_red_.hue_min = 350.0;
    color_condition_red_.hue_max = 360.0;
    color_condition_red_.saturation_min = 70.0;
    color_condition_red_.saturation_max = 100.0;
    color_condition_red_.value_min = 60.0;
    color_condition_red_.value_max = 100.0;
}

// シナリオを実行する
bool SmartCarryScene::ScenarioExe() {
    static int cnt=0;
    // カラー判定
    ColorCondition color1(tracer_, color_condition_blue_);
    ColorCondition color2(tracer_, color_condition_red_);

    // 反射光判定
    light_target_.base_light = reflection_condition_;
    ReflectLightCondition light(light_target_, tracer_);

    // 走行管理を呼ぶ
    drive_.DriveSwitch(scene_num_);

    // 判定呼ぶ
    switch (scene_num_) {
    case 0:
        SceneEnd();
        break;
    
    case 1:
        printf("NOW:SCENE 1\n");
        // カラー判定
        if (color1.IsConditionMet()) {
            SceneEnd();
        }
        break;

    case 2:
        printf("NOW:SCENE 2\n");
        cnt++;
        if(cnt==20){
        cnt=0;
        // 停止処理
            SceneEnd();
        }
        break;

    case 3://ゲートのほうに旋回
        printf("NOW:SCENE 3\n");
        // 角度判定
        if (angle_condition_r1_.IsConditionMet()) {
            SceneEnd();
        }
        break;

    case 4://ゲート正面まで直進
        printf("NOW:SCENE 4\n");
        // 走行距離判定（直進)
        if (mileage_condition_1_.IsConditionMet()) {

            SceneEnd();
        }
        break;

    case 5://正面になるように旋回
        printf("NOW:SCENE 5\n");
        // 角度判定
        if (angle_condition_r2_.IsConditionMet()) {
            SceneEnd();
        }
        break;

    case 6://ゲート通過
        printf("NOW:SCENE 4\n");
        // 走行距離判定（直進)
        if (mileage_condition_2_.IsConditionMet()) {

            SceneEnd();
        }
        break;

    case 7://サークルのほうに旋回(90度)
         printf("NOW:SCENE 3\n");
        // 角度判定
        if (angle_condition_r3_.IsConditionMet()) {
            SceneEnd();
        }
        break;
    
    case 8://サークルの前まで直進
        printf("NOW:SCENE 4\n");
        // 走行距離判定（直進)
        if (mileage_condition_3_.IsConditionMet()) {

            SceneEnd();
        }
        break;

    case 9://90度旋回
        printf("NOW:SCENE 3\n");
        // 角度判定
        if (angle_condition_r4_.IsConditionMet()) {
            SceneEnd();
        }
        break;
    
    case 10://サークルの中心に向かって直進
        printf("NOW:SCENE 4\n");
        // 走行距離判定（直進)
        if (mileage_condition_4_.IsConditionMet()) {

            SceneEnd();
        }
        break;
    
    //以下修正
    case 11:
         printf("NOW:SCENE 9\n");
        // 走行距離判定（後退）
        if (mileage_condition_5_.IsConditionMet()) {
            SceneEnd();
        }
        break;

    case 12:
        printf("NOW:SCENE 10\n");
        // 角度判定
        if (angle_condition_r5_.IsConditionMet()) {
            SceneEnd();
        }
        break;

    case 13:
       printf("NOW:SCENE 11\n");
        // 走行距離判定（直進)
        if (mileage_condition_6_.IsConditionMet()) {

            SceneEnd();
        }
        break;

    case 14:
        printf("NOW:SCENE 12\n");
        // 角度判定
        if (angle_condition_r6_.IsConditionMet()) {
            SceneEnd();
        }
        break;
    case 15:
       printf("NOW:SCENE 13\n");
        //反射光判定(黒)
        if (light.IsConditionMet()) {
            SceneEnd();
        }
        break;

    case 16:
        printf("NOW:SCENE 14\n");
        //カラー判定(赤)
        if (color2.IsConditionMet()) {
            SceneEnd();
        }
        break;

    case 17:
        printf("NOW:SCENE 15\n");
        cnt++;
        if(cnt==20){
        cnt=0;
        // 停止処理
        SceneEnd();
        }
        break;

    case 18:
        printf("NOW:SCENE 16\n");
        // 角度判定
        if (angle_condition_r7_.IsConditionMet()) {
            SceneEnd();
        }
        break;

    case 19:
        printf("NOW:SCENE 17\n");
        // 走行距離判定（直進)
        if (mileage_condition_7_.IsConditionMet()) {
            SceneEnd();
        }
        break;

    case 20:
        printf("NOW:SCENE 18\n");
        // 走行距離判定（後退）
        if (mileage_condition_8_.IsConditionMet()) {
            SceneEnd();
        }
        break;

    case 21:
        printf("NOW:SCENE 19\n");
        // 角度判定
        if (angle_condition_r8_.IsConditionMet()) {
            SceneEnd();
        }
        break;

    case 22:
        printf("NOW:SCENE 20\n");
        // 走行距離判定（直進）
        if (mileage_condition_9_.IsConditionMet()) {
            SceneEnd();
        }
        break;

    case 23:
            printf("NOW:SCENE 22\n");
        // 角度判定
        if (angle_condition_r9_.IsConditionMet()) {
            SceneEnd();
        }
        break;
    case 24:
        printf("NOW:SCENE 22\n");
        // 反射光判定
        if (light.IsConditionMet()) {
            SceneEnd();
        }
        break;

    default:
        // 何もしない
        printf("NOW:SCENE 19\n");
        break;
    }

    return (scene_num_ == 25);
}

// シーン終了を判断する
void SmartCarryScene::SceneEnd() {
    SceneSwitch();
}

// シーンを切り替える
void SmartCarryScene::SceneSwitch() {
    tracer_->getLeftWheel().resetCount();
    tracer_->getRightWheel().resetCount();
    scene_num_++;
}
