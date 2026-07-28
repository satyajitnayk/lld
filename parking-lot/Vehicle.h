#pragma once

#include "Enums.h"
#include <memory>
#include <string>

class ParkingTicket;

class Vehicle {
protected:
  std::string licenseNo;
  std::shared_ptr<ParkingTicket> ticket;

public:
  Vehicle(const std::string &lic) : licenseNo(lic) {}
  virtual ~Vehicle() = default;

  virtual VehicleType getVehicleType() const = 0;

  std::string getLicenseNo() const { return licenseNo; }

  void assignTicket(const std::shared_ptr<ParkingTicket> &t) { ticket = t; }

  std::shared_ptr<ParkingTicket> getTicket() const { return ticket; }
};

class Car : public Vehicle {
public:
  Car(const std::string &lic) : Vehicle(lic) {}
  VehicleType getVehicleType() const override { return VehicleType::Car; }
};

class Van : public Vehicle {
public:
  Van(const std::string &lic) : Vehicle(lic) {}
  VehicleType getVehicleType() const override { return VehicleType::Van; }
};

class Truck : public Vehicle {
public:
  Truck(const std::string &lic) : Vehicle(lic) {}
  VehicleType getVehicleType() const override { return VehicleType::Truck; }
};

class Motorcycle : public Vehicle {
public:
  Motorcycle(const std::string &lic) : Vehicle(lic) {}
  VehicleType getVehicleType() const override {
    return VehicleType::Motorcycle;
  }
};