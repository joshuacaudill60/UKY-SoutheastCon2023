#include <Servo.h>

// drive servos
Servo FrontLeft;  // Front left wheel servo
Servo FrontRight;	// Front right wheel servo
Servo BackLeft;		// Back left wheel servo
Servo BackRight;	// Back right wheel servo

// servo constants
const int MinPulse = 1000; // minimum 1000 microsecond pulses to servos
const int Stall = 1500;    // stall - 1500 microsecond pulses to servos
const int MaxPulse = 2000; // maximum 2000 microsecond pulses to servos

const int FRForward = MaxPulse; // right front servo
const int FRStopped = Stall;
const int FRBackward = MinPulse;

const int BRForward = MaxPulse; // right back servo
const int BRStopped = Stall;
const int BRBackward = MinPulse;

const int FLForward = MinPulse; // left front servo
const int FLStopped = Stall;
const int FLBackward = MaxPulse;

const int BLForward = MinPulse; // left back servo
const int BLStopped = Stall;
const int BLBackward = MaxPulse;

// attach servos to pins
void setup() {
  FrontLeft.attach(9);
  FrontRight.attach(10);
  BackLeft.attach(11);
  BackRight.attach(12);
}

// move the robot forward
void move_forward() {
  FrontLeft.write(FLForward);
  FrontRight.write(FRForward);
  BackLeft.write(BLForward);
  BackRight.write(BRForward);
  delay(2000);
}

// move the robot backward
void move_backward() {
  FrontLeft.write(FLBackward);
  FrontRight.write(FRBackward);
  BackLeft.write(BLBackward);
  BackRight.write(BRBackward);
  delay(2000);
}

// move the robot left
void move_left() {
  FrontLeft.write(FLBackward);
  FrontRight.write(FRForward);
  BackLeft.write(BLForward);
  BackRight.write(BRBackward);
  delay(2000);
}

// move the robot right
void move_right() {
  FrontLeft.write(FLForward);
  FrontRight.write(FRBackward);
  BackLeft.write(BLBackward);
  BackRight.write(BRForward);
  delay(2000);
}

// move the robot top left
void move_diag_top_left() {
  FrontLeft.write(FLStopped);
  FrontRight.write(FRForward);
  BackLeft.write(BLForward);
  BackRight.write(BRStopped);
  delay(2000);
}

// move the robot top right
void move_diag_top_right() {
  FrontLeft.write(FLForward);
  FrontRight.write(FRStopped);
  BackLeft.write(BLStopped);
  BackRight.write(BRForward);
  delay(2000);
}

// move the robot bottom left
void move_diag_bot_left() {
  FrontLeft.write(FLBackward);
  FrontRight.write(FRStopped);
  BackLeft.write(BLStopped);
  BackRight.write(BRBackward);
  delay(2000);
}

// move the robot bottom right
void move_diag_bot_right() {
  FrontLeft.write(FLStopped);
  FrontRight.write(FRBackward);
  BackLeft.write(BLBackward);
  BackRight.write(BRStopped);
  delay(2000);
}

// stop the robot
void stopped() {
  FrontLeft.write(FLStopped);
  FrontRight.write(FRStopped);
  BackLeft.write(BLStopped);
  BackRight.write(BRStopped);
  delay(2000);
}

void loop() {
  move_forward();
  move_diag_top_right();
  move_right();
  move_diag_bot_right();
  move_backward();
  move_diag_bot_left();
  move_left();
  move_diag_top_left();
}

//switch (var) {
//  case 8:
//    move_forward();
//    break;
//  case 6:
//    move_right();
//    break;
//  case 4:
//    move_left();
//    break;
//  case 2:
//    move_backward();
//    break;
//  default:
//    stopped();
//    break;
//}
