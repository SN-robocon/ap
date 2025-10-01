#include "i_drive_manager.h"
#include "double_loop_drive.h"

// コンストラクタ
DoubleLoopDrive::DoubleLoopDrive(Tracer* tracer) : 
IDriveManager(tracer),
turn_drive_(tracer) ,
straight_drive_(tracer), 
line_trace_drive_r_(tracer), 
line_trace_drive_l_(tracer) {
}
// シーンごとの走行切り替え
void DoubleLoopDrive::DriveSwitch(int scene_num) {

	switch (scene_num) {
		case 1:  // 旋回
			turn_drive_.Drive(ControlMode::TURN_RIGHT,60);
		break;

		case 2:  // 直進(距離が指定値に到達且つ黒色を検知)
			straight_drive_.Drive(ControlMode::STRAIGHT,60);
		break;
		
		case 3:  // 黒ライントレース
            line_trace_drive_r_.Drive(ControlMode::LINE_TRACE_R,60);
		break;

		case 4:  // 旋回
			turn_drive_.Drive(ControlMode::TURN_RIGHT,60);
		break;

		case 5:  // 直進(距離が指定値に到達且つ黒色を検知)
			straight_drive_.Drive(ControlMode::STRAIGHT,60);
		break;

		case 6:  // 黒ライントレース
            line_trace_drive_l_.Drive(ControlMode::LINE_TRACE_L,60);
		break;

		case 7:  // 直進
            straight_drive_.Drive(ControlMode::STRAIGHT,60);
		break;

		case 8:  // 旋回
            turn_drive_.Drive(ControlMode::TURN_LEFT,60);
		break;

		case 9:  // 直進(距離が指定値に到達且つ黒色を検知)
            straight_drive_.Drive(ControlMode::STRAIGHT,60);
		break;
		
		case 10:  // 黒ラインとレース
            line_trace_drive_r_.Drive(ControlMode::LINE_TRACE_R,60);
		break;

		case 11:  // 直進
            straight_drive_.Drive(ControlMode::STRAIGHT,60);
		break;

		case 12:  // 旋回
			turn_drive_.Drive(ControlMode::TURN_RIGHT,65);
		break;

		case 13:  // 直進(距離が指定値に到達且つ黒色を検知)
            straight_drive_.Drive(ControlMode::STRAIGHT,70);
		break;

		default:
		// 何もしない
		break;
	}
}
