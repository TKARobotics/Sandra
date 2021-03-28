/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template ok                                     */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:                                                                                 
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
vex::vision Vision1(vex::PORT5);

int leftStickXaxis = Controller1.Axis4.value();
int rawStrafeInput = leftStickXaxis;
int rightStickYaxis = (Controller1.Axis2.value() + 126) / 62.5;
int ArmSpeedPercent = 50;


/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) 
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();  

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void driveForward(int amountForward)
{
    FrontRightMotor.startRotateFor(vex::directionType::fwd, amountForward, vex::rotationUnits::deg);
    FrontLeftMotor.startRotateFor(vex::directionType::fwd, amountForward, vex::rotationUnits::deg);
    BackRightMotor.startRotateFor(vex::directionType::fwd, amountForward, vex::rotationUnits::deg);
    BackLeftMotor.rotateFor(vex::directionType::fwd, amountForward, vex::rotationUnits::deg);
}
void autonomous(void) 
{
  FrontLeftMotor.rotateFor(vex::directionType::rev, 659.4, vex::rotationUnits::deg);
 
  Brain.Screen.clearLine();
//  Vision1.takeSnapshot(REDBALL);
int seesRedBall = Vision1.largestObject.exists;

  if ( seesRedBall )
  {
    driveForward(1490);
    
    // bring in code

    LeftBasketMotor.startRotateFor(vex::directionType::fwd, 1000, vex::rotationUnits::deg);
    RightBasketMotor.rotateFor(vex::directionType::fwd, 1000, vex::rotationUnits::deg);

    // score out code

    LeftBasketMotor.startRotateFor(vex::directionType::rev, 1000, vex::rotationUnits::deg);
    RightBasketMotor.rotateFor(vex::directionType::rev, 1000, vex::rotationUnits::deg);

    FrontRightMotor.rotateFor(vex::directionType::rev, 70.2, vex::rotationUnits::deg);

    driveForward(1690);

    //      insert bring in code

    FrontRightMotor.rotateFor(vex::directionType::rev, 102.69, vex::rotationUnits::deg);

    driveForward(1159);

    LeftBasketMotor.startRotateFor(vex::directionType::fwd, 1000, vex::rotationUnits::deg);
    RightBasketMotor.rotateFor(vex::directionType::fwd, 1000, vex::rotationUnits::deg);

    //      insert score code

    LeftBasketMotor.startRotateFor(vex::directionType::rev, 1000, vex::rotationUnits::deg);
    RightBasketMotor.rotateFor(vex::directionType::rev, 1000, vex::rotationUnits::deg);

    FrontLeftMotor.rotateFor(vex::directionType::rev, 500, vex::rotationUnits::deg);

    driveForward(1490);
    
  }
  else
  {

  }
  //while (Vision1.value() != Vision1.takeSnapshot(REDBALL);
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

void usercontrol(void) 
{ 
  while (1) 
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

     FrontLeftMotor.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value()) * rightStickYaxis, vex::velocityUnits::pct);
     BackLeftMotor.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value() + Controller1.Axis4.value())* rightStickYaxis, vex::velocityUnits::pct);
     FrontRightMotor.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value()) * rightStickYaxis, vex::velocityUnits::pct);
     BackRightMotor.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value() - Controller1.Axis4.value()) * rightStickYaxis, vex::velocityUnits::pct);
     
     if ( Controller1.ButtonR1.pressing() ) 
     {
        LeftBasketMotor.spin(vex::directionType::fwd, ArmSpeedPercent, vex::velocityUnits::pct);
        RightBasketMotor.spin(vex::directionType::fwd, ArmSpeedPercent, vex::velocityUnits::pct);
     }
     else if ( Controller1.ButtonR2.pressing() )
     {
        LeftBasketMotor.spin(vex::directionType::rev, ArmSpeedPercent, vex::velocityUnits::pct);
        RightBasketMotor.spin(vex::directionType::rev, ArmSpeedPercent, vex::velocityUnits::pct);
     }
     else 
     {
        LeftBasketMotor.stop( vex::brakeType::brake );
        RightBasketMotor.stop( vex::brakeType::brake );
     }     
  }
}



    
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................




//
// Main will set up the competition functions and callbacks.
//
int main() 
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous( autonomous );
  Competition.drivercontrol( usercontrol );

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while ( true ) 
  {
    wait( 100, msec );
  }
}
