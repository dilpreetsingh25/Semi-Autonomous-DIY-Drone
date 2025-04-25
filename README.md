# Semi-Autonomous-DIY-Drone

![image](https://github.com/user-attachments/assets/708b4ae7-6f90-4242-b625-455ff4f8ffbc)

This custom drone features an ESP32-S3 microcontroller at its core, mounted on a leveled platform to allow a Raspberry Pi to be placed neatly below it. This mechanical arrangement helps optimize space and maintain a compact, balanced design while enabling the use of both microcontrollers for distributed processing.

ESP32-S3 microcontroller, which handles real-time control and sensor data processing. It integrates an MPU9250 IMU, combining a 3-axis accelerometer, gyroscope, and magnetometer to capture orientation and motion.

To improve the accuracy and stability of the attitude estimation, a Kalman filter is implemented to fuse accelerometer and gyroscope data, effectively reducing drift and noise. This fused data is then used by a PID (Proportional–Integral–Derivative) controller, which precisely adjusts motor speeds to maintain stable flight and execute maneuvering commands.

For wireless communication, the drone uses the NRF24L01+PA+LNA module, enabling long-range and reliable remote control.

The propulsion system consists of A2212 1000KV brushless motors driven by 30A SimonK ESCs, which are known for their fast and responsive performance in multirotor configurations.

This drone is designed for both performance and modularity, making it ideal for advanced robotics, autonomous navigation, and computer vision projects when paired with the Raspberry Pi.

![image](https://github.com/user-attachments/assets/d17ec21f-2a91-42dd-b8c5-237acc47705f)

Custom 
