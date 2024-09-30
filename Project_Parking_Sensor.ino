#include "SR04.h"
#define tonePin   4   
#define trigPin   6    
#define echoPin   5   
#define LED_Green 11
#define LED_Yellow 12
#define LED_Red 13
SR04 sr04 = SR04(echoPin,trigPin);
long distance;

void setup() {
  Serial.begin(9600);
  delay(500);
  pinMode(tonePin, OUTPUT);
  pinMode(LED_Green, OUTPUT);
  pinMode(LED_Yellow, OUTPUT);
  pinMode(LED_Red, OUTPUT);
}
void loop() {
  distance = sr04.Distance();
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);
  digitalWrite(LED_Green , LOW);
  digitalWrite(LED_Yellow , LOW);
  digitalWrite(LED_Red , LOW);
  if (distance <=25 && distance >= 0) 
      {
       digitalWrite(LED_Red , HIGH);
       Serial.print(" Danger distance ");
       tone(tonePin , 200000 , 200);
       delay(100);
       noTone(tonePin);
    
      } 
   else if (distance <= 40 && distance >=26 )
      {   
       digitalWrite(LED_Yellow , HIGH);
       Serial.print(" Medium distance ");
       tone(tonePin , 200000 , 100);
       delay(100);
       noTone(tonePin);
      }
   else
      {
       digitalWrite(LED_Green , HIGH);
       Serial.print(" save distance ");
      }
}
