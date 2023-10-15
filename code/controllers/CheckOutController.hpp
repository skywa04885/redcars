#pragma once

#include "Controller.hpp"
#include "../repo/Repository.hpp"
#include "../vehicle/VehicleComs.hpp"
#include "../payment/PaymentSystem.hpp"

namespace redcars::controllers {
    class CheckOutController : public Controller {
    public:
        explicit CheckOutController(redcars::repo::Repository &repo,
                                    redcars::vehicle::VehicleComs &vehicleComs,
                                    redcars::payment::PaymentSystem &paymentSystem);

        /**
         * pre-conditions:
         * - The current user is logged in.
         * - The current user is a customer
         * - The current user has a card.
         *
         * post-conditions:
         * - The new reservation's usage has been finished.
         * - The user is billed.
         * - The reservation's vehicle is linked a station.
         * */
        bool run(view::View &view) override;

    private:
        repo::Repository &repo;
        vehicle::VehicleComs &vehicleComs;
        payment::PaymentSystem &paymentSystem;
    };
}
