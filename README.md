# Data-Communication-Project
How to use SPI (Serial Peripheral Interface) in Arduino to Communication between two Arduino Boards.
We will use SPI Protocol for communication between two Arduinos. 
Here one Arduino will act as Master and another one will act as Slave, two LEDs and push buttons will be connected to both the Arduino. 
To demonstrate SPI communication, we will control the master side LED by the push button at the slave side and vice versa using the SPI Serial communication protocol.

What is SPI?
SPI (Serial Peripheral Interface) is a serial communication protocol. SPI interface was found by Motorola in 1970. 
SPI has a full-duplex connection, which means that the data is sent and received simultaneously. 
That is a master can send data to a slave and a slave can send data to the master simultaneously. 
SPI is synchronous serial communication means the clock is required for communication purposes.
