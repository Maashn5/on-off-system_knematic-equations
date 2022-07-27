# on-off-system_knematic-equations
## on off system 
in on off systems by using a push button, with a single change (on or off) with every push 
<br/> with keeping the new state when release the button
<br/> The flipflop sounds the perfect solution, precisouly the T flipflop
<br/> The T flipflop change the output state when the toggle is high , and keep it when the toggle is low 
<br/> T flipflop truth table : 
<br/>![alt text](https://www.allaboutcircuits.com/uploads/articles/TB_TFF_3.JPG)
<br/> Since tinkercad doesn't support T-flipflop, we will use the j-k flipflop
<br/> J-K truth table :
<br/> ![alt text](https://i.stack.imgur.com/dBc8x.gif)
<br/> From the J-K truth table, we can convert J-K flipflop to T flipflop 
<br/> by shorted the J & K inputs to be one input represent the T input 
<br/> For the clock pin the flipflop will not work unless it detect a rising edge from the clock pin 
<br/> ![alt text](https://electricalnotebook.com/wp-content/uploads/2022/05/image-49.png)
<br/> Since the flipflop need a rising edge to activate the clock ,so we need a clock signal to activate the clock pin,
<br/> So we need to 555 timer or oscliation signal.
<br/> there is an alternative solution, since we need a rising edge in the clock to activate the flipflop
<br/> Otherwise nothing will happen , so if we keep the T input (j,k input) always high
<br/> And connect the push button to the clock ,so when the push button is pressed the rising edge will activate the
<br/> clock pin & the flipflop ,since the T is always high this will change the state of the output.
<br/> The reset pin we will keep it high so there will be no resets.
<br/> When the output is high this will activate the nmos transistor, thus the relay will be activated,   
<br/> thus the load will be activated too , there is a diode connected in parallel & reverse connection 
<br/> to protect the relay from reverse current.
<br/> Here is the circuit
<br/> ![alt text](https://github.com/Maashn5/on-off-system_knematic-equations/blob/main/on%20off%20system.png)
<br/> [Here is the simulation link for the circuit](https://www.tinkercad.com/things/h2Qnr8GqlwS?sharecode=uJGjH094gYhzXHnRIB97MQHVZjRLOgiVTZa7BDeb5bo)
## kinematic equation
The kinematic equation showed the relation between the coordinates of the end effect of the robot arm
<br/> and the angles of the joint .
<br/> we can find it by using the trigonometric formulas & and here a full guide to how we obtain it.
[full solution for getting up the equations](https://github.com/Maashn5/on-off-system_knematic-equations/blob/main/arm_position/Robot%20arm%20Position_%20Calculations.pdf)
<br/> But we know that our servo can't rotate 180 degree & our links has finite length , so for a specific system 
<br/> what is the posiible outcomes , by doing some simulations by using [Geogebra geometery](https://www.geogebra.org/geometry) (once I assumed L1=10 , L2=20) ![alt text](https://github.com/Maashn5/on-off-system_knematic-equations/blob/main/arm_position/set%20od%20position.jpg)
<br/> here is a simulation for the arm , such that:
*the semicircle represent the 180 degree joint's angle
*the radius represent the lenght of the link 
*the point A:represent the first joint's location (A is the center of the fist semicirle)
*E:represent the second joint's location ( E are free to move on the first semicircle) (E is the center of the second semicircle)
*H: represent the end effector (H are free to move on the second semicircle)
* the first semicircle : represent the set of the possible outcomes for second joint's locations
* the second semicircle: represent the set of the possible outcomes for the end effect's locations
* the bigger circle : represent the farther leangth that the arm can't cross it . 
<br/> then by rotate the point E around the first semicircle and showing the trace of the seccond semicircle,
<br/> we will show the set of the possible locations for the end effector
<br/> ![alt text](https://github.com/Maashn5/on-off-system_knematic-equations/blob/main/arm_position/range%20of%20the%20arm.jpg)
<br/> by repeting the process for different links' lengths ( here L1=10 , L2=5) 
<br/> ![alt text](https://github.com/Maashn5/on-off-system_knematic-equations/blob/main/arm_position/range%20of%20arm.jpg)
<br/> we will notice that the range differs with the difference of the links' leangth 
<br/> we can conclude two conditions:
* we must check the inputs for the inverse trigonometric functions to be between -1,1 
* we must make sure that the angles are between 0,180
<br/> Here is the circuit 
<br/> ![alt text](https://github.com/Maashn5/on-off-system_knematic-equations/blob/main/arm_position/robot%20arm%20position.png)
<br/> Here is the cod 
```c++
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
```
<br/> [Here is the simulation link for the circuit](https://www.tinkercad.com/things/euq51ZJ6Y1S?sharecode=VZaXnRk_98ymOqStoC5CIJiVp37TUG4FMYykL6rEzIw)
