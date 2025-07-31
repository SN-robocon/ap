#ifndef DISTANCE_CALCULATOR_H
#define DISTANCE_CALCULATOR_H

class Tracer;

// タイヤ直径（mm）
// constexpr double tireDiameter = 81.6;
constexpr double tireDiameter = 56.0;
constexpr double PI = 3.141592653589793;

class DistanceCalculator {
public:
    static double calculateFromAngle(int angleDeg);
	static double calculateFromAngleInCm(int angleDeg);
};

class WheelDistanceManager {
private:
    // Motor& leftMotor;
    // Motor& rightMotor;
    Tracer* tracer_;

public:
    // WheelDistanceManager(Motor& left, Motor& right);
    WheelDistanceManager(Tracer* tracer);

    double getLeftDistance() const;
    double getRightDistance() const;
    double getAverageDistance() const;
};

#endif  // DISTANCE_CALCULATOR_H
