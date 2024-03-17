# Temp_Sensor_Arduino_Without_Delay
The code continuously reads the temperature from the LM35 sensor and adjusts the LED's behavior accordingly. If the temperature is below 30.0 degrees Celsius, the LED blinks with a 250 milliseconds on and off cycle. If the temperature is 30.0 degrees Celsius or higher, the LED blinks with a 500 milliseconds on and off cycle. This setup allows for a visual indication of the temperature range being monitored.

Variables and Pins:
LM and LED are defined to represent the analog pin connected to the LM35 temperature sensor (A0) and the digital pin connected to the LED (pin 13) respectively.
temp is a floating-point variable used to store the temperature value read from the LM35 sensor.
Delay Functions:
delay_cycles(unsigned long cycles): This function creates a delay based on the number of CPU cycles. It uses a loop with a nop (no operation) assembly instruction inside, which consumes one CPU cycle per iteration.
delay_ms(unsigned long milliseconds): This function converts milliseconds to CPU cycles and calls delay_cycles() to create the delay.
Setup Function:
setup():
Initializes serial communication at 9600 baud rate.
Sets the LED pin (led) as an output.
Sets the LM35 pin (LM) as an input.
Loop Function:
loop():
Reads the analog value from the LM35 temperature sensor using analogRead(LM).
Converts the analog value to temperature in Celsius and stores it in the temp variable.
If the temperature is less than 30.0 degrees Celsius:
Turns on the LED (digitalWrite(led, HIGH)) and waits for 250 milliseconds (delay_ms(250)).
Turns off the LED (digitalWrite(led, LOW)) and waits for another 250 milliseconds (delay_ms(250)).
If the temperature is 30.0 degrees Celsius or higher:
Turns on the LED and waits for 500 milliseconds.
Turns off the LED and waits for another 500 milliseconds.
