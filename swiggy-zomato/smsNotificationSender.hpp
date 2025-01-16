#pragma once
#include "inotificationSender.hpp"

class SMSNotificationSender : public INotificationSender {
public:
  void sendNotification(string pUserId, string pMessage) {
    cout << "SMS Notification for " << pUserId << " is " << pMessage << endl;
  }
};