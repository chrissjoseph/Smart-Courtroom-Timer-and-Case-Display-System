# Smart-Courtroom-Timer-and-Case-Display-System
An ESP32-based Smart Courtroom Timer and Case Display System that automates speaker time management using an IR sensor, RTC, LCD, sound sensor, and push button. The system tracks speakers, displays case details, manages countdown timing, and improves courtroom efficiency.The project integrates an ESP32 microcontroller with an IR sensor, DS3231 Real-Time Clock (RTC), 16×2 I2C LCD display, KY-038 sound sensor, and a push button to provide a simple and reliable solution for managing courtroom proceedings.

## Features

- Real-time date and time display
- Automatic case number management
- Speaker detection using an IR sensor
- Automatic speaker counter
- 2-minute countdown timer for each speaker
- Sound-based timer pause and resume
- LCD display for case and timer information
- ESP32-based embedded implementation
- Simple user interface using a push button

## Hardware Components

- ESP32 DevKit V1
- DS3231 RTC Module
- 16×2 I2C LCD Display
- IR Obstacle Sensor
- KY-038 Sound Sensor
- Push Button
- Breadboard
- Jumper Wires
- USB Power Supply

## Software Requirements

- Arduino IDE
- ESP32 Board Package
- Wire Library
- RTClib Library
- LiquidCrystal_I2C Library

## Working Principle

1. The system initially displays the current date and time.
2. Pressing the push button starts a new case or increments the case number.
3. The IR sensor detects the entry of a speaker.
4. The speaker number is automatically incremented.
5. A two-minute countdown timer starts for the speaker.
6. When the sound level exceeds the predefined threshold, the timer pauses.
7. When the threshold is crossed again, the timer resumes from the previous value.
8. Once the speaker exits the detection area, the timer stops.
9. The LCD displays "Waiting for Next Speaker."
10. The system returns to displaying the current date and time until the next speaker arrives.

![Watch Demo Video](Videos/demovideo.mp4)

## Simulation

The Smart Courtroom Timer and Case Display System was also designed and tested using the Wokwi simulator. The simulation helped verify the circuit connections, ESP32 program, LCD output, push-button input, speaker-detection logic, and countdown-timer operation before implementing the physical prototype.

![Wokwi Simulation](Simulation/wokwi_diagram.png)

### Simulation Files

- `diagram.json` contains the component arrangement and wiring connections.
- `sketch.ino` contains the ESP32 program used in the Wokwi simulation.
- `wokwi diagram.png` contains a screenshot of the simulated circuit.
- `wokwi link.txt` contains the link to the online Wokwi project.

### View Simulation

[Open the Wokwi Simulation](https://wokwi.com/projects/456312737790568449)
## Prototype

The completed hardware prototype of the Smart Courtroom Timer and Case Display System was developed using the ESP32 DevKit V1. It integrates the DS3231 RTC module, 16×2 I2C LCD, IR sensor, KY-038 sound sensor, and push button.

The prototype was tested for real-time clock display, case-number control, speaker detection, countdown timing, and sound-controlled pause and resume operation.

![Smart Courtroom Timer Prototype](Images/final%20prototype.jpeg)


## LCD Output

The 16×2 LCD provides real-time information about the system. During idle operation, it displays the current date and time obtained from the DS3231 RTC module.

During an active courtroom session, the LCD displays information such as the case number, speaker number, countdown timer, timer status, and waiting message for the next speaker.

![LCD Output](Images/lcd%20output.jpeg)

## Applications

- Courtroom proceedings
- Debate competitions
- Arbitration sessions
- Public hearings
- Academic presentations
- Conference speaker management

## Future Enhancements

- Voice recognition for speaker identification
- Wi-Fi-based monitoring and logging
- Web dashboard for real-time monitoring
- Mobile application integration
- Cloud-based data storage
- Multi-courtroom support

## License

This project is licensed under the MIT License.
