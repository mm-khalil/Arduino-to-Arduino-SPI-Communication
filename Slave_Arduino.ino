//Slave Arduino Code:

#include<SPI.h>
volatile boolean received;
volatile byte Slavereceived,Slavesend;
int y=22;

void setup()
{
  Serial.begin(115200);
  SPI.begin();
  
  pinMode(MISO,OUTPUT);                   //Sets MISO as OUTPUT (Have to Send data to Master IN 
  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode
  received = false;
  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation 
}

ISR (SPI_STC_vect)                        //Inerrrput routine function 
{ Slavereceived = SPDR; // Value received from master if store in variable slavereceived
  received = true;   }  //Sets received as True   

void loop()
{ 
   if(received)                            
   {    Serial.print("Data received from Master = ");
        Serial.println(Slavereceived);  
        Slavesend = y;                             
        SPDR = Slavesend;                           //Sends the x value to master via SPDR 
        delay(1000);  }
      
}
