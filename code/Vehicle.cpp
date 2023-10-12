#include "Vehicle.hpp"

Vehicle::Vehicle(GeoPosition position, std::time_t lastPositionUpdate,
                 VehicleKind kind)
    : position(position), lastPositionUpdate(lastPositionUpdate), kind(kind) {}

void Vehicle::updatePosition(GeoPosition position) {
  this->position = position;
  lastPositionUpdate = std::time(nullptr);
}
