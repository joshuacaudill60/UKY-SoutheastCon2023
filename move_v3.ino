#include <Servo.h>

// drive servos
Servo FL;  // Front left wheel servo
Servo FR;	// Front right wheel servo
Servo BL;		// Back left wheel servo
Servo BR;	// Back right wheel servo

// servo constants
const int MinPulse = 1000; // minimum 1000 microsecond pulses to servos
const int Stall = 1500;    // stall - 1500 microsecond pulses to servos
const int MaxPulse = 2000; // maximum 2000 microsecond pulses to servos

const int FLForward = MaxPulse; // left front servo
const int FLStopped = Stall;
const int FLBackward = MinPulse;

const int FRForward = MinPulse; // right front servo
const int FRStopped = Stall;
const int FRBackward = MaxPulse;

const int BLForward = MaxPulse; // left back servo
const int BLStopped = Stall;
const int BLBackward = MinPulse;

const int BRForward = MinPulse; // right back servo
const int BRStopped = Stall;
const int BRBackward = MaxPulse;






// attach servos to pins
void setup ()
{
  FL.attach (9);
  FR.attach (10);
  BL.attach (11);
  BR.attach (12);

  Serial.begin (9600); // Send and receive at 9600 baud
} // END setup






void loop ()
{
  if (Serial.available ())
  {
    char ch = (char) Serial.read (); 
    switch (ch)
    {
      case '9':
        move_diag_top_right ();
        break;
        
      case '8':
        move_forward ();
        break;
        
      case '7':
        move_diag_top_left ();
        break;
        
      case '6':
        move_right ();
        break;
        
      case '5':
        stopped ();
        break;
        
      case '4':
        move_left ();
        break;
        
      case '3':
        move_diag_bot_right ();
        break;
        
      case '2':
        move_backward ();
        break;
        
      case '1':
        move_diag_bot_left ();
        break; 

      case '>':
        move_cw();
        break;
      
      case '<':
        move_ccw ();
        break;
          
      default:
        stopped ();
        break;    
    }
  } 
} // END loop






// move the robot forward
void move_forward ()
{
  FL.writeMicroseconds (FLForward);
  FR.writeMicroseconds (FRForward);
  BL.writeMicroseconds (BLForward);
  BR.writeMicroseconds (BRForward);
} // END move_forward



// move the robot backward
void move_backward ()
{
  FL.writeMicroseconds (FLBackward);
  FR.writeMicroseconds (FRBackward);
  BL.writeMicroseconds (BLBackward);
  BR.writeMicroseconds (BRBackward);
} // END move_backward



// move the robot left
void move_left ()
{
  FL.writeMicroseconds (FLBackward);
  FR.writeMicroseconds (FRForward);
  BL.writeMicroseconds (BLForward);
  BR.writeMicroseconds (BRBackward);
} // END move_left



// move the robot right
void move_right ()
{
  FL.writeMicroseconds (FLForward);
  FR.writeMicroseconds (FRBackward);
  BL.writeMicroseconds (BLBackward);
  BR.writeMicroseconds (BRForward);
} // END move_right



// move the robot top left
void move_diag_top_left ()
{
  FL.writeMicroseconds (FLStopped);
  FR.writeMicroseconds (FRForward);
  BL.writeMicroseconds (BLForward);
  BR.writeMicroseconds (BRStopped);
} // END move_diag_top_left



// move the robot top right
void move_diag_top_right ()
{
  FL.writeMicroseconds (FLForward);
  FR.writeMicroseconds (FRStopped);
  BL.writeMicroseconds (BLStopped);
  BR.writeMicroseconds (BRForward);
} // END move_diag_top_right



// move the robot bottom left
void move_diag_bot_left ()
{
  FL.writeMicroseconds (FLBackward);
  FR.writeMicroseconds (FRStopped);
  BL.writeMicroseconds (BLStopped);
  BR.writeMicroseconds (BRBackward);
} // END move_diag_bot_left



// move the robot bottom right
void move_diag_bot_right ()
{
  FL.writeMicroseconds (FLStopped);
  FR.writeMicroseconds (FRBackward);
  BL.writeMicroseconds (BLBackward);
  BR.writeMicroseconds (BRStopped);
} // END move_diag_bot_right



// stop the robot
void stopped ()
{
  FL.writeMicroseconds (FLStopped);
  FR.writeMicroseconds (FRStopped);
  BL.writeMicroseconds (BLStopped);
  BR.writeMicroseconds (BRStopped);
} // END stopped



// move the robot clockwise
void move_cw ()
{
  FL.writeMicroseconds (FLForward);
  FR.writeMicroseconds (FRBackward);
  BL.writeMicroseconds (BLForward);
  BR.writeMicroseconds (BRBackward);
} // END move_cw



// move the robot counter clockwise
void move_ccw ()
{
  FL.writeMicroseconds (FLBackward);
  FR.writeMicroseconds (FRForward);
  BL.writeMicroseconds (BLBackward);
  BR.writeMicroseconds (BRForward);
} // END move_ccw
