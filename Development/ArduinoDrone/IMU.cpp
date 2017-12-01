#include "IMU.h"
#include "Diagnostics.h"

#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"


namespace {
    MPU6050 mpu;
    
    uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
    uint16_t fifoCount;     // count of all bytes currently in FIFO
    uint8_t fifoBuffer[64]; // FIFO storage buffer
    
    Quaternion q;           // [w, x, y, z]         quaternion container
    VectorFloat gravity;    // [x, y, z]            gravity vector
    float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector
    
    
}

IMU::IMU() : yaw(0), pitch(0), roll(0)
{
}

bool IMU::Initialize()
{
    Wire.begin();
    mpu.initialize();

    Diagnostics::SetLED(0, 0, 255);

    if (!mpu.testConnection())
    {
        Diagnostics::SetLED(0, 0, 255);
        return false;
    }    

    if (mpu.dmpInitialize() == 0) 
    {

        mpu.setXGyroOffset(220);
        mpu.setYGyroOffset(76);
        mpu.setZGyroOffset(-85);
        mpu.setZAccelOffset(1788); // 1688 factory default for my test chip
        mpu.setDMPEnabled(true);

        packetSize = mpu.dmpGetFIFOPacketSize();
    }
    else
    {
        //TODO: Diagnostics error
        Diagnostics::SetLED(0, 0, 255);
        return false;
    }

    Calibrate();
    return true;
}

void IMU::Update()
{
    uint8_t mpuIntStatus = mpu.getIntStatus();

    if ((mpuIntStatus & 0x10) || fifoCount == 1024) 
    {
        mpu.resetFIFO();
    }
    else
    {
        fifoCount = mpu.getFIFOCount();
        
        while (fifoCount < packetSize) 
        {
            fifoCount = mpu.getFIFOCount();
        }

        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        fifoCount -= packetSize;

        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

        yaw = ypr[0] * 180/M_PI;
        pitch = ypr[1] * 180/M_PI;
        roll = ypr[2] * 180/M_PI;
    }
}

void IMU::Calibrate()
{
    
    bool on = false;
    bool calibrated = false;
    while (!calibrated)
    {
        Serial.println("Calibrating...");
        
        if (on)
        {
            Diagnostics::SetLED(0, 0, 0);
        }
        else
        {
            Diagnostics::SetLED(255, 0, 0);
        }
        on = !on;

        float mean_yaw = 0;
        float mean_pitch = 0;
        float mean_roll = 0;

        for (int i = 0; i < 20; ++i)
        {
            float old_yaw = yaw;
            float old_pitch = pitch;
            float old_roll = roll;

            Update();
            mean_yaw += old_yaw - yaw;
            mean_pitch += old_pitch - pitch;
            mean_roll += old_roll - roll;
        }

        mean_yaw /= 20;
        mean_pitch /= 20;
        mean_roll /= 20;

        mean_yaw = (mean_yaw > 0) ? mean_yaw : -mean_yaw;
        mean_pitch = (mean_pitch > 0) ? mean_pitch : -mean_pitch;
        mean_roll = (mean_roll > 0) ? mean_roll : -mean_roll;

        if (mean_yaw < CALIBRATION_THRESHOLD && mean_pitch < CALIBRATION_THRESHOLD && mean_roll < CALIBRATION_THRESHOLD)
        {
            calibrated = true;
        }
    }
    yaw_offset = yaw;
    pitch_offset = pitch;
    roll_offset = roll;
}

float IMU::GetYaw()
{
    return yaw - yaw_offset;
}

float IMU::GetPitch()
{
    return pitch - pitch_offset;
}

float IMU::GetRoll()
{
    return roll - roll_offset;
}