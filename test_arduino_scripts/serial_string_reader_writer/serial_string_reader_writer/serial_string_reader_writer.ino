// sketch to test receiving and publishing data over serial


String c = ""; // Initialize an empty string
unsigned long previousMillis = 0; // Variable to store the last time the message was sent
const long interval = 10000; // Interval at which to send the message (2 seconds)
const int ledPin = LED_BUILTIN;


void setup() {
  Serial.begin(38400); // Initialize serial communication at 38400 baud
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis(); // Get the current time
  
  // Check if it's time to send the message
  if (currentMillis - previousMillis >= interval) {
    // Save the last time the message was sent
    previousMillis = currentMillis;
    
    // Send the "Hello from Fergduino" message
    Serial.println("Hello from Fergduino");
  }

  // Check if data is available to read
  if (Serial.available() > 0) {
     // Turn the LED on
    digitalWrite(ledPin, HIGH);

    // Wait for half a second
    delay(500);

    // Turn the LED off
    digitalWrite(ledPin, LOW);

    // Clear the previous content of the string
    c = "";
    // Read incoming data
    while (Serial.available() > 0) {
      char ch = Serial.read();
      c += ch;
      // Small delay to ensure all characters are read
      delay(10);
    }
    // Print the received string
    Serial.print("Received on Arduino: ");
    Serial.println(c);
  }
}
