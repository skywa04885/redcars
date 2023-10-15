#pragma once

#include "Controller.hpp"
#include "../repo/Repository.hpp"
#include "../payment/PaymentSystem.hpp"

namespace redcars::controllers {
    class SubscribeController : public Controller {
    public:
        explicit SubscribeController(redcars::repo::Repository &repo,
                                     redcars::payment::PaymentSystem &paymentSystem);

        /**
         * pre-conditions:
         * - The user is logged in.
         * - The user is a customer
         * - The user is active.
         *
         * post-conditions:
         * - The user has a subscription for one week.
         * - The user is billed.
         * */
        bool run(view::View &view) override;

    private:
        repo::Repository &repo;
        payment::PaymentSystem &paymentSystem;
    };
}
