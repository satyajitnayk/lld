#include "DisplayBoard.h"
#include "Entrance.h"
#include "Exit.h"
#include "ParkingLot.h"
#include "Vehicle.h"
#include <chrono>
#include <iostream>
#include <memory>
#include <thread>

int main() {
  // -------------- SYSTEM INITIALIZATION --------------
  std::cout << "\n====================== PARKING LOT SYSTEM DEMO "
               "======================\n"
            << std::endl;

  ParkingLot &lot = ParkingLot::getInstance();
  lot.addSpot(std::make_shared<Accessible>(1));
  lot.addSpot(std::make_shared<Compact>(2));
  lot.addSpot(std::make_shared<Large>(3));
  lot.addSpot(std::make_shared<MotorcycleSpot>(4));

  auto board = std::make_shared<DisplayBoard>(1);
  lot.addDisplayBoard(board);

  auto entrance = std::make_shared<Entrance>(1);
  auto exitPanel = std::make_shared<Exit>(1);

  // ----------------- SCENARIO 1: CUSTOMER ENTERS, PARKS -----------------
  std::cout << "\n→→→ SCENARIO 1: Customer enters and parks a car\n"
            << std::endl;

  auto car = std::make_shared<Car>("KA-01-HH-1234");
  std::cout << "-> Car " << car->getLicenseNo() << " arrives at entrance"
            << std::endl;
  auto ticket1 = entrance->getTicket(car);

  std::cout << "-> Updating display board after parking:" << std::endl;
  board->update(lot.getAllSpots());
  board->showFreeSpots();

  // ----------------- SCENARIO 2: CUSTOMER EXITS AND PAYS -----------------
  std::cout << "\n→→→ SCENARIO 2: Customer exits and pays\n" << std::endl;

  std::cout << "-> Car " << car->getLicenseNo() << " proceeds to exit panel"
            << std::endl;
  std::this_thread::sleep_for(
      std::chrono::milliseconds(1500)); // Simulate parking duration
  exitPanel->validateTicket(ticket1);

  std::cout << "-> Updating display board after exit:" << std::endl;
  board->update(lot.getAllSpots());
  board->showFreeSpots();

  // --------- SCENARIO 3: FILLING LOT AND REJECTING ENTRY IF FULL ---------
  std::cout << "\n→→→ SCENARIO 3: Multiple customers attempt to enter; lot may "
               "become full\n"
            << std::endl;

  // Vehicles arriving
  auto van = std::make_shared<Van>("KA-01-HH-9999");
  auto motorcycle = std::make_shared<Motorcycle>("KA-02-XX-3333");
  auto truck = std::make_shared<Truck>("KA-04-AA-9998");
  auto car2 = std::make_shared<Car>("DL-09-YY-1234");

  std::cout << "-> Van " << van->getLicenseNo() << " arrives at entrance"
            << std::endl;
  auto ticket2 = entrance->getTicket(van);

  std::cout << "-> Motorcycle " << motorcycle->getLicenseNo()
            << " arrives at entrance" << std::endl;
  auto ticket3 = entrance->getTicket(motorcycle);

  std::cout << "-> Truck " << truck->getLicenseNo() << " arrives at entrance"
            << std::endl;
  auto ticket4 = entrance->getTicket(truck);

  std::cout << "-> Car " << car2->getLicenseNo() << " arrives at entrance"
            << std::endl;
  auto ticket5 = entrance->getTicket(car2);

  std::cout << "-> Updating display board after several parkings:" << std::endl;
  board->update(lot.getAllSpots());
  board->showFreeSpots();

  // Try to park another car (lot may now be full)
  auto car3 = std::make_shared<Car>("UP-01-CC-1001");
  std::cout << "-> Car " << car3->getLicenseNo()
            << " attempts to park (should be denied if lot is full):"
            << std::endl;
  auto ticket6 = entrance->getTicket(car3);

  board->update(lot.getAllSpots());
  board->showFreeSpots();

  std::cout << "\n====================== END OF DEMONSTRATION "
               "======================\n"
            << std::endl;

  return 0;
}
