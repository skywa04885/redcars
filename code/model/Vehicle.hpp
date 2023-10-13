#pragma once

#include "GeoPosition.hpp"
#include <ctime>

namespace redcars::model {
    enum class VehicleKind {
        Station, Personal
    };


    class Vehicle {
    public:
        Vehicle(GeoPosition position, std::time_t lastPositionUpdate,
                VehicleKind kind);

        virtual ~Vehicle() = default;

        void updatePosition(GeoPosition position);

        const GeoPosition &getPosition() const;

        VehicleKind getKind() const;

    private:
        GeoPosition position;
        std::time_t lastPositionUpdate;
        VehicleKind kind;
    };

}
