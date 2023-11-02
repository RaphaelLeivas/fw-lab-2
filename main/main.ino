// includes
#include "inc/BluetoothService.hpp"
#include "inc/BalanceService.hpp"

#define SERIAL_BAUD_RATE 9600

BluetoothService bluetoothService;
BalanceService balanceService;

double measures[3] = { 124.5, 21.04, 0 };

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  bluetoothService.init();
  balanceService.init();

  // pinMode(LED_PIN, OUTPUT);
  // digitalWrite(LED_PIN, HIGH);
}

void loop() {
  if (bluetoothService.isConnected()) {
    // bluetoothService.write("Hello World! \n");
    // bluetoothService.getData();

    bluetoothService.sendData(measures);
  }

  double read = balanceService.getMeasurement();
  Serial.println(read);

  delay(1000);
}