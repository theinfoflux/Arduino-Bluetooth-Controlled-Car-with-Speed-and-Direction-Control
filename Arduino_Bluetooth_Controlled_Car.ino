// Arduino Bluetooth Car with Speed Control (using SoftwareSerial)
// 2 DC Motors + L298N Driver + HC-05 Bluetooth

#include <SoftwareSerial.h>

// Define SoftwareSerial pins for HC-05
SoftwareSerial BT(10, 11); // TX=10, RX=11

char command[10];   // buffer for incoming command
int index = 0;      // buffer index
int speedValue = 200; // default speed (0-255)

// Motor Driver Pins
int ENA = 9;  // Enable pin for Motor A
int IN1 = 8;  // Motor A input 1
int IN2 = 7;  // Motor A input 2

int ENB = 6;  // Enable pin for Motor B
int IN3 = 5;  // Motor B input 1
int IN4 = 4;  // Motor B input 2

void setup() {
  // Motor pins as output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start Serial for debugging
  Serial.begin(9600);
  // Start Bluetooth serial
  BT.begin(9600);

// stopMotors();
  Serial.println("Bluetooth Car Ready. Waiting for commands...");
}

void loop() {
  // Read incoming Bluetooth commands
 while (BT.available() > 0) {
  char c = BT.read();
  Serial.println(c);
switch(c){
  case 'F':
    Serial.println("Forward");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speedValue);
  analogWrite(ENB, speedValue);
  break;
   case 'B':
   Serial.println("Backward");

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speedValue);
  analogWrite(ENB, speedValue);
  break;
    case 'R':
  Serial.println("Right");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speedValue);
  analogWrite(ENB, speedValue);
  break;

      case 'L':
      Serial.println("Left");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speedValue);
  analogWrite(ENB, speedValue);
  break;

     case 'S':
        Serial.println("Stop");

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  break;
  case'0':
  speedValue=0;
  break;
  case'1':
  speedValue=25;
  break;
  case'2':
  speedValue=50;
  break;

  case'3':
  speedValue=75;
  break;
  case'4':
  speedValue=100;
  break;
  case'5':
  speedValue=125;
  break;
    case'6':
  speedValue=150;
  break;
  case'7':
  speedValue=175;
  break;

   case'8':
  speedValue=200;
  break;
    case'9':
  speedValue=255;
  break;
  
  }
}

}
