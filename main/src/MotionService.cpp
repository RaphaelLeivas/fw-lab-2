#include "../inc/MotionService.hpp"

MotionService::MotionService() {
}

MotionService::~MotionService() {
}

void MotionService::init() {
  pinMode(MOTION_SENSOR_INPUT, INPUT);
}

bool MotionService::hasPresence() {
  int read = digitalRead(MOTION_SENSOR_INPUT);
  return read == 1 ? true : false;
}



