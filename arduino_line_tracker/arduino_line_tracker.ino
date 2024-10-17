#include <Pixy2.h>

// Right Motor Pin
#define MotorRSpeedPin 5

// Left Motor Pin
#define MotorLSpeedPin 6

// Speed: 0-255
// Direction: High is forwards, LOW is reverse
// Brake: LOW is not applied, HIGH is applied

int MaxSpeed = 125;
int MinSpeed = 0;
int MaxDelta = 5000;
int Kp = 10;
int Deadzone = 0;
int offset = 10;

// Init speed
int MotorRSpeed = MaxSpeed;
int MotorLSpeed = MaxSpeed;

// X heading
int DeltaX = 0;

// Init Pixy cam 
Pixy2 pixy;

// Pixy vector coordinates
int ArrowSideX;
int ArrowSideY;
int LineSideX;
int LineSideY;

void setup()
{
  // Init Serial
  Serial.begin(115200);
  Serial.print("Starting...\n");
  
  // Init Motor R
  pinMode(MotorRSpeedPin, OUTPUT);
  analogWrite(MotorRSpeedPin, MotorRSpeed);

  // Init Motor L
  pinMode(MotorLSpeedPin, OUTPUT);
  analogWrite(MotorLSpeedPin, MotorLSpeed);

  // Init Pixy
  pixy.init();
  pixy.setLamp(1, 1);
}

void loop()
{
  // Get Pixy vector
  pixy.line.getMainFeatures(1,true);
  int numVectors = pixy.line.numVectors;

  // Arrow side = positive side of the vector
  // Line side = negative side of the vector

  // Get Pixy vector coordinates using callback (sends request, then waits for reply using callback sign '->') 
  ArrowSideX = pixy.line.vectors -> m_x0;
  ArrowSideY = pixy.line.vectors -> m_y0;
  LineSideX = pixy.line.vectors -> m_x1;
  LineSideY = pixy.line.vectors -> m_y1;

  // Delta X position between arrow side and line side times a scaling coefficient
  DeltaX = (ArrowSideX - 38) * Kp;

  // Maxdelta limits
  if (DeltaX > MaxDelta | DeltaX < (-1 * MaxDelta)) {
    DeltaX = 0;
  }

  // Deadzone limits
  if (DeltaX > (-1 * Deadzone) && DeltaX < Deadzone) {
    DeltaX = 0;
  }

  // Speed logic
  if (DeltaX > 0) {
    MotorRSpeed = MaxSpeed - DeltaX;
    MotorLSpeed = MaxSpeed;
  } else if (DeltaX < 0) {
    MotorLSpeed = MaxSpeed + DeltaX;
    MotorRSpeed = MaxSpeed;
  } else {
    MotorRSpeed = MaxSpeed;
    MotorLSpeed = MaxSpeed;
  }

  if (numVectors == 0) {
    MotorRSpeed = MaxSpeed;
    MotorLSpeed = MaxSpeed;
  }

  // Right speed minimum
  if (MotorRSpeed < MinSpeed) {
    MotorRSpeed = MinSpeed;
  }

  // Left speed minimum
  if (MotorLSpeed < MinSpeed) {
    MotorLSpeed = MinSpeed;
  }

  // Set motor speed 
  analogWrite(MotorRSpeedPin, MotorRSpeed);
  analogWrite(MotorLSpeedPin, MotorLSpeed);

  // Serial.println("Delta: (" + String(DeltaX) + "); R: (" + String(MotorRSpeed) + "); L: (" + String(MotorLSpeed) + ")");
  Serial.println(DeltaX);
}
