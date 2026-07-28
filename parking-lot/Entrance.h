#pragma once

#include "ParkingLot.h"
#include "ParkingTicket.h"
#include "Vehicle.h"
#include <memory>

class Entrance {
private:
  int id;

public:
  Entrance(int id) : id(id) {}

  std::shared_ptr<ParkingTicket>
  getTicket(const std::shared_ptr<Vehicle> &vehicle) {
    return ParkingLot::getInstance().parkVehicle(vehicle);
  }
};