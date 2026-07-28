#pragma once

#include "ParkingSpot.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

class DisplayBoard {
private:
  int id;
  std::map<std::string, int> freeSpotsMap;

public:
  DisplayBoard(int id) : id(id) {}

  void update(const std::vector<std::shared_ptr<ParkingSpot>> &spots) {
    freeSpotsMap.clear();
    for (const auto &spot : spots) {
      if (spot->isSpotFree()) {
        std::string type = spot->getSpotTypeName();
        freeSpotsMap[type]++;
      }
    }
  }

  void showFreeSpots() const {
    std::cout << "\nFree slots by type:" << std::endl;
    std::cout << "Type            Count" << std::endl;
    for (const auto &[spotType, count] : freeSpotsMap) {
      std::cout << spotType << " : " << count << "\n";
    }
  }
};