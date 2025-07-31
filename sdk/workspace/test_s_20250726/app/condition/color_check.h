#ifndef COLOR_CHECK_H_
#define COLOR_CHECK_H_

#include "i_condition.h"
#include "rgb_to_hsv.h"

class ColorCondition : public ICondition {
public:
  struct LineColorConditionData {
    double hue_min, hue_max;
    double saturation_min, saturation_max;
    double value_min, value_max;
  };
  ColorCondition(Tracer* tracer, LineColorConditionData target);
  bool IsConditionMet() override;

private:
  LineColorConditionData target_color_range_;
  RGBtoHSV rgb_to_hsv_;
};

#endif  // COLOR_CHECK_H_