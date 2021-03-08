//variables initialisation 
int sensor = A0;
int val = 0;
int limit = 47;
int ledPin = 8;



void setup()
{
  Serial.begin(9600); //enabling serial output
  pinMode(ledPin, OUTPUT); //definition of pin funcion
}

void loop()
{
  val = analogRead(sensor); //sensor reading
  val = map(val, 306, 750, 0, 100); //mapping values - converting sensor reading to actual value
    
    if(val < limit) //if value is below the limit then green LED is blinking 
    {     
        digitalWrite(8, HIGH);   
        delay(1000);              
        digitalWrite(8, LOW);   
        delay(1000);
    }
    else  //activate buzzer and red LED 
    {
      tone(9, 350);
        delay(300);
      noTone(9);
        delay(100);
    }
}
