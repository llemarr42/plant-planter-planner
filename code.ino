#include <Servo.h>
Servo myServo;
Servo myServo2;
int restAngle1 = 40;
int moveAngle1 = 90;
int Angle1 = 40;
int restAngle2 = 94;
int moveAngle2 = 97;
int undoAngle2 = 91;
int i = 0;
int button = 0;
int pause = 0;
int buttonPin = 7;
void setup() {
   Serial.begin(9600);
  myServo.attach(10);
  myServo2.attach(9);
  pinMode(buttonPin, INPUT);
  myServo2.write(restAngle2);
  myServo.write(restAngle1);
}
void loop() {
  for  (i ; i <100; i +=1){
    Serial.println(Angle1);
    myServo.write(Angle1);
    delay(100);    
    if (Angle1 <= moveAngle1) {
      Angle1 += 1;
    }
    if (i <= 50) {
      myServo2.write(moveAngle2);
    }
    else {
      myServo2.write(restAngle2);
    }
  }
  for  (i ; i > 0; i -=1){
    Serial.println(Angle1);
    myServo.write(Angle1);
    delay(100);    
    if (Angle1 >= restAngle1) { 
      Angle1-= 1;
    }
    if (i >= 50) {
      myServo2.write(undoAngle2);
    }
    else {
      myServo2.write(restAngle2);
    }
  }
}
