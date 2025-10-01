mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_CXXOBJS += \
	Tracer.o \
	goal_scene.o \
	goal_drive.o \
	line_trace_drive.o \
	straight_drive.o \
	stop_drive.o \
	color_check.o \
	milege_check.o \
	pid_controller.o \
	pwm_straight_controller.o \
	rgb_to_hsv.o \
	distance_calculator.o \
	imu_integrator.o \
	angle_check.o \
	reflect_light_check.o \
	turn_drive.o \
    smart_carry_scene.o \
    smart_carry_drive.o \
	double_loop_drive.o \
	double_loop_scene.o \
	first_mode_drive.o \
	first_mode_scene.o 

	
SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-spike/Makefile

endif

APPL_DIRS += \
	$(mkfile_path)app \
	$(mkfile_path)app/scenario \
	$(mkfile_path)app/drive \
	$(mkfile_path)app/condition \
	$(mkfile_path)app/calculation

INCLUDES += \
	-I$(mkfile_path)app \
	-I$(mkfile_path)app/scenario \
	-I$(mkfile_path)app/drive \
	-I$(mkfile_path)app/condition \
	-I$(mkfile_path)app/calculation \
