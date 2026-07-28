#pragma once

#include <string>

class Address {
private:
  int zipCode;
  std::string street;
  std::string city;
  std::string state;
  std::string country;

public:
  Address() = default;
  Address(int zipCode, const std::string &street, const std::string &city,
          const std::string &state, const std::string &country)
      : zipCode(zipCode), street(street), city(city), state(state),
        country(country) {}

  int getZipCode() const { return zipCode; }
  void setZipCode(int z) { zipCode = z; }

  const std::string &getStreet() const { return street; }
  void setStreet(const std::string &s) { street = s; }

  const std::string &getCity() const { return city; }
  void setCity(const std::string &c) { city = c; }

  const std::string &getState() const { return state; }
  void setState(const std::string &s) { state = s; }

  const std::string &getCountry() const { return country; }
  void setCountry(const std::string &c) { country = c; }
};