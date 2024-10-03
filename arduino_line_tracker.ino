#include <Pixy2.h>

// Motor A Pins
#define MotorASpeedPin 3
#define MotorADirectionPin 12
#define MotorABrakePin 9

// Motor B Pins
#define MotorBSpeedPin 11
#define MotorBDirectionPin 13
#define MotorBBrakePin 8

// Motor A Constants
int MotorASpeed = 255;
int MotorADirection = HIGH;
int MotorABrake = LOW;

// Motor B Constants
int MotorBSpeed = 255;
int MotorBDirection = HIGH;
int MotorBBrake = LOW;

// Init pixy cam 2
Pixy2 pixy;

// Pixy vector coordinates
int ArrowSideX = 0;
int ArrowSideY = 0;
int LineSideX = 0;
int LineSideY = 0;

void setup()
{
  // Init Serial
  Serial.begin(115200);
  Serial.print("Starting...\n");
  
  // Init Motor B
  analogWrite(MotorASpeedPin, MotorASpeed);
  pinMode(MotorADirectionPin, OUTPUT); //Initiates Motor Channel A direction pin
  digitalWrite(MotorADirectionPin, MotorADirection);
  pinMode(MotorABrakePin, OUTPUT); //Initiates Motor Channel A brake pin
  digitalWrite(MotorABrakePin, MotorABrake);

  // Init Motor B
  analogWrite(MotorBSpeedPin, MotorBSpeed);
  pinMode(MotorBDirectionPin, OUTPUT); //Initiates Motor Channel B direction pin
  digitalWrite(MotorBDirectionPin, MotorBDirection);
  pinMode(MotorBBrakePin, OUTPUT); //Initiates Motor Channel B brake pin
  digitalWrite(MotorBBrakePin, MotorBBrake);

  // Init Pixy
  pixy.init();
}

void loop()
{

  // Get Pixy vectors
  pixy.line.getMainFeatures(1,true);

  ArrowSideX = pixy.line.vectors -> m_x0;
  ArrowSideY = pixy.line.vectors -> m_y0;
  LineSideX = pixy.line.vectors -> m_x1;
  LineSideY = pixy.line.vectors -> m_y1;

  // Print Pixy vector coordinates
  Serial.println("Arrow Side: (" + String(ArrowSideX) + "," + String(ArrowSideY) + "); Line Side: (" + String(LineSideX) + "," + String(LineSideY) + ")");

}
