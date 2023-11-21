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

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);

  // bluetoothService.init();
  // balanceService.init();
  iluminationService.init();
  // motionService.init();
}

void loop() {
  // double read = balanceService.getMeasurement();
  // Serial.println(read);

  // if (bluetoothService.isConnected()) {
  //   // bluetoothService.write("Hello World! \n");
  //   bluetoothService.getData();

  //   measures[0] = read;
  //   bluetoothService.sendData(measures);
  // }

  // if (iluminationService.getCounter() % 500 == 0) {
  //     iluminationService.turnOnLed();
  //   }

  //   state = !state;
  // }

  // int firstBit =  (iluminationService.binaryCode >> 0) & 1;
  // int secondBit =  (iluminationService.binaryCode >> 1) & 1;
  // int thirdBit =  (iluminationService.binaryCode >> 2) & 1;

  // Serial.println(firstBit);
  // Serial.println(secondBit);
  // Serial.println(thirdBit);       
                                                                                                                                                                                                                                        
  // Serial.println(motionService.hasPresence());
  // Serial.println("Hello");

  int currBalance = 0;
  BalanceStatus currBalanceStatus = BalanceService::getBalanceStatus(currBalance);
  iluminationService.lightLedsByStatus(currBalance, currBalanceStatus);
  delay(500);
}
