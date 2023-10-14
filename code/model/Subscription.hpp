#pragma once

#include "TimeFrame.hpp"

namespace redcars::model {
    class Subscription {
    public:
        explicit Subscription(const TimeFrame &activeFor);

    private:
        TimeFrame activeFor;
    };
}
