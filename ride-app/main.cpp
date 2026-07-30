#include "Driver.h"
#include "DriverManager.h"
#include "Location.h"
#include "Rider.h"
#include "RiderManager.h"
#include "TripManager.h"
#include "common.h"
#include <memory>

int main() {

  auto &riderManager = RiderManager::getInstance();
  auto &driverManager = DriverManager::getInstance();
  auto &tripManager = TripManager::getInstance();

  auto rider1 = std::make_unique<Rider>("satya", RATING::FIVE_STARS);
  auto rider2 = std::make_unique<Rider>("sujit", RATING::TWO_STARS);

  riderManager.addRider(std::move(rider1));
  riderManager.addRider(std::move(rider2));

  auto driver1 = std::make_unique<Driver>("shyam", RATING::THREE_STARS);
  auto driver2 = std::make_unique<Driver>("ram", RATING::FOUR_STARS);
  driver1->setAvailable(true);
  driver2->setAvailable(true);

  driverManager.addDriver(driver1->getDriverName(), std::move(driver1));
  driverManager.addDriver(driver2->getDriverName(), std::move(driver2));

  const Rider *satya = riderManager.getRider("satya");
  const Rider *sujit = riderManager.getRider("sujit");

  std::cout << "\nCreating Trip for rider1 from location (10,10) to (30,30)\n";
  tripManager.createTrip(satya, Location(10, 10), Location(30, 30));

  std::cout << "\nCreating Trip for rider2 from location (200,200) to (500,500)\n";
  tripManager.createTrip(sujit, Location(200, 200), Location(500, 500));

  std::cout << "\nCreating Trip for rider1 from location (120,130) to (200,180)\n";
  tripManager.createTrip(satya, Location(120, 130), Location(200, 180));

  for (const Trip *trip : tripManager.getTrips()) {
    trip->displayTripDetails();
  }

  return 0;
}
