#include "../inc/BalanceService.hpp"

// private functions
double getGramsFromRead(double read) {
  return -2.02 * (read / 1000) + 1074.68;
}

BalanceService::BalanceService() {
  this->cell = new HX711();
}

BalanceService::~BalanceService() {
  delete this->cell;
}

void BalanceService::init() {
  this->cell->begin(DT, SCK);
}

double BalanceService::getMeasurement() {
  double rawRead = this->cell->read();
  return getGramsFromRead(rawRead);
}

static BalanceStatus BalanceService::getBalanceStatus(int balanceNumber) {
  // TODO: implement logic here
  return BalanceStatus::FULL_BALANCE;
}

static uint8_t BalanceService::getBinaryCode(int currBalance, BalanceStatus currBalanceStatus) {
  if (currBalanceStatus == BalanceStatus::FULL_BALANCE) {
    return 0b000;
  } else if (currBalanceStatus == BalanceStatus::HALF_BALANCE) {
    return 0b001;
  } else {
    return 0b010;
  }
}

