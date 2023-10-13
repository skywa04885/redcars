#include "ReservationController.hpp"
#include <sstream>

bool redcars::controllers::ReservationController::run(view::View& view) {
    if (!vehicleSearchController.run(view)) {
        return false;
    }

    while (true) {
        unsigned int durationInHours;

        view.getInput("reservation duration in hours", durationInHours);

        model::Customer customer = repo.customers().getCurrentCustomer();
        model::Reservation newReservation = model::Reservation::calculateNew(
                model::TimeFrame(std::time(nullptr), durationInHours * 60),
                vehicleSearchController.getSelected().value(),
                customer
        );

        std::stringstream ss;
        ss << "De reservering gaat (initeel) €";
        ss << newReservation.getInitialCharge().getAmount().eurosAsFloat();
        ss << " kosten";

        view.displayMessage(ss.str().c_str());

        if (!view.confirm("Is dit okay?")) {
            continue;
        }

        repo.reservations().addReservation(newReservation);

        model::Charge charge = newReservation.getInitialCharge();
        paymentSystem.fulfillCharge(charge, customer);

        return true;
    }
}

redcars::controllers::ReservationController::ReservationController(
        redcars::controllers::VehicleSearchController &vehicleSearchController, repo::Repository &repo,
        redcars::payment::PaymentSystem &paymentSystem)
        : vehicleSearchController(vehicleSearchController), repo(repo), paymentSystem(paymentSystem) {}
