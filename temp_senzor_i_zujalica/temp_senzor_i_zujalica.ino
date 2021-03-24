//#include "TinyDHT.h"

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

int buttonPin = 10; 
int btnState = 0;
DHT dht(DHTPIN, DHTTYPE);

void setup()
{   
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
    dht.begin();
    Serial.println("CLEARDATA");
    Serial.println("LABEL,Date,Time,Humdity,Temperature");

}

void loop()
{   
    btnState = digitalRead(buttonPin);
    int h = dht.readHumidity();
    int t = dht.readTemperature(0);

    tone(5, 500);
    delay(100);
    noTone(5);
    delay(100);
    if (h>50 && h<60)
    {
      tone(5,500);
      delay(100);
      noTone(5);
      }
    if (h>60 && btnState==false)
    {
      tone(5,700);
      delay(1000);
      noTone(5);
      }

    Serial.println((String) "DATA,DATE,16:32," + h + "," + t);

    delay(1100); 
}
