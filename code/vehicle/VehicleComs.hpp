#pragma once

#include "../model/Vehicle.hpp"

namespace redcars::vehicle {
    class VehicleComs {
    public:
        virtual void openDoor(const model::Vehicle &vehicle) = 0;

        virtual void closeDoor(const model::Vehicle &vehicle) = 0;

        virtual void enableEngine(const model::Vehicle &vehicle) = 0;

        virtual void disableEngine(const model::Vehicle &vehicle) = 0;

        virtual void displayLights(const model::Vehicle &vehicle, bool keepOn) = 0;

        virtual model::Distance requestDistanceDriven(const model::Vehicle &vehicle) = 0;

        virtual model::GeoPosition requestVehiclePosition(const model::Vehicle &vehicle) = 0;
    };
}

