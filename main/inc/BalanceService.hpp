#ifndef BALANCE_SERVICE_HPP
#define BALANCE_SERVICE_HPP

#include "Arduino.h"
#include "HX711.h"

#define DT A1
#define SCK A0

class BalanceService {
public:
  BalanceService();
  ~BalanceService();
  void init();
  double getMeasurement();

private:
  HX711* cell = NULL;
};

#endif