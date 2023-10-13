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

    public:
        bool runInteractive(std::istream &input, std::ostream &output) override;

    private:
        VehicleSearchController &vehicleSearchController;
        repo::Repository& repo;
        payment::PaymentSystem& paymentSystem;
    };
}
