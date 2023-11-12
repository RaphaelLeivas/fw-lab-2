#ifndef MAIN_H
#define MAIN_H

#include "Arduino.h"

// BalanceService
#define DT A1
#define SCK A0
#define NUMBER_OF_BALANCES 3

enum class BalanceStatus {
  FULL_BALANCE = 0, // green LED
  HALF_BALANCE, // yellow LED
  LOW_BALANCE // red LED
};

// BluetoothService
#define HC05_TXD 4
#define HC05_RXD 5
#define HC05_STATE 3

#define BLE_SUBSTRING_SIZE 12
#define BLE_STRING_SIZE 64

// IluminationService
#define LED_PIN 6
#define DEMUX_SEL_0 8
#define DEMUX_SEL_1 9
#define DEMUX_SEL_2 10

// MotionService
#define MOTION_SENSOR_INPUT 7

// main code
#define SERIAL_BAUD_RATE 9600

#endif