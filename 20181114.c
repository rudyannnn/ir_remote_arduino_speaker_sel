#include <IRremote.h>

const int RelayOutput_L=HIGH;
const int RelayOutput_H=LOW;

const int LED_Output_L=LOW;
const int LED_Output_H=HIGH;

const int IRinputPin=13;
const int keypad0=0x20DF08F7;
const int keypad1=0x20DF8877;
const int keypad2=0x20DF48B7;
const int keypad3=0x20DFC837;
const int keypad4=0x20DF28D7;
const int keypad5=0x20DFA857;
const int keypad6=0x20DF6897;

const int RelayPin[]={14,15,16,17,19,20,21,22,23,24};
const int LED_Pin[]={3,4,6,7,8,10,11};

IRrecv irrecv(IRinputPin);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    digitalWrite(RelayPin[0],RelayOutput_L);
    digitalWrite(RelayPin[1],RelayOutput_L);
    digitalWrite(RelayPin[2],RelayOutput_L);
    digitalWrite(RelayPin[3],RelayOutput_L);
    digitalWrite(RelayPin[4],RelayOutput_L);
    digitalWrite(RelayPin[5],RelayOutput_L);
    digitalWrite(RelayPin[6],RelayOutput_L);
    digitalWrite(RelayPin[7],RelayOutput_L);
    digitalWrite(RelayPin[8],RelayOutput_L);
    digitalWrite(RelayPin[9],RelayOutput_L);
    
    digitalWrite(LED_Pin[0],LED_Output_L);
    digitalWrite(LED_Pin[1],LED_Output_L);
    digitalWrite(LED_Pin[2],LED_Output_L);
    digitalWrite(LED_Pin[3],LED_Output_L);
    digitalWrite(LED_Pin[4],LED_Output_L);
    digitalWrite(LED_Pin[5],LED_Output_L);
    digitalWrite(LED_Pin[6],LED_Output_L);

  irrecv.enableIRIn();  // Start the receiver
}

