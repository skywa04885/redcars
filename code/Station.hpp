#pragma once

#include <vector>

#include "GeoPosition.hpp"

class Station {
public:
  Station(GeoPosition position, int maxVehicleCount);
  virtual ~Station() = default;

private:
  int maxVehicleCount;
  GeoPosition position;
};
