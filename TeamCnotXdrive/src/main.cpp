/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Speedbot (4-motor Drivetrain, No Gyro)                    */
/*                                                                            */
/*    Name:                                                                   */
/*    Date:                                                                   */
/*    Class:                                                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <algorithm>

using namespace vex;

using code = vision::code;

controller Controller1;
competition Competition;
brain brain;
motor frontL = motor(PORT19, ratio18_1, false);
motor backL = motor(PORT6, ratio18_1, false);
motor frontR = motor(PORT12, ratio18_1, true);
motor backR = motor(PORT4, ratio18_1, true);
motor intake = motor(PORT15, ratio18_1, false);
motor flywheel = motor(PORT16, ratio18_1, true);
motor flywheel2 = motor(PORT10, ratio18_1, true);
motor rope = motor(PORT14, ratio18_1, false);
inertial Gyro = inertial(PORT9);
float flywheel_speed = 10;
int ropespin = 1;
int backropespin = 1;
motor_group flywheel3 = motor_group(flywheel, flywheel2);
motor_group leftdrive = motor_group(frontL, backL);
motor_group rightdrive = motor_group(frontR, backR);
smartdrive robot = smartdrive(leftdrive, rightdrive, Gyro, 12.566, 12, 8,
                              distanceUnits::in, 1);

void autonomous(void) {
  // auto for getting both rollers
  // + degrees is to the right
  // - degrees is to the left
  // 22 in = 2 feet/1 block/ 24 inches


  //the best auto ever created
  flywheel3.spinFor(directionType::rev, 2, rotationUnits::rev, 100,
                 velocityUnits::pct, false);
  robot.driveFor(directionType::rev, 10, distanceUnits::in, 50,
                  velocityUnits::pct);
  flywheel3.spinFor(directionType::rev, 2, rotationUnits::rev, 100,
                 velocityUnits::pct, false);
  robot.turnToHeading(-25, rotationUnits::deg, 25, velocityUnits::pct);
  flywheel3.spinFor(directionType::rev, 5, rotationUnits::rev, 100,
                 velocityUnits::pct, false);
  intake.spinFor(directionType::rev, 5, rotationUnits::rev, 100,
                  velocityUnits::pct);
  flywheel3.spinFor(directionType::rev, 2, rotationUnits::rev, 100,
                 velocityUnits::pct, false);
  robot.turnToHeading(-25, rotationUnits::deg, 25, velocityUnits::pct);
  flywheel3.spinFor(directionType::rev, 5, rotationUnits::rev, 100,


                 velocityUnits::pct, false);
  robot.driveFor(directionType::fwd, 10, distanceUnits::in, 50,
                  velocityUnits::pct, false);
  intake.spinFor(directionType::rev, 5, rotationUnits::rev, 100,
                  velocityUnits::pct);
/////////////////////////////////////////////////////////////////////////////
  flywheel.spinFor(directionType::rev, 2, rotationUnits::rev, 100,
                 velocityUnits::pct, false);
  robot.driveFor(directionType::rev, 10, distanceUnits::in, 50,
                  velocityUnits::pct);
  flywheel.spinFor(directionType::rev, 2, rotationUnits::rev, 100,
                 velocityUnits::pct, false);
  robot.turnToHeading(-25, rotationUnits::deg, 25, velocityUnits::pct);
  flywheel.spinFor(directionType::rev, 5, rotationUnits::rev, 100,
                 velocityUnits::pct, false);
  intake.spinFor(directionType::rev, 5, rotationUnits::rev, 100,
                  velocityUnits::pct);
  flywheel.spinFor(directionType::rev, 2, rotationUnits::rev, 100,
                 velocityUnits::pct, false);
  robot.turnToHeading(-25, rotationUnits::deg, 25, velocityUnits::pct);
  flywheel.spinFor(directionType::rev, 5, rotationUnits::rev, 100,
                 velocityUnits::pct, false);
  robot.driveFor(directionType::fwd, 10, distanceUnits::in, 50,
                  velocityUnits::pct, false);
  intake.spinFor(directionType::rev, 5, rotationUnits::rev, 100,
                  velocityUnits::pct);



}

void increasespeed(void){
  flywheel_speed = fmin(flywheel_speed + 1, 12);
}
void decreasespeed(void){
  flywheel_speed = fmax(flywheel_speed - 1, 6);
}

void userController(void) {
  while (1) {

    // drivebase stuff
   
    robot.arcade(Controller1.Axis3.position(), Controller1.Axis1.position());

    // intake control and colorwheel
    if (Controller1.ButtonR2.pressing()) {
      intake.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
    } else if (Controller1.ButtonR1.pressing()) {
      intake.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    } else {
      intake.stop(brakeType::brake);
    }


    
    // flywheel control
    if (Controller1.ButtonL2.pressing()) {
      //  flywheel.spin(vex::directionType::fwd, 73, vex::velocityUnits::pct);
       flywheel3.spin(vex::directionType::fwd, flywheel_speed, vex::voltageUnits::volt);
    } else {
      flywheel3.stop(brakeType::brake);
    }
  Controller1.Screen.setCursor(1,19);
  Controller1.Screen.print("%f", flywheel_speed);


 

    // rope control

    if (Controller1.ButtonA.pressing()) {
      rope.stop(brakeType::brake);

    }

    else if (Controller1.ButtonY.pressing()) {
      rope.spin(vex::directionType::fwd, 80, vex::velocityUnits::pct);

    }

    else if (Controller1.ButtonB.pressing()) {
      rope.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
    }
  }
}

int main() {
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(0,0);
  Controller1.Screen.print("Flywheel Voltage: ");
  Controller1.ButtonUp.pressed(increasespeed);
  Controller1.ButtonDown.pressed(decreasespeed);


  Competition.drivercontrol(userController);
  while (true) {
    wait(100, msec);
  }
}