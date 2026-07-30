#pragma once

class Location {
private:
  const double latitude;
  const double longitude;

public:
  Location(double pLatitude, double pLongitude)
      : latitude(pLatitude), longitude(pLongitude) {}

  double getLatitude() const { return latitude; }
  double getLongitude() const { return longitude; }
};
