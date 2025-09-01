#include "main.h"

void driveTo(double target, double maxSpeed, double timeout) {
	// PID control variables
	double currentPos = 0;
	double startTime = pros::millis();

	double deadband = 2; // acceptable error range
	bool settled = false; 

	while (pros::millis() - startTime < timeout && !settled) {
		// currentPos = # of rotations * (3.25 * M_PI));

		double error = target - currentPos;
		double output = lateralPID.update(error);
		output = std::clamp(output, -maxSpeed, maxSpeed);

		left_mg.move_velocity(output);
		right_mg.move_velocity(output);

		if (std::fabs(error) < deadband) {
			settled = true; // Robot is within acceptable range -> exit loop
		}

		pros::delay(20);
	}

	left_mg.brake();
	right_mg.brake();
	lateralPID.reset();
}