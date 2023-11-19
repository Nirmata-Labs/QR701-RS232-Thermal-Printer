# QR701 Thermal Printer with RS232 Interface

## Overview

The QR701 thermal printer is a compact and versatile printing solution that can be easily integrated with Arduino and Wemos platforms. This guide provides instructions on how to set up and use the QR701 thermal printer.

## Basics of QR701 Thermal Printer

The QR701 thermal printer is known for its:

- **Compact Design:** Ideal for space-constrained projects.
- **Thermal Printing Technology:** No need for ink or toner cartridges.
- **Wide Compatibility:** Works seamlessly with Arduino and Wemos platforms.

## Hardware Setup



### GPIO-Pin Connections

| QR701 Pin   | Arduino Pin | Wemos Pin |
|-------------|-------------|-----------|
| TX (Data In) | 10          | D3        |
| RX (Data Out)| 11          | D4        |
| GND         | GND         | GND       |
| VCC (5V)    | 5V          | 5V        |

**Note:** Ensure that the voltage levels are compatible between the QR701 and your microcontroller (Arduino/Wemos).

## Software Setup


