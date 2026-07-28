#pragma once
#include "Enums.h"
#include "Person.h"
#include <memory>
#include <string>

class Account {
protected:
  std::string userName;
  std::string password;
  std::shared_ptr<Person> person;
  AccountStatus status;

public:
  virtual ~Account() = default;

  virtual bool resetPassword() = 0;
};
