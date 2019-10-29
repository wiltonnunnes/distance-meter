//#include <Wire.h>
#include <LiquidCrystal.h>

const int trigPin = 2;
const int echoPin = 3;

const int buttonPin = A0;
int buttonCurrState = HIGH;
int buttonPrevState = HIGH;

//const int addr = 0x1C;

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup() {
  //Wire.begin();
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonCurrState = digitalRead(buttonPin);
  if (buttonCurrState == LOW && buttonPrevState == HIGH) {
    unsigned long duration;
    float distanceCm;
  
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distanceCm = ((float) duration / 29.1) / 2;

    lcd.clear();
    lcd.print(distanceCm);
    lcd.print("cm");

    //Wire.requestFrom(addr, 7);
  }
  buttonPrevState = buttonCurrState;
}
