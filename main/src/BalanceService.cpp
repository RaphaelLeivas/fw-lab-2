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
  
  this->balance1 = 0;
  this->balance2 = 0;
  this->balance3 = 0;

  this->bal1FullThreshold = 0;
  this->bal1HalfThreshold = 0;
  this->bal2HalfThreshold = 0;
  this->bal2HalfThreshold = 0;
  this->bal3HalfThreshold = 0;
  this->bal3HalfThreshold = 0;
}

double BalanceService::getMeasurement() {
  int rawRead = this->cell->read();
  double read = getGramsFromRead(rawRead);

  this->balance1 = read;
  return read;
}

static BalanceStatus BalanceService::getBalanceStatus(int balanceNumber) {
  // switch (balanceNumber) {
  //   case 0: { // first balance
  //     if (this->balance1 >= this->bal1FullThreshold) {
  //       return BalanceStatus::FULL_BALANCE;
  //     } else if (this->balance1 >= this->bal1HalfThreshold) {
  //       return BalanceStatus::HALF_BALANCE;
  //     } else {
  //       return BalanceStatus::LOW_BALANCE;
  //     }

  //     break;
  //   }
  // }

  return BalanceStatus::FULL_BALANCE;
}

