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

using namespace vex;

using code = vision::code;

controller Controller1;
competition Competition;
brain brain;

motor frontL = motor(PORT19, ratio18_1,false);
motor backL = motor(PORT6, ratio18_1,false);
motor frontR = motor(PORT12, ratio18_1,false);
motor backR = motor(PORT4, ratio18_1,false);
motor intake = motor(PORT15, ratio18_1,false);
motor flywheel = motor(PORT16, ratio18_1,false);
motor color_wheel = motor(PORT2, ratio18_1,false);
motor rope = motor(PORT14, ratio18_1,false);
int ropespin = 1;
int backropespin = 1;
drivetrain leftTrain = drivetrain(frontL, backL);
drivetrain rightTrain = drivetrain(frontR, backR);
drivetrain intakeTrain = drivetrain(intake, intake);
drivetrain shootTrain = drivetrain(flywheel, flywheel);
drivetrain colorTrain = drivetrain(color_wheel, color_wheel);






void autonomous(void){
//auto for getting both rollers
rightTrain.driveFor(directionType::rev, 21, distanceUnits::in, 100, velocityUnits::pct,false);
leftTrain.driveFor(directionType::fwd, 21, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
rightTrain.driveFor(directionType::fwd, 13, distanceUnits::in, 100, velocityUnits::pct,false);
leftTrain.driveFor(directionType::fwd, 13, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100);
rightTrain.driveFor(directionType::fwd, 10, distanceUnits::in, 80, velocityUnits::pct,false);
leftTrain.driveFor(directionType::rev, 10, distanceUnits::in, 80, velocityUnits::pct, false);
colorTrain.driveFor(directionType::rev, 100, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
rightTrain.driveFor(directionType::rev, 3, distanceUnits::in, 100, velocityUnits::pct,false);
leftTrain.driveFor(directionType::fwd, 3, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
rightTrain.driveFor(directionType::fwd, 6, distanceUnits::in, 100, velocityUnits::pct,false);
leftTrain.driveFor(directionType::fwd, 6, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100);
rightTrain.driveFor(directionType::rev, 200, distanceUnits::in, 50, velocityUnits::pct,false);
leftTrain.driveFor(directionType::fwd, 200, distanceUnits::in, 50, velocityUnits::pct,false);
intakeTrain.driveFor(directionType::rev, 80, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
leftTrain.driveFor(directionType::fwd, 12, distanceUnits::in, 100, velocityUnits::pct,false);
rightTrain.driveFor(directionType::fwd, 12, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
shootTrain.driveFor(directionType::fwd, 30, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
shootTrain.driveFor(directionType::fwd, 30, distanceUnits::in, 100, velocityUnits::pct, false);
intakeTrain.driveFor(directionType::rev, 80, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
leftTrain.driveFor(directionType::rev, 20, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
rightTrain.driveFor(directionType::rev, 20, distanceUnits::in, 100, velocityUnits::pct,false);
leftTrain.driveFor(directionType::fwd, 20, distanceUnits::in, 100, velocityUnits::pct, false);
intakeTrain.driveFor(directionType::rev, 80, distanceUnits::in, 100, velocityUnits::pct);
// vex::task::sleep(100); 
// rightTrain.driveFor(directionType::fwd, 5, distanceUnits::in, 100, velocityUnits::pct,false);
// leftTrain.driveFor(directionType::rev, 5, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
leftTrain.driveFor(directionType::fwd, 20, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
shootTrain.driveFor(directionType::fwd, 30, distanceUnits::in, 100, velocityUnits::pct, false);
intakeTrain.driveFor(directionType::rev, 80, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
leftTrain.driveFor(directionType::rev, 20, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
rightTrain.driveFor(directionType::rev, 40, distanceUnits::in, 100, velocityUnits::pct,false);
leftTrain.driveFor(directionType::fwd, 40, distanceUnits::in, 100, velocityUnits::pct, false);
intakeTrain.driveFor(directionType::rev, 80, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
rightTrain.driveFor(directionType::rev, 9.5, distanceUnits::in, 100, velocityUnits::pct,false);
leftTrain.driveFor(directionType::rev, 9.5, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
colorTrain.driveFor(directionType::fwd, 100, distanceUnits::in, 100, velocityUnits::pct);

 /*
//auto for non roller side
rightTrain.driveFor(directionType::rev, 1, distanceUnits::in, 100, velocityUnits::pct,false);
leftTrain.driveFor(directionType::fwd, 1, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
rightTrain.driveFor(directionType::fwd, 15, distanceUnits::in, 100, velocityUnits::pct,false);
leftTrain.driveFor(directionType::fwd, 15, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100);
rightTrain.driveFor(directionType::rev, 10, distanceUnits::in, 100, velocityUnits::pct,false);
leftTrain.driveFor(directionType::fwd, 10, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100); 
rightTrain.driveFor(directionType::rev, 9.5, distanceUnits::in, 100, velocityUnits::pct,false);
leftTrain.driveFor(directionType::rev, 9.5, distanceUnits::in, 100, velocityUnits::pct);
vex::task::sleep(100);
rightTrain.driveFor(directionType::fwd, 5, distanceUnits::in, 100, velocityUnits::pct,false);
leftTrain.driveFor(directionType::rev, 5, distanceUnits::in, 100, velocityUnits::pct, false);
colorTrain.driveFor(directionType::fwd, 100, distanceUnits::in, 100, velocityUnits::pct);
 */
}



void userController(void) 
{
  while (1) 
  {


  backL.spin(vex::directionType::fwd, Controller1.Axis3.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
  frontL.spin(vex::directionType::fwd, Controller1.Axis3.value() + Controller1.Axis1.value(), vex::velocityUnits::pct);
  backR.spin(vex::directionType::rev, Controller1.Axis3.value() - Controller1.Axis1.value(), vex::velocityUnits::pct);
  frontR.spin(vex::directionType::rev, Controller1.Axis3.value()- Controller1.Axis1.value(), vex::velocityUnits::pct);

  
  //North East
 

  //intake control
  if (Controller1.ButtonR2.pressing()){
    intake.spin(vex::directionType::rev, 100, vex::velocityUnits::pct); 
  }
  else if (Controller1.ButtonR1.pressing()){
    intake.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct); 
  }
  else
  {
    intake.stop(brakeType::brake);
  }

  //flywheel control
  if (Controller1.ButtonL2.pressing())
  {
    flywheel.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
  }
  else
  {
    flywheel.stop(brakeType::brake);
  }

  //colorwheel control
  if (Controller1.ButtonL1.pressing())
  {
    color_wheel.spin(vex::directionType::rev  , 100, vex::velocityUnits::pct);
  }
  else if (Controller1.ButtonDown.pressing())
  {
    color_wheel.spin(vex::directionType::fwd  , 100, vex::velocityUnits::pct);
  }
  else
  {
    color_wheel.stop(brakeType::brake);
  }

  //left corner aim
  if (Controller1.ButtonA.pressing()){
    Brain.Timer.reset();
      wait(100, msec);
        for(int i = 3; i < Brain.Timer.value(); i++)
        {
          backL.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
          frontL.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
          backR.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
          frontR.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
        }
      wait(100, msec);
    break;
  }
   //right corner aim
  if (Controller1.ButtonB.pressing()){
    Brain.Timer.reset();
      wait(100, msec);
        for(int i = 3; i < Brain.Timer.value(); i++)
        {
          backL.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
          frontL.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
          backR.spin(vex::directionType::fwd, 50, vex::velocityUnits::pct);
          frontR.spin(vex::directionType::rev, 50, vex::velocityUnits::pct);
        }
      wait(100, msec);
    break;
  }
  //rope control
  if (Controller1.ButtonY.pressing())
  {
    backropespin = 1;
    ropespin = ropespin + 1;
    if (ropespin %2 == 0 )
    {
      rope.stop(brakeType::brake);
      }

    else
      {
      rope.spin(vex::directionType::fwd, 25, vex::velocityUnits::pct);
      }
  }

if (Controller1.ButtonX.pressing())
  {
    ropespin = 1;
    backropespin = backropespin + 1;
    if (ropespin %2 == 0 )
    {
      rope.stop(brakeType::brake);
      }

    else
      {
      rope.spin(vex::directionType::rev, 100, vex::velocityUnits::pct);
      }
  }



 
  }
  
}


int main(){
  Competition.drivercontrol(userController);
 while (true){
 wait(100, msec);
 }
}