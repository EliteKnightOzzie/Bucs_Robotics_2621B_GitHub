/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Emily Wang                                                */
/*    Created:      07/30/2023                                                */
/*    Description:  2621 Team Code                                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor1               motor         1               
// Motor2               motor         2               
// Motor3               motor         3               
// Motor4               motor         4 
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
competition Competition;

//  ______________
// |              |
// |2            1|   ^
// |              |  /|\
// |              |   |
// |4            3|   |
// | ____________ |
//

double abso(double k) {
    if (k < 0)
        return -k;
    else
        return k;
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void drive() {
    while (true) {
        // right stick, up - down
        double rightPos = Controller1.Axis2.position(percent);
        // left stick, up - down
        double leftPos = Controller1.Axis3.position(percent);

        // allows for assisstant to contribute
        if (Controller2.installed()) {
            double rightPos2 = Controller2.Axis2.position();
            double leftPos2 = Controller2.Axis3.position();

            if (abso(rightPos2) > abso(rightPos))
                rightPos = rightPos2;
            if (abso(leftPos2) > abso(leftPos))
                leftPos = leftPos2;
        }

        LeftMotorGroup.spin(directionType::fwd, leftPos, velocityUnits::pct);
        RightMotorGroup.spin(directionType::fwd, rightPos, velocityUnits::pct);

        // leftMotorA.spin(directionType::fwd, leftPos, velocityUnits::pct);
        // rightMotor.spin(directionType::fwd, rightPosition * driveSpeed/200, velocityUnits::pct);

        vex::task::sleep(20); // Sleep to prevent hogging the CPU
    }
}

int main() {
    // Initializing Robot Configuration. DO NOT REMOVE!
    vexcodeInit();

    // Call the drive function
    drive();

    // The code will never reach here due to the infinite loop in the drive function
    return 0;
}
