#pragma once

#include "AdminController.hpp"
#include "../model/Customer.hpp"

namespace redcars::controllers {
    class AdminCustomerController : public AdminController<model::Customer> {
    public:
        using AdminController<model::Customer>::AdminController;

        void show(view::View &view, const model::Customer &value) override;

        model::Customer create(view::View &view) override;
    };
}

