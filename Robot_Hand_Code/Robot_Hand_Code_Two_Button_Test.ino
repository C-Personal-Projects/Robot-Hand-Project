#include<Servo.h>

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

int angleStep = 2;

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
 Serial.begin(500000);

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

 pinMode(BUTTON1, INPUT_PULLUP);
 pinMode(BUTTON2, INPUT_PULLUP);
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


  while(digitalRead(BUTTON1) == LOW)
  {
    angle1 = angle1 + angleStep;
    angle2 = angle2 + angleStep;
    angle3 = angle3 + angleStep;
    angle4 = angle4 + angleStep;
    angle5 = angle5 + angleStep;
    
    if(angle1 > 180)
    {
      angle1 = 180;
    }
    else
    {
      s1.write(angle1);
    }

    if(angle2 > 180)
    {
      angle2 = 180;
    }
    else
    {
      s2.write(angle2);
    }

    if(angle3 > 180)
    {
      angle3 = 180;
    }
    else
    {
      s3.write(angle3);
    }

    if(angle4 > 180)
    {
      angle4 = 180;
    }
    else
    {
      s4.write(angle4);
    }

    if(angle5 > 180)
    {
      angle5 = 180;
    }
    else
    {
      s5.write(angle5);
    }

    delay(10);
  }


  while(digitalRead(BUTTON2) == LOW)
  {
    angle1 = angle1 - angleStep;
    angle2 = angle2 - angleStep;
    angle3 = angle3 - angleStep;
    angle4 = angle4 - angleStep;
    angle5 = angle5 - angleStep;

    if(angle1 < 0)
    {
      angle1 = 0;
    }
    else
    {
      s1.write(angle1);
    }

    if(angle2 < 0)
    {
      angle2 = 0;
    }
    else
    {
      s2.write(angle2);
    }

    if(angle3 < 0)
    {
      angle3 = 0;
    }
    else
    {
      s3.write(angle3);
    }

    if(angle4 < 0)
    {
      angle4 = 0;
    }
    else
    {
      s4.write(angle4);
    }

    if(angle5 < 0)
    {
      angle5 = 0;
    }
    else
    {
      s5.write(angle5);
    }



    delay(10);
  }


 //Servo 1 control with Joystick 1
  if(x_data1 >= 550)
  {
    if(pos1 <= 105)
    {
      pos1 = pos1 + 2;
      s6.write(pos1);
    }

    if(pos2<= 95){
      pos2 = pos2 + 2;
      s7.write(pos2);
    }

    if(pos3 >= 85)
    {
      pos3 = pos3 - 2;
      s8.write(pos3);
    }

    if(pos4 >= 75)
    {
      pos4 = pos4 - 2;
      s9.write(pos4);
    }
  }
  
  else if(x_data1 <= 450)
  {
    if(pos1 >= 90)
    {
      pos1 = pos1 - 2;
      s6.write(pos1);
    }

    if(pos2 >= 90)
    {
      pos2 = pos2 - 2;
      s7.write(pos2);
    }

    if(pos3<= 90){
      pos3 = pos3 + 2;
      s8.write(pos3);
    }

    if(pos4<= 90){
      pos4 = pos4 + 2;
      s9.write(pos4);
    }
  }




}
