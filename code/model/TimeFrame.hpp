#pragma once

#include <ctime>

namespace redcars::model {
    class TimeFrame {
    public:
        TimeFrame(time_t start, time_t duration);

        virtual ~TimeFrame() = default;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        time_t getStart() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        time_t getDuration() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        time_t getEnd() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        bool isInsideOf(const TimeFrame &other) const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        bool isInsideOf(time_t current) const;

    private:
        time_t start;
        time_t duration;
    };
}
