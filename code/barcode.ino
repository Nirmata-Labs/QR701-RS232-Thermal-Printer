// Include necessary library for software serial communication
#include "SoftwareSerial.h"

// Define transmit and receive pins for SoftwareSerial communication
#define TX_PIN 6 // Arduino 6, Wemos TX
#define RX_PIN 5 // Arduino 5, Wemos RX
#define BAUD_RATE 9600

// Create a SoftwareSerial instance named "printer" with RX on pin 5 and TX on pin 6
SoftwareSerial printer(RX_PIN, TX_PIN);

// Print example barcode
char bar_code[24]={
  0x1b, 0x40,                                                                            
  0x1d, 0x48, 0x02,  //the 43rd command of the general instruction, select the print address of the information (HRI character)included in the barcode.0×02 means that the printed information should be below the barcode.   
  0x1d, 0x68, 0x64,  //set barcode height, range”1~255”, here we set it to “0×64” .
  0x1d, 0x77, 0x03,  //the 45th command of the general instruction, set horizontal width, here we select “0×03”.                                          
  0x1d, 0x6b, 0x49, 0x09, 0x7B, 0x42, 0x44, 0x46, 0x52, 0x7B, 0x43, 0x05, 0x03   //set the information included in barcode. Barcode length “0×09” correspond to ”DFR0503”. “0×44, 0×46, 0×52” are ACILL codes of the three letter D,F,R respectively. “0×05, 0×03” is “0503”.
};     //if the information is “DFR050308”, the barcode length should be”0×0B”, and so on.

// Print example barcode QR code 
const char QRx[60]={
0x1b,0x40,                                                                                 
0x1d,0x28,0x6b,0x03,0x00,0x31,0x43,0x05,  //Refer to the 1st command of special instruction set.QR code size “0×05”
0x1d,0x28,0x6b,0x03,0x00,0x31,0x45,0x30,   //Set QR code verification level to L.
0x1d,0x28,0x6b,0x12,0x00,0x31,0x50,0x30,0x77,0x77,0x77,0x2E,0x64,0x66,0x72,0x6F,0x62,0x6F,0x74,0x2E,0x63,0x6F,0x6D, 
0x1b,0x61,0x01,  //centre the graphic
0x1d,0x28,0x6b,0x03,0x00,0x31,0x52,0x30,   //Verify the QR code
0x1d,0x28,0x6b,0x03,0x00,0x31,0x51,0x30   //print the QR code
};       

void setup() {  
  // Initialize software serial communication with the printer at the defined baud rate
  printer.begin(BAUD_RATE);
  // Initialize the serial communication for debugging
  Serial.begin(BAUD_RATE);  
  // Wait until the serial buffer is empty before proceeding
  while (Serial.read() >= 0) {}
}

void loop() {
  // Print a separator line for clarity
  printer.println();
  printer.print("---------------------------------"); 
  printer.println();
  
  // Send "print barcode instruction" to the printer
  printer.write(bar_code, 24);
  delay(5);
  
  printer.println();
  
  // Send "print QR code instruction" to the printer
  printer.write(QRx, 60);
  
  printer.println();
  printer.print("---------------------------------"); 
  
  // Delay for 5 seconds before the next iteration
  delay(5000);
}
