#include <Pixy2.h>

// Motor A = Left
// Motor B = Right

// Motor A Pins
#define MotorASpeedPin 6

// Motor B Pins
#define MotorBSpeedPin 5

// Speed: 0-255
// Direction: High is forwards, LOW is reverse
// Brake: LOW is not applied, HIGH is applied

// Motor A Constants
int MotorASpeed = 145;

// Motor B Constants
int MotorBSpeed = 145;

// Init Pixy cam 
Pixy2 pixy;

// Pixy vector coordinates
int ArrowSideX = 0;
int ArrowSideY = 0;
int LineSideX = 0;
int LineSideY = 0;

// Number of vectors
int VectorAmount = 0;

void setup()
{
  // Init Serial
  Serial.begin(115200);
  Serial.print("Starting...\n");
  
  // Init Motor B
  pinMode(MotorASpeedPin, OUTPUT);
  analogWrite(MotorASpeedPin, MotorASpeed);

  // Init Motor B
  pinMode(MotorBSpeedPin, OUTPUT);
  analogWrite(MotorBSpeedPin, MotorBSpeed);

  // Init Pixy
  pixy.init();
  pixy.setLamp(1, 1);
}

void loop()
{

  // Get Pixy vector
  pixy.line.getAllFeatures(1,true);

  // Arrow side = positive side of the vector
  // Line side = negative side of the vector

  // Get Pixy vector coordinates using callback (sends request, then waits for reply using callback sign '->') 
  ArrowSideX = pixy.line.vectors -> m_x0;
  ArrowSideY = pixy.line.vectors -> m_y0;
  LineSideX = pixy.line.vectors -> m_x1;
  LineSideY = pixy.line.vectors -> m_y1;
  
  // Amount of vectors detected by pixycam
  VectorAmount = pixy.line.numVectors;

  // Print Pixy vector coordinates
  Serial.println("Arrow Side: (" + String(ArrowSideX) + "," + String(ArrowSideY) + "); Line Side: (" + String(LineSideX) + "," + String(LineSideY) + ")");

}
