#pragma once

#include "Account.h"
#include "DisplayBoard.h"
#include "Entrance.h"
#include "Exit.h"
#include "ParkingSpot.h"

class Admin : public Account {
public:
  bool addParkingSpot(const std::shared_ptr<ParkingSpot> &spot) { return true; }

  bool addDisplayBoard(const std::shared_ptr<DisplayBoard> &board) {
    return true;
  }

  bool addEntrance(const std::shared_ptr<Entrance> &entrance) { return true; }

  bool addExit(const std::shared_ptr<Exit> &exit) { return true; }

  bool resetPassword() override { return true; }
};
