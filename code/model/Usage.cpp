#include "Usage.hpp"
#include "Charge.hpp"
#include "Distance.hpp"
#include "TimeFrame.hpp"

redcars::model::Usage::Usage(std::time_t startTime, redcars::model::Distance startDistance)
        : startTime(startTime), startDistance(startDistance) {}

std::optional<redcars::model::TimeFrame> redcars::model::Usage::getTimeFrame() const {
    if (!duration.has_value()) {
        return std::nullopt;
    }

    return TimeFrame(startTime, duration.value());
}

std::optional<redcars::model::Distance> redcars::model::Usage::getDistanceDriven() const {
    if (!endDistance.has_value()) {
        return std::nullopt;
    }

    return endDistance.value() - startDistance;
}

void redcars::model::Usage::finish(std::time_t duration, redcars::model::Distance endDistance, std::time_t) {
    this->duration = duration;
    this->endDistance = endDistance;
    this->charge = Charge(false, Money(10, std::time(nullptr))); // based on price params
}

const std::optional<redcars::model::Charge> &redcars::model::Usage::getCharge() const {
    return charge;
}
