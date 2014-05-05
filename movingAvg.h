/*----------------------------------------------------------------------*
 * Arduino Moving Average Library v1.1                                  *
 *                                                                      *
 * Jack Christensen                                                     *
 * v1.0 29Jun2011                                                       *
 * v1.1 28Sep2012                                                       *
 *                                                                      *
 * Arduino library for calculating a moving average of sensor readings. *
 * Useful for situations where a sensor is read at regular intervals.   *
 * Readings and the moving average are ints. LIST_LEN sets the number   *
 * of readings used to calculate the moving average (currently set      *
 * to 6).                                                               *
 *                                                                      *
 * This work is licensed under the Creative Commons Attribution-        *
 * ShareAlike 3.0 Unported License. To view a copy of this license,     *
 * visit http://creativecommons.org/licenses/by-sa/3.0/ or send a       *
 * letter to Creative Commons, 171 Second Street, Suite 300,            *
 * San Francisco, California, 94105, USA.                               *
 *----------------------------------------------------------------------*/
 
#ifndef movingAvg_h
#define movingAvg_h
#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h> 
#else
#include <WProgram.h> 
#endif

#define LIST_LEN 6          //average six readings

class movingAvg
{
    public:
        movingAvg();
        int reading(int newReading);
        int getAvg();
        void reset();

    private:
        int _readings[LIST_LEN];
        int _sum;           //sum of the _readings array
        boolean _first;     //first-time switch
        uint8_t _next;      //index to the next reading
};
#endif