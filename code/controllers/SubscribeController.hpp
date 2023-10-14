#pragma once

#include "Controller.hpp"
#include "../repo/Repository.hpp"
#include "../payment/PaymentSystem.hpp"

namespace redcars::controllers {
    class SubscribeController : public Controller {
    public:
        explicit SubscribeController(redcars::repo::Repository &repo,
                                     redcars::payment::PaymentSystem &paymentSystem);

        bool run(view::View &view) override;

    private:
        repo::Repository &repo;
        payment::PaymentSystem &paymentSystem;
    };
}
