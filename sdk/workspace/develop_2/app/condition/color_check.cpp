#include "color_check.h"
#include <stdio.h>

ColorCondition::ColorCondition(Tracer* tracer, LineColorConditionData target)
 : ICondition(tracer), target_color_range_(target), rgb_to_hsv_(tracer_) {}

bool ColorCondition::IsConditionMet() {
  printf("カラー条件（受取） H_min:%.2f, H_max:%.2f, S_min:%.2f, S_max:%.2f, V_min:%.2f, V_max:%.2f\n", target_color_range_.hue_min, target_color_range_.hue_max, target_color_range_.saturation_min, target_color_range_.saturation_max, target_color_range_.value_min, target_color_range_.value_max);

  // HSV値を取得
  printf("HSV値計算処理呼出し\n");
  rgb_to_hsv_.rgb_to_hsv();
  printf("取得HSV値 H:%.2f, S:%.2f, V:%.2f\n", rgb_to_hsv_.hsv.hue, rgb_to_hsv_.hsv.saturation, rgb_to_hsv_.hsv.value);

  // HSV値を判定
  // 引数で各条件範囲にHSV計算関数から取得した各値が含まれていること
  bool result = (target_color_range_.hue_min <= rgb_to_hsv_.hsv.hue && 
          rgb_to_hsv_.hsv.hue <= target_color_range_.hue_max) &&
          (target_color_range_.saturation_min <= rgb_to_hsv_.hsv.saturation && 
          rgb_to_hsv_.hsv.saturation <= target_color_range_.saturation_max) &&
          (target_color_range_.value_min <= rgb_to_hsv_.hsv.value && 
          rgb_to_hsv_.hsv.value <= target_color_range_.value_max);
  printf("カラー判定結果：%d\n", result);
  return result;
  // return (target_color_range_.hue_min <= rgb_to_hsv_.hsv.hue && 
  //         rgb_to_hsv_.hsv.hue <= target_color_range_.hue_max) &&
  //         (target_color_range_.saturation_min <= rgb_to_hsv_.hsv.saturation && 
  //         rgb_to_hsv_.hsv.saturation <= target_color_range_.saturation_max) &&
  //         (target_color_range_.value_min <= rgb_to_hsv_.hsv.value && 
  //         rgb_to_hsv_.hsv.value <= target_color_range_.value_max);
}
