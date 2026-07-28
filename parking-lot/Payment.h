#pragma once

#include "Enums.h"
#include <chrono>
#include <iostream>

class Payment {
protected:
  double amount;
  PaymentStatus status;
  std::chrono::system_clock::time_point timestamp;

public:
  Payment(double amount)
      : amount(amount), status(PaymentStatus::PENDING),
        timestamp(std::chrono::system_clock::now()) {}

  virtual ~Payment() = default;

  virtual bool initiateTransaction() = 0;

  double Amount() const { return amount; }
  PaymentStatus getStatus() const { return status; }
  std::chrono::system_clock::time_point getTimestamp() const {
    return timestamp;
  }
};

class Cash : public Payment {
public:
  Cash(double amount) : Payment(amount) {}

  bool initiateTransaction() override {
    status = PaymentStatus::COMPLETED;
    std::cout << "Cash payment of $" << amount << " completed." << std::endl;
    return true;
  }
};

class CreditCard : public Payment {
public:
  CreditCard(double amount) : Payment(amount) {}

  bool initiateTransaction() override {
    status = PaymentStatus::COMPLETED;
    std::cout << "Credit card payment of $" << amount << " completed."
              << std::endl;
    return true;
  }
};