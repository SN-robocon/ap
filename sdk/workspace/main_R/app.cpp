#include "app.h"
#include <stdio.h>

#include "Tracer.h"
#include "ForceSensor.h"
#include "Clock.h"  

Tracer tracer;
Clock clock;


using namespace spikeapi;

// 走行タスク
void tracer_task(intptr_t exinf) {
  // 走行処理を実行
  tracer.run();
  // 走行タスクの終了
  ext_tsk();
}

// メインタスク
void main_task(intptr_t unused) {
  const uint32_t duration = 100*1000;
  // フォースセンサーポート設定
  ForceSensor forceSensor(EPort::PORT_D);

  // 走行処理の初期処理
  tracer.init();

  printf("Press the force sensor to start...\n");

  // フォースセンサーが押下されるまで待機
  while (!forceSensor.isTouched()) {
    clock.sleep(duration);
  }
  // フォースセンサーから離れるまで待機
  while (forceSensor.isTouched()) {
    clock.sleep(duration);
  }

  // 走行タスクの開始
  printf("\nStarted!\n");
  sta_cyc(TRACER_CYC);
  
  // フォースセンサーが押下されるまで待機
  while (!forceSensor.isTouched()) {
    clock.sleep(duration);
  }
  // フォースセンサーから離れるまで待機
  while (forceSensor.isTouched()) {
    clock.sleep(duration);
  }

  // 走行タスクの停止
  stp_cyc(TRACER_CYC);
  // 走行処理の終了処理
  tracer.terminate();
  printf("\nStopped!\n");
  // メインタスクの終了
  ext_tsk();
}

