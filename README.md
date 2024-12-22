# MSD700 Microcontroller Firmware

This repository contains the firmware for the MSD700 microcontroller. Follow the steps below to set up and modify the firmware as needed.

### Setup Instruction:
1. Clone this repo to your local machine
2. Open the ArduinoIDE
3. Set /path/to/firmware_msd700 as Sketchbook location
4. Open /firmware_msd700/firmware/firmware.ino and Upload to Arduino Mega

### ROS Messages

#### The ROS node in the firmware publish 2 msg:
```
msd700_msgs/HardwareState
msd700_msgs/HardwareCommand
```

#### Command to add custom msg:

From your ROS Workspace, source the setup.bash/setup.zsh, then run this command to create a new ros_lib.

```
rosrun rosserial_arduino make_libraries.py <sketckbook_output_folder>
```

You can replace the old ros_lib with the new ros_lib or drag the new custom message folder to the ros_lib.


<!-- ## Introduction
Source code and libraries that are used for MSD700 microcontroller firmware.

## How to use
1. Copy all folder in `/libraries` to your Arduino libraries folder.
2. Open `firmware.ino` in Arduino IDE. -->