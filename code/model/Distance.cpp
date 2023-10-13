#include "Distance.hpp"

const int KM_FACTOR = 1000;

redcars::model::Distance::Distance(int meters) : meters(meters) {}

redcars::model::Distance redcars::model::Distance::fromKm(int kilometers) {
    return Distance(kilometers * KM_FACTOR);
}

int redcars::model::Distance::asKilometers() const { return meters / KM_FACTOR; }

int redcars::model::Distance::asMeters() const { return meters; }

redcars::model::Distance redcars::model::Distance::operator-(const Distance &lhs) const {
    return Distance(asMeters() - lhs.asMeters());
}

bool redcars::model::Distance::operator<(const redcars::model::Distance &lhs) const {
    return asMeters() < lhs.asMeters();
}

bool redcars::model::Distance::operator>(const redcars::model::Distance &lhs) const {
    return asMeters() > lhs.asMeters();
}
