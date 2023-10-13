#pragma once

#include <vector>
#include "../model/Vehicle.hpp"

namespace redcars::repo {
    class VehicleRepository {
    public:
        virtual std::vector<model::Vehicle> searchVehicles(model::GeoPosition position, model::Distance maxDistance) = 0;
    };
}
