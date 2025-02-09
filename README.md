Transo-Robot is an intelligent, autonomous transport robot designed to navigate predefined paths using sensor-based guidance. 
Built for Raspberry Pi, it integrates real-time sensor data to detect lines and markers, optimizing movement for package delivery or industrial automation tasks. 
The project demonstrates low-level C programming, hardware integration, and efficient control algorithms, making it a strong foundation for embedded systems and robotics applications.

## Key Features:

- Embedded C programming: Direct hardware control for motors and sensors.
- Real-time decision-making: Uses sensor inputs to adapt navigation.
- Portable to ARM-based systems: Potential for optimization on Arm architectures.
- Modular & extendable: Can be adapted for different use cases (e.g., industrial automation, smart logistics).
- Open-source & collaborative: Designed to encourage contributions and improvements.

## Prerequisites

- Raspberry Pi
- WiringPi library
- Sensors and motors connected to the Raspberry Pi

## Installation

1. **Install WiringPi:**

    ```sh
    sudo apt-get update
    sudo apt-get install wiringpi
    ```

2. **Clone the repository:**

    ```sh
    git clone https://github.com/yourusername/Transo-Robot.git
    cd Transo-Robot
    ```
## Usage

1. **Run the program:**

    ```sh
    sudo ./transo_robot
    ```
2. **Output:**

    The program will print "Transo-Robot Project" and start controlling the robot based on the sensor inputs.

## Project Structure

```
Transo-Robot
├── src
│   ├── main.c        
│   └── utils.c       
│   └── motors.c      
│   └── sensors.c     
│   └── servo.c       
├── include
│   └── utils.h       
│   └── motors.h       
│   └── sensors.h       
│   └── servo.h       
│   └── softPwm.h       
│   └── wiringPi.h       
├── tests
│   └── mock_wiringPi.c       
│   └── test_main.c
│   └── test_motors.c
│   └── test_sensors.c
│   └── test_servo.c
│   └── test_utils.c
├── Makefile          
└── README.md         
```

## Code Overview

- **main.c:** The main entry point of the program. Initializes the sensors, motors, and servo, and contains the main control loop.
- **utils.c / utils.h:** Utility functions used throughout the project.
- **sensors.c / sensors.h:** Functions to initialize and read from the sensors.
- **motors.c / motors.h:** Functions to control the motors.
- **servo.c / servo.h:** Functions to control the servo.

## Functions

- **initSensors():** Initializes the sensors.
- **initMotors():** Initializes the motors.
- **initServo():** Initializes the servo.
- **readLineSensors():** Reads the status of the line sensors.
- **readMarkSensors():** Reads the status of the mark sensors.
- **stop():** Stops the robot.
- **liftServo():** Lifts the servo.
- **lowerServo():** Lowers the servo.
- **moveForward():** Moves the robot forward.
- **moveBackward():** Moves the robot backward.
- **rotateRight():** Rotates the robot to the right.
- **rotateLeft():** Rotates the robot to the left.

## Servo Motor Movement

The servo motor is controlled to lift and lower based on the detection of significant marks:

- **liftServo():** This function is called when a significant mark is detected (all sensors high). It lifts the servo to perform an action.
- **lowerServo():** This function is called when a release mark is detected (all sensors low). It lowers the servo to perform an action.

## Control Logic

The main control loop in `main.c` continuously reads the status of the line and mark sensors and responds accordingly:

- **Line Sensors:**
  - No line detected: Stop the robot.
  - Line detected on the right: Rotate right.
  - Line detected in the center: Move forward.
  - Line detected on the left: Rotate left.
  - Line detected on multiple sensors: Move forward or rotate based on the combination.

- **Mark Sensors:**
  - Significant mark detected (all sensors high): Stop, lift the servo, and move forward.
  - Release mark detected (all sensors low): Stop, lower the servo, and move backward.


## Contributing

Feel free to submit issues or pull requests for improvements or bug fixes. 

## License

This project is licensed under the MIT License. See the LICENSE file for details.
