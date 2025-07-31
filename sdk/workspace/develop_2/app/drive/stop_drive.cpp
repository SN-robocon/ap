#include "stop_drive.h"
#include "Tracer.h"
#include <stdio.h>

StopDrive::StopDrive(Tracer* tracer)
    : IDrive(tracer){}

void StopDrive::Drive(ControlMode mode) {
    printf("停止処理開始\n");
    tracer_->getLeftWheel().stop(); // モーターの停止する処理を呼ぶ
    tracer_->getRightWheel().stop(); // モーターの停止する処理を呼ぶ
    printf("停止処理終了\n");
}