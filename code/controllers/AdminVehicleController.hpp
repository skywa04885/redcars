#pragma once

#include "../model/Vehicle.hpp"
#include "AdminController.hpp"

namespace redcars::controllers {
    class AdminVehicleController : public AdminController<model::Vehicle> {
    public:
        using AdminController<model::Vehicle>::AdminController;

        /**
         * see base class
         * */
        void show(view::View &view, const model::Vehicle &value) override;

        /**
         * see base class
         * */
        model::Vehicle create(view::View &view) override;
    };
}
