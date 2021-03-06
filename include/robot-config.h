using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor BackRightMotor;
extern motor BackLeftMotor;
extern motor FrontRightMotor;
extern motor FrontLeftMotor;
extern motor LeftBasketMotor;
extern motor RightBasketMotor;
extern motor LeftInTakeMotor;
extern motor RightInTakeMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
