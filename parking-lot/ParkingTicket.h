#pragma once

#include "Enums.h"
#include "Payment.h"
#include "Vehicle.h"
#include <chrono>
#include <memory>

class ParkingTicket {
private:
  static int ticketSeed;
  int ticketNo;
  int slotNo;
  std::shared_ptr<Vehicle> vehicle;
  std::chrono::system_clock::time_point entryTime;
  std::chrono::system_clock::time_point exitTime;
  double amount;
  TicketStatus status;
  std::shared_ptr<Payment> payment;

public:
  ParkingTicket(int slotNo, const std::shared_ptr<Vehicle> &v)
      : ticketNo(ticketSeed++), slotNo(slotNo), vehicle(v),
        entryTime(std::chrono::system_clock::now()),
        status(TicketStatus::ISSUED) {
    v->assignTicket(std::make_shared<ParkingTicket>(*this));
    std::cout << "Ticket issued: " << ticketNo << std::endl;
  }

  int getTicketNo() const { return ticketNo; }
  int getSlotNo() const { return slotNo; }
  std::shared_ptr<Vehicle> getVehicle() const { return vehicle; }

  std::chrono::system_clock::time_point getEntryTime() const {
    return entryTime;
  }
  std::chrono::system_clock::time_point getExitTime() const { return exitTime; }
  void setExitTime(const std::chrono::system_clock::time_point &dt) {
    exitTime = dt;
  }

  void setAmount(double amt) { amount = amt; }
  double getAmount() const { return amount; }

  void setStatus(TicketStatus s) { status = s; }
  TicketStatus getStatus() const { return status; }

  void setPayment(const std::shared_ptr<Payment> &p) { payment = p; }
  std::shared_ptr<Payment> getPayment() const { return payment; }
};

int ParkingTicket::ticketSeed = 1000;
