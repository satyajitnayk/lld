#pragma once

#include "DisplayBoard.h"
#include "Enums.h"
#include "ParkingRate.h"
#include "ParkingSpot.h"
#include "ParkingTicket.h"
#include "Vehicle.h"
#include <map>
#include <memory>
#include <mutex>

class ParkingLot {
private:
  static std::unique_ptr<ParkingLot> instance;
  ParkingLot() = default;

  std::map<int, std::shared_ptr<ParkingSpot>> spots;
  std::map<int, std::shared_ptr<ParkingTicket>> tickets;
  std::vector<std::shared_ptr<DisplayBoard>> displayBoards;

  bool canFit(const std::shared_ptr<Vehicle> &vehicle,
              const std::shared_ptr<ParkingSpot> &spot) const {
    if (!vehicle || !spot) {
      return false;
    }

    VehicleType vType = vehicle->getVehicleType();
    SpotType sType = spot->getSpotType();

    if (vType == VehicleType::Motorcycle && sType == SpotType::Motorcycle) {
      return true;
    } else if ((vType == VehicleType::Truck || vType == VehicleType::Van) &&
               sType == SpotType::Large) {
      return true;
    } else if (vType == VehicleType::Car &&
               (sType == SpotType::Compact || sType == SpotType::Accessible)) {
      return true;
    } else {
      return false;
    }
  }

public:
  ParkingRate parkingRate;

  static ParkingLot &getInstance() {
    // This is 100% thread-safe in C++11 and later
    static ParkingLot instance;
    return instance;
  }

  void addSpot(const std::shared_ptr<ParkingSpot> &s) { spots[s->getId()] = s; }

  void addDisplayBoard(const std::shared_ptr<DisplayBoard> &b) {
    displayBoards.push_back(b);
  }

  std::shared_ptr<ParkingSpot> getSpot(int id) {
    auto it = spots.find(id);
    if (it != spots.end()) {
      return it->second;
    }
    return nullptr;
  }

  void freeSlot(int id) {
    auto spot = getSpot(id);
    if (spot) {
      spot->removeVehicle();
    }
  }

  std::vector<std::shared_ptr<ParkingSpot>> getAllSpots() const {
    std::vector<std::shared_ptr<ParkingSpot>> vec;
    for (const auto &p : spots) {
      vec.push_back(p.second);
    }
    return vec;
  }

  std::shared_ptr<ParkingTicket>
  parkVehicle(const std::shared_ptr<Vehicle> &vehicle) {
    for (const auto &pair : spots) {
      const auto &spot = pair.second;
      if (spot->isSpotFree() && canFit(vehicle, spot)) {
        spot->assignVehicle(vehicle);
        auto ticket = std::make_shared<ParkingTicket>(spot->getId(), vehicle);
        tickets[ticket->getTicketNo()] = ticket;
        return ticket;
      }
    }
    std::cout << "Sorry, parking lot is full. New cars cannot be parked.\n";
    return nullptr;
  }
};

// Initialize the singleton instance pointer
std::unique_ptr<ParkingLot> ParkingLot::instance = nullptr;
