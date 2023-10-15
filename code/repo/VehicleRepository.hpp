#pragma once

#include <vector>
#include <optional>
#include "../model/Vehicle.hpp"
#include "CrudRepository.hpp"

namespace redcars::repo {
    class VehicleRepository : public CrudRepository<model::Vehicle> {
    public:
        virtual std::vector<model::Vehicle>
        searchVehicles(model::GeoPosition position, model::Distance maxDistance) = 0;

        /**
         * Get the current authenticated vehicle.
         * */
        virtual model::Vehicle getCurrentVehicle() = 0;
    };
}
