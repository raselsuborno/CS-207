
int analogInput=A0; //read the value from analog input
int sensorValue=0;
void setup() 
{
  // put your setup code here, to run once:
pinMode (0,1, OUTPUT);
pinMode (A0, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   sensorValue=analogRead(analogInput);
   Serial.println(sensorValue);
  //condition for the photoresistor
   if (sensorValue>700)
   {
    digitalWrite(13,HIGH); 
   }
 
   else
   {
    digitalWrite(13,LOW); 
   }
}
