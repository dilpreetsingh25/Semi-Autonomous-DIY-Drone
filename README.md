# Semi-Autonomous-DIY-Drone

This custom drone features an ESP32-S3 microcontroller at its core, mounted on a leveled platform to allow a Raspberry Pi to be placed neatly below it. This mechanical arrangement helps optimize space and maintain a compact, balanced design while enabling the use of both microcontrollers for distributed processing.ESP32-S3 microcontroller, which handles real-time control and sensor data processing. 

It integrates an MPU9250 IMU, combining a 3-axis accelerometer, gyroscope, and magnetometer to capture orientation and motion.
The propulsion system consists of A2212 1000KV brushless motors driven by 30A SimonK ESCs, which are known for their fast and responsive performance in multirotor configurations.This drone is designed for both performance and modularity, making it ideal for advanced robotics, autonomous navigation, and computer vision projects when paired with the Raspberry Pi.

![image](https://github.com/user-attachments/assets/708b4ae7-6f90-4242-b625-455ff4f8ffbc)

### Transmitter Module
The transmitter module is built using an ESP32-WROOM microcontroller in combination with an NRF24L01+ PA+LNA wireless transceiver to enable long-range, low-latency communication with the drone. Four 10kΩ potentiometers are integrated into the design to manually control yaw, pitch, roll, and throttle values. These analog values are read by the ESP32, encoded, and transmitted wirelessly using the NRF24L01 module operating over the 2.4GHz band.

The nRF24L01 module uses two main communication protocols, SPI for communication with a microcontroller and Enhanced ShockBurst for wireless data transmission. To provide real-time feedback to the user, an LED 1602 display is also connected to the ESP32-WROOM, showing the current values of yaw, pitch, roll, and throttle. This setup ensures intuitive control and reliable telemetry visualization in a compact and customizable form factor.

![image](https://github.com/user-attachments/assets/f254e1fc-05b5-4980-9411-ce673dbfdcf3)

### PID Controller for Stabilization
To ensure stable and responsive flight, a PID (Proportional-Integral-Derivative) controller is implemented on the drone's onboard microcontroller. The PID algorithm continuously processes sensor feedback—typically from an IMU (Inertial Measurement Unit) to correct deviations in roll, pitch, and yaw. 

Based on the error between the desired orientation (received from the transmitter) and the actual orientation, the PID controller adjusts the motor speeds in real time to minimize oscillations and maintain stability. Each axis has its own tuned PID parameters (Kp, Ki, Kd), allowing fine-grained control over how aggressively the drone reacts to disturbances. This control loop is essential for smooth hovering, precise maneuvering, and quick recovery from external forces such as wind or sudden movement.

https://github.com/user-attachments/assets/c67103d8-fe0a-43e1-a49c-d4b1c4fb971e


