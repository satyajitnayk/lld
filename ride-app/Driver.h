#pragma once

#include "common.h"
#include <string>
#include <utility>

class Driver {
private:
  std::string name;
  bool available;
  RATING rating;

public:
  Driver(std::string pName, RATING pRating)
      : name(std::move(pName)), rating(pRating) {
    available = false;
  }
  void setAvailable(bool availableNow) { available = availableNow; }
  bool isAvailable() const { return available; }
  std::string getDriverName() const { return name; }
  RATING getRating() const { return rating; }
};