//+=============================================================================
// Display IR code
//
void  ircode (decode_results *results)
{
  // Print Code
  Serial.print(results->value, HEX);

  if(results->value==0x20DF08F7){   //리모콘0 -- 돌비 3.2.2 CH
    digitalWrite(RelayPin[0],RelayOutput_L);
    digitalWrite(RelayPin[1],RelayOutput_L);
    digitalWrite(RelayPin[2],RelayOutput_L);
    digitalWrite(RelayPin[3],RelayOutput_L);
    digitalWrite(RelayPin[4],RelayOutput_H);
    digitalWrite(RelayPin[5],RelayOutput_H);
    digitalWrite(RelayPin[6],RelayOutput_H);
    digitalWrite(RelayPin[7],RelayOutput_L);
    digitalWrite(RelayPin[8],RelayOutput_H);
    digitalWrite(RelayPin[9],RelayOutput_L);
    
    digitalWrite(LED_Pin[0],LED_Output_L);
    digitalWrite(LED_Pin[1],LED_Output_H);
    digitalWrite(LED_Pin[2],LED_Output_H);
    digitalWrite(LED_Pin[3],LED_Output_H);
    digitalWrite(LED_Pin[4],LED_Output_H);
    digitalWrite(LED_Pin[5],LED_Output_H);
    digitalWrite(LED_Pin[6],LED_Output_L);
  }

  if(results->value==0x20DF8877){   //리모콘1 -- CSO 3.2 CH
    digitalWrite(RelayPin[0],RelayOutput_H);
    digitalWrite(RelayPin[1],RelayOutput_H);
    digitalWrite(RelayPin[2],RelayOutput_H);
    digitalWrite(RelayPin[3],RelayOutput_H);
    digitalWrite(RelayPin[4],RelayOutput_L);
    digitalWrite(RelayPin[5],RelayOutput_L);
    digitalWrite(RelayPin[6],RelayOutput_H);
    digitalWrite(RelayPin[7],RelayOutput_L);
    digitalWrite(RelayPin[8],RelayOutput_L);
    digitalWrite(RelayPin[9],RelayOutput_H);
    
    digitalWrite(LED_Pin[0],LED_Output_L);
    digitalWrite(LED_Pin[1],LED_Output_H);
    digitalWrite(LED_Pin[2],LED_Output_L);
    digitalWrite(LED_Pin[3],LED_Output_H);
    digitalWrite(LED_Pin[4],LED_Output_L);
    digitalWrite(LED_Pin[5],LED_Output_H);
    digitalWrite(LED_Pin[6],LED_Output_L);
  }

  if(results->value==0x20DF48B7){   //리모콘2 -- CSO 3.2ch + B&W 2ch
    digitalWrite(RelayPin[0],RelayOutput_H);
    digitalWrite(RelayPin[1],RelayOutput_H);
    digitalWrite(RelayPin[2],RelayOutput_H);
    digitalWrite(RelayPin[3],RelayOutput_H);
    digitalWrite(RelayPin[4],RelayOutput_L);
    digitalWrite(RelayPin[5],RelayOutput_L);
    digitalWrite(RelayPin[6],RelayOutput_H);
    digitalWrite(RelayPin[7],RelayOutput_H);
    digitalWrite(RelayPin[8],RelayOutput_L);
    digitalWrite(RelayPin[9],RelayOutput_H);
    
    digitalWrite(LED_Pin[0],LED_Output_H);
    digitalWrite(LED_Pin[1],LED_Output_H);
    digitalWrite(LED_Pin[2],LED_Output_L);
    digitalWrite(LED_Pin[3],LED_Output_H);
    digitalWrite(LED_Pin[4],LED_Output_L);
    digitalWrite(LED_Pin[5],LED_Output_H);
    digitalWrite(LED_Pin[6],LED_Output_H);
  }

  if(results->value==0x20DFC837){   //리모콘3 -- B&W 2ch
    digitalWrite(RelayPin[0],RelayOutput_L);
    digitalWrite(RelayPin[1],RelayOutput_L);
    digitalWrite(RelayPin[2],RelayOutput_L);
    digitalWrite(RelayPin[3],RelayOutput_L);
    digitalWrite(RelayPin[4],RelayOutput_L);
    digitalWrite(RelayPin[5],RelayOutput_L);
    digitalWrite(RelayPin[6],RelayOutput_L);
    digitalWrite(RelayPin[7],RelayOutput_H);
    digitalWrite(RelayPin[8],RelayOutput_L);
    digitalWrite(RelayPin[9],RelayOutput_L);
    
    digitalWrite(LED_Pin[0],LED_Output_H);
    digitalWrite(LED_Pin[1],LED_Output_L);
    digitalWrite(LED_Pin[2],LED_Output_L);
    digitalWrite(LED_Pin[3],LED_Output_L);
    digitalWrite(LED_Pin[4],LED_Output_L);
    digitalWrite(LED_Pin[5],LED_Output_L);
    digitalWrite(LED_Pin[6],LED_Output_H);
  }

  if(results->value==0x20DF28D7){   //리모콘4 -- B&W 2ch + Center CSO
    digitalWrite(RelayPin[0],RelayOutput_L);
    digitalWrite(RelayPin[1],RelayOutput_L);
    digitalWrite(RelayPin[2],RelayOutput_L);
    digitalWrite(RelayPin[3],RelayOutput_L);
    digitalWrite(RelayPin[4],RelayOutput_L);
    digitalWrite(RelayPin[5],RelayOutput_L);
    digitalWrite(RelayPin[6],RelayOutput_L);
    digitalWrite(RelayPin[7],RelayOutput_H);
    digitalWrite(RelayPin[8],RelayOutput_L);
    digitalWrite(RelayPin[9],RelayOutput_H);
    
    digitalWrite(LED_Pin[0],LED_Output_H);
    digitalWrite(LED_Pin[1],LED_Output_L);
    digitalWrite(LED_Pin[2],LED_Output_L);
    digitalWrite(LED_Pin[3],LED_Output_H);
    digitalWrite(LED_Pin[4],LED_Output_L);
    digitalWrite(LED_Pin[5],LED_Output_L);
    digitalWrite(LED_Pin[6],LED_Output_H);
  }

  if(results->value==0x20DFA857){   //리모콘5 -- mute
    digitalWrite(RelayPin[0],RelayOutput_L);
    digitalWrite(RelayPin[1],RelayOutput_L);
    digitalWrite(RelayPin[2],RelayOutput_L);
    digitalWrite(RelayPin[3],RelayOutput_L);
    digitalWrite(RelayPin[4],RelayOutput_L);
    digitalWrite(RelayPin[5],RelayOutput_L);
    digitalWrite(RelayPin[6],RelayOutput_L);
    digitalWrite(RelayPin[7],RelayOutput_L);
    digitalWrite(RelayPin[8],RelayOutput_L);
    digitalWrite(RelayPin[9],RelayOutput_L);
    
    digitalWrite(LED_Pin[0],LED_Output_L);
    digitalWrite(LED_Pin[1],LED_Output_L);
    digitalWrite(LED_Pin[2],LED_Output_L);
    digitalWrite(LED_Pin[3],LED_Output_L);
    digitalWrite(LED_Pin[4],LED_Output_L);
    digitalWrite(LED_Pin[5],LED_Output_L);
    digitalWrite(LED_Pin[6],LED_Output_L);
  }

  if(results->value==0x20DF6897){   //리모콘6 -- 3.2.2ch + Ex
    digitalWrite(RelayPin[0],RelayOutput_H);
    digitalWrite(RelayPin[1],RelayOutput_H);
    digitalWrite(RelayPin[2],RelayOutput_H);
    digitalWrite(RelayPin[3],RelayOutput_H);
    digitalWrite(RelayPin[4],RelayOutput_H);
    digitalWrite(RelayPin[5],RelayOutput_H);
    digitalWrite(RelayPin[6],RelayOutput_H);
    digitalWrite(RelayPin[7],RelayOutput_H);
    digitalWrite(RelayPin[8],RelayOutput_H);
    digitalWrite(RelayPin[9],RelayOutput_H);
    
    digitalWrite(LED_Pin[0],LED_Output_H);
    digitalWrite(LED_Pin[1],LED_Output_H);
    digitalWrite(LED_Pin[2],LED_Output_H);
    digitalWrite(LED_Pin[3],LED_Output_H);
    digitalWrite(LED_Pin[4],LED_Output_H);
    digitalWrite(LED_Pin[5],LED_Output_H);
    digitalWrite(LED_Pin[6],LED_Output_H);
  }
}

//+=============================================================================
// Dump out the decode_results structure.
//
void  dumpInfo (decode_results *results)
{
  // Check if the buffer overflowed
  if (results->overflow) {
    Serial.println("IR code too long. Edit IRremoteInt.h and increase RAWLEN");
    return;
  }
 
  // Show Code & length
  Serial.print("Code      : ");
  ircode(results);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
}

void loop() {
  decode_results  results;        // Somewhere to store the results
  
  if (irrecv.decode(&results)) {  // Grab an IR code
    dumpInfo(&results);           // Output the results
    Serial.println("");           // Blank line between entries
    irrecv.resume();              // Prepare for the next value
  }
}
