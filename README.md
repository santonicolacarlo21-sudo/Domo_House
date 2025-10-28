# DOMO HOUSE
This is my first project, developed as part of the final examination for high school. I designed and built a small wooden house consisting of multiple rooms, each equipped with a dedicated sensor.

In the living room, a DHT11 sensor monitors temperature and humidity.

In the kitchen, an MQ5 sensor detects potential gas leaks.

In the small bedroom, a PIR sensor identifies unauthorized intrusions.

At the entrance, a buzzer is installed for acoustic alerts. Additionally, the system includes a Bluetooth module, a light sensor to control garden lighting, and LED lights in every room.

The objective of the project is to manage the home automation system via a mobile application developed in Android Studio, using an Arduino Uno board as the central controller. The user can activate or deactivate the anti-theft alarm directly from the mobile device. In case of intrusion, the buzzer will sound. The application also allows monitoring of gas levels detected in the kitchen, temperature and humidity values, and control of indoor lighting. For outdoor lighting, activation is automatic when the brightness detected by the sensor falls below a predefined threshold.
