#include "AdminCustomerController.hpp"

void redcars::controllers::AdminCustomerController::show(view::View &view, const redcars::model::Customer &value) {
    view.displayMessage("Customer: ");
    view.displayMessage(value.getFirstname().c_str());
    view.displayMessage(value.getLastname().c_str());
    view.displayMessage(value.getEmail().c_str());
    view.displayMessage(value.getAddress().c_str());
    view.displayMessage(value.getCard().value().getNumber().c_str());
}

redcars::model::Customer redcars::controllers::AdminCustomerController::create(redcars::view::View &view) {
    std::string firstname;
    std::string lastname;
    std::string email;
    std::string address;
    std::string card;
    std::string bankAccount;

    view.getInput("firstname", firstname);
    view.getInput("lastname", lastname);
    view.getInput("email", email);
    view.getInput("address", address);
    view.getInput("card", card);
    view.getInput("bankAccount", bankAccount);
    bool active = view.confirm("Active");

    return model::Customer(firstname, lastname, email, false,
                           address, std::optional(model::Card(card)), model::BankAccount(bankAccount), std::nullopt,
                           active);
}
