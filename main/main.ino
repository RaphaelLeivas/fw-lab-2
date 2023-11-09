// includes
#include "inc/BluetoothService.hpp"
#include "inc/BalanceService.hpp"
#include "inc/IluminationService.hpp"
#include "inc/MotionService.hpp"

#define SERIAL_BAUD_RATE 9600

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
  // iluminationService.init();
  motionService.init();
}

void loop() {
  // if (bluetoothService.isConnected()) {
  //   // bluetoothService.write("Hello World! \n");
  //   // bluetoothService.getData();

  //   bluetoothService.sendData(measures);
  // }

  // double read = balanceService.getMeasurement();
  // Serial.println(read);

  // if (iluminationService.getCounter() == 1000) {
  //   iluminationService.setCounter(0);

  //   if (state) {
  //     iluminationService.turnOnLed();
  //   } else {
  //     iluminationService.turnOffLed();
  //   }

  //   state = !state;
  // }

  Serial.println(motionService.hasPresence());
  // Serial.println("Hello");
  delay(500);
}

// ISRs
// ISR(TIMER0_COMPA_vect) {  // TIMER0 ISR
//   int currentCounter = iluminationService.getCounter();
//   iluminationService.setCounter(currentCounter + 1);
// }

