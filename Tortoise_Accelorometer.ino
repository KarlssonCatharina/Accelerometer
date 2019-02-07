



/*
  SD card datalogger for accelorometer data

 This example shows how to log data from an accelorometer sensor
 to an SD card using the SD library as well as keeping track of time using milliseconds since start.

 The circuit:
 * SD card attached to SPI bus as follows: pin 10 used for writing on Tinyduino


Created on the 4th of February 2019 by Catharina Karlsson for Tinyduino


 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "BMA250.h"

unsigned long time;

const int chipSelect = 10; //TinyDuino uses pin 10

BMA250 accel_sensor;
int x, y, z;   //set integer
double temp;   //set temperature measurement

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Wire.begin();
  accel_sensor.begin(BMA250_range_2g, BMA250_update_time_64ms);//This sets up the BMA250 accelerometer

  //Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    //Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  //Serial.println("card initialized.");
}

void loop() 
{
  // make a string for assembling the data to log:
  String dataString = "";

  // read in accelorometer data and put it in a string
  accel_sensor.read();//This function gets new data from the accelerometer
  // Get the acceleration values from the sensor and store them into global variables
  // (Makes reading the rest of the program easier)
  x = accel_sensor.X;
  y = accel_sensor.Y;
  z = accel_sensor.Z;
  temp = ((accel_sensor.rawTemp * 0.5) + 24.0);
  time = millis();

  dataString = String(x) + "," + String(y) + "," + String(z) + "," + String(temp) + "," + String(time);
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.csv", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    //Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    //Serial.println("error opening datalog.csv");
  }
  delay(250); // delay before next write to SD Card, adjust as required

}



 
