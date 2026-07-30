#pragma once

#include "DriverManager.h"
#include "Location.h"
#include "PricingStrategy.h"
#include "RiderManager.h"
#include "StrategyManager.h"
#include "Trip.h"
#include "TripMetadata.h"
#include <algorithm>
#include <memory>
#include <mutex>
#include <vector>

class TripManager {
private:
  TripManager() = default;

  std::unordered_map<int, std::unique_ptr<TripMetadata>> tripsMetaDataInfo;
  std::unordered_map<int, std::unique_ptr<Trip>> tripsInfo;
  mutable std::mutex tripsMutex;

public:
  // Delete copy constructor and assignment operator for a strict singleton
  TripManager(const TripManager &) = delete;
  TripManager &operator=(const TripManager &) = delete;

  static TripManager &getInstance() {
    static TripManager instance;
    return instance;
  }

  void createTrip(const Rider *rider, Location srcLoc, Location dstLoc) {
    if (!rider) {
      return;
    }

    std::lock_guard<std::mutex> lock(tripsMutex);

    auto tripMetadata =
        std::make_unique<TripMetadata>(srcLoc, dstLoc, rider->getRating());

    auto &strategyManager = StrategyManager::getInstance();

    auto pricingStrategy =
        strategyManager.determinePricingStrategy(*tripMetadata);
    auto driverMatchingStrategy =
        strategyManager.determineMatchingStrategy(*tripMetadata);

    Driver *driver = driverMatchingStrategy->matchDriver(*tripMetadata);
    if (!driver) {
      std::cout << "Unable to create trip: no driver is currently available.\n";
      return;
    }

    double tripPrice = pricingStrategy->calculatePrice(*tripMetadata);

    auto trip = std::make_unique<Trip>(*rider, *driver, std::move(srcLoc),
                                       std::move(dstLoc), tripPrice,
                                       std::move(pricingStrategy),
                                       std::move(driverMatchingStrategy));

    int tripId = trip->getTripId();

    tripsInfo[tripId] = std::move(trip);
    tripsMetaDataInfo[tripId] = std::move(tripMetadata);
  }

  std::vector<const Trip *> getTrips() const {
    std::lock_guard<std::mutex> lock(tripsMutex);
    std::vector<const Trip *> trips;
    trips.reserve(tripsInfo.size());
    for (const auto &entry : tripsInfo) {
      trips.push_back(entry.second.get());
    }
    return trips;
  }
};
