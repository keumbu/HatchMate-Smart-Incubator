# Control Algorithm (Pseudocode)

START SYSTEM
Initialize ESP32 and peripherals
Initialize sensors, relays, display, buzzer
Initialize Wi-Fi connection

SET incubation parameters
SET day counter

WHILE system is running:
    Read temperature and humidity
    Validate sensor data

    IF sensor error:
        Trigger buzzer
        Display error
        Send Wi-Fi alert
        CONTINUE loop

    Control temperature
    Control humidity
    Control egg turning

    Update OLED display
    Send data to Wi-Fi dashboard

END WHILE

