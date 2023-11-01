#include "HX711.h"

// includes
#include "inc/bluetoothDriver.hpp"
#include "inc/balanceDriver.hpp"

HX711 cell;
BluetoothDriver driver;
BalanceDriver balDriver;

float getGramsFromRead(float read) {
  return -2.02 * (read / 1000) + 1074.68;
}

double measures[3] = { 124.5, 21.04, 0 };

void setup() {
  Serial.begin(9600);
  driver.init();

  // pinMode(LED_PIN, OUTPUT);
  // digitalWrite(LED_PIN, HIGH);

  // cell.begin(DT, SCK);
}

void loop() {
  if (driver.isBluetoothConnected()) {
    // driver.writeToBluetooth("Hello World! \n");
    // driver.getDataFromBluetooth();

    driver.sendJsonToApp(measures);
  }

  // float read = cell.read();
  // Serial.println(getGramsFromRead(read));
  delay(1000);
}