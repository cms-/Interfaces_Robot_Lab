#include <HalfBridge.h>
#include <openGLCD.h>
#include <Audio.h>
#include <SD.h>
#include <Wire.h>
#include <SPI.h>

Motor motors[2] = { Motor(5, 33, 32), Motor(10, 24, 26) };
volatile uint8_t turnFlag = 0;
gText display;

#define DRV_DURATION 500
#define MAX_SPEED 192
#define MIN_SPEED 48
#define INCREMENT 24
#define TURN 5
#define MIC_THRESHOLD 600

// setup pins for sensors
const int photoPowerPin = 25;
const int photoLeft = 29;
const int photoRight = 28;
const int micPin = 0;
const int whiskerPin = 30;

// setup Teensy sample player for 12 bit DAC via piezo
#include "AudioSampleR2d2.h"
#include "AudioSamplePew.h"
#include "AudioSampleYoink.h"
#include "AudioSampleSpacegas.h"
#include "AudioSampleSwish.h"
AudioPlayMemory    sound0;
AudioMixer4        mix1;
AudioOutputAnalog  dac;
AudioConnection    patchCord1(sound0, 0, mix1, 0);
AudioConnection    patchCord2(mix1, 0, dac, 0);

void setup() 
{  
  motors[0].init();
  motors[1].init();
  
  // set up pins for photo sensor array
  pinMode(photoPowerPin, OUTPUT);
  pinMode(photoLeft, INPUT);
  pinMode(photoRight, INPUT);
  pinMode(whiskerPin, INPUT);
   
  attachInterrupt(whiskerPin, WhiskerISR, RISING);
  
  InitDisplay();  
  InitSqueaker();
}

void loop()
{
  // default state is driving forward
  int drvState = 1;
  int i;
  int val;
  
  // check the photo sensors to see if they're active
  digitalWrite(photoPowerPin, HIGH);
  delay(40);
  if (digitalRead(photoRight) == HIGH) 
  {
    drvState = 2;
    //display.print("pright ");
  }
  if (digitalRead(photoLeft) == HIGH)
  {
    drvState = 3;
    //display.print("pleft ");
  }
  digitalWrite(photoPowerPin, LOW);
  
  // sample the mic several times to see if we pick up a 
  // sound above MIC_THRESHOLD 
  for (i=0; i<18; i++)
  {
    val = analogRead(micPin);
    //display.print(val);
    //display.print(" ");
    if (val > MIC_THRESHOLD)
    {
      drvState = 5;
    }
  }
  if (turnFlag == 1) // check the turnaround flag
  {
    TurnAround();
    turnFlag = 0;
  } else 
  {
    Display(drvState);
    Drive(drvState, DRV_DURATION);
    Squeak(drvState);
  }
  
}
