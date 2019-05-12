
/*
Line-Follower
Drives robot in intervals forward, backward, left and right,
depending on IR sensor inputs.
Inputs: Serial Port
Outputs: +5V, GND, Pin 4, Pin 5, Pin 6, Pin 7
Date: Nov 15, 2013
*/

#include <Servo.h> // sets library for code

Servo LeftServo;
Servo RightServo;// sets label for servo motor

void forward();
void backward();
void turnleft();
void turnright();

void setup() {
LeftServo.attach(4);
RightServo.attach(5); // attaches servo for Pin 5
pinMode(6, INPUT);
pinMode(7, INPUT);
Serial.begin(9600);
}

void loop() {

int LeftSensor;
int RightSensor;

LeftSensor = digitalRead(6);
RightSensor = digitalRead(7);
Serial.print("LED is reading:  ");
Serial.print(LeftSensor);
Serial.print(" ");
Serial.print(RightSensor);

if((LeftSensor == 0) & (RightSensor == 0)){
 forward();
}
else if((LeftSensor == 0) & (RightSensor == 1)){
 turnright();
}
else if((LeftSensor == 1) & (RightSensor == 0)){
 turnleft();
}
else{
 forward();
}
}

void backward(){
LeftServo.write(5);
RightServo.write(120);
Serial.print(" ");
Serial.println("Backward");
//delay(100);
}

void forward(){
LeftServo.write(120);
RightServo.write(5);
Serial.print(" ");
Serial.println("Forward");
//delay(100);
}

void turnright(){
LeftServo.write(120);
RightServo.write(120);
Serial.println("Turn Left");
//delay(100);
}

void turnleft(){
LeftServo.write(5);
RightServo.write(5);
Serial.println("Turn Right");
//delay(100);
}
