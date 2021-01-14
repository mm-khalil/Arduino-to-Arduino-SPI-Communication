//Master Arduino Code:

#include<SPI.h>                             //Library for SPI 
int x=1;
void setup (void)
{
  Serial.begin(115200);                   //Starts Serial Communication at Baud Rate 115200 
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS,HIGH);                  // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
}

void loop(void)
{ 
  byte Mastersend,Mastereceive;          
  digitalWrite(SS, LOW); //Starts communication with Slave connected to master
  Mastersend = x;                           
  Mastereceive=SPI.transfer(Mastersend); //Send the mastersend value to slave also receives value from slave
  
  Serial.print("Master Sending x = ");
  Serial.println(x);
  
  delay(1000);
  

}
