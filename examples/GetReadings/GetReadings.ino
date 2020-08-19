// Arduino Moving Average Library
// https://github.com/JChristensen/movingAvg
// Copyright (C) 2020 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html
//
// Example sketch to demonstrate retrieving the readings
// from a movingAvg object.

#include <movingAvg.h>          // https://github.com/JChristensen/movingAvg

movingAvg foo(6);

void setup()
{
    Serial.begin(115200);
    foo.begin();
    foo.reading(1);             // generate some sample data
    foo.reading(2);
    foo.reading(3);
    foo.reading(4);
    //foo.reading(5);
    //foo.reading(6);

    int *readings = foo.getReadings();  // returns a pointer to the readings
    int n = foo.getCount();             // returns the number of readings
    Serial.print("There are ");
    Serial.print(n);
    Serial.println(" readings:");
    for (int i=0; i<n; i++) {
        Serial.println(*readings++);
    }
}

void loop()
{
}
