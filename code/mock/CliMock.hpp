#pragma once

#include "../payment/PaymentSystem.hpp"
#include "../repo/Repository.hpp"


#include <ostream>

namespace redcars::mock {
    class CliMock : public payment::PaymentSystem, public repo::Repository, public repo::CustomerRepository {
    public:
        CliMock(std::ostream &output);

        bool fulfillCharge(model::Charge &charge, const model::BankAccount &from) override;

        CustomerRepository &customers() override;

        void createCustomer(const model::Customer &customer) override;

    private:
        std::ostream &output;
    };
}