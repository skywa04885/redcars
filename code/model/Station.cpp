#include "Station.hpp"

redcars::model::Station::Station(redcars::model::GeoPosition position, int maxVehicleCount)
        : position(position), maxVehicleCount(maxVehicleCount) {

}

int redcars::model::Station::getMaxVehicleCount() const {
    return maxVehicleCount;
}
