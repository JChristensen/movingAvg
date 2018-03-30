// Arduino Moving Average Library
// https://github.com/JChristensen/movingAvg
// Copyright (C) 2018 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html
//
// Example sketch to smooth readings from an MCP9802 I2C temperature sensor.

#include <movingAvg.h>                  // https://github.com/JChristensen/movingAvg
#include <MCP9800.h>                    // https://github.com/JChristensen/MCP9800

MCP9800 mySensor;                       // define the temperature sensor
movingAvg avgTemp(10);                  // define the moving average object

void setup()
{
    Serial.begin(115200);
    mySensor.begin();                           // initialize the sensor
    mySensor.writeConfig(ADC_RES_12BITS);       // max resolution, 0.0625 °C
    avgTemp.begin();                            // initialize the moving average
}

void loop()
{
    int c16 = mySensor.readTempC16(AMBIENT);    // returns °C * 16
    int avg = avgTemp.reading(c16);             // calculate the moving average
    Serial.print(c16 / 16.0);                   // print the individual reading
    Serial.print("C ");
    Serial.print(avg / 16.0);                   // print the moving average
    Serial.print("C\n");
    delay(1000);
}
