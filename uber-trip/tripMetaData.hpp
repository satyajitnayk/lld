#pragma once

#include "driver.hpp"
#include "rider.hpp"

// This class basically has all the info that will be used by strategy
// Pricing strategy and Driver Matching strategy will need data
// Even if more data is needed, only this class needs to be updated

class TripMetaData {
  Location *srcLoc;
  Location *dstLoc;
  RATING riderRating;
  RATING driverRating;

public:
  TripMetaData(Location *pSrcLoc, Location *pDstLoc, RATING pRiderRating)
      : srcLoc(pSrcLoc), dstLoc(pDstLoc), riderRating(pRiderRating) {
    driverRating = RATING::UNASSIGNED;
  }
  RATING getRiderRating() { return riderRating; }
  RATING getDriverRating() { return driverRating; }
  void setDriverRating(RATING pDriverRating) { driverRating = pDriverRating; }
};