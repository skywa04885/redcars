#include "ReservationController.hpp"

bool redcars::controllers::ReservationController::runInteractive(std::istream &input, std::ostream &output) {
    if (!vehicleSearchController.runInteractive(input, output)) {
        return false;
    }

    while (true) {
        unsigned int durationInHours;

        getInput(input, output, "reservation duration in hours", durationInHours);

        model::Customer customer = repo.customers().getCurrentCustomer();
        model::Reservation newReservation = model::Reservation::calculateNew(
                model::TimeFrame(std::time(nullptr), durationInHours * 60),
                vehicleSearchController.getSelected().value(),
                customer
        );

        output << "De reservering gaat (initeel) €" << newReservation.getInitialCharge().getAmount().eurosAsFloat()
               << " kosten" << std::endl;

        if (!confirm(input, output, "Is dit okay?")) {
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
