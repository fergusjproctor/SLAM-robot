// source https://www.youtube.com/watch?v=LzLdFBYQPvA

int ledPin = 3;
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
int ENA = 10;
int IN1 = 9;
int IN2 = 8;

// Motor B
int ENB = 5;
int IN3 = 7;
int IN4 = 6;

void setup ()
{
 // Declaramos todos los pines como salidas
 pinMode (ENA, OUTPUT);
 pinMode (ENB, OUTPUT);
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
 pinMode(LED_BUILTIN, OUTPUT);
 pinMode(ledPin, OUTPUT);
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

// void loop ()
// {
//  digitalWrite(LED_BUILTIN, HIGH);
//  delay (1000);
//  digitalWrite(LED_BUILTIN, LOW);
//  delay (1000);
//  Adelante ();
//  delay (5000);
//  Atras ();
//  delay (3000);
//  Derecha ();
//  delay (2000);
//  Izquierda ();
//  delay (2000);
//  Parar ();
//  delay (4000);
// }


// void setup() {
//   //setup pin modes
//   pinMode(ledPin, OUTPUT);
//   pinMode(buttonPin, INPUT_PULLUP);
//   attachInterrupt(digitalPinToInterrupt(2), ISR_button, CHANGE);
//   Serial.begin(9600);
// }

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

