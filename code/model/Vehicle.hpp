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

        void updatePosition(GeoPosition position);

        const GeoPosition &getPosition() const;

        VehicleKind getKind() const;

        const std::string &getLicencePlate() const;

    private:
        GeoPosition position;
        std::time_t lastPositionUpdate;
        VehicleKind kind;
        std::string licencePlate;
    };

}
