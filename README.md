# 🤖 MRC: Arduino Line Following Robot Workshop

Welcome to the official **Mobile Robotics Club (MRC)** repository for the Arduino Line Following Robot Workshop! (9/7/2026)

Whether you are a seasoned tinkerer or touching an Arduino for the exact first time, this repository has everything you need. We believe in skipping the empty theory and diving straight into hands-on practice. By the end of this workshop, you'll have a fully functional, autonomous robot that can navigate a track all on its own.

## 🚀 Quick Start & Code Links

We've split the code into two parts so you can test your hardware before tackling the complex sensor logic.

* **Testing your motors?** 👉 [Basic movement code is here](./basic_movements/basic_movements.ino)
* **Ready for the track?** 👉 [Line follower code is here](./line_follower/line_follower.ino)

*(Note: Click the links above to navigate directly to the `.ino` files in this repository!)*

---

## 🛠️ Hardware Requirements

Before we start wiring, make sure you have your kit ready:

* 1x Arduino Uno (The brains)
* 1x L298N Motor Driver (The brawn)
* 2x IR Sensors (The eyes)
* 2x DC Motors & Wheels (The legs)
* 1x Robot Chassis & Caster wheel
* Jumper wires (Male-to-Female & Male-to-Male)
* Battery AA packs

---

## 🔌 Wiring Cheat Sheet

To make sure the code provided matches your physical robot, hook up your components using this exact pin configuration (or change to what you desire✨):

### Motor Driver (L298N)

| L298N Pin | Arduino Pin | Function |
| --- | --- | --- |
| **IN1** | Pin 5 | Right Motor Forward |
| **IN2** | Pin 6 | Right Motor Reverse |
| **IN3** | Pin 9 | Left Motor Forward |
| **IN4** | Pin 10 | Left Motor Reverse |

### IR Sensors

| Sensor | Arduino Pin |
| --- | --- |
| **Right Sensor (OUT)** | Pin 11 |
| **Left Sensor (OUT)** | Pin 12 |

*(Don't forget to connect the `VCC` pins to 5V and `GND` pins to Ground on your Arduino!)*

---

## 📖 How to Use This Repository

1. **Download the Code:** Click the green `<> Code` button at the top right of this repository and select **Download ZIP**.
2. **Extract & Open:** Extract the folder and open the `.ino` files using the [Arduino IDE](https://www.google.com/search?q=https://www.arduino.cc/en/software).
3. **Test the Motors:** Upload the **Basic Movement Code** first. Put your robot on a block (so the wheels don't touch the table!) and make sure they spin the correct way.
4. **Follow the Line:** Once the motors work, upload the **Line Follower Code**, place your robot on the black line, and watch it go!

## 🐛 Troubleshooting

* **My robot is spinning in circles!** Check your motor wiring. You might have IN1/IN2 or IN3/IN4 swapped. Try flipping the wires on the motor driver.
* **It doesn't see the line!**
Adjust the small blue potentiometer on your IR sensors using a screwdriver until the LED reacts correctly to black vs. white surfaces.
* **Nothing is moving.**
Check your batteries! The L298N driver needs a solid power source to turn those motors.
