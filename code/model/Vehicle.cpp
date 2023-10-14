#include "Vehicle.hpp"
#include "GeoPosition.hpp"

redcars::model::Vehicle::Vehicle(redcars::model::GeoPosition position, std::time_t lastPositionUpdate,
                                 VehicleKind kind, std::string licencePlate)
        : position(position), lastPositionUpdate(lastPositionUpdate), kind(kind), licencePlate(licencePlate) {}

void redcars::model::Vehicle::updatePosition(redcars::model::GeoPosition position) {
    this->position = position;
    lastPositionUpdate = std::time(nullptr);
}

const redcars::model::GeoPosition &redcars::model::Vehicle::getPosition() const {
    return position;
}

redcars::model::VehicleKind redcars::model::Vehicle::getKind() const {
    return kind;
}
