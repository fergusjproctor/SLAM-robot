// Short sketch used to read values from encoder and store current velocity and absolute displacement.
// Based on original script by Lauren from DFRobot, Product name: Wheel Encoders for DFRobot 3PA and 4WD Rovers


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

void setup(){

  Serial.begin(9600);                            //init the Serial port to print the data
  attachInterrupt(LEFT, LwheelSpeed, CHANGE);    //init the interrupt mode for digital pin 2
  attachInterrupt(RIGHT, RwheelSpeed, CHANGE);   //init the interrupt mode for digital pin 3

}

void loop(){

  static unsigned long timer = 0;                //print manager timer
  
  if(millis() - timer > delta * 1000){
 
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
    
    // reset current coder value and timer
    coder[LEFT] = 0;               
    coder[RIGHT] = 0;
    timer = millis();
  }
}

// ISR used to add 1 to count whenever encoder photosensor changes from 1 to 0 or vice versa
void LwheelSpeed()
{
  coder[LEFT] ++;  //count the left wheel encoder interrupts
}


void RwheelSpeed()
{
  coder[RIGHT] ++; //count the right wheel encoder interrupts
}