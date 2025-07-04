mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_CXXOBJS += \
	Tracer.o \
        calculation/DistanceCalculator.o \
        calculation/IMUIntegrator.o \
        calculation/PWMStraightController.o \
        calculation/pid_controller.o \
        condition/angle_check.o \
        condition/milege_check.o \
        condition/reflect_light_check.o \
        drive/line_trace_drive.o \
        drive/straight_drive.o \
        drive/turn_drive.o \
        scenario/line_obstacle_drive.o \
        scenario/line_obstacle_scene.o


SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-spike/Makefile

endif

APPL_DIRS += $(mkfile_path)app $(mkfile_path)unit

INCLUDES += \
	-I$(mkfile_path)app
