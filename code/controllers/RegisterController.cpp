
#include "RegisterController.hpp"

void redcars::controllers::RegisterController::runInteractive(std::istream &input, std::ostream &output) {
    std::string firstname;
    std::string lastname;
    std::string email;
    std::string bankAccount;

    while (true) {
        getInput(input, output, "firstname", firstname);
        getInput(input, output, "lastname", lastname);
        getInput(input, output, "email", email);
        getInput(input, output, "bank account", bankAccount);

        if (!confirm(input, output, "Do you accept the terms of service?")) {
            output << "You must accept the terms of service to continue" << std::endl;
            continue;
        }

        break;
    }

    model::Customer newCustomer(firstname, lastname, email, std::nullopt);
    repo.customers().createCustomer(newCustomer);

}

redcars::controllers::RegisterController::RegisterController(redcars::payment::PaymentSystem &paymentSystem,
                                                             repo::Repository &repo)
        : paymentSystem(paymentSystem), repo(repo) {}
