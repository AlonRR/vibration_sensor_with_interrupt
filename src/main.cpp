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
  /**
   * mode: defines when the interrupt should be triggered. Four constants are predefined as valid values:
   *
   * LOW to trigger the interrupt whenever the pin is low
   *
   * CHANGE to trigger the interrupt whenever the pin changes value
   *
   * RISING to trigger when the pin goes from low to high
   *
   * FALLING for when the pin goes from high to low
   * https://reference.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/#:~:text=mode%3A%20defines%20when,high%20to%20low.
   */
  attachInterrupt(digitalPinToInterrupt(VIBRATION_SENSOR), vibration_detected, FALLING);
}

void loop()
{
  if (vibration_count > 0)
  {
    Serial.printf("Vibration detected! %u\n", vibration_count);
    vibration_count = 0;
  }
}