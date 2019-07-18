
/*
  Fallschirm-Modifikator
  modified 30 Mar 2019
  by Maja Cicvara, and Marek Czernohous

*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int incomingByte = 0;   // for incoming serial data

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}



void loop() {

  // send data only when you receive data:
  if (Serial.available() > 0) {   // Wenn am Serialport was anliegt
    // read the incoming byte:
    incomingByte = Serial.read();
    if (incomingByte != 10) { // wenn es kein Returnzeichen ist
      // say what you got:
      Serial.print("received: ");
      Serial.println(incomingByte);
      if (incomingByte == 108) {
        turnServo(1, 5000);
      } else if (incomingByte == 114) {
        turnServo(0, 5000);
      } else {
        Serial.println("ungueltiges Zeichen");
      }
    }
  }
}

boolean turnServo (boolean dir, int dur) {

  if (dir) {
    myservo.write(0);
    delay(5000);
    myservo.write(92);
    Serial.print("it turned to the right path for ");
    Serial.print(dur);
    Serial.println(" millisecs");
  }
  else
  {
    if (!dir)
    {
      myservo.write(180);
      delay(dur);
      myservo.write(92);
      Serial.print("it turned out on the wrong path for " );
      Serial.print(dur);
      Serial.println(" millisecs");
    }
    else
    {
      Serial.print("error, wrong signal");
    }
  }

  /*
     this is a method to turn the servo.
     i need to write it so that if the direction is true/right it should turn right and otherwise it should turn left
     or otherwise it should print out an error
  */

}
