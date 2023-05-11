# Temperature Sensor using LM35 and LCD
This is an Atmega 32 based project for measuring temperature using LM35 temperature sensor and displaying it on a 16x2 LCD. This project is capable of measuring both positive and negative temperatures.

## Hardware Requirements
- Atmega 32 microcontroller
- LM35 temperature sensor
- 16x2 LCD
- 10k ohm potentiometer
- Breadboard
- Jumper wires
- Power supply (5V DC)
## Software Requirements
- AVR Studio
- WinAVR
## Circuit Diagram
<img width="960" alt="image" src="https://github.com/ahmedSherif-eng/Temprature-Sensor/assets/72231218/75076c7c-ded0-4e48-9534-0cc33bf45aba">


## How to Use
- Connect the circuit as per the circuit diagram.
- Burn the code onto the Atmega 32 microcontroller using AVR Studio and WinAVR.
- Power on the circuit.
- The temperature will be displayed on the LCD.
- Code Explanation
The code reads the analog value of the LM35 temperature sensor using the ADC (Analog to Digital Converter) of the Atmega 32 microcontroller. The digital value is then converted to temperature in degrees Celsius using the formula:

temperature = (ADC_value * 2.65 * 100.0) / 1024

The temperature is then displayed on the 16x2 LCD.

## Acknowledgements
This project is inspired by the Study of Microcontrollers Course in Helwan University 
### License
This project is licensed under the MIT License. Feel free to use and modify the code as per your requirements.
