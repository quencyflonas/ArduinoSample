
#include <Arduino.h>
#include <Thread.h>

#define OutputLSB1 2
#define OutputLSB2 4
#define OutputLSB4 7
#define OutputLSB8 8

void LedChange(int);
void inputWait();
void NumberOutput(int, int);

    void setup()
{
  // put your setup code here, to run once:
  // PinMode
  pinMode(OutputLSB1, OUTPUT);
  pinMode(OutputLSB2, OUTPUT);
  pinMode(OutputLSB4, OUTPUT);
  pinMode(OutputLSB8, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Input Your Number (0~9) :");
  while(Serial.available()){

  }
  int data = Serial.parseInt();
  LedChange(data);

}

void NumberOutput(int ShowData, int Digital){
  switch (InputData)
  {
  case 0:
    //0
    digitalWrite(OutputLSB1, LOW);
    digitalWrite(OutputLSB2, LOW);
    digitalWrite(OutputLSB4, LOW);
    digitalWrite(OutputLSB8, LOW);
    Serial.println("0 Output");
    break;

  case 1:
    //1
    digitalWrite(OutputLSB1, HIGH);
    digitalWrite(OutputLSB2, LOW);
    digitalWrite(OutputLSB4, LOW);
    digitalWrite(OutputLSB8, LOW);

    break;

  case 2:
    //2
    digitalWrite(OutputLSB1, LOW);
    digitalWrite(OutputLSB2, HIGH);
    digitalWrite(OutputLSB4, LOW);
    digitalWrite(OutputLSB8, LOW);
    break;

  case 3:
    //3
    digitalWrite(OutputLSB1, HIGH);
    digitalWrite(OutputLSB2, HIGH);
    digitalWrite(OutputLSB4, LOW);
    digitalWrite(OutputLSB8, LOW);
    break;

  case 4:
    //4
    digitalWrite(OutputLSB1, LOW);
    digitalWrite(OutputLSB2, LOW);
    digitalWrite(OutputLSB4, HIGH);
    digitalWrite(OutputLSB8, LOW);
    break;

  case 5:
    //5
    digitalWrite(OutputLSB1, HIGH);
    digitalWrite(OutputLSB2, LOW);
    digitalWrite(OutputLSB4, HIGH);
    digitalWrite(OutputLSB8, LOW);
    break;

  case 6:
    //6
    digitalWrite(OutputLSB1, LOW);
    digitalWrite(OutputLSB2, HIGH);
    digitalWrite(OutputLSB4, HIGH);
    digitalWrite(OutputLSB8, LOW);
    break;

  case 7:
    //7
    digitalWrite(OutputLSB1, HIGH);
    digitalWrite(OutputLSB2, HIGH);
    digitalWrite(OutputLSB4, HIGH);
    digitalWrite(OutputLSB8, LOW);
    break;

  case 8:
    //8
    digitalWrite(OutputLSB1, LOW);
    digitalWrite(OutputLSB2, LOW);
    digitalWrite(OutputLSB4, LOW);
    digitalWrite(OutputLSB8, HIGH);
    break;

  case 9:
    //9
    digitalWrite(OutputLSB1, HIGH);
    digitalWrite(OutputLSB2, LOW);
    digitalWrite(OutputLSB4, LOW);
    digitalWrite(OutputLSB8, HIGH);
    break;

  default:
    digitalWrite(OutputLSB1, LOW);
    digitalWrite(OutputLSB2, LOW);
    digitalWrite(OutputLSB4, LOW);
    digitalWrite(OutputLSB8, LOW);
  }

void LedChange(int InputData){

switch (InputData)
{
  case 0:
  //0
  digitalWrite(OutputLSB1, LOW);
  digitalWrite(OutputLSB2, LOW);
  digitalWrite(OutputLSB4, LOW);
  digitalWrite(OutputLSB8, LOW);
  Serial.println("0 Output");
  break;

  case 1:
  //1
  digitalWrite(OutputLSB1, HIGH);
  digitalWrite(OutputLSB2, LOW);
  digitalWrite(OutputLSB4, LOW);
  digitalWrite(OutputLSB8, LOW);
  
  break;

  case 2:
  //2
  digitalWrite(OutputLSB1, LOW);
  digitalWrite(OutputLSB2, HIGH);
  digitalWrite(OutputLSB4, LOW);
  digitalWrite(OutputLSB8, LOW);
  break;

  case 3:
  //3
  digitalWrite(OutputLSB1, HIGH);
  digitalWrite(OutputLSB2, HIGH);
  digitalWrite(OutputLSB4, LOW);
  digitalWrite(OutputLSB8, LOW);
  break;

  case 4:
  //4
  digitalWrite(OutputLSB1, LOW);
  digitalWrite(OutputLSB2, LOW);
  digitalWrite(OutputLSB4, HIGH);
  digitalWrite(OutputLSB8, LOW);
  break;

 case 5:
  //5
  digitalWrite(OutputLSB1, HIGH);
  digitalWrite(OutputLSB2, LOW);
  digitalWrite(OutputLSB4, HIGH);
  digitalWrite(OutputLSB8, LOW);
  break;

  case 6:
  //6
  digitalWrite(OutputLSB1, LOW);
  digitalWrite(OutputLSB2, HIGH);
  digitalWrite(OutputLSB4, HIGH);
  digitalWrite(OutputLSB8, LOW);
  break;

  case 7:
  //7
  digitalWrite(OutputLSB1, HIGH);
  digitalWrite(OutputLSB2, HIGH);
  digitalWrite(OutputLSB4, HIGH);
  digitalWrite(OutputLSB8, LOW);
  break;

  case 8:
  //8
  digitalWrite(OutputLSB1, LOW);
  digitalWrite(OutputLSB2, LOW);
  digitalWrite(OutputLSB4, LOW);
  digitalWrite(OutputLSB8, HIGH);
  break;

  case 9:
  //9
  digitalWrite(OutputLSB1, HIGH);
  digitalWrite(OutputLSB2, LOW);
  digitalWrite(OutputLSB4, LOW);
  digitalWrite(OutputLSB8, HIGH);
  break;

  default:
   digitalWrite(OutputLSB1, LOW);
   digitalWrite(OutputLSB2, LOW);
   digitalWrite(OutputLSB4, LOW);
   digitalWrite(OutputLSB8, LOW);
}
}

void inputWait(){





}