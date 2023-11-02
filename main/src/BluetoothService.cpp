#include "../inc/bluetoothService.hpp"

BluetoothService::BluetoothService() {
  this->bluetooth = new SoftwareSerial(HC05_TXD, HC05_RXD);
}

BluetoothService::~BluetoothService() {
  delete this->bluetooth;
}

void BluetoothService::init() {
  this->bluetooth->begin(9600);
  pinMode(HC05_STATE, INPUT);
}

bool BluetoothService::isConnected() {
  return digitalRead(HC05_STATE);
}

void BluetoothService::write(const char* message) {
  this->bluetooth->write(message);
}

int BluetoothService::getData() {
  int data = 0;

  if (this->bluetooth->available()) {
    data = this->bluetooth->read();

    if (data == '1') {
      Serial.println("LED LIGADO");
    }
    if (data == '0') {
      Serial.println("LED DESLIGADO");
    }
    if (data == 'b') {
      Serial.println("LOOP DO LED ATIVADO");
    }
  }

  return data;
}

void BluetoothService::sendData(double* measures) {
  // checks the balances measurements
  for (int i = 0; i < NUMBER_OF_BALANCES; ++i) {
    if (measures[i] < 0) {
      measures[i] = 0;
    }
  }

  unsigned long bootTime = millis();

  // builds the data string
  char* str = "Hey \n";
  char firstPart[12];
  strcpy(firstPart, "[");

  char secondPart[12];
  strcpy(secondPart, ",");

  char thirdPart[12];
  strcpy(thirdPart, ",");

  char fourthPart[12];
  strcpy(fourthPart, ",");

  dtostrf(measures[0], 2, 2, &firstPart[strlen(firstPart)]);
  dtostrf(measures[1], 2, 2, &secondPart[strlen(secondPart)]);
  dtostrf(measures[2], 2, 2, &thirdPart[strlen(thirdPart)]);
  dtostrf(bootTime, 0, 0, &fourthPart[strlen(fourthPart)]);

  char message[64];
  strcpy(message, "");

  strcat(message, firstPart);
  strcat(message, secondPart);
  strcat(message, thirdPart);
  strcat(message, fourthPart);
  strcat(message, "]");

  this->bluetooth->write(message);
  this->bluetooth->write("\n");
}
