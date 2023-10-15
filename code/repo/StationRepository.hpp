#pragma once

#include <optional>
#include "../model/Station.hpp"
#include "CrudRepository.hpp"

namespace redcars::repo {
    class StationRepository : public CrudRepository<model::Station> {
    public:

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        virtual std::optional<model::Station>
        getClosestStation(model::GeoPosition pos, model::Distance maxDistance) = 0;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        virtual int getConnectedVehicleCount(const model::Station &station) = 0;
    };
}
