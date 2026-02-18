# Solar_Energy_Microgrid
An Arduino-based solar energy microgrid system with manual and automatic grid selection. The system switches between solar and utility power using relays based on voltage availability. Developed as an academic project.
# Introduction
This project implements a solar energy microgrid system that allows switching between solar power and utility grid power. The system supports both manual and automatic modes using switches and an Arduino controller.
# Problem Statement
Small and rural communities frequently experience unreliable electricity supply, with power outages lasting up to 7–8 hours a day. These frequent interruptions disrupt daily life, education, small businesses, and essential services, creating a significant challenge in maintaining a consistent and dependable power supply.
# Objective
* To design a microgrid system using solar and utility power 
* To provide manual and automatic mode selection
* To ensure uninterrupted power supply
* To automate source selection based on voltage availability
# System Description
The system uses three pin switches:
* Manual Solar Mode – Forces the system to use solar power
* Manual Utility Mode – Forces the system to use utility grid power
* Automatic Mode – The system automatically selects the power source
In automatic mode, the Arduino detects the incoming voltage and decides whether solar or utility power should be used. A relay module is used to switch and transmit the selected power source to the load.
# How the Project Works
* User selects the operating mode using switches
* Arduino reads the current received from solar and utility sources
* In automatic mode, Arduino compares voltage availability
* Relay switches the load to the appropriate power source
* Continuous power is supplied efficiently
# Components Used
* Arduino Uno R3
* 6V Solar panel
* AC Adapter (5V DC Output)
* 5V 1 Channel Relay module
* 18650 Li-ion Battery Cell (3.7V)
* TP4056 Li-ion Charging Module
* DC-DC Buck Converter
* 3 prong switch
* Status LEDs (2x)+Load LEDS(4x)
* Bread Board + Jumper wires
* Resistors
# Features
* Manual and automatic power selection
* Efficient energy utilization
* Reduces dependency on utility grid
* Reliable and uninterrupted power supply
* Simple and cost-effective design
# Technologies Used
* Hardware Platform: Arduino
* Arduino Programming Language
* Switching Device: Relay Module
# Applications
* Residential solar systems
* Small-scale microgrids
* Educational and academic demonstrations
* Backup power systems
# How to Run the Project
* Power the Arduino with USB or a 5V supply.
* Connect the solar and utility power sources to the relay as per the circuit.
* Upload the Arduino code using Arduino IDE.
* Select manual or automatic mode using the switches.
# Output
* Automatic switching between solar and utility power
* Stable power supply to the load
* Stable power supply to the load
(Add circuit diagram / output images here)
