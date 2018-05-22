# Interfaces_Robot_Lab
Final project for BerkeleyX EE40LX Electronic Interfaces (2015-04)

[Video of display and sound effects](https://www.youtube.com/watch?v=8A6rcPg1f8o)

[Video of robot movement](https://www.youtube.com/watch?v=O2uhIjSmHSg)

Final project for BerkeleyX EE40LX (2015-04)
My project deviates from the standard EE40LX project in several ways:

1. An aluminum U channel frame with 90 RPM DC gear motors was used as the platform.
2. A TI SN754410 quad half bridge is [mounted at rear](https://github.com/cms-/Interfaces_Robot_Lab/blob/master/GGM5Umn.jpg), providing directional motor control.
3. A forward-facing spectrasymbol [flex sensor](https://github.com/cms-/Interfaces_Robot_Lab/blob/master/qsmzJAh.jpg) detects collision, triggering a turn around function.
3.5. The flex sensor [frontend circuit](https://github.com/cms-/Interfaces_Robot_Lab/blob/master/8LE9uAw.png) detects a bend in [either direction](https://github.com/cms-/Interfaces_Robot_Lab/blob/master/LsIqCDJ.png).
4. Controlled by a Teensy 3.1 (Freescale MK20DX256VLH7). Arduino-based (Teensyduino) IDE was used.
5. Instead of simple square wave beeping, the robot emits audio samples from a piezo speaker via the Teensy's 12 bit DAC.
6. A 122*32 graphic LCD is attached, presenting visual cues as to the bot's status and assisting in debugging.
7. Circuits are soldered to protoboards, SOIC8 TLC272 op amps are used, and twin voltage regulators provide 3.3V and 5V.

More in-depth review of this project can be located on [my blog](https://hellocrispyking.wordpress.com/), which was active from 2013 to 2015.
