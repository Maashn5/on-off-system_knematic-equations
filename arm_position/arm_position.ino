#include <Servo.h>

#define PI 3.1415926535897932384626433832795

Servo servo1;
Servo servo2;

// the coordinates
float x;
float y;

// the angle of the servo motors
float theta1;
float theta2; 

float a;

float L1;
float L2;



void setup() {
  
servo1.attach(5);
servo2.attach(6);

// set the servo to their initial position  
servo1.write(0);
servo2.write(0);

//To get the angle from the serial monitor 
Serial.begin(9600);

Serial.setTimeout(10);  

Serial.print("write the leangth of the first link ");
while (Serial.available()==0) {}   // waiting to receiving the coordinate   
L1=Serial.parseFloat();// raed the leangth as float
Serial.print(L1);  
Serial.print("\n");  

Serial.print("write the leangth of the seccond link ");
while (Serial.available()==0) {}   // waiting to receiving the coordinate   
L2=Serial.parseFloat();// raed the leangth as float
Serial.print(L2);  
Serial.print("\n");  

}

void loop() {
  // reading the coordinates from the serial monitor
Serial.print("write the value of the x coordinate ");
while (Serial.available()==0) {}   // waiting to receiving the coordinate   
x=Serial.parseFloat();// raed the coordinate as float
  
Serial.print(x);
  
Serial.print("\n");
  
Serial.print("write the value of the y coordinate ");
while(Serial.available()==0){} // waiting to receiving the coordinate 
y=Serial.parseFloat(); // raed the coordinate as float
  
Serial.print(y);  
  
Serial.print("\n");

// calculating the angle using the the formela

//first we must check that what inside the arccos is not bigger than 1 or less than -1

a=(pow(x,2)+pow(y,2)-pow(L1,2)-pow(L2,2))/(2*(L1)*(L2));

if (a>=-1 && a<=1){

theta2= acos(a);

//first we must check that what inside the arccos is not bigger than 1 or less than -1 
//the term x/sqrt(x^2+y^2) is always in the interval [-1,1] so no need to check it 
a=(pow(x,2)+pow(y,2)+pow(L1,2)-pow(L2,2))/(2*(L1)*(sqrt(pow(x,2)+pow(y,2))));
if (a>=-1 && a<=1){
theta1= acos(x/(sqrt(pow(x,2)+pow(y,2))))-acos(a);


//convert the angles from radian to degree

theta1= theta1*180/PI;

theta2= theta2*180/PI;

// since the servo motor move to angle between 0 & 180, so we must check that the angles is in this interval
// or the arm won't go the right position 

if (theta1>=0 && theta1<=180 && theta2>=0 && theta2<=180){ 

// moving the arm to its position

servo1.write(theta1);
servo2.write(theta2);
  
Serial.print("\n");

Serial.print(theta1);
Serial.print(" , ");  
Serial.print(theta2);  
  
Serial.print("\n");  }else{Serial.print("this coordinates is out of the arm's range, it isn't reachable ");
 Serial.print("\n"); }

}else{Serial.print("this coordinates is out of the arm's range, it isn't reachable");
 Serial.print("\n");    }
}else{Serial.print("this coordinates is out of the arm's range, it isn't reachable");
     Serial.print("\n");}
}
