#include "api.h"

extern pros::Controller master;
extern pros::MotorGroup left_mg;
extern pros::MotorGroup right_mg;
extern pros::Motor intake;
extern pros::IMU inertial;

extern void driveTo(double target, double maxSpeed, double timeout);
extern void turnTo(double heading, double maxSpeed, double timeout);