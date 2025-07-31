#ifndef RGB_TO_HSV_H
#define RGB_TO_HSV_H

class Tracer;

class RGBtoHSV {
public:
  struct HSV {
      double hue; // 色相
      double saturation; // 彩度
      double value; // 明度
  };

  HSV hsv; // HSV値を格納する構造体
  RGBtoHSV(Tracer* tracer);
  void rgb_to_hsv();

private:
  Tracer* tracer_;  
};
    
#endif // RGB_TO_HSV_H