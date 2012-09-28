ReadMe file for Arduino Moving Average Library v1.1
https://github.com/JChristensen/movingAvg
Jack Christensen Mar 2012

This work is licensed under the Creative Commons Attribution-ShareAlike 3.0
Unported License. To view a copy of this license, visit
http://creativecommons.org/licenses/by-sa/3.0/ or send a letter to Creative
Commons, 171 Second Street, Suite 300, San Francisco, California, 94105, USA.

--------------------------------------------------------------------------------
Arduino library for calculating a moving average of sensor readings.
Useful for situations where a sensor is read at regular intervals.
Readings and the moving average are ints. LIST_LEN sets the number
of readings used to calculate the moving average (currently set to 6).

--------------------------------------------------------------------------------
To use the library:
(1) Go to https://github.com/JChristensen/movingAvg/downloads and download the
file in the compressed format of your choice (zip or tar.gz) to a convenient
location on your PC.
(2) Uncompress the downloaded file. This will result in a folder containing all
the files for the library, that has a name similar to "JChristensen-
movingAvg-42e98a7".
(3) Rename the folder to just "movingAvg".
(4) Copy the renamed folder to the Arduino sketchbook\libraries folder.

--------------------------------------------------------------------------------
The following example sketch is included with the movingAvg library:

photoCell: Smooths analog readings taken from a CdS photocell.

--------------------------------------------------------------------------------
Declare a movingAvg object as follows.

movingAvg photoCell;

--------------------------------------------------------------------------------
Add new readings to the moving average using the reading() method. This method
also returns the moving average value.

int pc = photoCell.reading ( analogRead(PHOTOCELL_PIN) );

--------------------------------------------------------------------------------
To just return the current moving average without adding a new reading:

int pc = photoCell.getAvg();

--------------------------------------------------------------------------------
