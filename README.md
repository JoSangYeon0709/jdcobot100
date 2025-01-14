# JDcobot 100
<p align="center">
    <img src="assets/jdcobot100.png" style="align:centre" width="35%">
</p>

The JDcobot 100 is a simple manipulator that uses Arduino and SG90, MG90S,MG996R servos.  
You can use a computer to move the motors to desired angles through the serial port.  
The JDcobot 100 SDK provides a platform for development of custom applications for the JDcobot 100.  
This repository contains files for use of the JDcobot 100 SDK.



## How to use JDcobot 100?

### H/W
1. assembly
   
### S/W
1. Download [jdcobot 100 repository](https://github.com/JoSangYeon0709/jdcobot100/archive/refs/heads/main.zip) and unzip it
2. Install the <a href="https://www.arduino.cc/en/software" target="_blank">Arduino IDE</a> appropriate for your computer
3. Please upload this arduino_code/ jdcobot_100.ino to Arduino
4. Proceed with the code step by step in python_code/step_by_step_code.
   
! Do not open the Serial Monitor in the Arduino IDE when controlling it with Python code. !

## Dependency
### Arduino IDE
[u8g2](https://github.com/olikraus/u8g2)

### Python
pip install pyserial

## Code & Tickets
||URI|
|-----------------|-----------------------------------------------------------------------------------------|
| Documentatioadn | URL                                                                                     |
| Issues          | https://github.com/JoSangYeon0709/jdcobot100/issues |


## JDcobot100 Repository Overview
```
├── assets                                    Images, photos, and assembly manual of JDcobot 100
├── arduino_code                              
|  └── jdcobot_100                            JDcobot 100 arduino code
|  └── jdcobot_100_v2                         Enhanced Servo Motor Control
└── python_code                               JDcobot 100 python code
   └── robot_UI_reference_code                UI reference code for jdcobot 100 robot using tkinter
   └── robot_sequxnce_move_example            jdcobot 100 sequence move example code
   └── sample_URDF                            robot URDF file sample
   └── step_by_step_code                      code with added functions step by step to move JDcobot 100
      └── tk1_drop_down_serial_port.py
      └── tk2_add_btn_fram.py
      └── tk3_add_grid.py
      └── tk4_add_servo_value.py
      └── tk5_add_slider.py
      └── tk6_add_robot_run_stop.py
      └── tk7_add_base_servo_ctrl.py
      └── tk8_add_serial_seletor.py
      └── tk9_add_slider_all.py
      └── tk10_add_robot_reset.py
      └── tk11_add_save_position.py
      └── tk12_add_trajectory.py
```



## Other JDcobot 100 Repositories
|                         |URI                                                                                      |
|-------------------------|-----------------------------------------------------------------------------------------|
| jdcobot_100_description | [https://github.com/JoSangYeon0709/jdcobot_100_description](https://github.com/JoSangYeon0709/jdcobot_100_description) |
