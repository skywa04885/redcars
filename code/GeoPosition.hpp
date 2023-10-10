#pragma once

#include "Distance.hpp"

/**
 * An immutable object representing geographic position, eg. longitude,
 * latitude.
 * */
class GeoPosition {
public:
  GeoPosition(double longitude, double latitude);
  virtual ~GeoPosition() = default;

  double getLongitude() const;
  double getLatitude() const;

  /**
   * Calculate the distance between 2 geo points using the Haversine Formula.
   * */
  Distance distanceFrom(const GeoPosition &other) const;
private:
  double longitude;
  double latitude;
};
