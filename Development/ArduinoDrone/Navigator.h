#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "IMU.h"
#include "Sonar.h"

#define ASCENSION_RATE 1
#define STABILIZER_THRESHOLD 1
#define MOVEMENT_ANGLE 15
#define SENSITIVITY 1
#define MAX_BASE_SPEED 240
#define DESIRED_RISING_RATE 5
#define HOVER_HEIGHT 75
#define STABLE_CONSTANT 10
#define LANDING_THRESHOLD 10

enum NavState
{
    kTakingOff, kLanding, kStabilizing, kFlying, kLanded
};

class Navigator
{
public:
    Navigator();

    void Initialize(PwmPin ne, PwmPin nw, PwmPin se, PwmPin sw);
    void Update();

    void Ascend();
    void Descend();

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

    MotorSpeed nw_speed;
    MotorSpeed ne_speed;
    MotorSpeed sw_speed;
    MotorSpeed se_speed;

    float pitch_offset;
    float roll_offset;

    bool forward;
    bool backward;
    bool left;
    bool right;
};

#endif