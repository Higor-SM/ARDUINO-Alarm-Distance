#define trigPin 11 
#define echoPin 12 
#define period 10 

int freq= 0; 
int buzz= 13;
int dur, dist;
 
void setup() 
{
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(buzz, OUTPUT);
}
 
void loop() 
{
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 dur= pulseIn(echoPin, HIGH);
 dist= (dur / 2) / 29.1; 
 
 if (dist>= 30 || dist<= 0) 
 {
 Serial.println("target");
 digitalWrite(buzz, LOW);
 }
 
 else 
  {
   Serial.println("unknown detected");
   Serial.print("dist= ");
   Serial.print(dist); 
 
   for (freq= 150; freq < 1800; freq+= 1) 
    { 
    tone(buzz, freq, period);
    delay(3);
    }
 
   for (freq= 1800; freq > 150; freq-= 1) 
    { 
    tone(buzz, freq, period);
    delay(3);
    }
 
  }
}
