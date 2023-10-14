#pragma once

#include "Controller.hpp"
#include "../repo/Repository.hpp"
#include "../vehicle/VehicleComs.hpp"

namespace redcars::controllers {
    class CheckInController : public Controller {
    public:
        explicit CheckInController(redcars::repo::Repository &repo,
                                   redcars::vehicle::VehicleComs &vehicleComs);

        bool run(view::View &view) override;
    private:
        repo::Repository& repo;
        vehicle::VehicleComs& vehicleComs;
    };
}
