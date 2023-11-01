#ifndef BLUETOOTH_DRIVER_HPP
#define BLUETOOTH_DRIVER_HPP

#include "Arduino.h"
#include "SoftwareSerial.h"

#define DT A1
#define SCK A0
#define HC05_TXD 4
#define HC05_RXD 5
#define HC05_STATE 3

#define MESSAGE_LENGTH 256
#define NUMBER_OF_BALANCES 3

class BluetoothDriver {
public:
  BluetoothDriver();
  ~BluetoothDriver();
  void init();
  bool isBluetoothConnected();
  void writeToBluetooth(const char*);
  int getDataFromBluetooth();
  void sendJsonToApp(double*);

private:
  SoftwareSerial* bluetooth = NULL;
};

#endif