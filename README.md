# Arduino Moving Average Library
https://github.com/JChristensen/movingAvg  
README file  
Jack Christensen  
Mar 2012  

## License
Arduino movingAvg Library Copyright (C) 2018 Jack Christensen GNU GPL v3.0

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License v3.0 as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <https://www.gnu.org/licenses/gpl.html>

## Description
*movingAvg* is a simple Arduino library for calculating moving averages. It is useful for smoothing sensor readings, etc. For efficiency, the library operates in the integer domain. This means that the calculated moving averages are mathematically approximate. Both data input to the library and the returned moving averages are 16-bit signed integers.

The user specifies the interval (number of data points) for the moving average in the constructor. When the `begin()` function is called, an array is dynamically allocated to hold the number of data points in the interval. This array is never deallocated, and the user should call `begin()` only once (for a given `movingAvg` instance) in setup or other initialization code. Dynamic allocation is used strictly with the intent of creating the proper size array for the user's purposes, and not to free up the memory at a later point. It is strongly recommended that `movingAvg` objects remain allocated as long as the code is running. Failure to observe these guidelines can result in heap fragmentation, crashes and other undesired behavior.

## Constructor
### movingAvg(int interval)
##### Description
Defines a `movingAvg` object where the average is calculated using *interval* data points.
##### Syntax
`movingAvg(interval);`
##### Parameters
**interval:** The number of data points to use when calculating the moving average. *(int)*
##### Returns
None.
##### Example
```c++
movingAvg mySensor(10);    // use 10 data points for the moving average
```

## Methods
### begin()
##### Description
Initializes a `movingAvg` object. Call `begin()` once and only once for any given `movingAvg` instance. See comments in the **Description** section above.
##### Syntax
`begin();`
##### Parameters
None.
##### Returns
None.
##### Example
```c++
movingAvg mySensor(10);    // use 10 data points for the moving average
mySensor.begin();
```

### reading(int dataPoint)
##### Description
Adds a new data point to the moving average. Returns the new moving average value. Until the interval array is filled, the average is calculated from those data points already added, i.e. a fewer number of points than defined by the constructor - thanks to Tom H. (Duckie) for this idea!
##### Syntax
`reading(dataPoint);`
##### Parameters
**dataPoint:** The new data point to be added to the moving average. *(int)*
##### Returns
The new moving average value. *(int)*
##### Example
```c++
int sensorData = analogRead(SENSOR_PIN);
int sensorMovingAvg = mySensor.reading(sensorData);
```

### getAvg()
##### Description
Returns the current moving average value without adding a new reading.
##### Syntax
`getAvg();`
##### Parameters
None.
##### Returns
The moving average value. *(int)*
##### Example
```c++
int sensorMovingAvg = mySensor.getAvg();
```

### getCount()
##### Description
Returns the number of data points collected for the moving average, a number between zero and *interval*. This function can be used to determine if a valid moving average exists. This may be useful, for example, to avoid calling `getAvg()` before any data points have been added to the moving average. Calling `getAvg()` before any data points are added causes a divide by zero which will result in invalid data and/or undefined/undesired behavior.
##### Syntax
`getCount();`
##### Parameters
None.
##### Returns
The number of data points. *(int)*
##### Example
```c++
int n = mySensor.getCount();
```

### reset()
##### Description
Restarts the moving average. Zeros the interval array and associated data.
##### Syntax
`reset();`
##### Parameters
None.
##### Returns
None.
##### Example
```c++
mySensor.reset();
```

### getReadings()
##### Description
Returns a pointer to the integer array containing the collected data points.
##### Syntax
`getReadings();`
##### Parameters
None.
##### Returns
Pointer to an integer array. *(int\*)*
##### Example
```c++
movingAvg foo(6);
...
int* myData;
myData = foo.getReadings();
Serial.println(myData[0]);  // first data point
Serial.println(myData[1]);  // second data point
// etc.
```