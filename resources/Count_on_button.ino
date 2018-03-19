//////////////////////////////////////////
// Author: Seth Deane (sxd4738@rit.edu)
// Date Completed: 11/5/2016
// Description: Increment the output of a 7-segment display on button press.
//
// Inspiration and assisting code from the following licensed source
// License: http://www.opensource.org/licenses/mit-license.php
/////////////////////////////////////////

// set pin numbers:
const int buttonPin = 13;     // the number of the pushbutton pin

// variable for button:
int buttonState = 0;         // variable for reading the pushbutton status
byte count = 0;

// Define the LED digit patters, from 0 - 9
// Note that these patterns are for common cathode displays
// For common anode displays, change the 1's to 0's and 0's to 1's
// 1 = LED on, 0 = LED off, in this order:

//                                    Arduino pin: 2,3,4,5,6,7,8
byte seven_seg_digits[10][7] = { { 1,1,1,1,1,1,0 },  // = 0
                                 { 0,1,1,0,0,0,0 },  // = 1
                                 { 1,1,0,1,1,0,1 },  // = 2
                                 { 1,1,1,1,0,0,1 },  // = 3
                                 { 0,1,1,0,0,1,1 },  // = 4
                                 { 1,0,1,1,0,1,1 },  // = 5
                                 { 1,0,1,1,1,1,1 },  // = 6
                                 { 1,1,1,0,0,0,0 },  // = 7
                                 { 1,1,1,1,1,1,1 },  // = 8
                                 { 1,1,1,0,0,1,1 }   // = 9
                               };

void setup() {         
  Serial.begin(9600);      
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(buttonPin, INPUT);
  writeDot(0);  // start with the "dot" off
}

void writeDot(byte dot) {
  digitalWrite(9, dot);
}
   
void sevenSegWrite(byte digit) {
  byte pin = 2;
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
}

void loop() {
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  Serial.print(buttonState);
  delay(50);

  // if the count is above 9, restart the count
  if (count > 9){
    count = 0;
  }

  // if the button is pressed, increment
  if (buttonState == HIGH) {
      Serial.print(count);
      delay(50);
      sevenSegWrite(count);
      count = count + 1;
  }
  delay(50);
}

