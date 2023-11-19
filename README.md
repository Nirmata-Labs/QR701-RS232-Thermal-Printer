# QR701 Thermal Printer with RS232 Interface

![Overview](https://github.com/RaccoonAI/QR701-RS232-Thermal-Printer/blob/main/images/QR701-Overview.png)

## Overview

The QR701 thermal printer is a compact and versatile printing solution that can be easily integrated with Arduino and Wemos platforms. This guide provides instructions on how to set up and use the QR701 thermal printer.

## QR701 TTL vs. QR701 RS232 Thermal Printers

When choosing a thermal printer for your project, you may encounter different variants, such as the QR701 TTL and QR701 RS232. 
**You can not use the RS232-version without any converter!** Here are the key differences between the two:

### QR701 TTL Thermal Printer

The QR701 TTL variant is designed to work with microcontrollers and devices that support TTL-level serial communication. TTL, or Transistor-Transistor Logic, refers to the logic levels used in digital circuits.

- **Compatibility:** Ideal for use with microcontrollers like Arduino, Raspberry Pi, and similar devices.
- **Communication Interface:** Uses TTL-level serial communication.
- **Voltage Level:** Operates at logic level voltages (usually 3.3V or 5V).
- **Wiring:** Connects directly to the TX and RX pins of the microcontroller.

### QR701 RS232 Thermal Printer

The QR701 RS232 variant, on the other hand, is designed to work with devices that support RS232 serial communication. RS232 is a standard for serial communication transmission of data.

- **Compatibility:** Suitable for devices with RS232 serial ports, such as computers, industrial equipment, and certain communication modules.
- **Communication Interface:** Uses RS232-level serial communication.
- **Voltage Level:** Operates at higher voltage levels (commonly -12V to +12V).
- **Wiring:** Requires a voltage level shifter or converter to interface with microcontrollers.


## Basics of QR701 Thermal Printer

The QR701 thermal printer is known for its:

- **Compact Design:** Ideal for space-constrained projects.
- **Thermal Printing Technology:** No need for ink or toner cartridges.
- **Wide Compatibility:** Works seamlessly with Arduino and Wemos platforms.

## Hardware Setup

### RS232 to TTL Converter with cable interface
![GPIO-Connection](https://github.com/RaccoonAI/QR701-RS232-Thermal-Printer/blob/main/images/QR701-Connection.png)

### Mini RS232 to TTL Converter 
![GPIO-Connection](https://github.com/RaccoonAI/QR701-RS232-Thermal-Printer/blob/main/images/QR701-Connector-Small-Module.png)

### GPIO-Pin Connections

**Microcontroller to RS232-TTL-Converter:**
| RS232-TTL-Converter  | Arduino Pin | Wemos Pin |
|-------------|-------------|-----------|
| TX (Data In) | 6          | TX        |
| RX (Data Out)| 5          | RX        |
| GND         | GND         | GND       |
| VCC (5V)    | 5V          | 5V        |

**Microcontroller to RS232-TTL-Converter :**
|QR701 Pin   | RS232-TTL-Converter | Mini RS232-TTL-Converter | 
|-------------|-------------|-------------|
| TX (Data In) | 3          |  TXD          | 
| RX (Data Out)| 4          |  RXD          | 
| GND         | 1         |  GND          | 

**Power Source:**
| QR701 Pin   | Power Source |
|-------------|-------------|
| VH (9V)    | 9V          | 
| GND    | GND          | 

**Note:** Printer can be powerd in a range from 5 to 9V. At low voltage (5V), the print image is very weak and printing is slow. 

## Software Setup

**Note:** When using the Arduino 9V power supply, the power supply must be deactivated during programming, otherwise the microcontroller will not appear at the port.

