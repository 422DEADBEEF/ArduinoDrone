/******************************************************************************
*   File:           IMU.h
*
*   Description:    Most of this source code comes from the MPU6050 Arduino 
*                   Examples. This class is a wrapper around the MPU6050
*                   Arduino Library driver, and provides simple Yaw, Pitch,
*                   and Roll values.
*
*   Authors:        Team 0xDEADBEEF:
*                   Ryan Berge and Jeremy DeHaan
*
******************************************************************************/

#ifndef IMU_H
#define IMU_H

#define CALIBRATION_THRESHOLD 0.01

class IMU
{
public:
    IMU();

    bool Initialize(); // Blocks until system is calibrated
    void Update();

    float GetYaw();
    float GetPitch();
    float GetRoll();    

private:
    void Calibrate();

    float yaw;
    float pitch;
    float roll;

    float yaw_offset;
    float pitch_offset;
    float roll_offset;
};

#endif