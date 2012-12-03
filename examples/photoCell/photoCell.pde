/*----------------------------------------------------------------------*
 * Example sketch for Arduino Moving Average Library v1.1               *
 *                                                                      *
 * Jack Christensen 28Sep 2012                                          *
 * v1.1 28Sep2012                                                       *
 *                                                                      *
 * Sketch to smooth the readings from a CdS photocell. Connect          *
 * the photocell from the A5 pin to ground. The internal pullup         *
 * resistor is used to form a voltage divider. A potentiometer or       *
 * something similar could be used in place of a photocell.             *
 *                                                                      *
 * This work is licensed under the Creative Commons Attribution-        *
 * ShareAlike 3.0 Unported License. To view a copy of this license,     *
 * visit http://creativecommons.org/licenses/by-sa/3.0/ or send a       *
 * letter to Creative Commons, 171 Second Street, Suite 300,            *
 * San Francisco, California, 94105, USA.                               *
 *----------------------------------------------------------------------*/

#include <movingAvg.h>                   //https://github.com/JChristensen/movingAvg

#define PHOTOCELL_PIN A5                 //connect photocell from A5 pin to ground
movingAvg photoCell;                     //declare the moving average object
int pc;                                  //a single photocell reading
int avg;                                 //the moving average

void setup(void)
{
    digitalWrite(PHOTOCELL_PIN, HIGH);    //turn on pullup resistor
    Serial.begin(115200);
}

void loop(void)
{
    pc = analogRead(PHOTOCELL_PIN);       //read the photocell
    avg = photoCell.reading(pc);          //calculate the moving average
    Serial.print(pc, DEC);                //print the individual reading
    Serial.print(' ');
    Serial.println(avg, DEC);             //print the moving average
    delay(1000);
}

