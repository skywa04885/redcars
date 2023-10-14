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

        bool run(view::View &view) override;

    private:
        repo::Repository &repo;
        vehicle::VehicleComs &vehicleComs;
        payment::PaymentSystem &paymentSystem;
    };
}
