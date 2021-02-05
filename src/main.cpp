/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template k                                     */
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



/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
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

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
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

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
      //mecanum draft one//
      
     /*FrontLeftMotor = Axis3 + Axis1 + Axis4;
     BackLeftMotor = Axis3 + Axis1 - Axis4;
     FrontRightMotor = Axis3 - Axis1 - Axis4;
     BackRightMotor = Axis3 - Axis1 + Axis4;*/

     //mecanum//
     
     
      /* */
       int leftStickXaxis = Controller1.Axis4.value();
       int rawStrafeInput = leftStickXaxis;


       int rightStickYaxis = (Controller1.Axis2.value() + 126) / 62.5;

       // defining variables with Quincy
     // strafe = left stick x-axis
     // drive = left stick y-axis
     // turn = right stick x-axis
     /* */  

     FrontLeftMotor.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value() - Controller1.Axis4.value()) * rightStickYaxis, vex::velocityUnits::pct);
     BackLeftMotor.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis1.value() + Controller1.Axis4.value())* rightStickYaxis, vex::velocityUnits::pct);
     FrontRightMotor.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value() + Controller1.Axis4.value()) * rightStickYaxis, vex::velocityUnits::pct);
     BackRightMotor.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis1.value() - Controller1.Axis4.value()) * rightStickYaxis, vex::velocityUnits::pct);
     
    }
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
//code I found online relating to the wheels(commented out for now)
/*int x1 = THRESHOLD(vexRT[Ch4], 15);
    int y1 = THRESHOLD(vexRT[Ch3], 15);
    int x2 = THRESHOLD(vexRT[Ch1], 15);
    int y2 = THRESHOLD(vexRT[Ch2], 15);
  int yComp = ((abs(y1) > abs(y2)) ? y1 : y2);
  int turnComp = ((abs(x2) == 0) ? x1/2 : x1);
  int strafeComp = ((abs(x1) == 0) ? x2/2 : x2);
    output_Left_Front = LIMIT(127, -127, yComp + turnComp + strafeComp);
    output_Left_Rear = LIMIT(127, -127, yComp + turnComp - strafeComp);
    output_Right_Front = LIMIT(127, -127, yComp - turnComp - strafeComp);
    output_Right_Rear = LIMIT(127, -127, yComp - turnComp + strafeComp);*/

/*int chAddition = Ch3 + Ch1 + Ch4;
chAddition = abs(chAddition) > 127 ? sgn(chAddition) * 127 : chAddition;
**int motorValue = (int) (pow(chAddition, 2) / 127);**
motor[FrontRightMotor] = motorValue > DEADZONE ? sgn(chAddition) * motorValue : 0;*/
