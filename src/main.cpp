#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_mg({-12,
						  -13,
});

pros::MotorGroup right_mg({-4,
						   -5,
});

pros::Motor intake(-16);
pros::IMU inertial(17);

void initialize() {
	inertial.reset();
}

void autonomous() {
	driveTo(24, 127, 4000);
	turnTo(90, 127, 4000);
}

void opcontrol() {
	while (true) {
		// Arcade control scheme
		int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		left_mg.move(dir + turn);                      // Sets left motor voltage
		right_mg.move(dir - turn);                     // Sets right motor voltage

		// Intake
		if (master.get_digital(DIGITAL_R1)) {         
			intake.move_velocity(127);                      
		} else if (master.get_digital(DIGITAL_R2)) {  
			intake.move_velocity(-127);
		} else {
			intake.move_velocity(0);
		}

		pros::delay(10);
	}
}