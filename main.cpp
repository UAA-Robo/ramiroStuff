/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Riotu                                                     */
/*    Created:      Fri Oct 07 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include <iostream>

using namespace vex;
//using namespace std;
// A global instance of competition


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

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}


void activate_motor(int axis){
  if (axis == 1){
    goForward1;
  } else if (axis == 3){
    goForward3;
  }
}

void goForward1(){
  int velocity = Contro.Axis1.position();
  Motro.setVelocity(velocity, percent);
  Motro.spin(forward);
  wait(10, msec);
  Brain.Screen.print("It's 1");
  Brain.Screen.clearLine();
}


void goForward3(){
  int velocity = Contro.Axis3.position();
  Motro.setVelocity(velocity, percent);
  Motro.spin(forward);
  wait(10,msec);
  Brain.Screen.print("It's 3");
  Brain.Screen.clearLine();
}

//
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
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
void stop(void){
  Motro.stop();
}

void usercontrol(void) {

  // User control code here, inside the loop
  

    Contro.Axis1.changed(goForward1);
    Contro.Axis3.changed(goForward3);
    //Contro.ButtonA.pressed(goForward);
    //Contro.ButtonX.released(stop);
    //Contro.Axis1.position();


    // else if(not(Contro.ButtonX.pressing())){
    //   std::cout << "herein" << std::endl;
    // }
    
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  
}



// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  //Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  usercontrol();
  //double rando = 100;
  // Run the pre-autonomous function.
  //pre_auton();

  // Prevent main from exiting with an infinite loop.
  /*while (true) {
    Motro.setVelocity(rando,percent);
    Motro.spin(forward);*/
  wait(20, msec);
}
