/**********************************************************************;
* Project           : RES_Class, Position Control, Two bits Rotary Encoder 
*
* Program name      : RES_Rotary_Encoder_Basic.ino
*
* Author            : Jong-Hoon Kim
*
* Date created      : 03/10/2020
*
* Purpose           : How to make a rotray encoder.
*
* Revision History  :
*
* Date        Author      Ref    Revision (Date in MMDDYYYY format) 
* MMDDYYYY    name      1  v-xx   revision note. 
*
*********************************************************************/
/*********************************************************************
*   Instructional Note:  
*           Arduino Leonardo has 4 interrupt pins ( 0, 1, 2, 3  13 )
*           Arduino Mega has 6 interrupt pins ( 2, 3, 18, 19, 20, 21)
*   reference website ( https://www.pjrc.com/teensy/td_libs_Encoder.html )                    
***********************************************************************/

#include <Encoder.h>

// Change these pin numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
//Encoder knobLeft(18,19);
//Encoder knobRight(20, 21);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
  Serial.println("TwoKnobs Encoder Test:");
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), updateEncoder, CHANGE);  
}


int encoderPin_X  = 0;
int encoderPin_Y  = 0;
long counter  =0;

void loop() {
  long newLeft, newRight;
    
    Serial.print(encoderPin_X);
    Serial.print("  ");
    Serial.print(encoderPin_Y);
    Serial.print("  ");
    Serial.println(counter);
}



void updateEncoder(){
  encoderPin_X = digitalRead(2);
  encoderPin_Y = digitalRead(9);

  if (encoderPin_X == 0){   
    if (encoderPin_Y == 0){
      counter++;
    }else{
      counter--;
    }
  }else{
    if (encoderPin_Y == 0){
      counter--;
    }else{
      counter++;
    }    
  }
}
