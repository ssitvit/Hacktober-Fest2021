#include<Console.h>
#include<Servo.h>
Servo myServo;
int x = 0;



void setup() {
  Serial.begin(115200);
  myServo.write(0);
  myServo.attach(8);
}

void loop() {
  if(Serial.available() > 0)
  {
    x=Serial.read();
  }
 
  if (x == '1'){
   myServo.write(36);
  }
  else if (x == '2'){
    myServo.write(72);
  }
  else if (x == '3'){
   myServo.write(108);
  }
  else if (x == '4'){
   myServo.write(144);
  }
  else if (x == '5'){
    myServo.write(180);
  }
}
