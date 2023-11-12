#ifndef BALANCE_SERVICE_HPP
#define BALANCE_SERVICE_HPP

#include "../main.h"
#include "HX711.h"

class BalanceService {
public:
  BalanceService();
  ~BalanceService();
  void init();
  double getMeasurement();
  static BalanceStatus getBalanceStatus(int balanceNumber);
  static uint8_t getBinaryCode(int currBalance, BalanceStatus currBalanceStatus);

private:
  HX711* cell = NULL;
};

#endif