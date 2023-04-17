#include <Servo.h>
Servo myServo;
Servo myServo2;
Servo myServo3;
Servo myServo4;
int restAngle1 = 90;
int moveAngle1 = 130;
int Angle1 = 90;
int restAngle2 = 95;
int moveAngle2 = 97;
int undoAngle2 = 93;
int restAngle3 = 120;
int moveAngle3 = 60;
int Angle3 = 120;
int restAngle4 = 90;
int moveAngle4 = 45;
int Angle4 = 90;
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
  myServo4.attach(15);

  pinMode(buttonPin, INPUT_PULLUP);
  
  myServo3.write(restAngle3);
  myServo2.write(restAngle2);
  myServo.write(restAngle1);
}
void loop() {
  button = digitalRead(buttonPin);
  //Serial.println(button);
  if (button == LOW && previous == HIGH){
    for  (i ; i <100; i +=1){
      Serial.println(Angle3);
      myServo.write(Angle1);
      myServo3.write(Angle3);
      delay(100);    
      if (Angle1 < moveAngle1) {
        Angle1 += 1;
      }
      if (i <= 20) {
        myServo2.write(moveAngle2);
      }
      else {
        myServo2.write(restAngle2);
      }
      if (Angle3 >= moveAngle3) {
        Angle3 -= 1;
      } 
    }
    for  (i ; i > 0; i -=1){
      Serial.println(Angle3);
      myServo.write(Angle1);
      myServo3.write(Angle3);
      delay(100);    
      if (Angle1 >= restAngle1) { 
        Angle1 -= 1;
      }
      if (i >= 20) {
        myServo2.write(undoAngle2);
      }
      else {
        myServo2.write(restAngle2);
      }
      if (Angle3 <= restAngle3) { 
        Angle3 += 1;
      }
   }
  }
  previous = button;
}
