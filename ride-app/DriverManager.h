#pragma once

#include "Driver.h"
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

class DriverManager {
private:
  DriverManager() = default;
  ~DriverManager() = default;

  std::unordered_map<std::string, std::unique_ptr<Driver>> driversMap;
  mutable std::mutex driversMutex;

public:
  static DriverManager &getInstance() {
    static DriverManager instance;
    return instance;
  }

  // Delete copy and move semantics to enforce true uniqueness
  DriverManager(const DriverManager &) = delete;
  DriverManager &operator=(const DriverManager &) = delete;
  DriverManager(DriverManager &&) = delete;
  DriverManager &operator=(DriverManager &&) = delete;

  bool addDriver(const std::string &driverName, std::unique_ptr<Driver> driver) {
    if (!driver) {
      return false;
    }

    std::lock_guard<std::mutex> lock(driversMutex);
    return driversMap.emplace(driverName, std::move(driver)).second;
  }

  const Driver *getDriver(const std::string &driverName) const {
    std::lock_guard<std::mutex> lock(driversMutex);
    const auto driver = driversMap.find(driverName);
    if (driver == driversMap.end()) {
      return nullptr;
    }
    return driver->second.get();
  }

  Driver *reserveAvailableDriver() {
    std::lock_guard<std::mutex> lock(driversMutex);
    for (const auto &entry : driversMap) {
      Driver *driver = entry.second.get();
      if (driver->isAvailable()) {
        driver->setAvailable(false);
        return driver;
      }
    }
    return nullptr;
  }
};
