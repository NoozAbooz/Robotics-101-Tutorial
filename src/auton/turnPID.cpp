#include "main.h"
#include <cmath>

void turnTo(double heading, double maxSpeed, double timeout) {
	// PID control variables
	double currentHeading = 0;
	double startTime = pros::millis();

	double deadband = 2; // acceptable error range
	bool settled = false; 

	while (pros::millis() - startTime < timeout && !settled) {
		if (!isnanf(inertial.get_rotation()) && !isinf(inertial.get_rotation())) {
			currentHeading = inertial.get_heading();
		} else {
			currentHeading = 0;
		}
		double error = heading - currentHeading;
		double output = turnPID.update(error);
		output = std::clamp(output, -maxSpeed, maxSpeed);

		left_mg.move_velocity(-output);
		right_mg.move_velocity(output);

		previousError = error;
		pros::delay(20);
	}

	left_mg.brake();
	right_mg.brake();
}