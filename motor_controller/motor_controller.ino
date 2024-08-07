// Sketch used to control 4 motors of mobile platform. Based on test sketch test_arduino_scripts/motor_driver_buttons
// Code inefficient, but given it´ll be replaced by ROS2 controller refactoring was not undertaken.

// Pin groups:
// Input: pin 2
// PWM speed: pins 5,6 and 10,11 (front left right, back left right)
// Direction: (12,4), (7,8) and (A0,A1), (A2,A3)


// Updating interrupt pins to test  digitalPinToInterrupt() function
#include <EnableInterrupt.h>
// Pin connected to pull up interrupt button
int buttonDPin = 9;




// Global variables
int toggleStateS;
int toggleStateD;
int lastButtonDState = 1;
long unsigned int lastPress;
volatile int buttonDFlag;
int debounceTime = 20;
int speed;

// Motor A (Front Left)
int ENA = 5;
int IN1 = 12;
int IN2 = 4;

// Motor B (Front Right)
int ENB = 6;
int IN3 = 7;
int IN4 = 8;

// Motor C (Back Left)
int ENC = 10;
int IN5 = A0;
int IN6 = A1;

// Motor D (Back Right)
int END = 11;
int IN7 = A2;
int IN8 = A3;


//encoder inputs and variables
#define LEFT 0 // #        left wheel encoder  -> Digital pin 2, interrupt 0
#define RIGHT 1 // #        right wheel encoder -> Digital pin 3, interrupt 1



// store current count of coder
long coder[2] = {
  0,0};
// store absolute count of coder
long coder_abs[2] = {
  0,0};
// store current speed of coder
float lastSpeed[2] = {
  0,0};
float delta = 2; // Period of measuring cycle, T seconds speed is measured at


void setup() {
  // Initialize all pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENC, OUTPUT);
  pinMode(END, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(buttonDPin, INPUT_PULLUP);
  enableInterrupt(buttonDPin, ISR_buttonD, CHANGE);

  //encoder setup
  enableInterrupt(2, LwheelSpeed, CHANGE);    //init the interrupt mode for digital pin 2 (interrupt 0)
  enableInterrupt(3, RwheelSpeed, CHANGE);   //init the interrupt mode for digital pin 3 (interrupt 1)


  Serial.begin(9600);
}

void Forward(int speed) {
  // Front Left Motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);
  
  // Front Right Motor
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, speed);
  
  // Back Left Motor
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  analogWrite(ENC, speed);
  
  // Back Right Motor
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(END, speed);
}

void Back(int speed) {
  // Front Left Motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, speed / 2);
  
  // Front Right Motor
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, speed / 2);
  
  // Back Left Motor
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  analogWrite(ENC, speed / 2);
  
  // Back Right Motor
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(END, speed / 2);
}

void Right(int speed) {
  // Front Left Motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 4 * speed / 5);
  
  // Front Right Motor
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 2 * speed / 5);
  
  // Back Left Motor
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  analogWrite(ENC, 4 * speed / 5);
  
  // Back Right Motor
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(END, 2 * speed / 5);
}

void Left(int speed) {
  // Front Left Motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 2 * speed / 5);
  
  // Front Right Motor
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 4 * speed / 5);
  
  // Back Left Motor
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  analogWrite(ENC, 2 * speed / 5);
  
  // Back Right Motor
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(END, 4 * speed / 5);
}

void Stop() {
  // Front Left Motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  
  // Front Right Motor
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
  
  // Back Left Motor
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  analogWrite(ENC, 0);
  
  // Back Right Motor
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
  analogWrite(END, 0);
}

void loop() {
  // code pertaining to reading pullup buttons' interrupt
  int buttonDState = digitalRead(buttonDPin);
  
  if ((millis() - lastPress) > debounceTime && buttonDFlag) {
    Serial.print("Button D state:");
    Serial.print(buttonDState);
    lastPress = millis();
    if (digitalRead(buttonDPin) == 0 && lastButtonDState == 1) {
      speed = 255;
      toggleStateS = (toggleStateS + 1) % 5;
      switch (toggleStateS) {
        case 0:
          Forward(speed);
          break;
        case 1:
          Back(speed);
          break;
        case 2:
          Left(speed);
          break;
        case 3:
          Right(speed);
          break;
        case 4:
          Stop();
          break;
      }
      lastButtonDState = 0;
    }
    if (digitalRead(buttonDPin) == 1 && lastButtonDState == 0) {
      lastButtonDState = 1;
    }
    buttonDFlag = 0;
  }
  // code pertaining to reading encoder value
  static unsigned long enc_time = 0;                //print manager enc_time
  
  if(millis() - enc_time > delta * 1000){
 
    //record the latest speed value
    lastSpeed[LEFT] = coder[LEFT] / delta;   
    lastSpeed[RIGHT] = coder[RIGHT] / delta;
    // update total displacement
    coder_abs[LEFT] += coder[LEFT];
    coder_abs[RIGHT] += coder[RIGHT];
    // print values
    Serial.println("Speed value: ");
    Serial.print("[Left Wheel]");
    Serial.print(lastSpeed[LEFT]);
    Serial.print("[Right Wheel]");
    Serial.println(lastSpeed[RIGHT]);
    Serial.println("Coder value: ");
    Serial.print("[Left Wheel]");
    Serial.print(coder_abs[LEFT]);
    Serial.print("[Right Wheel]");
    Serial.println(coder_abs[RIGHT]);
    
    // reset current coder value and enc_time
    coder[LEFT] = 0;               
    coder[RIGHT] = 0;
    enc_time = millis();
  }
}

void ISR_buttonD() {
  Serial.print("Button ISR called, button value");
  Serial.println(digitalRead(buttonDPin));
  buttonDFlag = 1;
}

// encoder ISRs
// ISR used to add 1 to count whenever encoder photosensor changes from 1 to 0 or vice versa
void LwheelSpeed()
{
  coder[LEFT] ++;  //count the left wheel encoder interrupts
}


void RwheelSpeed()
{
  coder[RIGHT] ++; //count the right wheel encoder interrupts
}