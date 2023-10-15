#pragma once

#include "../model/Station.hpp"
#include "AdminController.hpp"

namespace redcars::controllers {
    class AdminStationController : public AdminController<model::Station> {
    public:
        using AdminController<model::Station>::AdminController;

        void show(view::View &view, const model::Station &value) override;

        model::Station create(view::View &view) override;
    };
}

