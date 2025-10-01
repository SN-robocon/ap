#include "imu_integrator.h"
#include <cstdio>

IMUIntegrator::IMUIntegrator() : prev_time(std::chrono::steady_clock::now()) {}

void IMUIntegrator::reset() {
  thetaZ = 0.0f;
  prev_time = std::chrono::steady_clock::now();
  printf("RESET!!!!!\n\n");
}

float IMUIntegrator::update() {
  spikeapi::IMU::AngularVelocity angVel;
  imu.getAngularVelocity(angVel);

  auto curr_time = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed = curr_time - prev_time;
  double dt = elapsed.count();  // 秒

  thetaZ += std::abs(angVel.z * dt);  // 積分：角速度 × 時間

  prev_time = curr_time;
  printf("dt = %f",dt);

  printf("Z軸角速度: %.2f deg/s, 推定角度: %.2f deg\n\n", angVel.z, thetaZ);
  return thetaZ;
}
