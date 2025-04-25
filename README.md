# Semi-Autonomous-DIY-Drone

![image](https://github.com/user-attachments/assets/708b4ae7-6f90-4242-b625-455ff4f8ffbc)

This drone is powered by the ESP32-S3 microcontroller, which handles real-time control and sensor data processing. It integrates an MPU9250 IMU, combining a 3-axis accelerometer, gyroscope, and magnetometer to capture orientation and motion.

To improve the accuracy and stability of the attitude estimation, a Kalman filter is implemented to fuse accelerometer and gyroscope data, effectively reducing drift and noise. This fused data is then used by a PID (Proportional–Integral–Derivative) controller, which precisely adjusts motor speeds to maintain stable flight and execute maneuvering commands.

For wireless communication, the drone uses the NRF24L01+PA+LNA module, enabling long-range and reliable remote control.

The propulsion system consists of A2212 1000KV brushless motors driven by 30A SimonK ESCs, which are known for their fast and responsive performance in multirotor configurations.

This setup creates a responsive and stable drone platform, ideal for custom development, autonomous flight experiments, and educational projects in control systems and embedded electronics.
