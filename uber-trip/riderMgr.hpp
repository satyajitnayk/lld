#pragma once

#include "rider.hpp"
#include <mutex>
#include <unordered_map>
using namespace std;

class RiderMgr {
  RiderMgr() {}
  static RiderMgr *ridrMgrInstance;
  static mutex mtx;
  unordered_map<string, Rider *> ridersMap;

public:
  static RiderMgr *getRiderMgr();
  void addRider(string pRiderName, Rider *pRider);
  Rider *getRider(string pRiderName);
};