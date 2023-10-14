#pragma once

#include <optional>
#include "../model/Station.hpp"

namespace redcars::repo {
    class StationRepository {
    public:
        virtual std::optional<model::Station>
        getClosestStation(model::GeoPosition pos, model::Distance maxDistance) = 0;

        virtual int getConnectedVehicleCount(const model::Station &station) = 0;
    };
}
