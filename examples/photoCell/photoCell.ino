// Arduino Moving Average Library
// https://github.com/JChristensen/movingAvg
// Copyright (C) 2018 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html
//
// Example sketch to smooth the readings from a CdS photocell.
// Connect the photocell from the A0 pin to ground. The internal pullup
// resistor is used to form a voltage divider. A potentiometer or
// something similar could be used in place of a photocell.

#include <movingAvg.h>                  // https://github.com/JChristensen/movingAvg

const uint8_t PHOTOCELL_PIN(A0);        // connect photocell from A0 pin to ground
movingAvg photoCell(10);                // define the moving average object

void setup()
{
    pinMode(PHOTOCELL_PIN, INPUT_PULLUP);
    Serial.begin(115200);
    photoCell.begin();
}

void loop()
{
    int pc = analogRead(PHOTOCELL_PIN); // read the photocell
    int avg = photoCell.reading(pc);    // calculate the moving average
    Serial.print(pc);                   // print the individual reading
    Serial.print(' ');
    Serial.println(avg);                // print the moving average
    delay(1000);
}
