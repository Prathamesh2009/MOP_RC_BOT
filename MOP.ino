#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RX, TX

// Define motor pins
int leftForwardPin = 5;
int leftBackwardPin = 6;
int rightForwardPin = 9;
int rightBackwardPin = 3;
int waterPumpPin = 8;
int mopRotationPin = 7;

void setup() {
  // Set motor pins as output
  pinMode(leftForwardPin, OUTPUT);
  pinMode(leftBackwardPin, OUTPUT);
  pinMode(rightForwardPin, OUTPUT);
  pinMode(rightBackwardPin, OUTPUT);
  pinMode(waterPumpPin, OUTPUT);
  pinMode(mopRotationPin, OUTPUT);

  // Set up Bluetooth serial communication
  BTSerial.begin(9600);
}

void loop() {
  // Check if there is data available from the Bluetooth app
  if (BTSerial.available()) {
    // Read the incoming data
    char command = BTSerial.read();
    
    // Control motors based on the received command
    if (command == 'F') { // Forward
      digitalWrite(leftForwardPin, HIGH);
      digitalWrite(leftBackwardPin, LOW);
      digitalWrite(rightForwardPin, HIGH);
      digitalWrite(rightBackwardPin, LOW);
    } else if (command == 'B') { // Backward
      digitalWrite(leftForwardPin, LOW);
      digitalWrite(leftBackwardPin, HIGH);
      digitalWrite(rightForwardPin, LOW);
      digitalWrite(rightBackwardPin, HIGH);
    } else if (command == 'L') { // Left
      digitalWrite(leftForwardPin, LOW);
      digitalWrite(leftBackwardPin, HIGH);
      digitalWrite(rightForwardPin, HIGH);
      digitalWrite(rightBackwardPin, LOW);
    } else if (command == 'R') { // Right
      digitalWrite(leftForwardPin, HIGH);
      digitalWrite(leftBackwardPin, LOW);
      digitalWrite(rightForwardPin, LOW);
      digitalWrite(rightBackwardPin, HIGH);
    } else if (command == 'P') { // Water Pump
      digitalWrite(waterPumpPin, HIGH);
    } else if (command == 'M') { // Mop Rotation
      digitalWrite(mopRotationPin, HIGH);
    } else if (command == 'S') { // Stop
      digitalWrite(leftForwardPin, LOW);
      digitalWrite(leftBackwardPin, LOW);
      digitalWrite(rightForwardPin, LOW);
      digitalWrite(rightBackwardPin, LOW);
      digitalWrite(waterPumpPin, LOW);
      digitalWrite(mopRotationPin, LOW);
    }
  }
}
