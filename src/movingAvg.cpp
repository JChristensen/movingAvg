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

// add a new reading and return the new moving average
int movingAvg::reading(int newReading)
{
    if (m_nbrReadings < m_interval)
    {
        ++m_nbrReadings;
        m_sum = m_sum + newReading;
    }
    else
    {
        m_sum = m_sum - m_readings[m_next] + newReading;
    }
    
    m_readings[m_next] = newReading;
    if (++m_next >= m_interval) m_next = 0;
    return (m_sum + m_nbrReadings / 2) / m_nbrReadings;
}

// just return the current moving average
int movingAvg::getAvg()
{
    return (m_sum + m_nbrReadings / 2) / m_nbrReadings;
}
