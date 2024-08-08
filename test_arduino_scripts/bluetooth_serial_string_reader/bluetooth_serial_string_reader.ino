//Sketch used to re-familiarise with Serial comms on Bluetooth module


String c = "Ready"; // Initialize with a default message

void setup() {
  Serial.begin(38400);
  Serial.println(c); // Print the initial message
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Clear the previous content of the string
    c = "";
    // Read incoming data
    while (Serial.available() > 0) {
      char ch = Serial.read();
      c += ch;
      delay(10); // Small delay to ensure all characters are read
    }
    // Print the received string
    Serial.println(c);
  }
}

