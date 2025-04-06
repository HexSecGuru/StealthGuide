# Ultrasonic Sensor with Vibration Motor/Buzzer Alert

This project demonstrates how to use an ultrasonic sensor in combination with a vibration motor or buzzer to alert when an object comes within a specified range. The system uses the **HC-SR04 Ultrasonic Sensor** for distance measurement and activates a vibration motor or buzzer when an obstacle is detected within a set distance threshold.

## Components

- **HC-SR04 Ultrasonic Sensor**
  - `TRIG_PIN`: Pin 5 (Trigger)
  - `ECHO_PIN`: Pin 18 (Echo)
  
- **Vibration Motor/Buzzer**
  - `VIBRATION_PIN`: Pin 15 (Motor/Buzzer)

## Circuit Diagram

- Connect the **TRIG_PIN** to **GPIO 5** of your ESP32 or Arduino.
- Connect the **ECHO_PIN** to **GPIO 18**.
- Connect the **VIBRATION_PIN** to **GPIO 15**.
- Power the ultrasonic sensor with 5V and ground.

## Features

- **Real-time Distance Measurement**: Measures distance using the ultrasonic sensor.
- **Proximity Alert**: Triggers a vibration motor or buzzer when an object is within the set threshold distance.
- **Adjustable Threshold**: Easily change the threshold distance for proximity alerts.

## Code Explanation

The following Arduino sketch captures the main functionality of the system:

```cpp
// Define pins for Ultrasonic Sensor
#define TRIG_PIN 5
#define ECHO_PIN 18

// Define pin for Vibration Motor or Buzzer
#define VIBRATION_PIN 15

// Define distance threshold in centimeters
const int thresholdDistance = 30; // Adjust based on desired range

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  
  // Set pin modes for ultrasonic sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  // Set pin mode for vibration motor or buzzer
  pinMode(VIBRATION_PIN, OUTPUT);
  
  // Start with motor or buzzer off
  digitalWrite(VIBRATION_PIN, LOW);
}

void loop() {
  // Get the distance reading from the ultrasonic sensor
  long duration, distance;
  
  // Clear the trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  
  // Set the trigger pin high for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the echo pin (duration of the pulse in microseconds)
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance (in cm)
  distance = (duration * 0.034) / 2;
  
  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if distance is less than threshold
  if (distance < thresholdDistance && distance > 0) {
    // Turn on vibration motor or buzzer if an obstacle is near
    digitalWrite(VIBRATION_PIN, HIGH);
  } else {
    // Turn off the motor/buzzer if no obstacle is detected
    digitalWrite(VIBRATION_PIN, LOW);
  }
  
  // Add a small delay to avoid rapid switching
  delay(200);
}
