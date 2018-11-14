#include <IRremote.h>

const int RL=HIGH;   // Relay 표시
const int RH=LOW;

const int IL=LOW;    // LED 표시
const int IH=HIGH;

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

int RelayOutput_case[][10]={
                          {RL,  RL,  RL,  RL,  RH,  RH,  RH,  RL,  RH,  RL},  
                          {RH,  RH,  RH,  RH,  RL,  RL,  RH,  RL,  RL,  RH},  
                          {RH,  RH,  RH,  RH,  RL,  RL,  RH,  RH,  RL,  RH},  
                          {RL,  RL,  RL,  RL,  RL,  RL,  RL,  RH,  RL,  RL},  
                          {RL,  RL,  RL,  RL,  RL,  RL,  RL,  RH,  RL,  RH},  
                          {RL,  RL,  RL,  RL,  RL,  RL,  RL,  RL,  RL,  RL}
                          };

int LED_Output_case[][7]={
                            {IL,  IH,  IH,  IH,  IH,  IH,  IL},  
                            {IL,  IH,  IL,  IH,  IL,  IH,  IL},  
                            {IH,  IH,  IL,  IH,  IL,  IH,  IH},  
                            {IH,  IL,  IL,  IL,  IL,  IL,  IH},  
                            {IH,  IL,  IL,  IH,  IL,  IL,  IH},  
                            {IL,  IL,  IL,  IL,  IL,  IL,  IL}
                            };

IRrecv irrecv(IRinputPin);


void digitW(int a)
{
  for(int i=0; i<10; i++)
  {
    digitalWrite(RelayPin[i],RelayOutput_case[a][i]);
  }
  for(int j=0; j<7; j++)
  {
    digitalWrite(LED_Pin[j],LED_Output_case[a][j]);
  }  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  digitW(5);
  
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
   digitW(0);
  }

  if(results->value==0x20DF8877){   //리모콘1 -- CSO 3.2 CH
   digitW(1);
  }

  if(results->value==0x20DF48B7){   //리모콘2 -- CSO 3.2ch + B&W 2ch
   digitW(2);
  }

  if(results->value==0x20DFC837){   //리모콘3 -- B&W 2ch
   digitW(3);
  }

  if(results->value==0x20DF28D7){   //리모콘4 -- B&W 2ch + Center CSO
   digitW(4);
  }

  if(results->value==0x20DFA857){   //리모콘5 -- mute
   digitW(5);
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
