#pragma once
#include "driverMgr.hpp"
#include "riderMgr.hpp"
#include "strategyMgr.hpp"
#include "trip.hpp"
#include "tripMetaData.hpp"

#include <mutex>

class TripMgr {
  static TripMgr *tripMgrInstance;
  static mutex mtx;
  RiderMgr *riderMgr;
  DriverMgr *driverMgr;
  TripMgr() {
    riderMgr = RiderMgr::getRiderMgr();
    driverMgr = DriverMgr::getDriverMgr();
  }
  unordered_map<int, TripMetaData *> tripsMetaDataInfo;
  unordered_map<int, Trip *> tripsInfo;

public:
  static TripMgr *getTripMgr();
  void CreateTrip(Rider *pRider, Location *pSrcLoc, Location *pDstLoc);
  unordered_map<int, Trip *> getTripsMap();
};
