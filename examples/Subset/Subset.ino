// Arduino Moving Average Library
// https://github.com/JChristensen/movingAvg
// Copyright (C) 2020 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html
//
// Example sketch to test/demonstrate calculating shorter term averages
// from a subset of the data, using just the most recent data points.

#include <movingAvg.h>      // https://github.com/JChristensen/movingAvg
#include <Streaming.h>      // https://github.com/janelia-arduino/Streaming

constexpr int arraySize{30};
movingAvg foo(arraySize);

void setup()
{
    Serial.begin(115200);
    Serial << F( "\n" __FILE__ "\nCompiled " __DATE__ " " __TIME__ "\n\n" );
    foo.begin();

    // generate sample data, more points than interval size
    for (int i=1; i<=42; ++i) {
        foo.reading(i);
    }

    avgTest("Average overall", foo.getAvg(),   28);
    avgTest("Average last 10", foo.getAvg(10), 38);
    avgTest("Average last 3 ", foo.getAvg(3),  41);
    avgTest("Average last 2 ", foo.getAvg(2),  42);
    avgTest("Average last 1 ", foo.getAvg(1),  42);
    avgTest("Average last 0 ", foo.getAvg(0),   0);
    avgTest("Average last 30", foo.getAvg(30), 28);
    avgTest("Average last 31", foo.getAvg(31),  0);

    Serial << endl;
    foo.reset();
    // generate sample data, fewer points than interval size
    for (int i=1; i<=17; ++i) {
        foo.reading(i);
    }
    avgTest("Average overall", foo.getAvg(),    9);
    avgTest("Average last 10", foo.getAvg(10), 13);
    avgTest("Average last 3 ", foo.getAvg(3),  16);
    avgTest("Average last 2 ", foo.getAvg(2),  17);
    avgTest("Average last 1 ", foo.getAvg(1),  17);
    avgTest("Average last 0 ", foo.getAvg(0),   0);
    avgTest("Average last 30", foo.getAvg(30),  0);
    avgTest("Average last 31", foo.getAvg(31),  0);
    avgTest("Average last 17", foo.getAvg(17),  9);
}

// function to compare the average returned by the library to the known correct value
void avgTest(const char* msg, int val, int correctVal)
{
    Serial << msg << ": " << val << " ... ";
    if (val == correctVal) {
        Serial << "OK\n";
    }
    else {
        Serial << "ERROR, expected " << correctVal << endl;
    }
}

void loop() {}
