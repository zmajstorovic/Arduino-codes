//definiramo varijable
int echoPin = 2;
int trigPin = 3;
int buzzPin = 4;
long duration, cm, inches;

void setup()
{
Serial.begin (9600);

//definiramo ulaze i izlaze
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

//beskonačna petlja
void loop()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);

//izračun udaljenosti na temelju brzine zvuka
cm = (duration/2) / 29.1;
inches = (duration/2) / 74;

//uključivanje zujalice
if(cm>20 && cm<30)
{
  tone(4,500);
  delay(100);
  noTone(4);
  }

if(cm>5 && cm<15)
{
  tone(4,500);
  delay(1000);
  noTone(4);
  }

//Ispis u konzolu 
Serial.print(inches);
Serial.print("in, ");
Serial.print(cm);
Serial.print("cm");
Serial.println();

delay(250);
}
