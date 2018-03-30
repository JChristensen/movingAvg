// Arduino Moving Average Library
// https://github.com/JChristensen/movingAvg
// Copyright (C) 2018 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html
//
// Example sketch to smooth the readings from a TMP36 analog temperature sensor.
// Connect the sensor to the A0 pin.

#include <movingAvg.h>                  // https://github.com/JChristensen/movingAvg

const uint8_t SENSOR_PIN(A0);           // connect sensor to A0 pin
movingAvg avgTemp(10);                  // define the moving average object

void setup()
{
    Serial.begin(115200);
    avgTemp.begin();
}

void loop()
{
    int tC100 = readTMP36(SENSOR_PIN);  // read the sensor
    int avg = avgTemp.reading(tC100);   // calculate the moving average
    Serial.print(tC100 / 100.0);        // print the individual reading
    Serial.print("C  ");
    Serial.print(avg / 100.0);        // print the moving average
    Serial.print("C\n");
    delay(1000);
}

// read TMP36 temperature sensor, return °C * 100
// TMP36 output is 10mV/C with a 500mV offset
long readTMP36(int muxChannel)
{
    long uV = (analogRead(muxChannel) * 5000000L + 512) / 1024;    //microvolts from the TMP36 sensor
    return (uV - 500000 + 50) / 100;
}

