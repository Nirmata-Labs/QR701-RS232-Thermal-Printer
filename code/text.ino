// Include necessary libraries for thermal printer and software serial communication
#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"

// Define transmit and receive pins for SoftwareSerial communication
#define TX_PIN TX // Arduino 6, Wemos TX
#define RX_PIN RX // Arduino 5, Wemos RX
#define BAUD_RATE 9600 // Choose 9600 or 19200 based on your printer

// Initialize SoftwareSerial with specified transmit and receive pins
SoftwareSerial printer_connection(RX_PIN, TX_PIN);
// Create an instance of Adafruit_Thermal using the SoftwareSerial instance
Adafruit_Thermal printer(&printer_connection);

void setup() {
  // Initialize SoftwareSerial communication with the thermal printer at 9600 baud
  printer_connection.begin(BAUD_RATE); 
  // Initialize the thermal printer
  printer.begin();
  // Wait until the serial buffer is empty before proceeding
  while(Serial.read() >= 0){}
}

void loop() { 
  // Font options
  printer.setFont('B');
  printer.println("FontB");
  printer.println("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  
  printer.setFont('A');
  printer.println("FontA (default)");
  printer.println("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

  // Test inverse on & off
  printer.inverseOn();
  printer.println(F("Inverse ON"));
  printer.inverseOff();

  // Test character double-height on & off
  printer.doubleHeightOn();
  printer.println(F("Double Height ON"));
  printer.doubleHeightOff();

  // Set text justification (right, center, left) -- accepts 'L', 'C', 'R'
  printer.justify('R');
  printer.println(F("Right justified"));
  printer.justify('C');
  printer.println(F("Center justified"));
  printer.justify('L');
  printer.println(F("Left justified"));

  // Test more styles
  printer.boldOn();
  printer.println(F("Bold text"));
  printer.boldOff();

  printer.underlineOn();
  printer.println(F("Underlined text"));
  printer.underlineOff();

  // Set text size ('S', 'M', 'L')
  printer.setSize('L');
  printer.println(F("Large"));
  printer.setSize('M');
  printer.println(F("Medium"));
  printer.setSize('S');
  printer.println(F("Small"));

  // Adjust text justification and line spacing
  printer.justify('C');
  printer.println(F("normal\nline\nspacing"));
  printer.setLineHeight(50);
  printer.println(F("Taller\nline\nspacing"));
  printer.setLineHeight(); // Reset to default
  printer.justify('L');

  // Put the printer to sleep for 10 seconds
  printer.sleep();
  delay(10000);

  // Wake up the printer (MUST wake before printing again, even if reset)
  printer.wake();
  // Restore printer to default settings
  printer.setDefault();
}
