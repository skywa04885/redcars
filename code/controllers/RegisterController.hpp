#pragma once

#include "Controller.hpp"
#include "../payment/PaymentSystem.hpp"
#include "../repo/Repository.hpp"

namespace redcars::controllers {
    class RegisterController : public Controller {
    public:
        explicit RegisterController(payment::PaymentSystem &paymentSystem, repo::Repository &repo);

        void runInteractive(std::istream &input, std::ostream &output) override;

    private:
        payment::PaymentSystem &paymentSystem;
        repo::Repository &repo;
    };
}
