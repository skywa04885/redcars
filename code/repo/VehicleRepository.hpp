#pragma once

#include <vector>
#include <optional>
#include "../model/Vehicle.hpp"
#include "CrudRepository.hpp"

namespace redcars::repo {
    class VehicleRepository : public CrudRepository<model::Vehicle> {
    public:

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        virtual std::vector<model::Vehicle>
        searchVehicles(model::GeoPosition position, model::Distance maxDistance) = 0;

        /**
         * pre-conditions:
         * - The current request is from a vehicle.
         * post-conditions: none
         * */
        virtual model::Vehicle getCurrentVehicle() = 0;
    };
}
