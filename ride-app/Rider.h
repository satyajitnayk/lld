#pragma once
#include "common.h"
#include <string>
#include <utility>

class Rider {
  std::string name;
  RATING rating;

public:
  Rider(std::string pName, RATING pRating)
      : name(std::move(pName)), rating(pRating) {};
  std::string getRiderName() const { return name; }
  RATING getRating() const { return rating; }
};
