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

bool AdirectionState;
bool BdirectionState;


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

  pixy.init();
  // change to the line_tracking program.  Note, changeProg can use partial strings, so for example,
  // you can change to the line_tracking program by calling changeProg("line") instead of the whole
  // string changeProg("line_tracking")
  Serial.println(pixy.changeProg("line"));


  BdirectionState = !BdirectionState; //is leuk om niet beide dezelfde kant uit te beginnen ofzo

}

void loop()
{
  int8_t i;
  char buf[128];
 
  pixy.line.getMainFeatures();

  if (pixy.line.numVectors)
    pixy.line.vectors->print();
 
  if (pixy.line.numIntersections)
    pixy.line.intersections->print();

  if (pixy.line.barcodes)
    pixy.line.barcodes->print();


//#########################


//change direction every loop()

AdirectionState = !AdirectionState;
BdirectionState = !BdirectionState;

if(AdirectionState == false){

  digitalWrite(AdirectionPin, LOW);

} else{

  digitalWrite(AdirectionPin, HIGH);

}

if(BdirectionState == false){

  digitalWrite(BdirectionPin, LOW);

} else{

  digitalWrite(BdirectionPin, HIGH);

}


//release breaks

digitalWrite(AbrakePin, LOW);
digitalWrite(BbrakePin, LOW);
analogWrite(ApwmPin, 254);
analogWrite(BpwmPin, 254);

delay(2000);


digitalWrite(AbrakePin, HIGH);
digitalWrite(BbrakePin, HIGH);

delay(2000);



//#########################
    





}
