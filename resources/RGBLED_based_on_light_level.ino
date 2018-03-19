//////////////////////////////////////////
// Author: Seth Deane (sxd4738@rit.edu)
// Date Completed: 11/5/2016
// Description: Change the color of an RGB LED based on light level.
/////////////////////////////////////////

int LDR = 0;              // pin correspond to A0 of the LDR sensor on the arduino
int LDRValue = 0;         // store LDR values
int blu_sens_val = 200;   // the light level at which the LED turns blue
int grn_sens_val = 400;   // the light level at which the LED turns green
int red_sens_val = 600;   // the light level at which the LED turns red
int max_sens_val = 800;   // the light level at which the LED turns off

int redPin = 9;   // pin number of the red LED pin
int grnPin = 10;  // pin number of the green LED pin
int bluPin = 11;  // pin number of the blue LED pin

void setup() {
    Serial.begin(9600);         //start the serial monitor with 9600 buad
    
    pinMode(redPin, OUTPUT);    // set the red pin as output
    pinMode(grnPin, OUTPUT);    // set the green pin as output
    pinMode(bluPin, OUTPUT);    // set the blue pin as output

    // RGB Initialization
    digitalWrite(redPin, LOW);
    digitalWrite(grnPin, LOW);
    digitalWrite(bluPin, LOW);
  }
 
void loop() {
    // LDR STUFF
    LDRValue = analogRead(LDR);     //reads the ldr’s value through LDR
    Serial.println(LDRValue);       //prints the LDR values to serial monitor
    
    // 200 to 400 is BLUE
    if (LDRValue > blu_sens_val && LDRValue < grn_sens_val) {
        digitalWrite(redPin, LOW);
        digitalWrite(grnPin, LOW);
        digitalWrite(bluPin, HIGH);
    }

    // 400 to 600 is GREEN
    else if (LDRValue > grn_sens_val && LDRValue < red_sens_val) {
        digitalWrite(redPin, LOW);
        digitalWrite(grnPin, HIGH);
        digitalWrite(bluPin, LOW);
    }

    // 600 to 800 is RED
    else if (LDRValue >red_sens_val && LDRValue < max_sens_val) {
        digitalWrite(redPin, HIGH);
        digitalWrite(grnPin, LOW);
        digitalWrite(bluPin, LOW);
    } 

    // PAUSE
    delay(50);
  }
