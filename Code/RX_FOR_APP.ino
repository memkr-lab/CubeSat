#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// NRF24L01 Pins
#define CE_PIN 9
#define CSN_PIN 8

// NRF24L01 Address
const byte address[6] = "00001";

// Instances
RF24 radio(CE_PIN, CSN_PIN);

void setup() {
  Serial.begin(115200);  // Serial monitor for debugging

  // Initialize NRF24L01
  if (!radio.begin()) {
    Serial.println("NRF24L01 not detected!");
    while (1);
  }

  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();  // Start listening for incoming data
}

void loop() {
  if (radio.available()) {
    char receivedData[32];  // Adjust size based on expected data length

    // Read the incoming data
    radio.read(&receivedData, sizeof(receivedData));

    // Display the received data (without labels like S, G, etc.)
    Serial.println(receivedData);
  }
}
