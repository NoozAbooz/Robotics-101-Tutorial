#include "main.h"

void driveTo(double target, double maxSpeed, double timeout) {
	// PID control variables
	double kP = 0.5;
	double kI = 0;
	double kD = 0;
	double integral = 0;
	double previousError = 0;

	double distanceTravelled = 0;
	double startTime = pros::millis();

	while (pros::millis() - startTime < timeout) {
		distanceTravelled = # of rotations * (3.25 * M_PI));

		double error = target - distanceTravelled;
		integral += error;
		double derivative = error - previousError;

		double output = kP * error + kI * integral + kD * derivative;
		output = std::clamp(output, -maxSpeed, maxSpeed);

		left_mg.move_velocity(output);
		right_mg.move_velocity(output);

		previousError = error;
		pros::delay(20);
	}

	left_mg.brake();
	right_mg.brake();
}