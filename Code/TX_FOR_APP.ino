#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_MPU6050.h>
#include <DHT.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <TinyGPSPlus.h>
#include <QMC5883LCompass.h>
#include <Adafruit_NeoPixel.h>

// Sensor Pins
#define DHTPIN 14
#define DHTTYPE DHT22

// NRF24L01 Pins
#define CE_PIN 26
#define CSN_PIN 27

// GPS Pins (HardwareSerial)
#define GPS_RX_PIN 16
#define GPS_TX_PIN 17

// LED Strip Pin
#define LED_PIN 17
#define NUM_LEDS 8

// Instances
DHT dht(DHTPIN, DHTTYPE);
Adafruit_MPU6050 mpu;
Adafruit_BMP280 bmp;
QMC5883LCompass compass;  // Replace Adafruit HMC5883 with QMC5883LCompass
RF24 radio(CE_PIN, CSN_PIN);
HardwareSerial mySerial(1);  // Use hardware serial port 1 for GPS
TinyGPSPlus gps;
Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// NRF24L01 Address
const byte address[6] = "00001";

unsigned long previousMillisG = 0;
unsigned long previousMillisS = 0;
unsigned long previousMillisA = 0;
unsigned long previousMillisGY = 0;
unsigned long previousMillisO = 0; // For orientation
unsigned long intervalG = 1000;  // 1000ms delay for GPS
unsigned long intervalS = 1000;  // 1000ms delay for Sensors
unsigned long intervalA = 100;   // 100ms delay for Accelerometer
unsigned long intervalGY = 100;  // 100ms delay for Gyroscope and Magnetometer
unsigned long intervalO = 500;   // 500ms delay for Orientation

void setup() {
  Serial.begin(115200);  // Initialize serial monitor
  mySerial.begin(9600, SERIAL_8N1, GPS_RX_PIN, -1);  // GPS communication on HardwareSerial1

  // Initialize sensors
  dht.begin();
  if (!mpu.begin()) {
    Serial.println("MPU6050 not initialized");
  }
  if (!bmp.begin(0x76)) {
    Serial.println("BMP280 not initialized");
  }
  
  // Initialize the QMC5883L Compass
  compass.init();
  if (!radio.begin()) {
    Serial.println("NRF24L01 not initialized");
  }
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  Serial.println("Waiting for GPS fix...");

  // Initialize the LED strip
  strip.begin();
  strip.setBrightness(5);  // Set brightness to 5%
  strip.show();            // Initialize all LEDs to off
  setAllLEDsRed();         // Set all LEDs to red
}

void loop() {
  // Send accelerometer data
  if (millis() - previousMillisA >= intervalA) {
    previousMillisA = millis();
    sendAccelerationData();
  }

  // Send gyroscope and magnetometer data
  if (millis() - previousMillisGY >= intervalGY) {
    previousMillisGY = millis();
    sendGyroscopeAndMagnetometerData();
  }

  // Update GPS data
  if (millis() - previousMillisG >= intervalG) {
    previousMillisG = millis();
    sendGPSData();
  }

  // Update sensor data
  if (millis() - previousMillisS >= intervalS) {
    previousMillisS = millis();
    sendSensorData();
  }

  // Detect orientation
  if (millis() - previousMillisO >= intervalO) {
    previousMillisO = millis();
    detectOrientation();
  }
}

void setAllLEDsRed() {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));  // Set each LED to red
  }
  strip.show();
}

void sendAccelerationData() {
  sensors_event_t a, g, temp_event;
  mpu.getEvent(&a, &g, &temp_event);

  char lineAC[32];
  snprintf(lineAC, sizeof(lineAC), "AC,%.2f,%.2f,%.2f", a.acceleration.x, a.acceleration.y, a.acceleration.z);
  radio.write(&lineAC, sizeof(lineAC));
  Serial.println(lineAC);
}

void sendGyroscopeAndMagnetometerData() {
  sensors_event_t a, g, temp_event;
  mpu.getEvent(&a, &g, &temp_event);

  compass.read();
  int mx = compass.getX();
  int my = compass.getY();
  int mz = compass.getZ();

  char lineGY[32], lineMG[32];
  snprintf(lineGY, sizeof(lineGY), "GY,%.2f,%.2f,%.2f", g.gyro.x, g.gyro.y, g.gyro.z);
  snprintf(lineMG, sizeof(lineMG), "MG,%d,%d,%d", mx, my, mz);

  radio.write(&lineGY, sizeof(lineGY));
  Serial.println(lineGY);

  radio.write(&lineMG, sizeof(lineMG));
  Serial.println(lineMG);
}

void sendGPSData() {
  while (mySerial.available() > 0) {
    gps.encode(mySerial.read());
  }

  char gpsData[32];
  if (gps.location.isUpdated()) {
    snprintf(gpsData, sizeof(gpsData), "G,%.6f,%.6f", gps.location.lat(), gps.location.lng());
  } else {
    snprintf(gpsData, sizeof(gpsData), "G,NA,NA");
  }

  radio.write(&gpsData, sizeof(gpsData));
  Serial.println(gpsData);
}

void sendSensorData() {
  float temp = isnan(dht.readTemperature()) ? NAN : dht.readTemperature();
  float hum = isnan(dht.readHumidity()) ? NAN : dht.readHumidity();
  float pressure = isnan(bmp.readPressure()) ? NAN : bmp.readPressure();

  compass.read();
  int mx = compass.getX();
  int my = compass.getY();
  float heading = atan2(my, mx);
  heading = heading < 0 ? heading + 2 * PI : heading;
  heading = heading * 180 / PI;

  char lineS[32];
  snprintf(lineS, sizeof(lineS), "S,%.1f,%.1f,%.1f,%.1f", temp, hum, pressure, heading);

  radio.write(&lineS, sizeof(lineS));
  Serial.println(lineS);
}

void detectOrientation() {
  sensors_event_t a, g, temp_event;
  mpu.getEvent(&a, &g, &temp_event);

  String orientation = "Unknown";
  const float threshold = 8.5;

  if (a.acceleration.z > threshold) orientation = "Topside Up";
  else if (a.acceleration.z < -threshold) orientation = "Reverse Up";
  else if (a.acceleration.x > threshold) orientation = "Right Side Up";
  else if (a.acceleration.x < -threshold) orientation = "Left Side Up";
  else if (a.acceleration.y > threshold) orientation = "Front Side Up";
  else if (a.acceleration.y < -threshold) orientation = "Back Side Up";

  char orientationMsg[32];
  snprintf(orientationMsg, sizeof(orientationMsg), "OR,%s", orientation.c_str());
  radio.write(&orientationMsg, sizeof(orientationMsg));
  Serial.println(orientationMsg);
}
