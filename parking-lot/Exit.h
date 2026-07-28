#pragma once
#include "Enums.h"
#include "ParkingLot.h"
#include "ParkingTicket.h"
#include "Payment.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <memory>

class Exit {
private:
  int id;

public:
  Exit(int id) : id(id) {}

  void validateTicket(const std::shared_ptr<ParkingTicket> &ticket) {
    auto now = std::chrono::system_clock::now();
    ticket->setExitTime(now);

    std::chrono::duration<double> duration = now - ticket->getEntryTime();
    double hours = duration.count() / 3600.0;

    auto &parkingLot = ParkingLot::getInstance();
    double fee = parkingLot.parkingRate.calculate(
        hours, ticket->getVehicle(), parkingLot.getSpot(ticket->getSlotNo()));
    ticket->setAmount(fee);

    std::cout << "Ticket " << ticket->getTicketNo()
              << " | Parked for: " << hours << " hrs"
              << " | Fee: $" << fee << std::endl;

    std::shared_ptr<Payment> payment;
    if (fee > 10) {
      payment = std::make_shared<CreditCard>(fee);
    } else {
      payment = std::make_shared<Cash>(fee);
    }

    payment->initiateTransaction();

    parkingLot.freeSlot(ticket->getSlotNo());
    ticket->setStatus(TicketStatus::PAID);
  }
};