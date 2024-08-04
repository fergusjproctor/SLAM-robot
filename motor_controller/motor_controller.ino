// Sketch used to control 4 motors of mobile platform. Based on test sketch test_arduino_scripts/motor_driver_buttons
// 

// Pin groups:
// Input: pin 2
// PWM speed: pins 5,6 and 10,11 (front left right, back left right)
// Direction: (3,4), (7,8) and (A0,A1), (A2,A3)


int buttonDPin = 2;

// global variables
int toggleStateS;
int toggleStateD;
int lastButtonDState = 1;
long unsigned int lastPress;
volatile int buttonDFlag;
int debounceTime = 20;
int speed;



// Motor A
int ENA = 5;
int IN1 = 3;
int IN2 = 4;

// Motor B
int ENB = 6;
int IN3 = 7;
int IN4 = 8;

void setup ()
{
 // Declaramos todos los pines como salidas
 pinMode (ENA, OUTPUT);
 pinMode (ENB, OUTPUT);
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
 pinMode(buttonDPin, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(2), ISR_buttonD, CHANGE);
 Serial.begin(9600);
 
}

void Adelante (int speed)
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, speed); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, HIGH);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, speed); //Velocidad motor B
}

void Atras (int speed)
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, speed/2); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, speed/2); //Velocidad motor B
}

void Derecha (int speed)
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 4*speed/5); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, 2*speed/5); //Velocidad motor A
}

void Izquierda (int speed)
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, 2*speed/5); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, HIGH);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 4*speed/5); //Velocidad motor A
}

void Parar ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 0); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 0); //Velocidad motor A
}



void loop() {
  // put your main code here, to run repeatedly:
  int buttonDState = digitalRead(buttonDPin);
  
  if((millis() - lastPress) > debounceTime && buttonDFlag){
    Serial.print("Button D state:");
    Serial.print(buttonDState);
    lastPress = millis();
    if (digitalRead(buttonDPin) == 0 && lastButtonDState == 1){
      speed=255;
      toggleStateS = (toggleStateS + 1) % 5;
      switch(toggleStateS){
        case 0:
        Adelante(speed);
        break;
        case 1:
        Atras(speed);
        break;
        case 2:
        Izquierda(speed);
        break;
        case 3:
        Derecha(speed);
        break;
        case 4:
        Parar();
        break;
      }
      // replace this with calling next type of movement - start with on off
      //if (toggleState == 0){Adelante ();};
      //if (toggleState == 1){Atras();};
      //
      lastButtonDState = 0;
    }
    if (digitalRead(buttonDPin) == 1 && lastButtonDState == 0){
      lastButtonDState = 1;
    }
    buttonDFlag = 0;
  }

}

void ISR_buttonD(){
  buttonDFlag = 1;
 
}

