#include "../inc/IluminationService.hpp"

IluminationService::IluminationService() {
}

IluminationService::~IluminationService() {
}

void IluminationService::init() {
  pinMode(LED_PIN, OUTPUT);
  this->counter = 0;

  // TIMER0 configuration
  TCCR0A = (1 << WGM01);  // Set the CTC mode
  OCR0A = 0xF9;           // ORC0A value for 1ms

  TIMSK0 |= (1 << OCIE0A);  // Set  the interrupt request
  sei();                    // Enable interrupt

  TCCR0B |= (1 << CS01);  // prescaler 1/64 of internal clock
  TCCR0B |= (1 << CS00);
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


