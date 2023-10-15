#pragma once

#include "../model/Vehicle.hpp"

namespace redcars::vehicle {
    class VehicleComs {
    public:

        /**
         * pre-conditions:
         * - The vehicle is connected.
         * post-conditions:
         * - The door is open.
         * */
        virtual void openDoor(const model::Vehicle &vehicle) = 0;

        /**
         * pre-conditions:
         * - The vehicle is connected.
         * post-conditions:
         * - The door is closed.
         * */
        virtual void closeDoor(const model::Vehicle &vehicle) = 0;

        /**
         * pre-conditions:
         * - The vehicle is connected.
         * post-conditions:
         * - The engine is enabled.
         * */
        virtual void enableEngine(const model::Vehicle &vehicle) = 0;

        /**
         * pre-conditions:
         * - The vehicle is connected.
         * post-conditions:
         * - The engine is disabled.
         * */
        virtual void disableEngine(const model::Vehicle &vehicle) = 0;

        /**
         * pre-conditions:
         * - The vehicle is connected.
         * - The vehicle's linked station is connected
         * post-conditions:
         * - The lights of the vehicle emit a signal to the user.
         * - The lights of the vehicle's linked station emit a signal to the user.
         * */
        virtual void displayLights(const model::Vehicle &vehicle, bool keepOn) = 0;

        /**
         * pre-conditions:
         * - The vehicle is connected.
         * post-conditions: none
         * */
        virtual model::Distance requestDistanceDriven(const model::Vehicle &vehicle) = 0;

        /**
         * pre-conditions:
         * - The vehicle is connected.
         * post-conditions: none
         * */
        virtual model::GeoPosition requestVehiclePosition(const model::Vehicle &vehicle) = 0;
    };
}

