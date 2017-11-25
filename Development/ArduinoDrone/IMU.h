#ifndef IMU_H
#define IMU_H

class IMU
{
public:
    IMU();

    void Initialize(); // Blocks until system is calibrated
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