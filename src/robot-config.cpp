#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);

motor BackRightMotor = motor(PORT10, true);
motor BackLeftMotor = motor (PORT9, false);
motor FrontLeftMotor = motor (PORT1, false);
motor FrontRightMotor = motor (PORT2, true);
motor LeftBasketMotor = motor (PORT3, false);
motor RightBasketMotor = motor (PORT4, true);
motor LeftInTakeMotor = motor (PORT5, false);
motor RightInTakeMotor = motor (PORT6, true);

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
