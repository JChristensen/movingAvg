// Arduino Moving Average Library
// https://github.com/JChristensen/movingAvg
// Copyright (C) 2018 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html

#ifndef MOVINGAVG_H_INCLUDED
#define MOVINGAVG_H_INCLUDED

class movingAvg
{
    public:
        movingAvg(int interval)
            : m_interval(interval), m_nbrReadings(0), m_first(true) {}
        void begin();
        int reading(int newReading);
        int getAvg();
    
    private:
        int m_interval;     // number of data points for the moving average
        int m_nbrReadings;  // number of readings
        bool m_first;       // first-time switch
        int *m_readings;    // pointer to the dynamically allocated interval array
        long m_sum;         // sum of the m_readings array
        int m_next;         // index to the next reading
};
#endif
