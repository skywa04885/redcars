#include "CheckOutController.hpp"

bool redcars::controllers::CheckOutController::run(redcars::view::View &view) {
    model::Vehicle currentVehicle = repo.vehicles().getCurrentVehicle();

    model::GeoPosition vehicleDistance = vehicleComs.requestVehiclePosition(currentVehicle);
    auto station = repo.stations().getClosestStation(vehicleDistance, model::Distance(5));

    if (!station.has_value()) {
        return false;
    }

    if (repo.stations().getConnectedVehicleCount(*station) + 1 > station->getMaxVehicleCount()) {
        vehicleComs.displayLights(currentVehicle, false);
        return false;
    }

    vehicleComs.disableEngine(currentVehicle);
    vehicleComs.displayLights(currentVehicle, true);

    std::string cardNumber;
    view.getInput("card number", cardNumber);
    model::Card card(cardNumber);

    auto reservation = repo.reservations().getActiveReservationByCard(card);

    if (!reservation.has_value()) {
        vehicleComs.displayLights(currentVehicle, false);
        return false;
    }

    if (!reservation->isLinkedWithVehicle(currentVehicle)) {
        vehicleComs.displayLights(currentVehicle, false);
        return false;
    }

    vehicleComs.displayLights(currentVehicle, false);
    auto usage = reservation->getLastUsage();

    usage->finish(std::time(nullptr), vehicleComs.requestDistanceDriven(currentVehicle),
                  reservation->getTime().getEnd());

    model::Charge charge = usage->getCharge().value();

    paymentSystem.fulfillCharge(charge, reservation->getCustomer());

    return true;
}

redcars::controllers::CheckOutController::CheckOutController(redcars::repo::Repository &repo,
                                                             redcars::vehicle::VehicleComs &vehicleComs,
                                                             redcars::payment::PaymentSystem &paymentSystem)
        : repo(repo), vehicleComs(vehicleComs), paymentSystem(paymentSystem) {}
