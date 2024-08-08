String c = "Ready"; // Initialize with a default message

void setup() {
  Serial.begin(38400);
  Serial.println(c); // Print the initial message
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read a single character
    char ch = Serial.read();
    // Print the received character
    Serial.println(ch);
  }
}
