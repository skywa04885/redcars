#pragma once

#include <vector>

#include "GeoPosition.hpp"

namespace redcars::model {
    class Station {
    public:
        Station(GeoPosition position, int maxVehicleCount);

        virtual ~Station() = default;

    private:
        GeoPosition position;
        int maxVehicleCount;
    };
}
