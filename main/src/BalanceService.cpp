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
