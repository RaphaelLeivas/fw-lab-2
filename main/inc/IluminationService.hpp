#ifndef ILUMINATION_SERVICE_HPP
#define ILUMINATION_SERVICE_HPP

#include "Arduino.h"

#define LED_PIN 6

class IluminationService {
public:
  IluminationService();
  ~IluminationService();
  void init();
  void turnOnLed();
  void turnOffLed();
  int getCounter();
  void setCounter(int);

private:
  int counter;
};

#endif