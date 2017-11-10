#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#include "Util.h"

// TODO: Redesign this as a packed bit-field to reduce memory footprint
struct POST_FLAGS
{
    bool bluetooth;
    bool left_motor;
    bool right_motor;
    bool imu;
    bool ultrasonic;
};

class Diagnostics
{
public:

    static bool post()
    {
        POST_FLAGS flags{ false, false, false, false, false };
        RunTest(flags);
        Display(flags);

        if (flags.bluetooth && flags.left_motor && flags.right_motor &&
            flags.imu && flags.ultrasonic)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    static void RunTest(POST_FLAGS& flags)
    {
        // TODO: Design POST tests and set flags
        flags.bluetooth = true;
        flags.left_motor = true;
        flags.right_motor = true;
        flags.imu = true;
        flags.ultrasonic = true;
    }

    static void Display(POST_FLAGS& flags)
    {
        // TODO: Display result of POST on bluetooth (if available)
        //       and LEDs
    }

    static void ErrorMessage(const char* message)
    {
        // TODO: Send message over bluetooth connection.
        //       Also possibly flash LEDs.
    }
};

#endif