#pragma once

#include "../model/Customer.hpp"
#include "../model/Charge.hpp"

namespace redcars::payment {
    class PaymentSystem {
    public:
        virtual ~PaymentSystem() = default;

        virtual bool fulfillCharge(model::Charge &charge, const model::Customer &customer) = 0;

        virtual bool fulfillCharge(model::Charge &charge, const model::BankAccount &from) = 0;

        virtual bool requestAutomaticCharging(const model::BankAccount &account) = 0;
    };

}
