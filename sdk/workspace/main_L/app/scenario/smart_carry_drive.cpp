#include "i_drive_manager.h"
#include "smart_carry_drive.h"

// コンストラクタ
SmartCarryDrive::SmartCarryDrive(Tracer* tracer) : 
IDriveManager(tracer),
turn_drive_(tracer) ,
straight_drive_(tracer), 
line_trace_drive_r_(tracer), 
line_trace_drive_l_(tracer),
stop_drive_(tracer) {
}
// シーンごとの走行切り替え
void SmartCarryDrive::DriveSwitch(int scene_num) {

	switch (scene_num) {
		case 1:  // ライントレース
            line_trace_drive_l_.Drive(ControlMode::LINE_TRACE_L,60);
		break;

		case 2:  //停止
			straight_drive_.Drive(ControlMode::STRAIGHT,0);
		break;
		
		case 3:  //旋回(右に90度)
			turn_drive_.Drive(ControlMode::TURN_RIGHT_2,80);
		break;

		case 4:  // 直進
			straight_drive_.Drive(ControlMode::STRAIGHT,80);
		break;

		case 5:  //後退
			straight_drive_.Drive(ControlMode::STRAIGHT,-80);
		break;

		case 6:  //旋回(左に90度)
            turn_drive_.Drive(ControlMode::TURN_LEFT,80);
		break;

		case 7:  // 直進
            straight_drive_.Drive(ControlMode::STRAIGHT,70);
		break;

		case 8:  // 旋回
			turn_drive_.Drive(ControlMode::TURN_LEFT,70);//80
		break;

		case 9:  // 直進
			straight_drive_.Drive(ControlMode::STRAIGHT,60);
		break;

		case 10:  // ライントレース
            line_trace_drive_r_.Drive(ControlMode::LINE_TRACE_R,60);
		break;

		case 11:  // 停止
			stop_drive_.Drive(ControlMode::STOP,0);
		break;
		
		case 12:  //旋回(左に90度)
			turn_drive_.Drive(ControlMode::TURN_LEFT_2,80);
		break;

		case 13:  //直進
            straight_drive_.Drive(ControlMode::STRAIGHT,80);
		break;

		case 14:  //後退
            straight_drive_.Drive(ControlMode::STRAIGHT,-70);//80
		break;

		case 15:  // 旋回(左に45度)
			turn_drive_.Drive(ControlMode::TURN_LEFT,80);
		break;

		case 16:  // 直進
            straight_drive_.Drive(ControlMode::STRAIGHT,100);
		break;

		case 17:  //旋回(右に45度)
			turn_drive_.Drive(ControlMode::TURN_RIGHT,80);  //直進(黒ライン検知)
		break;

		case 18:  //直進(黒ライン検知)
            straight_drive_.Drive(ControlMode::STRAIGHT,60);//70
		break;

		default:
		// 何もしない
		break;
	}
}
