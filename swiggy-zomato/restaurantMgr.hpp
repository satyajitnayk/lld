#pragma once

#include "common.hpp"
#include "mutex"
#include "restaurant.hpp"
#include "unordered_map"

class RestaurantMgr {
  RestaurantMgr() {}
  static RestaurantMgr *restaurantMgrInstance;
  static mutex mtx;
  unordered_map<string, Restaurant *> restaurantsMap;

public:
  static RestaurantMgr *getRestaurantMgr();
  void addRestaurant(string pRestaurantName, Restaurant *pRestaurant);
  Restaurant *getRestaurant(string pRestaurantName);
};