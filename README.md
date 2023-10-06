# Auto-Watering
Auto-watering system for Arduinos.

## Directions
### Sensors and Solenoid
Ensure your water source is being regulated by the solenoid.
Have two water sensors (one above and one below) connected
to the Arduino as specified at the top of the ino file.
Additionally, you'll want a reset button and a light. Their
pins are also specified in the ino file.

Ideally you'll have the water emptying into a tub where
the water sensors are. This is how this project is intended
to be used.

### Arduino
These directions are for the arduino-cli on Linux, look
elsewhere for Windows and MacOS directions.

Start by installing the core:
<https://arduino.github.io/arduino-cli/0.34/getting-started/>

With the Arduino connected to your computer run this
to give yourself permission to write to the Arduino:
```
sudo chmod a+rw /dev/ttyACM0
```

Next compile and upload the code. Run these commands in the
repository's top directory. Replace "arduino:avr:uno"
with your device. If you wish to upload the golfed code,
replace "main" with "golfed".
```
arduino-cli compile --fqbn arduino:avr:uno main
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno main
```

## License
This code is licensed under GPL Version 3, which means you
are free to fork this code, modify it, and redistribute it
however you like. This code is free and open source software.
Please refer to the GPL Version 3 license as provided
if you have any questions.



