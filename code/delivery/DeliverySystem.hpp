#pragma once

#include "../model/Customer.hpp"
#include "../model/Money.hpp"

namespace redcars::delivery {
    class DeliverySystem {
    public:
        /**
         * pre-conditions:
         * - The customer has a valid address.
         *
         * post-conditions:
         * - A card is being sent to the customer's address.
         * */
        virtual model::Money deliverToCustomer(const model::Customer &customer, const model::Card &card) = 0;
    };
}