// pin definitions
int ledPin = 3;
int buttonPin = 2;

// global variables
int toggleState;
int lastButtonState = 1;
long unsigned int lastPress;
volatile int buttonFlag;
int debounceTime = 20;



void setup() {
  //setup pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), ISR_button, CHANGE);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(buttonPin);
  
  if((millis() - lastPress) > debounceTime && buttonFlag){
    lastPress = millis();
    if (digitalRead(buttonPin) == 0 && lastButtonState == 1){
      
      toggleState =! toggleState;
    
      digitalWrite(ledPin, toggleState);
      lastButtonState = 0;
    }
    if (digitalRead(buttonPin) == 1 && lastButtonState == 0){
      lastButtonState = 1;
    }
    buttonFlag = 0;
  }

}

void ISR_button(){
  buttonFlag = 1;
}
