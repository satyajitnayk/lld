#pragma once
#include "driverMatchingStrategy.hpp"

class LeastTimeBasedMatchingStrategy : public DriverMatchingStrategy {
public:
  Driver *matchDriver(TripMetaData *pTripMetaData) {
    DriverMgr *driverMgr = DriverMgr::getDriverMgr();

    if (driverMgr->getDriversMap().size() == 0) {
      cout << "No drivers! What service is this huh?\n";
    }
    cout << "Using quadtree to see nearest cabs, using driver manager to get "
            "details of driverand send notifications\n";
    // for simplicity returning 1st driver
    Driver *driver =
        ((driverMgr->getDriversMap()).begin())
            ->second; // here we can call quadtree algo to get nearest cabs
    cout << "Setting " << driver->getDriverName() << " as driver\n";
    pTripMetaData->setDriverRating(driver->getRating());
    return driver;
  }
};