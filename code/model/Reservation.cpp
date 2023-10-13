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

const redcars::model::Charge& redcars::model::Reservation::getInitialCharge() const {
    return initialCharge;
}

void redcars::model::Reservation::payInitialCharge() {
    initialCharge.pay();
}
