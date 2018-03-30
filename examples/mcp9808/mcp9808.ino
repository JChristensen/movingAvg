// Arduino Moving Average Library
// https://github.com/JChristensen/movingAvg
// Copyright (C) 2018 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html
//
// Example sketch to smooth readings from an MCP9802 I2C temperature sensor.

#include <movingAvg.h>                  // https://github.com/JChristensen/movingAvg
#include <MCP9808.h>                    // https://github.com/JChristensen/MCP9808

MCP9808 mySensor;                       // define the temperature sensor
movingAvg avgTemp(10);                  // define the moving average object

void setup()
{
    Serial.begin(115200);
    delay(1000);                                // time for sensor to do an initial temperature conversion
    mySensor.begin();                           // initialize the sensor
    avgTemp.begin();                            // initialize the moving average
}

void loop()
{
    mySensor.read();
    int c16 = mySensor.tAmbient;                // °C * 16
    int avg = avgTemp.reading(c16);             // calculate the moving average
    Serial.print(c16 / 16.0);                   // print the individual reading
    Serial.print("C ");
    Serial.print(avg / 16.0);                   // print the moving average
    Serial.print("C\n");
    delay(1000);
}
