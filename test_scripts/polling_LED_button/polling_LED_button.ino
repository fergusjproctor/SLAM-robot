// pin definitions
int ledPin = 3;
int buttonPin = 2;

// global variables
int toggleState;
int lastButtonState = 1;
long unsigned int lastPress;
int debounceTime = 20;



void setup() {
  //setup pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(buttonPin);
  
  if((millis() - lastPress) > debounceTime){
    lastPress = millis();
    if (buttonState == 0 && lastButtonState == 1){
      
      Serial.print("Button state:");
      Serial.print(buttonState);
      Serial.print(".");
      Serial.print("Last Button state:");
      Serial.print(lastButtonState);
      Serial.print(".");
      toggleState =! toggleState;
      Serial.print("toggle state:");
      Serial.print(toggleState);
      Serial.print(".");
      digitalWrite(ledPin, toggleState);
      lastButtonState = 0;
    }
    if (buttonState == 1 && lastButtonState == 0){
      Serial.print("Button state:");
      Serial.print(buttonState);
      Serial.print(".");
      Serial.print("Last Button state:");
      Serial.print(lastButtonState);
      Serial.print(".");
      lastButtonState = 1;
    }
  }

}
