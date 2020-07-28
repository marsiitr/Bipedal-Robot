#include <Servo.h>       //include servo library

//Creating servo objects    
Servo LeftAnkleJunc;
Servo RightAnkleJunc;
Servo LeftHipJunc;
Servo RightHipJunc;
Servo LeftKneeJunc;
Servo RightKneeJunc;

//Global Variables
// Setting initial position values for each motor   
   
int LeftAnklePos = 85;  
int RightAnklePos = 98;            // for initial position I am adjusting servo motors according to Bot's standing position
int LeftHipPos = 74;              
int RightHipPos = 82;
int LeftKneePos = 99;
int RightKneePos = 103;

void StandingPosition()                                  //Standing equilibrium position for all motors
{
  LeftAnkleJunc.write(LeftAnklePos);
  RightAnkleJunc.write(RightAnklePos);                    // Updates the servo objects to the standing equilibrium positions
  LeftHipJunc.write(LeftHipPos);                          
  RightHipJunc.write(RightHipPos);                        
  LeftKneeJunc.write(LeftKneePos);                        
  RightKneeJunc.write(RightKneePos);                      
  delay(1500);
}

// Set up(gets executed only once)
void setup()
{
  

                                                                        //setting output for motors
  LeftAnkleJunc.attach(11);                                             // attaches the servo on pin 9 to the servo object
  RightAnkleJunc.attach(10);                                            // attaches the servo on pin 4 to the servo object
  LeftHipJunc.attach(9);                                                // attaches the servo on pin 11 to the servo object
  RightHipJunc.attach(6);                                               // attaches the servo on pin 6 to the servo object
  LeftKneeJunc.attach(5);                                               // attaches the servo on pin 10 to the servo object
  RightKneeJunc.attach(3);                                              // attaches the servo on pin 5 to the servo object



  StandingPosition();                                                   //equilibrium position

}

// Loop gets executed continously
void loop() 
{
  
  }
