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

