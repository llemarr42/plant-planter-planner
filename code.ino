#include <Servo.h>
Servo myServo;
Servo myServo2;
Servo myServo3;
int restAngle1 = 60;
int moveAngle1 = 90;
int Angle1 = 60;
int restAngle2 = 94.5;
int moveAngle2 = 97;
int undoAngle2 = 92;
//int restAngle3 = 40;
//int moveAngle3 = 90;
//int Angle3 = 40;
int i = 0;
bool button = HIGH;
bool previous = HIGH;
int pause = 0;
int buttonPin = 4;
void setup() {
   Serial.begin(9600);
  myServo.attach(10);
  myServo2.attach(9);
  myServo3.attach(13);

  pinMode(buttonPin, INPU T_PULLUP);
  //myServo2.write(restAngle3);
  myServo2.write(restAngle2);
  myServo.write(restAngle1);
}
void loop() {
  button = digitalRead(buttonPin);
  Serial.println(button);
  if (button == LOW && previous == HIGH){
    for  (i ; i <100; i +=1){
      Serial.println(Angle1);
      myServo.write(Angle1);
      //myServo.write(Angle3);
      delay(100);    
      //Serial.println(button);

      if (Angle1 <= moveAngle1) {
        Angle1 += 1;
      }
      if (i <= 50) {
        myServo2.write(moveAngle2);
      }
      else {
        myServo2.write(restAngle2);
      }
      //if (Angle3 <= moveAngle3) {
      //  Angle3 += 1;
      //}
    }
    for  (i ; i > 0; i -=1){
      Serial.println(Angle1);
      myServo.write(Angle1);
     // myServo.write(Angle3);
      delay(100);    
      //Serial.println(button);
      if (Angle1 >= restAngle1) { 
        Angle1-= 1;
      }
      if (i >= 50) {
        myServo2.write(undoAngle2);
      }
      else {
        myServo2.write(restAngle2);
      }
      //if (Angle3 >= restAngle3) { 
       // Angle3-= 1;
      //}
   }
  }
  previous = button;
}
