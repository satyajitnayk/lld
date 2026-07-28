#pragma once
#include "ParkingSpot.h"
#include "Vehicle.h"
#include <cmath>
#include <memory>

class ParkingRate {
public:
  double calculate(double hours, const std::shared_ptr<Vehicle> &v,
                   const std::shared_ptr<ParkingSpot> &s) const {
    int hrs = static_cast<int>(std::ceil(hours));
    double fee = 0.0;
    if (hrs >= 1) {
      fee += 4;
    }
    if (hrs >= 2) {
      fee += 3.5;
    }
    if (hrs >= 3) {
      fee += 3.5;
    }
    if (hrs > 3) {
      fee += (hrs - 3) * 2.5;
    }
    return fee;
  }
};
