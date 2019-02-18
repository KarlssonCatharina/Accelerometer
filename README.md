# Accelerometer

#Arduino code for a accelerometer initially made for tortoise tracking using a 3-axis accelerometer with TinyDuino. The script stores data in a CSV file with five columns: X, Y, Z, Temperature and Milliseconds (since start). 

#Initial tests indicate a ~10mAh power usage. To reduce power usage a Real Time Clock was not added, instead the unit keeps track of milliseconds since it was last started. If time and date is needed these need to be recorded when the unit is started and the millisecond column can then be converted. 

#Instructional video in link: https://youtu.be/4A9uOH046pg
