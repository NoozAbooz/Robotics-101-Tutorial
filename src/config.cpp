#include "main.h"

double gear_ratio = 36.0 / 48.0; // "driver gear / driven gear"
double wheel_diameter = 3.25;  // in inches
double wheel_distance = 12; // in inches, distance between left and right wheels

PID lateralPID(1, 0.2, 2.5); 
PID turnPID(1, 0.2, 2.5); 