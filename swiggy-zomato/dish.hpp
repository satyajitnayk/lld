#pragma once
#include "common.hpp"
#include "dishAddon.hpp"
#include <vector>

class Dish {
  string name;
  CUISINE cuisine;
  string description;
  double price;
  vector<string> dishImages;
  vector<DishAddOn *> addons;

public:
  Dish(string pName, CUISINE pCuisine, double pPrice)
      : name(pName), cuisine(pCuisine), price(pPrice) {}
  void addAddOn(DishAddOn *pAddOn) { addons.push_back(pAddOn); }
  // remove add on function
  double getPrice() {
    double totalPrice = price;
    for (auto addOn : addons)
      totalPrice += addOn->getPrice();
    return totalPrice;
  }
  string getDescription() { return description; }
  string getDishName() { return name; }
  CUISINE getCuisine() { return cuisine; }
};