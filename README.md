
<a id="readme-top"></a>


# Bluetooth_controlled_car_with_obstacle_avoidance
## Explanatory Video for Sign Language Interpreter
https://github.com/user-attachments/assets/b01cc729-9f00-4dfe-87ab-bde48abe7c9e


## Index: 
- [About The Project](#About-The-Project)
- [Features](#Features)
- [Requirements](#Requirements)
- [Steps to Implement](#Steps-to-Implement)
- [Applications](#Applications)





  
## About The Project
This project combines robotics and wireless communication to create a versatile Bluetooth-controlled car that features obstacle avoidance. The car is controlled via a mobile app (e.g., Bluetooth RC Controller) and can move in all directions: forward, backward, left, and right. Its special feature is obstacle avoidance, which allows the car to detect objects in its path using an ultrasonic sensor and automatically change its route. With a range of 80-100 meters, this car is practical for diverse terrains and tasks.

# Requirements:
1. Hardware:
      * Arduino Board (e.g., Arduino Uno): Processes commands and controls the motors.
      * HC-05 Bluetooth Module: Establishes wireless communication with the mobile app.
      * L298N Motor Driver: Drives the two TT gear motors.
      * TT Gear Motors (2): Provide movement in the X and Y axes.
      * Ultrasonic Sensor: Detects obstacles and calculates distance to avoid collisions.
      * Servo Motor: Rotates the ultrasonic sensor for obstacle scanning
      * Battery Pack: Powers the car.
      * Jumper Wires: Connects components.
  
   
2. Software:
     * Arduino IDE 

# Features:
1. Bluetooth Control:
   * Use the Bluetooth RC Controller app to send commands via Bluetooth for directional control.
2. Obstacle Avoidance:
   * If an obstacle is detected within a specific range, the car stops and changes direction.
  

# Steps to Implement: 

1. Wiring and Connections:
     * HC-05 Bluetooth Module: Connect to Arduino (RX to TX and TX to RX).
     * Ultrasonic Sensor: Trig pin to Pin 9, Echo pin to Pin 8.
     * Servo Motor: Connect to Pin 10 for rotating the ultrasonic sensor.
     * L298N Motor Driver:
         - IN1, IN2, IN3, IN4 to Arduino Pins 4, 5, 6, and 7.
         - Motor outputs connected to TT motors.
         - Power from the battery pack.
  
2. Arduino Code:
   - Upload the given code in this repository of Bluetooth_controlled_car_with_obstacle_avoidance.ino
   - If you only want obstacle_avoidance then Upload the given code in this repository of build_Obstacle_Avoider_Robot.ino
  
3. Mobile App Control:  
    * Install Bluetooth RC Controller (available on Google).
    * Pair the app with the HC-05 module.
    * Use the app to send commands (F, B, L, R, S) to control the car.(its automatic)

# Applications:
1. Military: Navigate through complex terrains while avoiding obstacles.
2. Security: Patrol areas with autonomous obstacle detection.
3. Robotics: Teach concepts of wireless communication and obstacle detection. :smile:


<p align="center">(<a href="#readme-top">back to top</a>)</p>
