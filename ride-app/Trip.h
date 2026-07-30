#pragma once

#include "Driver.h"
#include "DriverMatchingStrategy.h"
#include "Location.h"
#include "PricingStrategy.h"
#include "Rider.h"
#include "common.h"
#include <algorithm>
#include <memory>

class Trip {
private:
  std::string riderName;
  std::string driverName;

  Location srcLoc;
  Location dstLoc;

  TRIP_STATUS status;
  int tripId;
  double price;

  std::unique_ptr<PricingStrategy> pricingStrategy;
  std::unique_ptr<DriverMatchingStrategy> driverMatchingStrategy;

public:
  Trip(const Rider &rider, const Driver &driver, Location srcLoc,
       Location dstLoc, double price, std::unique_ptr<PricingStrategy> pStrat,
       std::unique_ptr<DriverMatchingStrategy> dStrat)
      : riderName(rider.getRiderName()), driverName(driver.getDriverName()),
        srcLoc(std::move(srcLoc)), dstLoc(std::move(dstLoc)),
        status(TRIP_STATUS::DRIVER_ON_THE_WAY),
        tripId(nextTripId.fetch_add(1)),
        price(price), pricingStrategy(std::move(pStrat)),
        driverMatchingStrategy(std::move(dStrat)) {}

  int getTripId() const { return tripId; }
  TRIP_STATUS getStatus() const { return status; }

  void displayTripDetails() const {
    std::cout << std::endl;
    std::cout << "Trip id - " << tripId << std::endl;
    std::cout << "Rider - " << riderName << std::endl;
    std::cout << "Driver - " << driverName << std::endl;
    std::cout << "Price - " << price << std::endl;
    std::cout << "Locations - " << srcLoc.getLatitude() << ","
              << srcLoc.getLongitude() << " and " << dstLoc.getLatitude()
              << "," << dstLoc.getLongitude() << std::endl;
  }
};
