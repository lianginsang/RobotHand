#include <Servo.h>

Servo thumb_servo;
Servo finger_servo;
int thumbPin = 9;
int fingerPin = 7;
const char TRIGGER_PIN = 8;
int Pos = 180;
bool closed = false;

void setup() {
  thumb_servo.attach(thumbPin);
  finger_servo.attach(fingerPin);
  pinMode(TRIGGER_PIN, INPUT);
}

void loop() {
  if((digitalRead(TRIGGER_PIN) == HIGH) && (closed == false)){
      //code to run when button is pressed
      for(int fingerPos = Pos; fingerPos >= 0; fingerPos -= 1){
          finger_servo.write(fingerPos);
          thumb_servo.write(fingerPos);
          delay(15);
          Pos = fingerPos;
        }
      while(digitalRead(TRIGGER_PIN) == HIGH){
          //loops if button is held
        }
      closed = true;
    }

   if((digitalRead(TRIGGER_PIN) == HIGH) && (closed == true)){
      //code to run when button is pressed
      for(int fingerPos = Pos; fingerPos <= 180; fingerPos += 1){
          finger_servo.write(fingerPos);
          thumb_servo.write(fingerPos);
          delay(15);
          Pos = fingerPos;
        }
      while(digitalRead(TRIGGER_PIN) == HIGH){
          //loops if button is held
        }
      closed = false;
    }
}
