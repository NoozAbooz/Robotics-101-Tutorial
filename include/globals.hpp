#pragma once
#include "api.h"

extern pros::Controller master;
extern pros::MotorGroup left_mg;
extern pros::MotorGroup right_mg;
extern pros::Motor intake;
extern pros::IMU inertial;

extern double gear_ratio;
extern double wheel_diameter;
extern double wheel_distance;

extern void driveTo(double target, double maxSpeed, double timeout);
extern void turnTo(double heading, double maxSpeed, double timeout);
extern void delay(double seconds);

class PID {
    public:
    // Constructor
    PID(float kP, float kI, float kD);
    
    // Member function declarations
    float update(const float error);
    void reset();

    protected:
    // Member variables
    float kP;
    float kI;
    float kD;
    float integral;
    float prevError;
};
extern PID lateralPID;
extern PID turnPID;