#include "../inc/IluminationService.hpp"

IluminationService::IluminationService() {
}

IluminationService::~IluminationService() {
}

void IluminationService::init() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(DEMUX_SEL_0, OUTPUT);
  pinMode(DEMUX_SEL_1, OUTPUT);
  pinMode(DEMUX_SEL_2, OUTPUT);
  this->counter = 0;

  // Configuração do timer1 
  TCCR1A = 0;                        //confira timer para operação normal pinos OC1A e OC1B desconectados
  TCCR1B = 0;                        //limpa registrador
  TCCR1B |= (1<<CS10)|(1 << CS12);   // configura prescaler para 1024: CS12 = 1 e CS10 = 1
 
  TCNT1 = 0xC2F7;                    // incia timer com valor para que estouro ocorra em 1 segundo
                                     // 65536-(16MHz/1024/1Hz) = 49911 = 0xC2F7
  
  TIMSK1 |= (1 << TOIE1);           // habilita a interrupção do TIMER1
}

void IluminationService::turnOnLed() {
  digitalWrite(LED_PIN, HIGH);
}

void IluminationService::turnOffLed() {
  digitalWrite(LED_PIN, LOW);
}

int IluminationService::getCounter() {
  return this->counter;
}

void IluminationService::setCounter(int counter) {
  this->counter = counter;
}

uint8_t IluminationService::getBinaryCode(int currBalance, BalanceStatus currBalanceStatus) {
  if (currBalanceStatus == BalanceStatus::FULL_BALANCE) {
    return 0b000;
  } else if (currBalanceStatus == BalanceStatus::HALF_BALANCE) {
    return 0b001;
  } else {
    return 0b010;
  }
}

void IluminationService::lightLedsByBinaryCode(uint8_t binaryCode) {
  int firstBit =  (binaryCode >> 0) & 1;
  int secondBit =  (binaryCode >> 1) & 1;
  int thirdBit =  (binaryCode >> 2) & 1;

  digitalWrite(DEMUX_SEL_0, firstBit);
  digitalWrite(DEMUX_SEL_1, secondBit);
  digitalWrite(DEMUX_SEL_2, thirdBit);
}

void IluminationService::handleTimerISR() {
  int currBalance = this->counter % 3; 
  BalanceStatus currBalanceStatus = BalanceService::getBalanceStatus(currBalance);

  uint8_t binaryCode = this->getBinaryCode(currBalance, currBalanceStatus);
  this->binaryCode = binaryCode;

  this->lightLedsByBinaryCode(binaryCode);

  this->counter = this->counter + 1;
}


