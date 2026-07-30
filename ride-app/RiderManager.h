#pragma once

#include "Rider.h"
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

class RiderManager {
private:
  RiderManager() = default;
  std::unordered_map<std::string, std::unique_ptr<Rider>> ridersMap;
  mutable std::mutex ridersMutex;

public:
  // Delete copy constructor and assignment operator for proper singleton
  RiderManager(const RiderManager &) = delete;
  RiderManager &operator=(const RiderManager &) = delete;

  // Meyers Singleton: Thread-safe in C++11 and later without explicit mutexes
  static RiderManager &getInstance() {
    static RiderManager instance;
    return instance;
  }

  bool addRider(std::unique_ptr<Rider> rider) {
    if (!rider) {
      return false;
    }

    std::lock_guard<std::mutex> lock(ridersMutex);
    return ridersMap.emplace(rider->getRiderName(), std::move(rider)).second;
  }

  // Returns a raw pointer as an observer because callers only read/inspect the
  // data
  const Rider *getRider(const std::string &riderName) const {
    std::lock_guard<std::mutex> lock(ridersMutex);
    const auto rider = ridersMap.find(riderName);
    if (rider == ridersMap.end()) {
      return nullptr;
    }
    return rider->second.get();
  }
};
