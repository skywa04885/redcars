#include "Usage.hpp"

Usage::Usage(std::time_t startTime, Distance startDistance)
    : startTime(startTime), startDistance(startDistance) {}

std::optional<TimeFrame> Usage::getTimeFrame() const {
  if (!duration.has_value()) {
    return std::nullopt;
  }

  return TimeFrame(startTime, duration.value());
}

std::optional<Distance> Usage::getDistanceDriven() const {
  if (!endDistance.has_value()) {
    return std::nullopt;
  }

  return endDistance.value() - startDistance;
}

void Usage::finish(std::time_t duration, Distance endDistance, Charge charge) {
  this->duration = duration;
  this->endDistance = endDistance;
  this->charge = charge;
}
