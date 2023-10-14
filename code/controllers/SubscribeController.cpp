#include "SubscribeController.hpp"

bool redcars::controllers::SubscribeController::run(redcars::view::View &view) {
    model::Customer currentCustomer = repo.customers().getCurrentCustomer();

    view.displayMessage("#1 Paid subscription (1 week)");

    unsigned int choice;
    view.getInput("choice", choice);

    while (true) {
        model::Charge charge(false, model::Money(10, std::time(nullptr)));

        if (!paymentSystem.fulfillCharge(charge, currentCustomer)) {
            if (!view.confirm("Could not complete transaction, would you like to try again?")) {
                return false;
            }
        }

        break;
    }

    model::Subscription sub(model::TimeFrame(std::time(nullptr), 60 * 60 * 24 * 7));

    repo.customers().setCustomerSubscription(currentCustomer, sub);

    return false;
}

redcars::controllers::SubscribeController::SubscribeController(redcars::repo::Repository &repo,
                                                               redcars::payment::PaymentSystem &paymentSystem)
        : repo(repo), paymentSystem(paymentSystem) {}
