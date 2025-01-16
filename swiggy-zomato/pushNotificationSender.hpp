#pragma once
#include "inotificationSender.hpp"

class PushNotificationSender : public INotificationSender {
public:
  void sendNotification(string pUserId, string pMessage) {
    cout << "Push Notification for " << pUserId << " is " <<pMessage << endl;
  }
};