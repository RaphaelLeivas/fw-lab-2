#ifndef MOTION_SERVICE_HPP
#define MOTION_SERVICE_HPP

#include "../main.h"

class MotionService {
public:
  MotionService();
  ~MotionService();
  void init();
  bool hasPresence();
};

#endif