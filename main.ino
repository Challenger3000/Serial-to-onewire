#include <OneWire.h>

// Instantiate the OneWire object. The argument is the Arduino pin number where your one-wire device is connected.
OneWire oneWire(2);

void setup() {
  // Start the serial communication with a baud rate of 9600 (or whatever your device uses).
  Serial.begin(115200);
}

void loop() {
  // Check if data is available to read from the USB serial.
  if (Serial.available() > 0) {
    // Read the incoming byte.
    byte incomingByte = Serial.read();

    // Reset the one-wire bus and select the device
    oneWire.reset();
    oneWire.skip(); // Use this if you have a single one-wire device on the bus. If not, you'll need to address it specifically.
    
    // Send the byte to the one-wire device.
    oneWire.write(incomingByte);
  }

  // If you expect a response from the one-wire device, read it here.
  // Note that not all one-wire devices will send responses in this manner,
  // and you will typically need to adhere to the specific protocol of the device.
  // ...
}
