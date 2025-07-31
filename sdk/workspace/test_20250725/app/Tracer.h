#ifndef TRACER_H_
#define TRACER_H_

#include "Motor.h"
#include "ColorSensor.h"
#include "UltrasonicSensor.h"

using namespace spikeapi;

class Tracer {
public:
  Tracer();
  void run();
  void init();
  void terminate();

  const Motor& getLeftWheel() const { return left_wheel_; }
  const Motor& getRightWheel() const { return right_wheel_; }
  const ColorSensor& getColorSensor() const { return color_sensor_; }
  const UltrasonicSensor& getUltrasonicSensor() const { return ultrasonic_sensor_; }

private:
  Motor left_wheel_;
  Motor right_wheel_;
  ColorSensor color_sensor_;
  UltrasonicSensor ultrasonic_sensor_;
  int scenario_num_;
  int counter_;
};

#endif  // TRACER_H_