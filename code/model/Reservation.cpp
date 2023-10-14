#include "Reservation.hpp"

redcars::model::Reservation::Reservation(std::vector<Usage> usages,
                                         redcars::model::TimeFrame time,
                                         redcars::model::Charge initialCharge,
                                         redcars::model::Vehicle vehicle,
                                         redcars::model::Customer customer) : usages(usages), time(time),
                                                                              initialCharge(initialCharge),
                                                                              vehicle(vehicle),
                                                                              customer(customer) {}

redcars::model::Reservation
redcars::model::Reservation::calculateNew(redcars::model::TimeFrame time, redcars::model::Vehicle vehicle,
                                          redcars::model::Customer customer) {
    // TODO: calculate the actual price based on the provided parameters.
    Charge charge(false, Money(100, std::time(nullptr)));

    return Reservation({}, time, charge, vehicle, customer);
}

const redcars::model::Charge &redcars::model::Reservation::getInitialCharge() const {
    return initialCharge;
}

void redcars::model::Reservation::payInitialCharge() {
    initialCharge.pay();
}

bool redcars::model::Reservation::isLinkedWithVehicle(const redcars::model::Vehicle &) const {
    return true;
}

bool redcars::model::Reservation::hasOpenUsages() const {
    return false;
}

const redcars::model::Vehicle &redcars::model::Reservation::getVehicle() const {
    return vehicle;
}

const redcars::model::Customer &redcars::model::Reservation::getCustomer() const {
    return customer;
}

std::optional<redcars::model::Usage> redcars::model::Reservation::getLastUsage() {
    return std::optional<Usage>(Usage(std::time(nullptr) - 1000, Distance::fromKm(1000)));
}

const redcars::model::TimeFrame &redcars::model::Reservation::getTime() const {
    return time;
}
