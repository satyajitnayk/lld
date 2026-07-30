#pragma once

#include "TripMetadata.h"
#include "common.h"

class PricingStrategy {
public:
  virtual ~PricingStrategy() = default;
  virtual double calculatePrice(const TripMetadata &metadata) const = 0;
};

class DefaultPricingStrategy : public PricingStrategy {
public:
  double calculatePrice(const TripMetadata &) const override {
    std::cout << "Based on default strategy, price is 100" << std::endl;
    return 100.0;
  }
};

class RatingBasedPricingStrategy : public PricingStrategy {
public:
  double calculatePrice(const TripMetadata &metadata) const override {
    double price = isHighRating(metadata.getRiderRating()) ? 55.0 : 65.0;
    std::cout << "Based on " << ratingToString(metadata.getRiderRating())
              << " rider rating, price of the trip is " << price << std::endl;
    return price;
  }
};
