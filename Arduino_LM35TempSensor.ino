int LM= A0; // Assigning pin numbers.
int led=13; // Assigning pin numbers to built in led pin.


float temp=0; // Assigin temperature variable.

void delay_cycles(unsigned long cycles) // Creating a function to generate delay based in the CPU cycles.
{
  for(unsigned long i=0;i<cycles;i++)
  {
    asm volatile("nop"); //Assembly instruction this instruction do nothing and consumes one CPU cycle.
  }
}
void delay_ms(unsigned long milliseconds) //Creating a function for proper conversion between milliseconds and cycles.
{
  unsigned long cycles=(milliseconds*16000);// Convert milliseconds to cycles.
  delay_cycles(cycles);
}

void setup() 
{
  pinMode(led,OUTPUT);  //Assigning the pin mode.
  pinMode(LM,INPUT);    //Assigning the pin mode.

}

void loop() {
  int sensorValue=analogRead(LM);     // Reading the analog value given out by LM35 temperature sensor.
  temp=(sensorValue*5.0*100.0)/1024;  // Converting the sensor value which in the range of 0 to 1024 to °C.

if(temp<30.0)                         
{
 digitalWrite(led,HIGH);
 delay_ms(250);                       // Calling the delay function.
 digitalWrite(led,LOW);
 delay_ms(250);                       // Calling the delay function.
 }else{
  digitalWrite(led,HIGH);
  delay_ms(500);                      // Calling the delay function.
  digitalWrite(led,LOW);
  delay_ms(500);                      // Calling the delay function.
}
}