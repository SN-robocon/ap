#include <iostream>
#include <cmath>
#include <stdio.h>
#include "rgb_to_hsv.h"
#include "Tracer.h"

RGBtoHSV::RGBtoHSV(Tracer* tracer)
    : tracer_(tracer) {}

void RGBtoHSV::rgb_to_hsv()
{

    // 変数定義
    // カラーセンサーから取得したRGB値
    double red;   // 赤
    double green; // 緑
    double blue;  // 青

    double all;     // RGB値の合計(正規化の際に使用)
    double max_rgb; // RGB値の最大値
    double min_rgb; // RGB値の最小値

    // 求めるHSV値
    double hue;        // 色相
    double saturation; // 彩度
    double value;      // 明度

    // RGB値を取得する
    spikeapi::ColorSensor::RGB rgb;
    // colorSensor.getRGB(rgb);
    // tracer_->getColorSensor()::RGB rgb;
    tracer_->getColorSensor().getRGB(rgb);
//    printf("---RGB---\n");
   // printf("R:%d ,G:%d ,B:%d\n", rgb.r, rgb.g, rgb.b);

/*
    単体テスト用コード

    struct RGB 
    {
        int r; // 赤
        int g; // 緑
        int b; // 青
    } rgb;
    
    rgb.r = 1;
    rgb.g = 500;
    rgb.b = 499;
    printf("---RGB---\n");
    printf("R:%d ,G:%d ,B:%d\n", rgb.r, rgb.g, rgb.b);
*/
    // RGB値を正規化（0~255の範囲に収める）
    all = rgb.r + rgb.g + rgb.b;
    if (rgb.r > 0) {
        red = rgb.r / all * 255;
    }
    if (rgb.g > 0) {
        green = rgb.g / all * 255;
    }
    if (rgb.b > 0) {
        blue = rgb.b / all * 255;
    }
 //   printf("---RGB(0~255)---\n");
 //   printf("R:%f ,G:%f ,B:%f\n", red, green, blue);

    // RGB値の最大値と最小値を求める
    max_rgb = std::max(red, std::max(green, blue));
    min_rgb = std::min(red, std::min(green, blue));
  //  printf("---RGB(最大値と最小値)---\n");
   // printf("最大値:%f \n", max_rgb);
   // printf("最小値:%f \n", min_rgb);

    // 明度を計算
    value = max_rgb / 256 * 100;

    // 色相と彩度を計算
    if (max_rgb == min_rgb)
    {
        hue = 0;
        saturation = 0;
    }
    else
    {
        if (max_rgb == red)
        {
            hue = 60.0 * (green - blue) / (max_rgb - min_rgb) + 0;
        }
        else if (max_rgb == green)
        {
            hue = 60.0 * (blue - red) / (max_rgb - min_rgb) + 120.0;
        }
        else if (max_rgb == blue)
        {
            hue = 60.0 * (red - green) / (max_rgb - min_rgb) + 240.0;
        }

//        printf("調整前色相：%f\n", hue);

        if (hue > 360.0)
        {
            hue = hue - 360.0;
        }
        else if (hue < 0)
        {
            hue = hue + 360.0;
        }

        saturation = (max_rgb - min_rgb) / max_rgb * 100.0;
    }
 //   printf("RGB→HSV\n");
  //  printf("H:%f ,S:%f ,V:%f\n", hue, saturation, value);

    // HSV値を構造体に格納
    hsv.hue = hue;
    hsv.saturation = saturation;
    hsv.value = value;

   // printf("HSV値格納完了\n");
}
