
#include <RF24.h>
#include <nRF24L01.h>

#include <SPI.h>

RF24 radio(9, 10);

const byte rxAddr[6] = "00001";

#define relay1 2
#define relay2 3
#define relay3 4
#define relay4 5

void setup()
{
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  
  while (!Serial);
  Serial.begin(9600);
  
  radio.begin();
  radio.openReadingPipe(0, rxAddr);
  
  radio.startListening();
  delay(100);
} // end setup

void loop()
{
  if (radio.available())
  {
    int i = 0;
    radio.read(&i, sizeof(i));
    Serial.println(i);

    // relay1 off
    if (i == 9991) {
     digitalWrite(relay1, LOW); 
    } 

    // relay1 on
    if (i == 9992) {
     digitalWrite(relay1, HIGH); 
    }

    // relay2 off
    if (i == 9993) {
     digitalWrite(relay2, LOW); 
    }
    
    // relay2 on
    if (i == 9994) {
     digitalWrite(relay2, HIGH); 
    }

    // relay3 off
    if (i == 9995) {
     digitalWrite(relay3, LOW); 
    }

    // relay3 on
    if (i == 9996) {
     digitalWrite(relay3, HIGH); 
    }

    // relay4 off
    if (i == 9997) {
     digitalWrite(relay4, LOW); 
    }
    
    // relay4 on
    if (i == 9998) {
     digitalWrite(relay4, HIGH); 
    }

    
  } // end radio available
} // end loop
