#pragma once

#include <string>

enum class TicketStatus { ISSUED, IN_USE, PAID, VALIDATED, CANCELED, REFUNDED };

enum class AccountStatus { ACTIVE, CLOSED, CANCELED, BLOCKLISTED, NONE };

enum class PaymentStatus { COMPLETED, FAILED, PENDING, UNPAID, REFUNDED };

enum class SpotType { Motorcycle, Compact, Large, Accessible };

inline std::string to_string(SpotType type) {
  switch (type) {
  case SpotType::Motorcycle:
    return "Motorcycle";
  case SpotType::Compact:
    return "Compact";
  case SpotType::Large:
    return "Large";
  case SpotType::Accessible:
    return "Accessible";
  }
  return "Unknown";
}

enum class VehicleType { Motorcycle, Car, Van, Truck };
