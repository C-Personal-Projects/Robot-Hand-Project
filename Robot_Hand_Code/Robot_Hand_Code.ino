#include<Servo.h>

//Pins for servis on arduino
int servoPin1 = 3;
int servoPin2 = 4;
int servoPin3 = 5;
int servoPin4 = 6;
int servoPin5 = 7;

int servoPin6 = 8;
int servoPin7 = 9;
int servoPin8 = 10;
int servoPin9 = 11;
int servoPin10 = 12;

//Increment for rotating servo
int angleStep = 2;

//Angles for corresponding servos
int angle1 = 0;
int angle2 = 0;
int angle3 = 0;
int angle4 = 0;
int angle5 = 0;

int pos1 = 90;
int pos2 = 90;
int pos3 = 90;
int pos4 = 90;
int pos5 = 90;


//Joystick 1 (X and Y axis)
int x_pin1 = A0;
int y_pin1 = A1;

//Joystick 2 (X and Y axis)
int x_pin2 = A2;
int y_pin2 = A3;



#define BUTTON1 1
#define BUTTON2 2

//Setting up servos
Servo s1;
Servo s2;
Servo s3;
Servo s4;
Servo s5;

Servo s6;
Servo s7;
Servo s8;
Servo s9;
Servo s10;


void setup() { 

 //Set up baudrate
 Serial.begin(500000);

 //Setup servos to corresponding pins
 s1.attach(servoPin1);
 s2.attach(servoPin2);
 s3.attach(servoPin3);
 s4.attach(servoPin4);
 s5.attach(servoPin5);

 s6.attach(servoPin6);
 s7.attach(servoPin7);
 s8.attach(servoPin8);
 s9.attach(servoPin9);
 s10.attach(servoPin10);

 //Setup for buttons
 pinMode(BUTTON1, INPUT_PULLUP);
 pinMode(BUTTON2, INPUT_PULLUP);

 //Setting default position on servos
 s1.write(angle1);
 s2.write(angle2);
 s3.write(angle3);
 s4.write(angle4);
 s5.write(angle5);

 s6.write(pos1);
 s7.write(pos2);
 s8.write(pos3);
 s9.write(pos4);
 s10.write(pos5);

 //Setup for joysticks
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);
 pinMode(A2, INPUT);
 pinMode(A3, INPUT);
 
}

void loop() {

  //Reading X and Y axis of Joystick 1
  int x_data1 = analogRead(A0);
  int y_data1 = analogRead(A1);

  //Reading X axis of Joystick 2
  int x_data2 = analogRead(A2);
  int y_data2 = analogRead(A3);

  //Ran when button1 is pressed
  while(digitalRead(BUTTON1) == LOW)
  {
    //Updates servos with defined step (closing finger)
    angle1 = angle1 + angleStep;
    angle2 = angle2 + angleStep;
    angle3 = angle3 + angleStep;
    angle4 = angle4 + angleStep;
    angle5 = angle5 + angleStep;
    
    //Makes sure angle is not set over the max
    if(angle1 > 180)
    {
      angle1 = 180;
    }
    else//Sets angle for the first finger servo
    {
      s1.write(angle1);
    }

    //Makes sure angle is not set over the max
    if(angle2 > 180)
    {
      angle2 = 180;
    }
    else//Sets angle for the second finger servo
    {
      s2.write(angle2);
    }

    //Makes sure angle is not set over the max
    if(angle3 > 180)
    {
      angle3 = 180;
    }
    else//Sets angle for the third finger servo
    {
      s3.write(angle3);
    }

    //Makes sure angle is not set over the max
    if(angle4 > 180)
    {
      angle4 = 180;
    }
    else//Sets angle for the fourth finger servo
    {
      s4.write(angle4);
    }

    //Makes sure angle is not set over the max
    if(angle5 > 180)
    {
      angle5 = 180;
    }
    else//Sets angle for the fifth finger servo
    {
      s5.write(angle5);
    }

    delay(10);
  }

  //Ran when Button2 is pressed
  while(digitalRead(BUTTON2) == LOW)
  {
    //Updates servos with defined step (opening finger)
    angle1 = angle1 - angleStep;
    angle2 = angle2 - angleStep;
    angle3 = angle3 - angleStep;
    angle4 = angle4 - angleStep;
    angle5 = angle5 - angleStep;

    //Makes sure angle is not set under the min
    if(angle1 < 0)
    {
      angle1 = 0;
    }
    else//Sets angle for the first finger servo
    {
      s1.write(angle1);
    }

    //Makes sure angle is not set under the min
    if(angle2 < 0)
    {
      angle2 = 0;
    }
    else//Sets angle for the second finger servo
    {
      s2.write(angle2);
    }

    //Makes sure angle is not set under the min
    if(angle3 < 0)
    {
      angle3 = 0;
    }
    else//Sets angle for the third finger servo
    {
      s3.write(angle3);
    }

    //Makes sure angle is not set under the min
    if(angle4 < 0)
    {
      angle4 = 0;
    }
    else//Sets angle for the fourth finger servo
    {
      s4.write(angle4);
    }

    //Makes sure angle is not set under the min
    if(angle5 < 0)
    {
      angle5 = 0;
    }
    else//Sets angle for the fifth finger servo
    {
      s5.write(angle5);
    }

    delay(10);
  }


 //Checking the position of the joystick1
  if(x_data1 >= 550)
  {

    //Checks if finger 1 is not a spread out position
    if(pos1 <= 105)
    {
      pos1 = pos1 + 2;
      s6.write(pos1);
    }

    //Checks if finger 2 is not a spread out position
    if(pos2<= 95){
      pos2 = pos2 + 2;
      s7.write(pos2);
    }

    //Checks if finger 3 is not a spread out position
    if(pos3 >= 85)
    {
      pos3 = pos3 - 2;
      s8.write(pos3);
    }

    //Checks if finger 4 is not a spread out position
    if(pos4 >= 75)
    {
      pos4 = pos4 - 2;
      s9.write(pos4);
    }
  }
  
  //Checking the position of the joystick1
  else if(x_data1 <= 450)
  {
    //Checks if finger 1 is spread out position
    if(pos1 >= 90)
    {
      pos1 = pos1 - 2;
      s6.write(pos1);
    }

    //Checks if finger 2 is not a spread out position
    if(pos2 >= 90)
    {
      pos2 = pos2 - 2;
      s7.write(pos2);
    }

    //Checks if finger 3 is not a spread out position
    if(pos3<= 90){
      pos3 = pos3 + 2;
      s8.write(pos3);
    }

    //Checks if finger 4 is not a spread out position
    if(pos4<= 90){
      pos4 = pos4 + 2;
      s9.write(pos4);
    }
  }

 //Checking the position of the joystick2
  if(x_data2 >= 550){

    //Checks if finger5 is rotated
    if(pos5 <= 140){
      pos5 = pos5 + 2;
      s10.write(pos5);
    }
  }

 //Checking the position of the joystick2
  else if(x_data2 <= 450){

    //Checks if finger is not rotated
    if(pos5 >= 90){
      pos5 = pos5 - 2;
      s10.write(pos5);
    }
  }



}
