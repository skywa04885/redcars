
#include "RegisterController.hpp"

bool redcars::controllers::RegisterController::run(view::View &view) {
    while (true) {
        std::string firstname;
        std::string lastname;
        std::string address;
        std::string email;
        std::string bankAccount;

        while (true) {
            view.getInput("firstname", firstname);
            view.getInput("lastname", lastname);
            view.getInput("email", email);
            view.getInput("address", address);
            view.getInput("bank account", bankAccount);

            if (!view.confirm("Do you accept the terms of service?")) {
                view.displayErrorMessage("You must accept the terms of service to continue");
                continue;
            }

            break;
        }

        auto existingAccount = repo.bankAccounts().getBankAccountByNumber(bankAccount);
        if (existingAccount.has_value()) {
            view.displayErrorMessage("Bank account exists");
            continue;
        }

        auto existingCustomer = repo.customers().getCustomerByEmail(email);
        if (existingCustomer.has_value()) {
            view.displayErrorMessage("Email exists");
            continue;
        }

        model::Customer newCustomer(firstname, lastname, email, false, address, std::nullopt,
                                    model::BankAccount(bankAccount), std::nullopt, false);

        model::BankAccount account(bankAccount);
        if (!paymentSystem.requestAutomaticCharging(account)) {
            if (view.confirm("Failed to request automatic charging, would you like to try again?")) {
                continue;
            } else {
                return false;
            }
        }

        mail.verifyCustomerEmail(newCustomer);
        repo.customers().createCustomer(newCustomer);

        model::Card newCard = repo.cards().generateCard();
        model::Money cardMoney = delivery.deliverToCustomer(newCustomer, newCard);
        model::Charge cardCharge(false, cardMoney);

        while (!paymentSystem.fulfillCharge(cardCharge, account)) {
            if (!view.confirm("Could not pay for the card, would you like to try again? ")) {
                return false;
            }
        }

        repo.cards().registerCard(newCard);

        return true;
    }
}

redcars::controllers::RegisterController::RegisterController(redcars::payment::PaymentSystem &paymentSystem,
                                                             repo::Repository &repo, mail::EmailSystem &mail,
                                                             delivery::DeliverySystem &delivery)
        : paymentSystem(paymentSystem), repo(repo), mail(mail), delivery(delivery) {}
