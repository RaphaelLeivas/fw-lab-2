#ifndef ILUMINATION_SERVICE_HPP
#define ILUMINATION_SERVICE_HPP

#include "../main.h"
#include "BalanceService.hpp"

class IluminationService {
public:
  IluminationService();
  ~IluminationService();
  void init();
  uint8_t lightLedsByStatus(int currBalance, BalanceStatus currBalanceStatus);

private:
  int counter;
};

#endif