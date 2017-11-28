#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include "IMU.h"
#include "Sonar.h"

#define ASCENSION_RATE 16
#define STABILIZER_THRESHOLD 1
#define MOVEMENT_ANGLE 15
#define HOVER_SPEED 200
#define SENSITIVITY 1
#define MAX_BASE_SPEED 240

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

private:
    IMU imu;

    MotorSpeed base_speed;

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

    bool taking_off;
    bool landing;
};

#endif