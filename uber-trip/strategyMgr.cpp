#include "strategyMgr.hpp"

using namespace std;

StarategyMgr *StarategyMgr::strategyMgrInstance = nullptr;
mutex StarategyMgr::mtx;

StarategyMgr *StarategyMgr::getStrategyMgr() {
  if (strategyMgrInstance == nullptr) {
    mtx.lock();
    if (strategyMgrInstance == nullptr) {
      strategyMgrInstance = new StarategyMgr();
    }
    mtx.unlock();
  }
  return strategyMgrInstance;
}

PricingStrategy *
StarategyMgr::determinePricingStrategy(TripMetaData *metaData) {
  cout << "Based on location and other factors, setting pricing strategy\n";
  return new RatingBasedPricingStrategy();
}

DriverMatchingStrategy *
StarategyMgr::determineMatchingStrategy(TripMetaData *metaData) {
  cout << "Based on location and other factors, setting matching strategy\n";
  return new LeastTimeBasedMatchingStrategy();
}