/*
  Project: Gwendoline's Home Rolling Door Anti-presure sensing conrtol
  Design : Quency.Wang
  Action : When rolling down, first bar get push and magnetic reed switch on,
           one time output 1Sec flash ON to the remote control's stop button.
  Self Check : When Battery Voltage Low , Buzzer ON
  controller : CJMCU ATtiny85
  define :
          p0 : MRS_IN -> from Magnetic reed switch input
          p1 : EMPTY  -> No Use
          p2 : EMPTY  -> No Use
          p3 : EMPTY  -> No Use
          p4 : Remote -> to Rolling Door Remote Controller Stop button.
*/

#include <Arduino.h>
#include <Thread.h>

// PIN Define
#define MRS_IN 0
#define LedPin 2
#define Remote 4

// Use Time Const
#define StopTime 1000     // Stop Signal Interval Time
#define DETECT_Clock 500  // Loop Interval Time

// Scan Loop Thread
Thread MRS_Scan = Thread();

// Check Status , if Stop singal seted then true,else false
boolean checkStatus = false;

// LED flash Time Count
int LED_InTime = 0;

int MagenticReedSwitchStatus = 0;

void MRS_Check();
void LED_Flash();

void setup()
{
 pinMode(MRS_IN,INPUT);
 pinMode(LedPin,OUTPUT);
 pinMode(Remote,OUTPUT);
 MRS_Scan.onRun(MRS_Check);
 MRS_Scan.setInterval(DETECT_Clock);

 Serial.begin(9600);
}

void loop()
{
  
  if(MRS_Scan.shouldRun())
  {
    MRS_Scan.run();
  } else digitalWrite(LedPin,LOW);
   
}

// Magentic Reed Switch Status Check and Rolling Door Stop Control
void MRS_Check()
{
  // Digital Read from MRS_IN Pin
  MagenticReedSwitchStatus = digitalRead(MRS_IN);

  if (MagenticReedSwitchStatus == HIGH)
  {
    if (checkStatus == false)
    {
      digitalWrite(Remote, HIGH);
      delay(StopTime);
      digitalWrite(Remote, LOW);
      checkStatus = true;
    }
  }
  else if (MagenticReedSwitchStatus == LOW)
  {
    digitalWrite(Remote, LOW);
    checkStatus = false;
  }
  LED_InTime++;
  if (LED_InTime >= 30)
    LED_Flash();
}

// LED Flash
void LED_Flash()
{
  digitalWrite(LedPin, HIGH);
  LED_InTime = 0;
}