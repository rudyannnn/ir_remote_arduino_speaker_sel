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

int RelayOutput_case0[]={0,0,0,0,1,1,1,0,1,0}
int RelayOutput_case1[]={1,1,1,1,0,0,1,0,0,1}
int RelayOutput_case2[]={1,1,1,1,0,0,1,1,0,1}
int RelayOutput_case3[]={0,0,0,0,0,0,0,1,0,0}
int RelayOutput_case4[]={0,0,0,0,0,0,0,1,0,1}
int RelayOutput_case5[]={0,0,0,0,0,0,0,0,0,0}

int LED_Output_case0[]={0,1,1,1,1,1,0}
int LED_Output_case1[]={0,1,0,1,0,1,0}
int LED_Output_case2[]={1,1,0,1,0,1,1}
int LED_Output_case3[]={1,0,0,0,0,0,1}
int LED_Output_case4[]={1,0,0,1,0,0,1}
int LED_Output_case5[]={0,0,0,0,0,0,0}

IRrecv irrecv(IRinputPin);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  for(int i=0; i<10; i++)
  {
    digitalWrite(RelayPin[i],RelayOutput_case0[i]);
  }
  for(int i=0; i<7; i++)
  {
    digitalWrite(LED_Pin[i],LED_Output_case0[i]);
  }
  
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

    for(int i=0; i<10; i++)
    {
      digitalWrite(RelayPin[i],RelayOutput_case0[i]);
    }
    for(int i=0; i<7; i++)
    {
      digitalWrite(LED_Pin[i],LED_Output_case0[i]);
    }
  }

  if(results->value==0x20DF8877){   //리모콘1 -- CSO 3.2 CH

    for(int i=0; i<10; i++)
    {
      digitalWrite(RelayPin[i],RelayOutput_case1[i]);
    }
    for(int i=0; i<7; i++)
    {
      digitalWrite(LED_Pin[i],LED_Output_case1[i]);
    }
  }

  if(results->value==0x20DF48B7){   //리모콘2 -- CSO 3.2ch + B&W 2ch

    for(int i=0; i<10; i++)
    {
      digitalWrite(RelayPin[i],RelayOutput_case2[i]);
    }
    for(int i=0; i<7; i++)
    {
      digitalWrite(LED_Pin[i],LED_Output_case2[i]);
    }
  }

  if(results->value==0x20DFC837){   //리모콘3 -- B&W 2ch

    for(int i=0; i<10; i++)
    {
      digitalWrite(RelayPin[i],RelayOutput_case3[i]);
    }
    for(int i=0; i<7; i++)
    {
      digitalWrite(LED_Pin[i],LED_Output_case3[i]);
    }
  }

  if(results->value==0x20DF28D7){   //리모콘4 -- B&W 2ch + Center CSO

    for(int i=0; i<10; i++)
    {
      digitalWrite(RelayPin[i],RelayOutput_case4[i]);
    }
    for(int i=0; i<7; i++)
    {
      digitalWrite(LED_Pin[i],LED_Output_case4[i]);
    }
  }

  if(results->value==0x20DFA857){   //리모콘5 -- mute

    for(int i=0; i<10; i++)
    {
      digitalWrite(RelayPin[i],RelayOutput_case5[i]);
    }
    for(int i=0; i<7; i++)
    {
      digitalWrite(LED_Pin[i],LED_Output_case5[i]);
    }
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
