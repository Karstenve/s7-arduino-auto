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

// #include <Pixy2.h>

// Pixy2 pixy;

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

  //pixy.init();
  // change to the line_tracking program.  Note, changeProg can use partial strings, so for example,
  // you can change to the line_tracking program by calling changeProg("line") instead of the whole
  // string changeProg("line_tracking")
  //Serial.println(pixy.changeProg("line"));

}

void loop()
{


}
