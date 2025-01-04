#include "riderMgr.hpp"
using namespace std;

RiderMgr *RiderMgr::ridrMgrInstance = nullptr;
mutex RiderMgr::mtx;

RiderMgr *RiderMgr::getRiderMgr() {
  if (ridrMgrInstance == nullptr) {
    mtx.lock();
    if (ridrMgrInstance == nullptr) {
      ridrMgrInstance = new RiderMgr();
    }
    mtx.unlock();
  }
  return ridrMgrInstance;
}

void RiderMgr::addRider(string pRiderName, Rider *pRider) {
  ridersMap[pRiderName] = pRider;
}

Rider *RiderMgr::getRider(string pRiderName) { return ridersMap[pRiderName]; }