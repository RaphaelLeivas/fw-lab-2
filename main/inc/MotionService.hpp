#ifndef MOTION_SERVICE_HPP
#define MOTION_SERVICE_HPP

#include "Arduino.h"

#define MOTION_SENSOR_INPUT 7

class MotionService {
public:
  MotionService();
  ~MotionService();
  void init();
  bool hasPresence();
};

#endif