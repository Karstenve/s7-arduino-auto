#include <Pixy2.h>

// Motor A = Left
// Motor B = Right

// Motor A Pins
#define MotorASpeedPin 3
#define MotorADirectionPin 12
#define MotorABrakePin 9

// Motor B Pins
#define MotorBSpeedPin 11
#define MotorBDirectionPin 13
#define MotorBBrakePin 8

// Speed: 0-255
// Direction: High is forwards, LOW is reverse
// Brake: LOW is not applied, HIGH is applied

// Motor A Constants
int MotorASpeed = 0;
int MotorADirection = HIGH;
int MotorABrake = LOW;

// Motor B Constants
int MotorBSpeed = 0;
int MotorBDirection = HIGH;
int MotorBBrake = LOW;

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
  analogWrite(MotorASpeedPin, MotorASpeed);
  pinMode(MotorADirectionPin, OUTPUT);
  digitalWrite(MotorADirectionPin, MotorADirection);
  pinMode(MotorABrakePin, OUTPUT);
  digitalWrite(MotorABrakePin, MotorABrake);

  // Init Motor B
  analogWrite(MotorBSpeedPin, MotorBSpeed);
  pinMode(MotorBDirectionPin, OUTPUT);
  digitalWrite(MotorBDirectionPin, MotorBDirection);
  pinMode(MotorBBrakePin, OUTPUT);
  digitalWrite(MotorBBrakePin, MotorBBrake);

  // Init Pixy
  pixy.init();
  pixy.setLamp(1, 1);

  //Disable zumomotor library
  #define PWM_L 3
  #define PWM_R 3
  #define DIR_L 3
  #define DIR_R 3
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
  // Serial.println("Arrow Side: (" + String(ArrowSideX) + "," + String(ArrowSideY) + "); Line Side: (" + String(LineSideX) + "," + String(LineSideY) + ")");
  Serial.println("Amount Vectors" + String(VectorAmount));
}
