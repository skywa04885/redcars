#pragma once

#include "GeoPosition.hpp"
#include <ctime>

namespace redcars::model {
    enum class VehicleKind {
        Station, Personal
    };


    class Vehicle {
    public:
        Vehicle(GeoPosition position, time_t lastPositionUpdate,
                VehicleKind kind);

        virtual ~Vehicle() = default;

        void updatePosition(GeoPosition position);

    private:
        GeoPosition position;
        time_t lastPositionUpdate;
        VehicleKind kind;
    };

}
