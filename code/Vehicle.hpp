#pragma once

#include "GeoPosition.hpp"
#include <ctime>

enum class VehicleKind { Station, Personal };

class Vehicle {
public:
  Vehicle(GeoPosition position, std::time_t lastPositionUpdate,
          VehicleKind kind);

  virtual ~Vehicle() = default;

  void updatePosition(GeoPosition position);

private:
  GeoPosition position;
  std::time_t lastPositionUpdate;
  VehicleKind kind;
};
