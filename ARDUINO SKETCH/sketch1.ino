// Define pins
const int trigPin = 9; // Trigger pin
const int echoPin = 10; // Echo pin

void setup() {
  Serial.begin(9600); // Start the Serial communication
  pinMode(trigPin, OUTPUT); // Set trigger pin as output
  pinMode(echoPin, INPUT); // Set echo pin as input
}

void loop() {
  long duration, distance;

  // Clear the trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigger pin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin, which returns the time it took for the signal to return
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm (speed of sound is 34300 cm/s)
  distance = (duration / 2) * 0.0343;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Delay before next measurement
  delay(500);
} 
