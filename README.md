# CubeSat
A Robust Cube Satellite

# CubeSat Project README

## Introduction
The CubeSat project is a compact satellite prototype designed for educational and experimental purposes. It integrates microcontrollers, sensors, and communication modules to simulate real-world satellite functionalities. This document provides an overview of the components, structure, and operation of the CubeSat, including placeholder spaces for images and videos to enhance understanding.

---

## Components Used

### Microcontrollers
- **ESP32 (38-pin version)**: The main processing unit responsible for sensor data acquisition and communication.
- **Arduino Mega**: Functions as the receiver and visualization processor, handling data display and interpretation.

### Sensors
- **BMP280**: Measures atmospheric pressure and temperature.
- **MPU6050**: Provides orientation, acceleration, and gyroscope data.
- **NEO-6M GPS Module**: Tracks location, including latitude, longitude, and altitude.

### Camera
- **OV7670 Camera Module**: Captures and transmits images for analysis and visualization.

### Wireless Communication
- **NRF24L01 Module (2 units)**:
  - 1 unit for sensor data transmission.
  - 1 unit for image data transmission.
- **Antenna Modules**: Extend the communication range of the NRF24L01 modules.

### Visualization
- **WS2812 RGB LED Strip**: Displays system status and activities through dynamic animations.

### Power Supply
- **Power Regulators**: Ensure stable power distribution at 3.3V and 5V levels.

### Connections and Miscellaneous
- **Connecting Wires**: Facilitate interfacing between components.
- **Breadboard/PCB**: Provides a platform for circuit integration.
- **Headers and Connectors**: Ensure secure and reliable connections.

---

## Prototype Structure

### Mechanical Design
The CubeSat prototype features a lightweight and robust structure designed to house all components securely while maintaining accessibility for testing and upgrades.

![](1.jpeg)
![](2.jpeg)

#### Placeholder for Images:
- **Structure Image 1**
- **Structure Image 2**

### PCB Layout
Custom-designed PCBs streamline the integration of electronic components, ensuring reliability and minimizing loose connections.

#### Placeholder for Images:
![]()
![]()

---

## Working
The CubeSat performs the following key operations:
1. Sensor data collection (pressure, temperature, orientation, and location).
2. Image capture and processing.
3. Wireless transmission of sensor and image data to a ground station.
4. Real-time visualization using the RGB LED strip.

#### Placeholder for Videos:
![](01.mp4)
![](02.mp4)

---

## Conclusion
While the CubeSat prototype achieves significant milestones in integrating sensors, microcontrollers, and communication modules, it is important to note that the camera module is not yet operational. Its integration remains an open possibility, hinging on future design and testing phases. The uncertainty surrounding this feature leaves room for potential advancements, ensuring that the CubeSat’s capabilities remain adaptable to emerging technologies and project goals. Though not confirmed, the inclusion of the camera is an exciting prospect for future iterations of the CubeSat.
