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

private:
  HX711* cell = NULL;

  // balance measurements (in grams)
  double balance1;
  double balance2;
  double balance3;

  // balance limits (comes from the app via Bluetooth)
  double bal1FullThreshold;
  double bal1HalfThreshold;
  double bal2FullThreshold;
  double bal2HalfThreshold;
  double bal3FullThreshold;
  double bal3HalfThreshold;
};

#endif