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

                                 // variables for the time delay
int Delay_1 = 35;
int Delay_2 = 25;

int BalancingAngle = 12;
int ExtremeAngle = 18;

boolean FirstCycle = true;      //Value true by default for executing first cycle
int x=10;                       // determine x for having a limited number of moving forward, can be changed according to user's convenience

//Functions

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

void Move_Forward()                                                               //forward movement function
{   
  if (FirstCycle)
  {
    for (int i = 0; i <=BalancingAngle ; i++ )                                     //angle updating for balancing at one leg
    { LeftAnkleJunc.write(LeftAnklePos-i);                                         //we can update either left foot or right foot first, left leg is used here 
      delay(Delay_1);}                                                             // here we have iteration using -i which depends her on orientation of servo motor

    delay(Delay_2);

    for (int i = 0; i <=BalancingAngle ; i++ )                                     //angle for the second leg is now updated so that its foot is parallel to the surface
    {RightAnkleJunc.write(RightAnklePos-i);                                        //here again we have iteration of -i because there is a change in orientation of motor from before
      delay(Delay_1);}                                                             //as well as we have to rotate in opposite direction so the effects cancel out 

    //Right Leg moves Forward

    for (int i = 0; i <=14 ; i++ )
    {
      RightHipJunc.write(RightHipPos+i);                                           //right leg is executing the first half(ellipse) of the gait cycle 
      RightKneeJunc.write(RightKneePos+5+i);                                       //increasing angle means lifting leg forward
      
      LeftHipJunc.write(LeftHipPos+i);                                             //left leg is executing the second half(straight line) of the gait cycle 
      LeftKneeJunc.write(LeftKneePos+5+i);                                         //due to change in orientation when compared from the right leg 
                                                                                   //we have to increase angle for moving the leg in backward direction
      delay(Delay_1);}

    delay(Delay_2);
  }

  else
  {
    //Left leg moves forward 
    for (int i = 0; i <= 30; i++ ) 
    {
      RightHipJunc.write(RightHipPos-13+i);                                         //right leg is executing the second half(straight line) of the gait cycle                                        
      RightKneeJunc.write(RightKneePos-22+i);                                       //increasing angle here means we are traversing the current gait cycle 
                                                                                    //minor changes in angle values to provide necessary torque from surface
      LeftHipJunc.write(LeftHipPos-13+i);                                           //left leg is executing the first half(ellipse) of the gait cycle 
      LeftKneeJunc.write(LeftKneePos-22+i);                                         //due to change in orientation when compared from the right leg 
      delay(Delay_1);}                                                              //we have to increase angle for moving the left leg in forward direction
  } 

  delay(Delay_2);

    //Balancing using ankle servos
    for (int i = 0; i <=BalancingAngle+ExtremeAngle ; i++ )                              //angle updating for balancing at one leg
    {                                                                                    //first servos are pushed to extreme angle for generation of tilting torque
      LeftAnkleJunc.write(LeftAnklePos-ExtremeAngle+i);                                  //increasing in both cases due to different orientations and different rotations                                             
      RightAnkleJunc.write(RightAnklePos-ExtremeAngle+i);                                //angle for the second foot follows that of the first foot
      delay(Delay_1);}                                                                   //angle for the second leg is now updated so that its foot is parallel to the surface

  delay(Delay_2);

  //Right Leg moves Forward

  for (int i = 0; i <=29 ; i++ )
  {
    LeftHipJunc.write(LeftHipPos+12-i);                                           //left leg is executing the second half(straight line) of the gait cycle 
    LeftKneeJunc.write(LeftKneePos+13-i);                                         //decreasing angle here means we are traversing the current gait cycle 
                                                                                  //minor changes in angle values to provide necessary torque from surface
    RightHipJunc.write(RightHipPos+12-i);                                         //right leg is executing the first half(ellipse) of the gait cycle 
    RightKneeJunc.write(RightKneePos+13-i);                                       //due to change in orientation when compared from the right leg 
                                                                                  //we have to decrease angle for moving the right leg in forward direction
    delay(Delay_1);
  }

  delay(Delay_2);

  //Balancing using ankle servos
  for (int i = 0; i <=BalancingAngle+ExtremeAngle ; i++ )                              //angle updating for balancing at one leg
  {                                                                                   //first servos are pushed to extreme angle for generation of tilting torque
    RightAnkleJunc.write(RightAnklePos+ExtremeAngle-i);                               //decreasing in both cases due to different orientations and different rotations 
    LeftAnkleJunc.write(LeftAnklePos+ExtremeAngle-i);                                 //angle for the second foot follows that of the first foot
    delay(Delay_1);                                                                   //angle for the second leg is now updated so that its foot is parallel to the surface
   }

  delay(Delay_2);

  FirstCycle = false;

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
  delay(3000);                                                          //delay 3 seconds

  
  for (int i = 0; i <x; i++)                                            //Walks forward for a limited number of times
  {
    Move_Forward();} 
    delay(1000);

  StandingPosition();                                                   //reverting back to equilibrium
      
}

// Loop gets executed continously
void loop()
{
  
 }
