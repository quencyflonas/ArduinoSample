#include <Arduino.h>

#define BIN1 2
#define BIN2 3
#define BIN4 4
#define BIN8 5
#define BI001 6
#define BI010 7
#define BI100 8

#define ScoreGet1 10
#define ScoreGet5 11
#define ScoreGet10 12
#define ScoreClear 9



void NumberOutput(int);
void LED_PrintOut();
void ScoreCount();
void ScoreButtonCheck();
int Score = 0;
unsigned long time_pre;
unsigned long DelayTime = 150;

void setup() {
  // put your setup code here, to run once:

  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(BIN4,OUTPUT);
  pinMode(BIN8,OUTPUT);
  pinMode(BI001,OUTPUT);
  pinMode(BI010,OUTPUT);
  pinMode(BI100,OUTPUT);

  pinMode(ScoreGet1,INPUT);
  pinMode(ScoreGet5,INPUT);
  pinMode(ScoreGet10,INPUT);
  pinMode(ScoreClear,INPUT);

  time_pre = millis();

}

void loop() {

  ScoreButtonCheck();
  LED_PrintOut();
  ScoreCount();

}

void ScoreButtonCheck()
{
  if (digitalRead(ScoreClear) == 1)
  {
    Score = 0;
  }
  if (digitalRead(ScoreGet1) == 1)
  {
    Score += 1;
  }
  if (digitalRead(ScoreGet5) == 1)
  {
    Score += 5;
  }
  if (digitalRead(ScoreGet10) == 1)
  {
    Score += 10;
  }
}

void ScoreCount()
{
  unsigned long time_this = millis();
  if (time_this - time_pre > DelayTime)
  {
    Score++;
    if (Score > 99)
    {
      Score = 0;
    }
    time_pre += DelayTime;
  }
}

void LED_PrintOut()
{
  //int digital_100 = Score / 100;
  int digital_010 = (Score / 10);// - (Score % 10);
  int digital_001 = Score % 10;

  digitalWrite(BI001, 1);
  digitalWrite(BI010, 0);
  // digitalWrite(BI100,0);
  NumberOutput(digital_001);

  delay(5);
  digitalWrite(BI001, 0);
  digitalWrite(BI010, 1);
  // digitalWrite(BI100,0);
  NumberOutput(digital_010);

  delay(5);
  //digitalWrite(BI001, 0);
  //digitalWrite(BI010, 0);
  //digitalWrite(BI100,1);
  //NumberOutput(digital_100);
  //delay(5);
}
// 輸出數字至74 IC，並選擇位數
void NumberOutput(int ShowData){

  byte ledData[10][4] = {
      {0, 0, 0, 0},
      {1, 0, 0, 0},
      {0, 1, 0, 0},
      {1, 1, 0, 0},
      {0, 0, 1, 0},
      {1, 0, 1, 0},
      {0, 1, 1, 0},
      {1, 1, 1, 0},
      {0, 0, 0, 1},
      {1, 0, 0, 1}};

      for(int pd = 0; pd<4 ; pd++)
      {
        digitalWrite(BIN1+pd, ledData[ShowData][pd]);
      }
}


