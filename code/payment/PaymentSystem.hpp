#pragma once

#include "../model/Customer.hpp"
#include "../model/Charge.hpp"

namespace redcars::payment {
    class PaymentSystem {
    public:
        virtual ~PaymentSystem() = default;

        /**
         * pre-conditions:
         * - The customer has automatic charging enabled.
         * post-conditions:
         * - The customer is billed for the given amount.
         * */
        virtual bool fulfillCharge(model::Charge &charge, const model::Customer &customer) = 0;

        /**
         * pre-conditions:
         * - The bank account has automatic charging enabled.
         * post-conditions:
         * - The customer is billed for the given amount.
         * */
        virtual bool fulfillCharge(model::Charge &charge, const model::BankAccount &from) = 0;

        /**
         * pre-conditions:
         * - The bank account is valid.
         * - The payment system can work with the bank of the account.
         * post-conditions:
         * - Automatic billing is authorized for the given bank account.
         * */
        virtual bool requestAutomaticCharging(const model::BankAccount &account) = 0;
    };

}
