#pragma once

#include "../model/Customer.hpp"
#include "../model/Money.hpp"

namespace redcars::delivery {
    class DeliverySystem {
    public:
        virtual model::Money deliverToCustomer(const model::Customer &customer, const model::Card &card) = 0;
    };
}