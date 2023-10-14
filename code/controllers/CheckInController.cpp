#include "CheckInController.hpp"

bool redcars::controllers::CheckInController::run(redcars::view::View &view) {
    model::Vehicle currentVehicle = repo.vehicles().getCurrentVehicle();

    std::string cardNumber;
    view.getInput("card number", cardNumber);
    model::Card card(cardNumber);

    auto reservation = repo.reservations().getActiveReservationByCard(card);

    if (!reservation.has_value()) {
        vehicleComs.displayLights(currentVehicle);
        return false;
    }

    if (!reservation->isLinkedWithVehicle(currentVehicle)) {
        vehicleComs.displayLights(currentVehicle);
        return false;
    }

    vehicleComs.openDoor(currentVehicle);

    model::Usage newUsage(std::time(nullptr), vehicleComs.requestDistanceDriven(currentVehicle));
    repo.reservations().addReservationUsage(reservation.value(), newUsage);

    return true;
}

redcars::controllers::CheckInController::CheckInController(redcars::repo::Repository &repo,
                                                           redcars::vehicle::VehicleComs &vehicleComs)
        : repo(repo), vehicleComs(vehicleComs) {}
