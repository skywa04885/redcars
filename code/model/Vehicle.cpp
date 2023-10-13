#include "Vehicle.hpp"
#include "GeoPosition.hpp"

redcars::model::Vehicle::Vehicle(redcars::model::GeoPosition position, std::time_t lastPositionUpdate,
                                 VehicleKind kind)
        : position(position), lastPositionUpdate(lastPositionUpdate), kind(kind) {}

void redcars::model::Vehicle::updatePosition(redcars::model::GeoPosition position) {
    this->position = position;
    lastPositionUpdate = std::time(nullptr);
}
