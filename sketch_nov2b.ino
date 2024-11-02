#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

// Replace with your WiFi credentials
const char* ssid = "oneplus_1";
const char* password = "oneplus1";

ESP8266WebServer server(80);
Servo myServo;
bool servoOn = false;

void setup() {
  Serial.begin(115200);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");

  // Setup server routes
  server.on("/", HTTP_GET, handleRoot);
  server.on("/toggle-servo", HTTP_GET, toggleServo);

  server.begin();
  Serial.println("HTTP server started");

  // Attach the servo to pin D5
  myServo.attach(2);
  myServo.write(0); // Initial position
}

void handleRoot() {
  server.send(200, "text/plain", "NodeMCU is up and running!");
}

void toggleServo() {
  if (servoOn) {
    myServo.write(0); // Turn servo off
    server.send(200, "text/plain", "Servo is off");
  } else {
    myServo.write(90); // Turn servo on
    server.send(200, "text/plain", "Servo is on");
  }
  servoOn = !servoOn;
}

void loop() {
  server.handleClient();
}
