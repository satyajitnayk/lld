#pragma once

#include "Driver.h"
#include "Location.h"
#include "Rider.h"
#include "common.h"

class TripMetadata {
private:
  Location srcLoc;
  Location dstLoc;
  RATING riderRating;
  RATING driverRating;

public:
  TripMetadata(Location pSrcLoc, Location pDstLoc, RATING pRiderRating)
      : srcLoc(std::move(pSrcLoc)), dstLoc(std::move(pDstLoc)),
        riderRating(pRiderRating) {
    driverRating = RATING::UNASSIGNED;
  }
  RATING getDriverRating() const { return driverRating; }
  RATING getRiderRating() const { return riderRating; }
  void setDriverRating(RATING rating) { driverRating = rating; }
};
