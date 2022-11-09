/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\johnf                                            */
/*    Created:      Tue Oct 18 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

using code = vision::code;

controller Controller1;
competition Competition;
brain brain;

motor frontL = motor(PORT18, ratio18_1,false);
motor backL = motor(PORT19, ratio18_1,false);
motor frontR = motor(PORT12, ratio18_1,false);
motor backR = motor(PORT11, ratio18_1,false);
motor intake = motor(PORT15, ratio18_1,false);
motor flywheel = motor(PORT16, ratio18_1,false);
motor color_wheel = motor(PORT13, ratio18_1,false);
motor rope = motor(PORT2, ratio18_1,false);

int x = 0;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while (1)
  {
    x = x + 1; 
    wait(1, seconds);
  }

}
