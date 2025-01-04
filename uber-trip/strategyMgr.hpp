#pragma once

#include "common.hpp"
#include "defaultPricingStrategy.hpp"
#include "leastTimeBasedMatchingStrategy.hpp"
#include "ratingBasedPricingStrategy.hpp"
#include "tripMetaData.hpp"
#include <mutex>
using namespace std;

class StarategyMgr {
  StarategyMgr() {}
  static StarategyMgr *strategyMgrInstance;
  static mutex mtx;

public:
  static StarategyMgr *getStrategyMgr();
  PricingStrategy *determinePricingStrategy(TripMetaData *metaData);
  DriverMatchingStrategy *determineMatchingStrategy(TripMetaData *metaData);
};