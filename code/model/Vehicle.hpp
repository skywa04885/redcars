#pragma once

#include "GeoPosition.hpp"
#include <ctime>
#include <string>

namespace redcars::model {
    enum class VehicleKind {
        Station, Personal
    };


    class Vehicle {
    public:
        Vehicle(redcars::model::GeoPosition position, std::time_t lastPositionUpdate,
                VehicleKind kind, std::string licencePlate);

        virtual ~Vehicle() = default;

        /**
         * pre-conditions: none
         * post-conditions:
         * - The vehicle's position has been updated.
         * */
        void updatePosition(GeoPosition position);

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const GeoPosition &getPosition() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        VehicleKind getKind() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const std::string &getLicencePlate() const;

    private:
        GeoPosition position;
        std::time_t lastPositionUpdate;
        VehicleKind kind;
        std::string licencePlate;
    };

}
