#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

String a = ";";
int buttonPin = 10; 
int btnState = 0;

DHT dht(DHTPIN, DHTTYPE);

void setup()
{   
    Serial.begin(9600);
    dht.begin();
}

void loop()
{   
    int h = dht.readHumidity();
    int t = dht.readTemperature(0);
    String s = h+a+t;
    Serial.print(s);
    delay(5000); 
}
