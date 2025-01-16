#pragma once
#include "common.hpp"
#include "deliveryChargeCalculationStrategy.hpp"

class LocBasedDeliveryChargecalculationStrategy
    : public DeliveryChargeCalculationStrategy {
public:
  double calculateDeliveryCharge(DeliveryMetaData *pDeliveryMetaData) {
    cout << "Delivery charge is decided based on location. Setting to 20 as "
            "default value for now"
         << endl;
    return 20.0;
  }
};