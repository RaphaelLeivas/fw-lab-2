#include "../inc/IluminationService.hpp"

IluminationService::IluminationService() {
}

IluminationService::~IluminationService() {
}

void IluminationService::init() {
  pinMode(BAL1_GREEN, OUTPUT);
  pinMode(BAL1_YELLOW, OUTPUT);
  pinMode(BAL1_RED, OUTPUT);
}

uint8_t IluminationService::lightLedsByStatus(int currBalance, BalanceStatus currBalanceStatus) {
  // tests considering the balance number
  switch (currBalance) {
    case 0:
      {
        // reset bal leds
        digitalWrite(BAL1_GREEN, LOW);
        digitalWrite(BAL1_YELLOW, LOW);
        digitalWrite(BAL1_RED, LOW);

        if (currBalanceStatus == BalanceStatus::FULL_BALANCE) {
          digitalWrite(BAL1_GREEN, HIGH);
        } else if (currBalanceStatus == BalanceStatus::HALF_BALANCE) {
          digitalWrite(BAL1_YELLOW, HIGH);
        } else {
          digitalWrite(BAL1_RED, HIGH);
        }
      }
    case 1:
      {
        // reset bal leds
        digitalWrite(BAL1_GREEN, LOW);
        digitalWrite(BAL1_YELLOW, LOW);
        digitalWrite(BAL1_RED, LOW);

        if (currBalanceStatus == BalanceStatus::FULL_BALANCE) {
          digitalWrite(BAL1_GREEN, HIGH);
        } else if (currBalanceStatus == BalanceStatus::HALF_BALANCE) {
          digitalWrite(BAL1_YELLOW, HIGH);
        } else {
          digitalWrite(BAL1_RED, HIGH);
        }
      }
    case 2:
      {
        // reset bal leds
        digitalWrite(BAL1_GREEN, LOW);
        digitalWrite(BAL1_YELLOW, LOW);
        digitalWrite(BAL1_RED, LOW);

        if (currBalanceStatus == BalanceStatus::FULL_BALANCE) {
          digitalWrite(BAL1_GREEN, HIGH);
        } else if (currBalanceStatus == BalanceStatus::HALF_BALANCE) {
          digitalWrite(BAL1_YELLOW, HIGH);
        } else {
          digitalWrite(BAL1_RED, HIGH);
        }
      }
  }
}
