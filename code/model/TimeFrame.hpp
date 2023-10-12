#pragma once

#include <ctime>

namespace redcars::model {
    class TimeFrame {
    public:
        TimeFrame(time_t start, time_t duration);

        virtual ~TimeFrame() = default;

        time_t getStart() const;

        time_t getDuration() const;

        time_t getEnd() const;

        bool isInsideOf(const TimeFrame &other) const;

        bool isInsideOf(time_t current) const;

    private:
        time_t start;
        time_t duration;
    };
}
