# FlightControls
A small flight control system that imitates the look of the cockpit displays of the Airbus planes.<br>
Works on Arduino and a 128x64 OLED display.
## Usage
Prepare the circuit according to this schematic;<br>
![Schematic](https://github.com/baranonen/FlightControls/blob/master/Schematics/FlightControls.png "Schematic")<br>
Install the following libraries;<br>
[Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306 "Adafruit SSD1306")<br>
[Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library "Adafruit GFX")<br>
Open `FlightControls.ino` and run the program.
## Necessary items
- Arduino
- OLED display with SSD1306 chip
- Two servos
- Potentiometer
- Breadboard and jumper cables

## Notes
At the moment, only left and right ailerons are supported.<br>
Support for elevator, rudder, trim and more will be added in the future.
