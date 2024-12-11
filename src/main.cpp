#include <Arduino.h>
#include <Wire.h>

#define VIBRATION_SENSOR 4

unsigned int vibration_count = 0;

IRAM_ATTR void vibration_detected()
{
  vibration_count++;
}

void setup()
{
  Serial.begin(115200);
  pinMode(VIBRATION_SENSOR, INPUT);
  attachInterrupt(4, vibration_detected, FALLING);
}

void loop()
{
  if (vibration_count > 0)
  {
    Serial.printf("Vibration detected! %u\n", vibration_count);
    vibration_count = 0;
  }
}