#pragma once

#include "DriverMatchingStrategy.h"
#include "PricingStrategy.h"
#include "TripMetadata.h"
#include <memory>

class StrategyManager {
private:
  StrategyManager() = default;

public:
  static StrategyManager &getInstance() {
    static StrategyManager instance;
    return instance;
  }

  std::unique_ptr<PricingStrategy>
  determinePricingStrategy(const TripMetadata &) const {
    std::cout << "Based on location and other factors, setting pricing strategy\n";
    return std::make_unique<RatingBasedPricingStrategy>();
  }

  std::unique_ptr<DriverMatchingStrategy>
  determineMatchingStrategy(const TripMetadata &) const {
    std::cout << "Based on location and other factors, setting matching strategy\n";
    return std::make_unique<LeastTimeBasedMatchingStrategy>();
  }
};
