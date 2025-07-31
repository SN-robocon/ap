#ifndef LINE_TRACE_SCENE_H_
#define LINE_TRACE_SCENE_H_

#include "i_scene_manager.h"
#include "mg_line_trace_drive.h"

class MgLineTraceScene : public ISceneManager{
public:
  MgLineTraceScene(Tracer* tracer, int scenario_num);

  bool ScenarioExe() override; //シナリオを実行する

private:
  int scenario_num_;
  MgLineTraceDrive drive_;
};

#endif // LINE_TRACE_SCENE_H_