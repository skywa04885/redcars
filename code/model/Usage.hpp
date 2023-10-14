#pragma once

#include <ctime>
#include <optional>

#include "Charge.hpp"
#include "Distance.hpp"
#include "TimeFrame.hpp"

namespace redcars::model {
    class Usage {
    public:
        Usage(time_t startTime, Distance startDistance);

        virtual ~Usage() = default;

        std::optional<TimeFrame> getTimeFrame() const;

        std::optional<Distance> getDistanceDriven() const;

        void finish(time_t duration, Distance endDistance, std::time_t deadline);

        const std::optional<Charge> &getCharge() const;

    private:
        time_t startTime;
        std::optional<time_t> duration;

        Distance startDistance;
        std::optional<Distance> endDistance;

        std::optional<Charge> charge;
    };
}
