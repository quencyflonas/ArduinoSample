#include <Arduino.h>

byte ledData[10][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 1},
    {0, 0, 1, 0},
    {0, 0, 1, 1},
    {0, 1, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 1, 1, 1},
    {1, 0, 0, 0},
    {1, 0, 0, 1}};

void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);

  digitalWrite(6,1);
  digitalWrite(7,1);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(5,1);
digitalWrite(4,0);
digitalWrite(3,0);
digitalWrite(2,0);
}