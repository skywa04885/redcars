#include "TimeFrame.hpp"

redcars::model::TimeFrame::TimeFrame(std::time_t start, std::time_t duration)
        : start(start), duration(duration) {}

std::time_t redcars::model::TimeFrame::getStart() const { return start; }

std::time_t redcars::model::TimeFrame::getEnd() const { return start + duration; }

std::time_t redcars::model::TimeFrame::getDuration() const { return duration; }

bool redcars::model::TimeFrame::isInsideOf(const TimeFrame &other) const {
    return other.getStart() >= getStart() && other.getEnd() <= getEnd();
}

bool redcars::model::TimeFrame::isInsideOf(std::time_t current) const {
    return current >= getStart() && current <= getEnd();
}
