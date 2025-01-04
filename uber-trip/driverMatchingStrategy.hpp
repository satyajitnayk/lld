#pragma once

#include "driverMgr.hpp"
#include "tripMetaData.hpp"

class DriverMatchingStrategy {
public:
  virtual Driver *matchDriver(TripMetaData *pTripMetaData) = 0;
};