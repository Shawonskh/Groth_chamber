# Growth Chamber for Plants
Introduction
How often do you find your favourite flowers or healthy house-grown vegetables dry and dead because you are always forget to water them? How many times the idea of having your own small garden with healing herbs came to your mind? 
We suppose that our Growth Chamber for Plants can be used at any place and any conditions where plants supposed to grow. The reason for that is that this Smart Chamber will help you to automate and improve the process of growing the plants in couple of clicks!
The Smart Chamber will keep track of temperature and humidity around the plant, preserve the necessary humidity level and extend the light cycle which is crucial for fast and positive growth.
You need to choose the plant, prepare the water supply, setup couple of settings and enjoy the life while Chamber is doing its job


We are team of 4 Science&Technology students who really want to combine biology and robotics together!

# Copyright and Authors (C) 2018 Dainis Ivanovs, Daniel Shmidt, Kirill Demishin, Sakhawat Shawon
blondaisd@gmail.com
d.shmidt99@gmail.com
demishin.kirill@gmail.com
shawon95@icloud.com

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

Component list
quantity
Where to get
We bye at shop
Flower pot
1-2
Take from teachers
Arduino Nano
1
Temperature and humidity sensor module
1
3 colour LED module
1-2
General servo
1
Light sensor
1
Sonar
1


I checked the repository the project has been discussed and we are planning to make next steps as soon as possible. By Sakhawat
~~This text is nothing just a test-commit~~
~~K joined~~
--The D joined lobby---
Eastern EU server


# Overview:
We are going to solve the problem of getting fresh vegetables (onions and green onions in our project)
in less then favorable enviroments like during the winter when growing basic greens is problematic.
We are planning to construct a cube shaped construct. The upper side of it will have LED's (for delivering enough light to the plant for sufficient growth),
an ultrasonic sensor for distance detection to the plant and a continuous motor for adjusting height from the plant.
The construct will also include humidity sensors in the enviroment(to detect air humidity) and a humidity sensor in the soil(to determine
if the plant has to be watered) and a light sensor to determine if the plant has sufficient amounts of light). We are going to use Raspberry pi as our mainboard and main computer.
And a computer fan to help with air circulation in the enviroment of the constructed box. Problems: 3D-modelling of the box, ~~My problems started around a week after I was born (c) Dainis~~
Designing electrical circuits of sensors (which pins should we use), proper formulas for light intensity detection by the light sensor, soledring and software problems. 

# Schedule for Pair A (Dainis and Kirill):


Week 1, 12.11 - 18.11: 
Dainis = Reading and getting to know the sensors to work with.
Kirill = Discussing with Daniel about how to properly set up our Raspberry pi with
needed sensors, paper plan for programming.

Week 2, 19.11 - 25.11: 
Dainis = Blueprint of the electric circuit.
Kirill = According to the plan, we have to set up and test each sensor separately and if time allows, also together.

Week 3, 26.11 - 02.12: 
Dainis = Electronic circuit construction.
Kirill = Making overall program for all of the sensors and raspberry pi control. Make sure that everything works.
Preparing programming part of our Demo video.

Week 4, 03.12 - 09.12: 
Dainis = Testing circuit with programms, debugging.
Kirill = Debugging and further stress testing. Preparing programming part of our Poster.

Week 5, 10.12 - 16.12:
Dainis = Setting up final demo.
Kirill = Setting up construct for final live demo (and preparing for poster, robustness, ingenuity and the end results).

# Schedule for Pair B (Daniel and Shawon):


Week 1, 12.11 - 18.11: 
Daniel = Discussing with Kirill about how to properly set up our Raspberry pi with
needed sensors, paper plan for programming.
Shawon = Blueprint of construct frame on paper.

Week 2, 19.11 - 25.11: 
Daniel = According to the plan, we have to set up and test each sensor separately and if time allows, also together.
Shawon = Browsing and choosing 3D-modelling program.

Week 3, 26.11 - 02.12: 
Daniel = Making overall program for all of the sensors and raspberry pi control. Make sure that everything works. Preparing
programming part of our Demo video.
Shawon = Creating the 3D construct.

Week 4, 03.12 - 09.12: 
Daniel = Debugging and further stress testing. Preparing programming part of our Poster.
Shawon = 3D-printing of the construct/Assembly and Debugging.

Week 5, 10.12 - 16.12: 
Daniel = Setting up construct for final live demo (and preparing for poster, robustness, ingenuity and the end results).
Shawon = Demo.

We will divide all the programming tasks between 2 of us (Kirill and Daniel), but in general,
we have to work together on same tasks according to the programming plan (like we did in Robotex). We will discuss it later on with instructors.
I hope we will not lose any points for filling up the same plan for programming. Thank you in advance! 

# Component list (also in sheets):

*1Raspberry pi 3
*2 humidity sensors (If you have only one, we can order another one online)
*1 Thermal sensor
*1 Computer fan (due to air circulation purposes)
*1 light sensor
*2 continious electrical motors
*1 ultrasonic sensor
*5 (we have to discuss the intensity with instructors) LED's
*Onion
Week 3, 26.11 - 02.12:
Daniel = Making overall program for all of the sensors and raspberry pi control. Make sure that everything works. Preparing
programming part of our Demo video.
Shawon = Creating the 3D construct.

Week 4, 03.12 - 09.12:
Daniel = Debugging and further stress testing. Preparing programming part of our Poster.
Shawon = 3D-printing of the construct/Assembly and Debugging.

Week 5, 10.12 - 16.12:
Daniel = Setting up construct for final live demo (and preparing for poster, robustness, ingenuity and the end results).
Shawon = Demo.

We will divide all the programming tasks between 2 of us (Kirill and Daniel), but in general,
we have to work together on same tasks according to the programming plan (like we did in Robotex). We will discuss it later on with instructors.
I hope we will not lose any points for filling up the same plan for programming. Thank you in advance!

# Component list (also in sheets):

*1Raspberry pi 3

*2 humidity sensors (If you have only one, we can order another one online)

*1 Thermal sensor

*1 Computer fan (due to air circulation purposes)

*1 light sensor

*2 continious electrical motors

*1 ultrasonic sensor

*5 (we have to discuss the intensity with instructors) LED's

*Onion


# Challenges and Solutions:

Kirill - Problem was to connect fan and LEDs and to be able to controll them. Solution was to use AC to DC adapter and couple of transistors to we able to controll all of it by simple signals(5 volts).

Shawon - There was some sort of electrical issues when we were connecting all the connection together with arduino. We managed to identify correctly the ground, VCC, other correct analog & digital Pin in arduino. Now it works as we wanted the way it should work.

Daniel - Problem was to find a proper sensor which can be used on Arduino with low voltage. Solution: After we ordered a DHT-11, I managed to write the code. Now  we already can test it on the field. Problem was to make a server to which we can send and check the data (e.g. humidity level). Solution: In progress. I already have it on my paper-plan. 

Dainis - Problems :figuring out high adjustment system
Solution: making the upper side of the box be rotated up and down by two bolts on a long screw with the help of servos
Problem: stabilising hight adjustment so the sides don't wobble
Solution : in progress. Solution: The upper parts could be connected via a metal rod or something like that and the plate on which the pot stays will be glued to the plastic legs which should decrease the wiggling in theory








