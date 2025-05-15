#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   4
#define CSN_PIN  5

// Setup LCD (change 0x27 to your I2C address if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Setup RF24
RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

struct DroneData {
  int throttle;
  int yaw;
  int pitch;
  int roll;
} __attribute__((packed));

DroneData data;

void setup() {
  Serial.begin(115200);

  // Initialize I2C LCD
  Wire.begin(21, 22);  // Set SDA to GPIO21, SCL to GPIO22 (ESP32 default)
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");

  // Initialize RF24
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();

  delay(500);
  lcd.clear();
}

void loop() {
  data.throttle = map(analogRead(34), 0, 4095, 1000, 2000);
  data.yaw      = map(analogRead(35), 0, 4095, 1000, 2000);
  data.pitch    = map(analogRead(33), 0, 4095, 1000, 2000);
  data.roll     = map(analogRead(32), 0, 4095, 1000, 2000);

  // Transmit via nRF24L01
  if (radio.write(&data, sizeof(data))) {
    Serial.printf("Sent: T:%d Y:%d P:%d R:%d\n", data.throttle, data.yaw, data.pitch, data.roll);
  } else {
    Serial.println("Message Sending Failed!");
  }

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.printf("T:%d Y:%d", data.throttle, data.yaw);
  lcd.setCursor(0, 1);
  lcd.printf("R:%d P:%d", data.roll, data.pitch);

  delay(200);
}
