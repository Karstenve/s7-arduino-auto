//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//


int ApwmPin = 3;
int BpwmPin = 11;

#include <Pixy2.h>

Pixy2 pixy;

void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");
  

  pinMode(12, OUTPUT); //Initiates Motor Channel A direction pin
  digitalWrite(12, HIGH);
  pinMode(9, OUTPUT); //Initiates Motor Channel A brake pin
  digitalWrite(9, LOW);

  pinMode(13, OUTPUT); //Initiates Motor Channel B direction pin
  digitalWrite(13, HIGH);
  pinMode(8, OUTPUT); //Initiates Motor Channel B brake pin
  digitalWrite(8, LOW);

  //pixy.init();
  // change to the line_tracking program.  Note, changeProg can use partial strings, so for example,
  // you can change to the line_tracking program by calling changeProg("line") instead of the whole
  // string changeProg("line_tracking")
  //Serial.println(pixy.changeProg("line"));

}

void loop()
{
 // int8_t i;
 // char buf[128];
 
  // pixy.line.getMainFeatures(1,false);

 // if (pixy.line.numVectors) {
 //   pixy.line.vectors->print();
 //   }
//#########################

  analogWrite(ApwmPin, 255); //motor A go brrt
  analogWrite(BpwmPin, 255);

//#########################


}
