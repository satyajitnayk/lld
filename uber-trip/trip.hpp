#pragma once
#include "driver.hpp"
#include "driverMatchingStrategy.hpp"
#include "location.hpp"
#include "pricingStrategy.hpp"

class Trip {
  Rider *rider;
  Driver *driver;
  Location *srcLoc;
  Location *dstLoc;
  TRIP_STATUS status;
  int tripId;
  double price;
  PricingStrategy *pricingStrategy;
  DriverMatchingStrategy *driverMatchingStrategy;

public:
  Trip(Rider *pRider, Driver *pDriver, Location *pSrcLoc, Location *pDstLoc,
       double pPrice, PricingStrategy *pPricingStrategy,
       DriverMatchingStrategy *pDriverMatchingStrategy)
      : rider(pRider), driver(pDriver), srcLoc(pSrcLoc), dstLoc(pDstLoc),
        price(pPrice), pricingStrategy(pPricingStrategy),
        driverMatchingStrategy(pDriverMatchingStrategy) {
    status = TRIP_STATUS::DRIVER_ON_THE_WAY;
    // This is not threadsafe and is just for demo purposes
    tripId = nextTripId;
    nextTripId++;
  }
  int getTripId() { return tripId; }
  void displayTripDetails() {
    cout << endl;
    cout << "Trip id - " << tripId << endl;
    cout << "Rider - " << rider->getRiderName() << endl;
    cout << "Driver - " << driver->getDriverName() << endl;
    cout << "Price - " << price << endl;
    cout << "Locations - " << srcLoc->latitude << "," << srcLoc->longitude
         << " and " << dstLoc->latitude << "," << dstLoc->longitude << endl;
  }
};