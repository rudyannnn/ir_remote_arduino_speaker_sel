#include <IRremote.h>

const int RL=HIGH;   // Relay 표시
const int RH=LOW;

const int IRinputPin=13;
const int IC_AddressPin=2;

const int RelayPin[]={14,15,16,17,  19,20,21,22,23,24,  30,31,32,33,34,35};

const int LED_Pin[]={4,6,7,8,10};

const int RelayOutput_case[][16]={
    {RH, RH, RH, RH,  RH, RH, RH, RH, RH, RH,   RH, RH, RH, RH, RH, RH},
    {RH, RH, RL, RL,  RL, RL, RH, RH, RH, RH,   RL, RL, RL, RL, RL, RL},
    {RH, RH, RL, RL,  RH, RH, RH, RH, RH, RH,   RL, RL, RL, RL, RL, RL},
    {RL, RL, RL, RL,  RL, RL, RL, RL, RL, RL,   RL, RL, RL, RL, RL, RL}
                          };

IRrecv irrecv(IRinputPin);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    pinMode(IRinputPin, INPUT);
    pinMode(IC_AddressPin, INPUT);
  for(int i=0; i<16; i++){
    pinMode(RelayPin[i], OUTPUT);
    pinMode(LED_Pin[i], OUTPUT);
    delay(5);
  }
  
  digitW(0);
  
  irrecv.enableIRIn();  // Start the receiver
}

void digitW(int a)
{
  for(int i=0; i<16; i++)
  {
    digitalWrite(RelayPin[i],RelayOutput_case[a][i]);
    delay(5);
  }
  int flag[5]= {
                RelayOutput_case[a][0],
                RelayOutput_case[a][2],
                RelayOutput_case[a][4],
                RelayOutput_case[a][2],
                RelayOutput_case[a][0]
               };
  
  for(int j=0; j<5; j++)
  {
    if( flag[j] == 1 )flag[j]=0;else flag[j]=1;
    digitalWrite(LED_Pin[j],flag[j]);
    delay(5);
  }
}

//+=============================================================================
// Display IR code
//
void  ircode (decode_results *results)
{
  // Print Code

  // 0 
  Serial.print(results->value, HEX);
  int addrflag = digitalRead(IC_AddressPin);
  if(addrflag==HIGH)   /// 왼쪽 8K
  {
  if(results->value==0x20DFE817 | results->value==0xE7D0D303){   //리모콘7 -- 돌비 3.2.2 CH
   digitW(0);
  }

  if(results->value==0x20DF8877 | results->value==0x2ADE08A3){   //리모콘1 -- CSO 3.2ch
   digitW(2);
  }
  
  if(results->value==0x20DF28D7 | results->value==0x9F3E1063){   //리모콘4 -- mute
   digitW(3);
  }
  }
  else if(addrflag==LOW)   /// 오른쪽 8K
  {
    
  if(results->value==0x20DF9867 | results->value==0x2331B07F){   //리모콘9 -- 돌비 3.2.2 CH
   digitW(0);
  }

  if(results->value==0x20DFC837 | results->value==0x1A46B33F){   //리모콘3 -- CSO 3.2ch
   digitW(2);
  }
  
  if(results->value==0x20DF6897 | results->value==0x4CEB59FF){   //리모콘6 -- mute
   digitW(3);
  }
  }

  // 8k both
  
  if(results->value==0x20DF08F7 | results->value==0xD130B09F){   //리모콘0 -- 돌비 3.2.2 CH
   digitW(0);
  }
  
  if(results->value==0x20DF48B7 | results->value==0x7F613A3B){   //리모콘2 -- CSO 3.2ch
   digitW(2);
  }
  
  if(results->value==0x20DFA857 | results->value==0x2FB2625F){   //리모콘5 -- mute
   digitW(3);
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
