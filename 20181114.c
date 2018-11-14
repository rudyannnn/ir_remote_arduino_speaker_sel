#include <IRremote.h>

const int RL=HIGH;   // Relay 표시
const int RH=LOW;

const int IRinputPin=13;

const int RelayPin[]={24,23,22,21,20,19,17,16,15,14};

const int LED_Pin[]={3,4,6,7,8,10,11};

const int RelayOutput_case[][10]={
                          {RL,  RL,  RL,  RL,  RH,  RH,  RH,  RL,  RH,  RL},  
                          {RH,  RH,  RH,  RH,  RL,  RL,  RH,  RL,  RL,  RH},  
                          {RH,  RH,  RH,  RH,  RL,  RL,  RH,  RH,  RL,  RH},  
                          {RL,  RL,  RL,  RL,  RL,  RL,  RL,  RH,  RL,  RL},  
                          {RL,  RL,  RL,  RL,  RL,  RL,  RL,  RH,  RL,  RH},  
                          {RL,  RL,  RL,  RL,  RL,  RL,  RL,  RL,  RL,  RL},
                          {RL,  RL,  RL,  RL,  RH,  RH,  RH,  RH,  RH,  RL}  
                          };

IRrecv irrecv(IRinputPin);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0; i<10; i++){
    pinMode(RelayPin[i], OUTPUT);
    pinMode(LED_Pin[i], OUTPUT);
  }
  
  digitW(0);
  
  irrecv.enableIRIn();  // Start the receiver
}

void digitW(int a)
{
  for(int i=0; i<10; i++)
  {
    digitalWrite(RelayPin[i],RelayOutput_case[a][i]);
  }
  int flag[7]= {
                RelayOutput_case[a][7],
                RelayOutput_case[a][6],
                RelayOutput_case[a][4],
                RelayOutput_case[a][9] * RelayOutput_case[a][8],
                RelayOutput_case[a][4],
                RelayOutput_case[a][6],
                RelayOutput_case[a][7]
               };
  
  for(int j=0; j<7; j++)
  {
    if( flag[j] == 1 )flag[j]=0;else flag[j]=1;
    digitalWrite(LED_Pin[j],flag[j]);
  }
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

  if(results->value==0x20DF6897){   //리모콘6 -- ALL
   digitW(6);
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
