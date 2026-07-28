#pragma once

#include "Enums.h"
#include "Vehicle.h"
#include <iostream>
#include <memory>

class ParkingSpot {
protected:
  int id;
  bool isFree = true;
  std::shared_ptr<Vehicle> vehicle;

public:
  ParkingSpot(int id) : id(id) {}
  virtual ~ParkingSpot() = default;

  bool isSpotFree() const { return isFree; }

  int getId() const { return id; }

  virtual SpotType getSpotType() const = 0;

  std::string getSpotTypeName() const { return to_string(getSpotType()); }

  bool assignVehicle(const std::shared_ptr<Vehicle> &newVehicle) {
    if (isFree) {
      std::cout << "Allocated " << getSpotTypeName() << " slot " << id << " to "
                << newVehicle->getLicenseNo() << "\n";
      vehicle = newVehicle;
      isFree = false;
      return true;
    }
    return false;
  }

  virtual bool removeVehicle() {
    if (!isFree && vehicle) {
      std::cout << "Slot " << id << " freed (was " << vehicle->getLicenseNo()
                << ")\n";
      vehicle = nullptr;
      isFree = true;
      return true;
    }
    return false;
  }
};

class MotorcycleSpot : public ParkingSpot {
public:
  MotorcycleSpot(int id) : ParkingSpot(id) {}

  SpotType getSpotType() const override { return SpotType::Motorcycle; }
};

class Large : public ParkingSpot {
public:
  Large(int id) : ParkingSpot(id) {}

  SpotType getSpotType() const override { return SpotType::Large; }
};

class Compact : public ParkingSpot {
public:
  Compact(int id) : ParkingSpot(id) {}

  SpotType getSpotType() const override { return SpotType::Compact; }
};

class Accessible : public ParkingSpot {
public:
  Accessible(int id) : ParkingSpot(id) {}

  SpotType getSpotType() const override { return SpotType::Accessible; }
};