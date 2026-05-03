# Fading LED

## Description
This project demonstrates how to create a breathing or fading effect with an LED. Instead of simply turning the LED fully on or off (like in the Blinking LED project), this sketch uses Pulse Width Modulation (PWM) to gradually increase and decrease the brightness of the LED. 

*Note: The provided sketch targets pin 13. On a standard Arduino Uno R3, true PWM hardware fading is only supported on pins marked with a tilde (`~`), such as `9`, `10`, or `11`. If you do not see a smooth fade on pin 13, simply move the LED wire to pin 9 and change the `13` to `9` in the `Fading_LED.ino` code.*

## Components Required
* 1x Arduino Uno R3
* 1x Red LED (or any color of your choice)
* 1x 220 Ω Resistor (to prevent the LED from drawing too much current)

## Circuit Connections
Connect your external LED and resistor to the Arduino as follows:

* **LED Anode (Long Leg)** to digital pin **13** *(or a PWM pin like **9**)*
* **LED Cathode (Short Leg)** to one end of the **220 Ω Resistor**
* The other end of the **220 Ω Resistor** to **Ground (GND)**

*(Refer to the included `Fading_LED.png` and `Fading_LED.pdf` for visual wiring diagrams.)*

## Included Files
* `Fading_LED.ino`: The main Arduino C++ sketch.
* `Fading_LED.csv`: A Bill of Materials (BOM) listing the required components.
* `Fading_LED.pdf`: PDF documentation/circuit diagram for the project.
* `Fading_LED.png`: Visual layout of the breadboard connections.
* `Fading_LED_Working_Images/`: Directory containing a video demonstration of the fading LED.
* `Readme.md`: This documentation file.

## Steps to Run
1. **Build the Circuit**: Connect the LED and the 220 Ω resistor to Pin 13 (or a PWM pin) and Ground on the Arduino Uno, as described above.
2. **Connect the Arduino**: Plug the Arduino Uno into your computer using a USB cable.
3. **Open the Code**: Open the `Fading_LED.ino` file using the Arduino IDE. *(If you moved the LED to pin 9, make sure to update the `pinMode` and `analogWrite` functions in the code to target `9` instead of `13`).*
4. **Configure IDE**: Go to `Tools > Board` and select **Arduino Uno**. Go to `Tools > Port` and select the appropriate COM port for your Arduino.
5. **Upload**: Click the **Upload** button to compile and upload the sketch to the Arduino board. The LED should begin to smoothly fade in and out.

## Demonstration
Here is the working project in action:

### Video Demonstration
*See the included `Fading_LED_Working_Images/Fading_LED_Working.mp4` video for a live demonstration of the PWM fading effect.*
