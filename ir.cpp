
#include <IRremote.hpp>

const int rcvPin=9;
const int motorInput1 = 7;  
const int motorInput2 = 3;  
IRrecv irrecv(rcvPin);
decode_results results;

void setup()
{ 
  Serial.begin(9600);
  irrecv.enableIRIn();
    
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);

  
}


void startMotor() {
  digitalWrite(motorInput1, HIGH);
  digitalWrite(motorInput2, LOW);
}

void stopMotor() {
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
}


void loop() {
  
  if(IrReceiver.decode()) {
    auto value= IrReceiver.decodedIRData.decodedRawData; 	
    
      switch(value)
      {        
        case 4010852096:
            Serial.println("1");  
        	startMotor();
          	break;
          
        case 3994140416: 
              Serial.println("2"); 
        	  stopMotor();
         	  break;
                
 
            
      }  
    IrReceiver.resume();
  }
  
}