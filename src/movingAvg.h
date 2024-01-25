// Arduino Moving Average Library
// https://github.com/JChristensen/movingAvg
// Copyright (C) 2018 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html

#ifndef MOVINGAVG_H_INCLUDED
#define MOVINGAVG_H_INCLUDED

class movingAvg {
public:
    movingAvg(int intervalSize); // Constructor
    ~movingAvg();                // Destructor
    void begin();
    int reading(int newReading);
    int getAvg();
    int getAvg(int nPoints);
    int getCount() const { return numReadings; }
    void reset();
    int* getReadingsArray() const { return readings; }
    void getReadings(int* outArray, int maxSize) const;

private:
    int interval;       // Number of data points for the moving average
    int numReadings;    // Number of readings
    long totalSum;      // Sum of the readings array
    int nextIndex;      // Index to the next reading
    int* readings;      // Pointer to the dynamically allocated interval array
};

#endif // MOVINGAVG_H_INCLUDED

