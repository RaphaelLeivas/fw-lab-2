// includes
#include "main.h"
#include "inc/BluetoothService.hpp"
#include "inc/BalanceService.hpp"
#include "inc/IluminationService.hpp"
#include "inc/MotionService.hpp"

BluetoothService bluetoothService;
BalanceService balanceService;
IluminationService iluminationService;
MotionService motionService;

double measures[3] = { 124.5, 21.04, 0 };
bool state = false;
int count = 0;

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);
  // bluetoothService.init();
  // balanceService.init();
  iluminationService.init();
  // motionService.init();
}

void loop() {
  // if (bluetoothService.isConnected()) {
  //   // bluetoothService.write("Hello World! \n");
  //   // bluetoothService.getData();

  //   bluetoothService.sendData(measures);
  // }

  // double read = balanceService.getMeasurement();
  // Serial.println(read);

  // if (iluminationService.getCounter() % 500 == 0) {
  //     iluminationService.turnOnLed();
  //   }

  //   state = !state;
  // }

  // BalanceStatus status = iluminationService.status;
  // if (status == BalanceStatus::FULL_BALANCE) {
  //   Serial.println("FULL_BALANCE");
  // } else {
  //   Serial.println("Failed");
  // }

  // int firstBit =  (iluminationService.binaryCode >> 0) & 1;
  // int secondBit =  (iluminationService.binaryCode >> 1) & 1;
  // int thirdBit =  (iluminationService.binaryCode >> 2) & 1;

  // Serial.println(firstBit);
  // Serial.println(secondBit);
  // Serial.println(thirdBit);                                                                                                                                                                                                                                                         


  // Serial.println(motionService.hasPresence());
  Serial.println("Hello");
  delay(1000);
}

// ISRs
ISR(TIMER1_OVF_vect) {  // TIMER1 ISR
  iluminationService.handleTimerISR();
}
