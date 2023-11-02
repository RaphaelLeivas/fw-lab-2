#ifndef BLUETOOTH_SERVICE_HPP
#define BLUETOOTH_SERVICE_HPP

#include "Arduino.h"
#include "SoftwareSerial.h"

#define HC05_TXD 4
#define HC05_RXD 5
#define HC05_STATE 3

#define MESSAGE_LENGTH 256
#define NUMBER_OF_BALANCES 3

class BluetoothService {
public:
  BluetoothService();
  ~BluetoothService();
  void init();
  bool isConnected();
  void write(const char*);
  int getData();
  void sendData(double*);

private:
  SoftwareSerial* bluetooth = NULL;
};

#endif