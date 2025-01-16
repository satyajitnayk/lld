#pragma once
#include "common.hpp"
#include "deliveryChargeCalculationStrategy.hpp"
#include "ideliveryPartnerMatchingStrategy.hpp"
#include "locBasedDeliveryPartnerMatchingStrategy.hpp"
#include "mutex"

class StrategyMgr {
  StrategyMgr() {}
  static StrategyMgr *strategyMgrInstance;
  static mutex mtx;

public:
  static StrategyMgr *getStrategyMgr();
  IDeliveryPartnerMatchingStrategy *
  determineDeliveryPartnerMatchingStrategy(DeliveryMetaData *metaData);
};