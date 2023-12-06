// includes
#include "main.h"
#include "inc/BluetoothService.hpp"
#include "inc/BalanceService.hpp"
#include "inc/IluminationService.hpp"
#include "inc/MotionService.hpp"

BalanceService bal2Service;
BalanceService bal3Service;

BluetoothService bluetoothService;
IluminationService iluminationService;
MotionService motionService;

double measures[3] = { 0, 0, 0 };
bool state = false;

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);

  // initialize all balances
  bal2Service.init(BAL2_DT, BAL2_SCK, CHANNEL_A);
  bal3Service.init(BAL3_DT, BAL3_SCK, CHANNEL_B);

  bluetoothService.init();
  // iluminationService.init();
  // motionService.init();
}

void loop() {
  // reads all balances
  int read_bal1 = 0;
  int read_bal2 = bal2Service.getRawMeasurement();
  // Serial.print("read_bal2: ");
  // Serial.print(read_bal2);
  // Serial.print("\n");
  int read_bal3 = bal3Service.getRawMeasurement();
  // Serial.print("read_bal3: ");
  // Serial.print(read_bal3);
  // Serial.print("\n");

  measures[0] = read_bal1;
  measures[1] = read_bal2;
  measures[2] = read_bal3;

  // sends data to Bluetooth
  if (bluetoothService.isConnected()) {
    bluetoothService.getData();
    bluetoothService.sendData(measures);
  }

  // bluetoothService.write("Hello \n");

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

  // int currBalance = 0;
  // BalanceStatus currBalanceStatus = BalanceService::getBalanceStatus(currBalance);
  // iluminationService.lightLedsByStatus(currBalance, currBalanceStatus);
  delay(1000);
}
