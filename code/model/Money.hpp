#pragma once

#include <ctime>

namespace redcars::model {
    class Money {
    public:
        Money(unsigned int euroCents, time_t valuedAt);
        virtual ~Money() = default;

    private:
        unsigned int euroCents;
        time_t valuedAt;
    };
}
