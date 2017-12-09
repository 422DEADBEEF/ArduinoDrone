/******************************************************************************
*   File:           Navigator.h
*
*   Description:    The navigator subsystem controls the speeds of the motors
*                   based on user input, flight state 
*
*   Authors:        Team 0xDEADBEEF:
*                   Ryan Berge and Jeremy DeHaan
*
******************************************************************************/

#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "IMU.h"
#include "Sonar.h"

#define ASCENSION_RATE 1
#define UP_DOWN_RATE 12
#define STABILIZER_THRESHOLD 4
#define MOVEMENT_ANGLE 25
#define SENSITIVITY 1
#define MAX_BASE_SPEED 243
#define DESIRED_RISING_RATE 5
#define HOVER_HEIGHT 75
#define STABLE_CONSTANT 1
#define LANDING_THRESHOLD 10
#define TAKEOFF_SPEED 40

#define NAVIGATION_CLOCK_DELAY 200
#define TAKEOFF_CLOCK_DELAY 20

enum NavState
{
    kTakingOff, kLanding, kStabilizing, kFlying, kLanded, kTesting
};

class Navigator
{
public:
    Navigator();

    bool Initialize(PwmPin ne, PwmPin nw, PwmPin se, PwmPin sw);
    void Update();

    void Ascend();
    void Descend();
    void StopAscend();
    void StopDescend();

    void GoForward();
    void GoBack();
    void GoLeft();
    void GoRight();

    void StopForward();
    void StopBack();
    void StopLeft();
    void StopRight();

    void EmergencyShutdown();

    void LiftOff();
    void Land();

    NavState state;

private:
    IMU imu;
    Sonar sonar;

    MotorSpeed base_speed;
    MotorSpeed kHoverSpeed;

    PwmPin nw_pin;
    PwmPin ne_pin;
    PwmPin sw_pin;
    PwmPin se_pin;

    MotorSpeedTuner nw_speed;
    MotorSpeedTuner ne_speed;
    MotorSpeedTuner sw_speed;
    MotorSpeedTuner se_speed;

    float pitch_offset;
    float roll_offset;

    bool forward;
    bool backward;
    bool left;
    bool right;
};

#endif