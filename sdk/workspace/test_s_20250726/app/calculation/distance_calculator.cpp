#include "distance_calculator.h"
#include "Tracer.h"

// タイヤ回転角度から走行距離を計算
double DistanceCalculator::calculateFromAngle(int angleDeg) {
    return tireDiameter * PI * static_cast<double>(angleDeg) / 360.0;
}

// WheelDistanceManager::WheelDistanceManager(Motor& left, Motor& right)
//     : leftMotor(left), rightMotor(right) {}
WheelDistanceManager::WheelDistanceManager(Tracer* tracer)
    : tracer_(tracer) {}

double WheelDistanceManager::getLeftDistance() const {
    return DistanceCalculator::calculateFromAngle(tracer_->getLeftWheel().getCount());
}

double WheelDistanceManager::getRightDistance() const {
    return DistanceCalculator::calculateFromAngle(tracer_->getRightWheel().getCount());
}

double WheelDistanceManager::getAverageDistance() const {
    return (getLeftDistance() + getRightDistance()) / 2.0;
}

