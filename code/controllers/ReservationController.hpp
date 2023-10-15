#pragma once

#include "Controller.hpp"
#include "VehicleSearchController.hpp"
#include "../payment/PaymentSystem.hpp"

namespace redcars::controllers {
    class ReservationController : public Controller {
    public:
        explicit ReservationController(
                redcars::controllers::VehicleSearchController &vehicleSearchController, repo::Repository &repo,
                redcars::payment::PaymentSystem &paymentSystem);

        /**
         * pre-conditions:
         * - The user is logged in.
         * - The user is a customer.
         * - The user's account is active.
         * - The user does not have another reservation.
         *
         * post-conditions:
         * - The user is billed.
         * - The user has a new reservation.
         * */
        bool run(view::View &view) override;

    private:
        VehicleSearchController &vehicleSearchController;
        repo::Repository &repo;
        payment::PaymentSystem &paymentSystem;
    };
}
