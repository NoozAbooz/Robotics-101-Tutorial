#include "main.h"

void delay(double seconds) {
  	pros::delay(seconds * 1000);
}

double to_rad(double degrees) {
	return degrees * (M_PI / 180);
}

double to_deg(double radians) {
	return radians * (180 / M_PI);
}