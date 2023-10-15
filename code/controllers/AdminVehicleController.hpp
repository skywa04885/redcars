#pragma once

#include "../model/Vehicle.hpp"
#include "AdminController.hpp"

namespace redcars::controllers {
    class AdminVehicleController : public AdminController<model::Vehicle> {
    public:
        using AdminController<model::Vehicle>::AdminController;

        void show(view::View &view, const model::Vehicle &value) override;

        model::Vehicle create(view::View &view) override;
    };
}
