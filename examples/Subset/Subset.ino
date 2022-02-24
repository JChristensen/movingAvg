// Arduino Moving Average Library
// https://github.com/JChristensen/movingAvg
// Copyright (C) 2020 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html
//
// Example sketch to demonstrate calculating shorter term averages
// from a subset of the data, using just the most recent data points.

#include <movingAvg.h>          // https://github.com/JChristensen/movingAvg

constexpr int arraySize {30};
movingAvg foo(arraySize);

void setup()
{
    Serial.begin(115200);
    foo.begin();

    // generate some sample data
    for (int i=1; i<=arraySize; ++i) {
        foo.reading(i);
    }

    Serial.print("Average overall: ");
    Serial.println(foo.getAvg());
    Serial.print("Average last 10: ");
    Serial.println(foo.getAvg(10));
    Serial.print("Average last 3:  ");
    Serial.println(foo.getAvg(3));
    Serial.print("Average last 2:  ");
    Serial.println(foo.getAvg(2));
    Serial.print("Average last 1:  ");
    Serial.println(foo.getAvg(1));
    Serial.print("Average last 0:  ");
    Serial.println(foo.getAvg(0));
    Serial.print("Average last 30: ");
    Serial.println(foo.getAvg(30));
    Serial.print("Average last 31: ");
    Serial.println(foo.getAvg(31));
}

void loop() {}
