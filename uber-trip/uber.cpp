#include "tripMgr.hpp"

int main() {
  // ---------- Creates Drivers & Riders ---------
  //---------------Creating Riders and Drivers--------------------------------
  Rider *satyaRider = new Rider("satya", RATING::FIVE_STARS);
  Rider *sujitRider = new Rider("sujit", RATING::TWO_STARS);
  RiderMgr *riderMgr = RiderMgr::getRiderMgr();
  riderMgr->addRider("satya", satyaRider);
  riderMgr->addRider("sujit", sujitRider);

  Driver *syamDriver = new Driver("syam", RATING::THREE_STARS);
  Driver *ramDriver = new Driver("ram", RATING::FOUR_STARS);
  DriverMgr *driverMgr = DriverMgr::getDriverMgr();
  driverMgr->addDriver("syam", syamDriver);
  driverMgr->addDriver("ram", ramDriver);

  // These details in turn will be stored in database
  //-------------------------------------------------------------------------

  TripMgr *tripMgr = TripMgr::getTripMgr();

  cout << endl
       << "Creating Trip for satya from location (10,10) to (30,30)" << endl;
  tripMgr->CreateTrip(satyaRider, new Location(10, 10), new Location(30, 30));

  cout << endl
       << "Creating Trip for sujit from location (200,200) to (500,500)"
       << endl;
  tripMgr->CreateTrip(sujitRider, new Location(200, 200),
                      new Location(500, 500));

  cout << endl
       << "Creating Trip for satya from location (200,200) to (500,500)"
       << endl;
  tripMgr->CreateTrip(satyaRider, new Location(200, 200),
                      new Location(500, 500));

  //-------------------Display all the trips created--------------------------
  unordered_map<int, Trip *> tripsMap = tripMgr->getTripsMap();
  for (auto mapVal : tripsMap) {
    (mapVal.second)->displayTripDetails();
  }

  return 0;
}