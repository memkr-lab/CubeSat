# Project CubeSat

## Introduction
This CubeSat Project is a compact satellite prototype designed for educational and experimental purposes. It integrates microcontrollers, sensors, and communication modules to simulate real-world satellite functionalities. This Project provides an overview of the components, structure, and operation of the CubeSat, including images and videos to enhance understanding.

<p align="center">
  <img src="https://raw.githubusercontent.com/memkr-lab/CubeSat/refs/heads/main/All%20Images/Photos%26Videos/A1.jpeg" width="600" height="800" />
</p>

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

### Structure Design
The CubeSat prototype features a lightweight and robust structure designed to house all components securely while maintaining accessibility for testing and upgrades.

<p align="center">
  <img src="https://raw.githubusercontent.com/memkr-lab/CubeSat/cd9bc366140790f9ef8681237d23812033c4454b/All%20Images/Prototype%20Creation/1.jpeg" width="300" height="400" />
  <img src="https://raw.githubusercontent.com/memkr-lab/CubeSat/refs/heads/main/All%20Images/Prototype%20Creation/2.jpeg" width="300" height="400" />
</p>

#### Outer Acrylic Frame
The outer acrylic frame serves as a protective layer, safeguarding internal components against minor impacts and environmental factors. It also provides aesthetic appeal and ensures modularity for component access.

<p align="center">
  <img src="https://raw.githubusercontent.com/memkr-lab/CubeSat/refs/heads/main/All%20Images/Prototype%20Creation/3.jpeg" width="300" height="400" />
  <img src="https://raw.githubusercontent.com/memkr-lab/CubeSat/refs/heads/main/All%20Images/Prototype%20Creation/4.jpeg" width="300" height="400" />
</p>

#### PCB Layout
The printed circuit boards (PCBs) integrate all electronic components, ensuring reliable electrical connections and reducing loose wiring. Custom layouts are used for efficiency and compactness.

<p align="center">
  <img src="https://raw.githubusercontent.com/memkr-lab/CubeSat/refs/heads/main/All%20Images/Prototype%20Creation/5.jpeg" width="300" height="300" />
  <img src="https://raw.githubusercontent.com/memkr-lab/CubeSat/refs/heads/main/All%20Images/Prototype%20Creation/6.jpeg" width="300" height="300" />
</p>

#### Inner Structure
The inner structure supports the arrangement of sensors, microcontrollers, and the camera module. It ensures that each component remains securely in place during operation.

<p align="center">
    <img src="https://raw.githubusercontent.com/memkr-lab/CubeSat/refs/heads/main/All%20Images/Prototype%20Creation/7.jpeg" width="300" height="400" />
    <img src="https://raw.githubusercontent.com/memkr-lab/CubeSat/refs/heads/main/All%20Images/Prototype%20Creation/8.jpeg" width="300" height="400" />
  <img src="https://raw.githubusercontent.com/memkr-lab/CubeSat/refs/heads/main/All%20Images/Prototype%20Creation/9.jpeg" width="300" height="400" />
</p>

#### Final Build
The final build represents the fully integrated CubeSat prototype, combining the structure, electronics, and aesthetic elements into a cohesive unit.

<p align="center">
  <img src="https://raw.githubusercontent.com/memkr-lab/CubeSat/refs/heads/main/All%20Images/Final%20Prototype/1(1).jpeg" width="300" height="400" />
  <img src="https://raw.githubusercontent.com/memkr-lab/CubeSat/refs/heads/main/All%20Images/Final%20Prototype/2(2).jpeg" width="400" height="400" />
</p>

---

## Working
The CubeSat performs the following key operations:
1. Sensor data collection (pressure, temperature, orientation, and location).
2. Image capture and processing.
3. Wireless transmission of sensor and image data to a ground station.
4. Real-time visualization using the RGB LED strip.

https://github.com/user-attachments/assets/92fa8aad-67d8-41a4-8ed6-5fe9906413f0

---

## Conclusion
While the CubeSat prototype achieves significant milestones in integrating sensors, microcontrollers, and communication modules, it is important to note that the camera module is not yet operational. Its integration remains an open possibility, hinging on future design and testing phases. The uncertainty surrounding this feature leaves room for potential advancements, ensuring that the CubeSat’s capabilities remain adaptable to emerging technologies and project goals. Though not confirmed, the inclusion of the camera is an exciting prospect for future iterations of the CubeSat.
