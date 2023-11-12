#ifndef BLUETOOTH_SERVICE_HPP
#define BLUETOOTH_SERVICE_HPP

#include "../main.h"
#include "SoftwareSerial.h"

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