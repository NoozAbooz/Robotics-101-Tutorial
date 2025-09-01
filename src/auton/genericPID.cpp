using namespace std;
#include <cmath> // Include cmath for fabs()

class PID {
    public:
    // Constructor
    PID(float kP, float kI, float kD) 
    : kP(kP), 
      kI(kI), 
      kD(kD) {}

    // Member function to update PID
    float update(const float error) {
        // calculate integral
        integral += error;

        // calculate derivative
        const float derivative = error - prevError;
        prevError = error;

        // calculate output
        return error * kP + integral * kI + derivative * kD;
    }

    // Member function to reset PID
    void reset() {
        integral = 0;
        prevError = 0;
    }

    protected:
    // Member variables
    float kP;
    float kI;
    float kD;
    float integral = 0;
    float prevError = 0;

    // Member functions can also be added here!
    
};