# ESP32 Web Server with BME280 Sensor

This GitHub project implements an HTTP web server on an ESP32 board that serves an HTML page displaying readings from a BME280 sensor, including temperature, humidity, and barometric pressure. The ESP32 communicates with the BME280 sensor using the I2C interface. The sensor readings are updated once every minute, providing real-time weather data.

In addition to displaying sensor readings, the HTML page generated by the web server also allows users to control the state of an LED connected to the ESP32 board. Users can set the state of the LED using the HTML page and change its state by pressing the "Submit" button.

This project is inspired by the ESP32 Weather Station project and leverages the capabilities of the ESP32 board, BME280 sensor, and I2C communication to create a simple weather monitoring system with LED control. The project is written in C/C++ using the Arduino framework for ESP32 development.

Features:

Real-time weather monitoring with BME280 sensor for temperature, humidity, and barometric pressure
LED control via an HTML page served by the ESP32 web server
I2C communication between ESP32 and BME280 sensor
Automatic updating of sensor readings every minute
User-friendly HTML page for setting LED state
This GitHub project is a practical example of using ESP32, BME280 sensor, and web server capabilities to create a weather monitoring system with LED control. It can serve as a starting point for similar IoT projects and can be customized to suit specific requirements.

# Video Tutorial

<p align="center">
  <img src="preview.jpg" alt="ESP32 WEB SERVER" width="960">
</p>

<p align="center">
🎥 <a href="https://youtu.be/aUSwEkJCIAA">Video Tutorial on YouTube</a>
</p>

<br>
<br>
<p align="center">
| 📺 <a href="https://www.youtube.com/educ8s">YouTube</a>
| 🌍 <a href="http://www.educ8s.tv">Website</a> | <br>
</p>


# Parts Needed

🛒 ESP32: https://educ8s.tv/part/ESP32

🛒 BME280: https://educ8s.tv/part/BME280

🛒 100Ω Resistor: https://educ8s.tv/part/Resistors

🛒 LED: https://educ8s.tv/part/LEDs

🛒 Small Breadboard: https://educ8s.tv/part/SmallBreadboard

🛒 Wires: https://educ8s.tv/part/Wires


💖 Full disclosure: All of the links above are affiliate links. I get a small percentage of each sale they generate. Thank you for your support!
