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


int AdirectionPin = 12;
int ApwmPin = 3;
int AbrakePin = 9;
int BdirectionPin = 13;
int BpwmPin = 11;
int BbrakePin = 8;

#include <Pixy2.h>

Pixy2 pixy;

void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");

  pinMode(AdirectionPin, OUTPUT);
  pinMode(ApwmPin, OUTPUT);
  pinMode(AbrakePin, OUTPUT);
  pinMode(BdirectionPin, OUTPUT);
  pinMode(BpwmPin, OUTPUT);
  pinMode(BbrakePin, OUTPUT);

  
  digitalWrite(AbrakePin, LOW);
  digitalWrite(BbrakePin, LOW);
  digitalWrite(AdirectionPin, HIGH);
  digitalWrite(BdirectionPin, HIGH);

  pixy.init();
  // change to the line_tracking program.  Note, changeProg can use partial strings, so for example,
  // you can change to the line_tracking program by calling changeProg("line") instead of the whole
  // string changeProg("line_tracking")
  Serial.println(pixy.changeProg("line"));

}

void loop()
{
  int8_t i;
  char buf[128];
 
  pixy.line.getMainFeatures(1,true);

  if (pixy.line.numVectors)
    pixy.line.vectors->print();
 
//#########################

analogWrite(ApwmPin, 254);
analogWrite(BpwmPin, 254);

delay(1000);

analogWrite(ApwmPin, 0);
analogWrite(BpwmPin, 0);

delay(1000);

//#########################
    





}
