// Include necessary library for software serial communication
#include <SoftwareSerial>

// Define transmit and receive pins for SoftwareSerial communication
#define TX_PIN 6 // Arduino 6, Wemos TX
#define RX_PIN 5 // Arduino 5, Wemos RX
#define BAUD_RATE 9600

// Create a SoftwareSerial instance named "printer" with RX on pin 5 and TX on pin 6
SoftwareSerial printer(RX_PIN, TX_PIN);

/*--------Print barcode instruction, including information “DFR0503”---------*/
char bar_code[24] = {
  0x1b, 0x40,            
  0x1d, 0x48, 0x02,  // Select the print address of the information (HRI character) included in the barcode. 0x02 means that the printed information should be below the barcode.
  0x1d, 0x68, 0x64,  // Set barcode height, range "1~255", here set to 0x64.
  0x1d, 0x77, 0x03,  // Set horizontal width, here select 0x03.
  0x1d, 0x6b, 0x49, 0x09, 0x7B, 0x42, 0x44, 0x46, 0x52, 0x7B, 0x43, 0x05, 0x03   // Set the information included in barcode. Barcode length 0x09 corresponds to "DFR0503".
};  // If the information is "DFR050308", the barcode length should be 0x0B, and so on.

/*--------Print QR code instruction, including information "www.dfrobot.com"---------*/
const char QRx[60] = {
  0x1b, 0x40,            
  0x1d, 0x28, 0x6b, 0x03, 0x00, 0x31, 0x43, 0x05,  // QR code size 0x05
  0x1d, 0x28, 0x6b, 0x03, 0x00, 0x31, 0x45, 0x30,  // Set QR code verification level to L.
  0x1d, 0x28, 0x6b, 0x12, 0x00, 0x31, 0x50, 0x30, 0x77, 0x77, 0x77, 0x2E, 0x64, 0x66, 0x72, 0x6F, 0x62, 0x6F, 0x74, 0x2E, 0x63, 0x6F, 0x6D  
  // 0x12 is the number of characters (15) of the information "www.dfrobot.com" included in QR code plus 3.
  // 0x77, 0x77, 0x77, 0x2E, 0x64, 0x66, 0x72, 0x6F, 0x62, 0x6F, 0x74, 0x2E, 0x63, 0x6F, 0x6D are the ASCII codes of the characters of the website address.
  0x1b, 0x61, 0x01,  // Center the graphic
  0x1d, 0x28, 0x6b, 0x03, 0x00, 0x31, 0x52, 0x30,  // Verify the QR code
  0x1d, 0x28, 0x6b, 0x03, 0x00, 0x31, 0x51, 0x30  // Print the QR code
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
