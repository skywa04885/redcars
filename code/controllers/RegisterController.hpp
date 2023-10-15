#pragma once

#include "Controller.hpp"
#include "../payment/PaymentSystem.hpp"
#include "../repo/Repository.hpp"
#include "../mail/EmailSystem.hpp"
#include "../delivery/DeliverySystem.hpp"

namespace redcars::controllers {
    class RegisterController : public Controller {
    public:
        explicit RegisterController(payment::PaymentSystem &paymentSystem, repo::Repository &repo,
                                    mail::EmailSystem &mail, delivery::DeliverySystem &delivery);

        /**
         * pre-conditions:
         * - The user is not logged in.
         * - The user does not have an existing account.
         *
         * post-conditions
         * - The user has a new account.
         * - The user is a customer.
         * - The user has been billed.
         * - The user has a new card and is being delivered.
         * */
        bool run(view::View &view) override;

    private:
        payment::PaymentSystem &paymentSystem;
        repo::Repository &repo;
        mail::EmailSystem &mail;
        delivery::DeliverySystem &delivery;
    };
}
