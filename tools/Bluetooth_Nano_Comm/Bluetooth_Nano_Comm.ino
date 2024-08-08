// sketch used to configure HC-05 module
//SEE VIDEO AT https://www.youtube.com/watch?v=A0uFtI_hX6Q&t=301s for circuit set up and commands

#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(2, 3);


char c= ' ';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("ready");
  Bluetooth.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Bluetooth.available()){
      c=Bluetooth.read();
      Serial.write(c);
    }
    if(Serial.available()){
      c=Serial.read();
      Bluetooth.write(c);
    }
}
