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

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        std::optional<TimeFrame> getTimeFrame() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        std::optional<Distance> getDistanceDriven() const;

        /**
         * pre-conditions:
         * - The usage is not finished.
         * post-conditions:
         * - The usage is finsihed.
         * */
        void finish(time_t duration, Distance endDistance, std::time_t deadline);

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const std::optional<Charge> &getCharge() const;

    private:
        time_t startTime;
        std::optional<time_t> duration;

        Distance startDistance;
        std::optional<Distance> endDistance;

        std::optional<Charge> charge;
    };
}
