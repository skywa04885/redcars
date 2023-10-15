#pragma once

#include "Controller.hpp"
#include "../repo/Repository.hpp"
#include "../vehicle/VehicleComs.hpp"

namespace redcars::controllers {
    class CheckInController : public Controller {
    public:
        explicit CheckInController(redcars::repo::Repository &repo,
                                   redcars::vehicle::VehicleComs &vehicleComs);

        /**
         * pre-conditions:
         * - The current user is logged in.
         * - The current user is a customer
         * - The current user has a card.
         * - The current user's account is active.
         *
         * post-conditions:
         * - a new usage has been added the the user's reservation.
         * */
        bool run(view::View &view) override;

    private:
        repo::Repository &repo;
        vehicle::VehicleComs &vehicleComs;
    };
}
