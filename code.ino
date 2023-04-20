//import the servo code

#include <Servo.h>

//naming the servos

Servo myServo;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;

//creates/defines the angles that each joint of the arm/claw move to/from

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
int restAngle5 = 90;
int moveAngle5 = 45;
int Angle5 = 90;

//sets up the for loop variables as well as the button variables

int i = 0;
bool button = HIGH;
bool previous = HIGH;
int pause = 0;
int buttonPin = 4;

void setup() {
  
   Serial.begin(9600); // sets up the serial moniter
   pinMode(buttonPin, INPUT_PULLUP); //changes the pinmode for the button pin to input and pullup which makes the pin rest at HIGH and when the circuit is complete it changes to LOW 

  //atatches the servos to pin on the arduino uno

  myServo.attach(10);
  myServo2.attach(9);
  myServo3.attach(13);
  myServo4.attach(12);

  //moves the servos to there rest position

  myServo4.write(restAngle4);
  myServo3.write(restAngle3);
  myServo2.write(restAngle2);
  myServo.write(restAngle1);
}
void loop() {
  button = digitalRead(buttonPin); //button variable changes to the imput on the buttonpin
  if (button == LOW && previous == HIGH){ //if the button is pressed then the code runs
    for  (i ; i <100; i +=1){
      Serial.println(Angle3);
      myServo.write(Angle1);
      myServo3.write(Angle3);
      myServo4.write(Angle4);
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
      if (Angle4 >= moveAngle4) {
        Angle4 -= 1;
      }
    }
    for  (i ; i > 0; i -=1){
      Serial.println(Angle3);
      myServo.write(Angle1);
      myServo3.write(Angle3);
      myServo4.write(Angle4);      
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
      if (Angle4 <= restAngle4) { 
        Angle4 += 1;
      }
   }
  }
  previous = button; //ensures that the code doesn't break if the button is held
}
