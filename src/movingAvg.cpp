// Arduino Moving Average Library
// https://github.com/JChristensen/movingAvg
// Copyright (C) 2018 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html

#include <movingAvg.h>

// Constructor
movingAvg::movingAvg(int intervalSize) 
    : interval(intervalSize), numReadings(0), totalSum(0), nextIndex(0), readings(nullptr) {
}

// Destructor
movingAvg::~movingAvg() {
    delete[] readings;
}

void movingAvg::begin() {
    readings = new int[interval]();
    numReadings = 0;
    totalSum = 0;
    nextIndex = 0;
}

void movingAvg::getReadings(int* outArray, int maxSize) const {
    for (int i = 0; i < numReadings && i < maxSize; ++i) {
        outArray[i] = readings[i];
    }
}

int movingAvg::reading(int newReading) {
    if (numReadings < interval) {
        totalSum += newReading;
        readings[nextIndex++] = newReading;
        ++numReadings;
    } else {
        totalSum = totalSum - readings[nextIndex] + newReading;
        readings[nextIndex++] = newReading;
    }

    if (nextIndex >= interval) nextIndex = 0;

    return totalSum / numReadings;
}

int movingAvg::getAvg() {
    if (numReadings == 0) return 0;
    return numReadings < interval ? totalSum / numReadings : totalSum / interval;
}

int movingAvg::getAvg(int nPoints) {
    if (nPoints < 1 || nPoints > interval || nPoints > numReadings) return 0;
    
    long sum = 0;
    int currentIndex = (nextIndex - 1 + interval) % interval;
    for (int n = 0; n < nPoints; ++n) {
        sum += readings[currentIndex];
        currentIndex = (currentIndex - 1 + interval) % interval;
    }
    return sum / nPoints;
}

void movingAvg::reset() {
    numReadings = 0;
    totalSum = 0;
    nextIndex = 0;
}


