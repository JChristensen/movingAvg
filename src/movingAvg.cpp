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

#include "movingAvg.h"

movingAvg::movingAvg() {
    _first = true;
}

//adds a new reading and returns the new moving average
int movingAvg::reading(int newReading) {
    if (_first) {                       //if first time through, fill the readings array
        _first = false;
        _next = 0;
        _sum = newReading * LIST_LEN;
        for (uint8_t i=0; i<LIST_LEN; i++) {
           _readings[i] = newReading;
        }
    }
    else {
        _sum = _sum - _readings[_next] + newReading;
        _readings[_next] = newReading;
        _next = ++_next % LIST_LEN;
    }
    return (_sum + LIST_LEN / 2) / LIST_LEN;
}

//just returns the current moving average
int movingAvg::getAvg(void) {
    return (_sum + LIST_LEN / 2) / LIST_LEN;
}
