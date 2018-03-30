// Arduino Moving Average Library
// https://github.com/JChristensen/movingAvg
// Copyright (C) 2018 by Jack Christensen and licensed under
// GNU GPL v3.0, https://www.gnu.org/licenses/gpl.html

#include <movingAvg.h>

// initialize - allocate the interval array
void movingAvg::begin()
{
    m_readings = new int[m_interval];
}

// add a new reading and returns the new moving average
int movingAvg::reading(int newReading)
{
    // if first time through, fill the readings array
    if (m_first)
    {
        m_first = false;
        m_next = 0;
        m_sum = newReading * m_interval;
        for (int i=0; i<m_interval; i++)
        {
           m_readings[i] = newReading;
        }
    }
    else
    {
        m_sum = m_sum - m_readings[m_next] + newReading;
        m_readings[m_next] = newReading;
        m_next = ++m_next % m_interval;
    }
    return (m_sum + m_interval / 2) / m_interval;
}

// just return the current moving average
int movingAvg::getAvg()
{
    return (m_sum + m_interval / 2) / m_interval;
}
