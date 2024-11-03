#include <Servo.h>

Servo myServo;

// Define pin connections
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 11;
const int switchPin = 2;

// Updated threshold distance in cm
const int thresholdDistance = 10;

void setup() {
  myServo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(switchPin, INPUT_PULLUP);

  myServo.write(0); // Initialize servo to 0 degrees
  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0343; // Calculate distance in cm

  Serial.print("Distance: ");
  Serial.println(distance);

  // Check if an object is detected within the updated threshold distance
  if (distance < thresholdDistance) {
    // Rotate servo to toggle switch
    myServo.write(90); // Rotate to 90 degrees (or the angle to press the switch)
    delay(1000); // Wait for 1 second
    myServo.write(0); // Return to 0 degrees
  }

  delay(500); // Delay for a short period before the next reading
}
