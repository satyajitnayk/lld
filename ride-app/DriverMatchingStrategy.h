#pragma once

#include "Driver.h"
#include "DriverManager.h"
#include "TripMetadata.h"
#include <memory>

class DriverMatchingStrategy {
public:
  virtual ~DriverMatchingStrategy() = default;
  virtual Driver *matchDriver(TripMetadata &metadata) = 0;
};

class LeastTimeBasedMatchingStrategy : public DriverMatchingStrategy {
public:
  Driver *matchDriver(TripMetadata &metadata) override {
    auto &driverManager = DriverManager::getInstance();

    std::cout << "Using quadtree to see nearest cabs, using driver manager to get "
                 "details of driver and send notifications\n";

    Driver *driver = driverManager.reserveAvailableDriver();
    if (driver) {
      std::cout << "Setting " << driver->getDriverName() << " as driver\n";
      metadata.setDriverRating(driver->getRating());
      return driver;
    }

    std::cout << "No drivers are currently available.\n";
    return nullptr;
  }
};
