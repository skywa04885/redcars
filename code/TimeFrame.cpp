#include "TimeFrame.hpp"

TimeFrame::TimeFrame(std::time_t start, std::time_t duration)
    : start(start), duration(duration) {}

std::time_t TimeFrame::getStart() const { return start; }
std::time_t TimeFrame::getEnd() const { return start + duration; }
std::time_t TimeFrame::getDuration() const { return duration; }

bool TimeFrame::isInsideOf(const TimeFrame &other) const {
  return other.getStart() >= getStart() && other.getEnd() <= getEnd();
}

bool TimeFrame::isInsideOf(std::time_t current) const {
	return current >= getStart() && current <= getEnd();
}
