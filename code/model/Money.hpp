#pragma once

#include <ctime>

namespace redcars::model {
    class Money {
    public:
        Money(unsigned int euroCents, time_t valuedAt);

        virtual ~Money() = default;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        float eurosAsFloat() const;

    private:
        unsigned int euroCents;
        time_t valuedAt;
    };
}
