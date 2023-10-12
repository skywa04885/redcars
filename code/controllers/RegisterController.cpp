
#include "RegisterController.hpp"

void redcars::controllers::RegisterController::runInteractive(std::istream &input, std::ostream &output) {
    while (true) {
        std::string firstname;
        std::string lastname;
        std::string address;
        std::string email;
        std::string bankAccount;

        while (true) {
            getInput(input, output, "firstname", firstname);
            getInput(input, output, "lastname", lastname);
            getInput(input, output, "email", email);
            getInput(input, output, "address", address);
            getInput(input, output, "bank account", bankAccount);

            if (!confirm(input, output, "Do you accept the terms of service?")) {
                output << "You must accept the terms of service to continue" << std::endl;
                continue;
            }

            break;
        }

        auto existingAccount = repo.bankAccounts().getBankAccountByNumber(bankAccount);
        if (existingAccount.has_value()) {
            output << "Bank account exists" << std::endl;
            continue;
        }

        auto existingCustomer = repo.customers().getCustomerByEmail(email);
        if (existingCustomer.has_value()) {
            output << "Email exists" << std::endl;
            continue;
        }

        model::Customer newCustomer(firstname, lastname, email, address, std::nullopt);

        model::BankAccount account(bankAccount);
        if (!paymentSystem.requestAutomaticCharging(account)) {
            if (confirm(input, output, "Failed to request automatic charging, would you like to try again?")) {
                continue;
            } else {
                break;
            }
        }

        mail.verifyCustomerEmail(newCustomer);
        repo.customers().createCustomer(newCustomer);

        model::Card newCard = repo.cards().generateCard();
        model::Money cardMoney = delivery.deliverToCustomer(newCustomer, newCard);
        model::Charge cardCharge(false, cardMoney);

        while(!paymentSystem.fulfillCharge(cardCharge, account)) {
            if (!confirm(input, output, "Could not pay for the card, would you like to try again? ")) {
                break;
            }
        }

        repo.cards().registerCard(newCard);

        break;
    }
}

redcars::controllers::RegisterController::RegisterController(redcars::payment::PaymentSystem &paymentSystem,
                                                             repo::Repository &repo, mail::EmailSystem &mail,
                                                             delivery::DeliverySystem &delivery)
        : paymentSystem(paymentSystem), repo(repo), mail(mail), delivery(delivery) {}
