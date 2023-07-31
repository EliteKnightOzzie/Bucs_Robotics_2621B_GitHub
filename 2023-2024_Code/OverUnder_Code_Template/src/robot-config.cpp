#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor MotorRf = motor(PORT1, ratio18_1, false);
motor MotorRb = motor(PORT3, ratio18_1, false);
motor_group RightMotorGroup = motor_group(MotorRf, MotorRb);
motor MotorLf = motor(PORT2, ratio18_1, true);
motor MotorLb = motor(PORT4, ratio18_1, true);
motor_group LeftMotorGroup = motor_group(MotorLf, MotorLb);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}