#pragma once
#include "IMU.h"
#include <chrono>
#include <cmath> 

class IMUIntegrator {
public:
  IMUIntegrator();
  void reset();                      // 積算初期化
  float update();                    // Z軸角度を更新し返す

private:
  spikeapi::IMU imu;                           // IMUインスタンス
  float thetaZ = 0.0f;                      // 積算角度
  std::chrono::steady_clock::time_point prev_time;  // 前回の時間
};

