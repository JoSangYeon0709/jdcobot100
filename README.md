# JDcobot 100 SDK

The JDcobot 100 SDK provides a platform for development of custom applications for the JDcobot 100.

This repository contains metapackages and files for installation/use of the JDcobot 100 SDK.

## Installation

- Please aaaa
- bbbb

## Code & Tickets

| Documentation   | a                                                                 |
|-----------------|-------------------------------------------------------------------|
| Issues          | [https://github.com/JoSangYeon0709/jdcobot100/issues](https://github.com/JoSangYeon0709/jdcobot100/issues) |

## JDcobot100 Repository Overview
```.
├── assets                                    Images used in the readme file
├── dingo_nano                                Code for the Arduino Nano V3 to read sensor data and send it to the Raspberry Pi
└── dingo_ws                                  ROS workspace containing all required packages
   └── src
     ├── dingo                                Package containing node and launch files for running the robot
     ├── dingo_control                        Package containing all files related to control, including kinematics and default trot controller
     ├── dingo_description                    Package containing simulation files (URDF file and meshes)
     ├── dingo_gazebo                         Package containing gazebo files
     ├── dingo_hardware_interfacing
     |  ├── dingo_input_interfacing           Package containing files for receiving and interpreting commands (From a joystick or keyboard)
     |  ├── dingo_peripheral_interfacing      Package containing files for interfacing with the Arduino Nano, LCD screen and IMU
     |  └── dingo_servo_interfacing           Package containing the hardware interface for sending joint angles to the servo motors
     └── dingo_utilities                      Package containing useful utilities
```




## Other JDcobot 100 Repositories

| Repository              | URL                                                                                     |
|-------------------------|-----------------------------------------------------------------------------------------|
| jdcobot_100_description | [https://github.com/JoSangYeon0709/jdcobot_100_description](https://github.com/JoSangYeon0709/jdcobot_100_description) |

## Latest Release Information

aa
