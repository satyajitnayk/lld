#pragma once
#include <string>

class Person {
private:
  std::string name;
  std::string address;
  std::string phone;
  std::string email;

public:
  // Constructors
  Person() = default;
  Person(const std::string &name, const std::string &address,
         const std::string &phone, const std::string &email)
      : name(name), address(address), phone(phone), email(email) {}

  // Getters and setters (optional, add if needed)
  const std::string &getName() const { return name; }
  void setName(const std::string &n) { name = n; }

  const std::string &getAddress() const { return address; }
  void setAddress(const std::string &a) { address = a; }

  const std::string &getPhone() const { return phone; }
  void setPhone(const std::string &p) { phone = p; }

  const std::string &getEmail() const { return email; }
  void setEmail(const std::string &e) { email = e; }
};
