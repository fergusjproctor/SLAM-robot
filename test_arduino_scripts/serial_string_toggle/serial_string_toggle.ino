// sketch used to test serial connection. Toggles build-in LED on/off when "TOGGLE" word received.


String receivedData = ""; // To store incoming data
const int ledPin = LED_BUILTIN; // Built-in LED pin on the Arduino
unsigned long previousMillis = 0; // Store the last time a message was sent
const long interval = 10000; // Interval at which to send a message (10 seconds)

void setup() {
  // Initialize the serial communication at 38400 baud
  Serial.begin(38400);
  
  // Initialize the built-in LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis(); // Get the current time
  
  // Check if it's time to send the message
  if (currentMillis - previousMillis >= interval) {
    // Update the last time the message was sent
    previousMillis = currentMillis;
    
    // Send a message to the ROS 2 node
    Serial.println("Hello from Arduino");
  }

  // Check if there is incoming data from the ROS 2 node
  if (Serial.available() > 0) {
    // Clear the previous content of the string
    receivedData = "";
    
    // Read incoming data
    while (Serial.available() > 0) {
      char ch = Serial.read();
      receivedData += ch;
      // Small delay to ensure all characters are read
      delay(10);
    }

    // Print the received data for debugging
    Serial.print("Received on Arduino:");
    Serial.print(receivedData);
    
    // If the received data is "TOGGLE", toggle the LED
    if (receivedData == "TOGGLE") {
      // Toggle the LED state
      digitalWrite(ledPin, !digitalRead(ledPin));
      // Send confirmation back to the ROS 2 node
      Serial.println("LED state toggled");
    }
  }
}
