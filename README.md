# 🚨 Smart Radar Surveillance System (Arduino + Processing UI)

A real-time **Smart Radar Surveillance System** built using **Arduino UNO + Ultrasonic Sensor + Servo Motor**, capable of scanning surroundings in a **0°–180° sweep**, detecting intrusions, triggering alerts, and logging detection data with timestamp, distance, direction, speed, and threat level.  
The system includes a **Processing GUI** that visualizes radar scanning live on screen.

---

## 🎯 Project Goal

We aimed to build something that:
- Works in **real life** (not just a simulation),
- Improves **situational awareness**,
- Helps in **automated security monitoring** at low cost.

---

## 🛡 Key Features

| Feature | Description |
|---------|-------------|
| ✅ 180° Scanning Radar | Servo rotates ultrasonic sensor from **0° → 180°** continuously. |
| ✅ Real-time Visualization | Processing UI displays detected objects live on radar screen. |
| ✅ Intruder Detection | Detects an object crossing pre-defined threshold distance. |
| ✅ Alert System | Buzzer + UI notification if object enters danger zone. |
| ✅ Logging System | Saves logs containing: Date, Time, Distance, Speed, Direction & Threat level. |
| ✅ Threat Level Analysis | Determines Low / Medium / High based on object distance. |
| ✅ Speed & Direction Estimation | Tracks object movement over time for prediction. |

---

## 🧠 How It Works (Concept)

1. **Ultrasonic sensor (HC-SR04)** emits sound pulses.
2. It measures **time taken** to receive the echo back.
3. Using speed of sound, system calculates **distance**:
4. **Servo motor rotates** the sensor from 0° → 180° → 0°.
5. Each reading is sent to the Processing UI.
6. If an obstacle is detected within threshold distance:
- The UI marks it on radar,
- Logs the event,
- Buzzer alerts.

> This combines physics (ultrasonic wave travel time), electronics (sensor + servo), and software (visualization + logging).

---

## 🛠 Tech Stack

| Category | Technologies Used |
|----------|------------------|
| Microcontroller | Arduino UNO |
| Sensor | HC-SR04 Ultrasonic Sensor |
| Motor | SG90 Servo Motor |
| Programming | Arduino C / Processing (Java-based) |
| Visualization Dashboard | Processing IDE |
| Logging System | File handling using Processing |

---

## 🧩 Hardware Requirements

- Arduino UNO
- HC-SR04 Ultrasonic sensor
- SG90 Servo Motor
- Buzzer
- Breadboard + Jumper Wires
- USB cable (for power + serial communication)

**Power used: USB 5V (DC)** — no external battery required.

---

## 🧩 Software Requirements

- Arduino IDE (for uploading code)
- Processing IDE (for visualization dashboard)



## 🔧 Circuit/Wiring Diagram

| Component | Arduino Pin |
|----------|-------------|
| HC-SR04 Trig | D10 |
| HC-SR04 Echo | D11 |
| Servo Signal | D9 |
| Buzzer | D6 |
| LEDs | D7 / D8 |
| VCC (Sensor + Servo) | 5V |
| GND | GND |



##🚀 How to Run the Project

1️⃣ Upload Arduino Code
1. Open `sketch_nov03a.ino` in Arduino IDE
2. Select board: **Arduino UNO**
3. Select Port (COMx)
4. Upload

2️⃣ Run Processing UI
1. Open `radar_UI` in Processing IDE
2. Change the serial port name (`COM7`, etc.)
3. Click Run ✅




## 🙌 Credits

Developed by:
- Ankit Mazumdar
- Ipsita Hazra
- Rima Mondal
- Arghyadeep Nag
- Team TechnoMinds (Technova 2025)

🏆 Achievements:
✔ Secured Top 3 position at Technova 2025,held at Asansol Engineering College





