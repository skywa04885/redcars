#pragma once

#include <ctime>
#include <vector>

#include "TimeFrame.hpp"
#include "Usage.hpp"
#include "Charge.hpp"

namespace redcars::model {
    class Reservation {
    public:
    private:
        std::vector<Usage> usages;

        TimeFrame time;
        Charge initialCharge;
    };
}
