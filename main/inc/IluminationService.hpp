#ifndef ILUMINATION_SERVICE_HPP
#define ILUMINATION_SERVICE_HPP

#include "../main.h"
#include "BalanceService.hpp"

class IluminationService {
public:
  IluminationService();
  ~IluminationService();
  void init();
  void turnOnLed();
  void turnOffLed();
  int getCounter();
  void setCounter(int);
  void handleTimerISR();
  void lightLedsByBinaryCode(uint8_t binaryCode);
  uint8_t binaryCode;

private:
  int counter;
};

#endif