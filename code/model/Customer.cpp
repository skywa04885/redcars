#include "Customer.hpp"
#include "Card.hpp"
#include "User.hpp"
#include <optional>

redcars::model::Customer::Customer(std::string firstname, std::string lastname, std::string email,
                                   bool emailVerified, std::string address,
                                   std::optional<redcars::model::Card> card, BankAccount bankAccount,
                                   std::optional<Subscription> subscription)
        : User(firstname, lastname, email, emailVerified), address(address), card(card), bankAccount(bankAccount),
          subscription(subscription) {}

const std::optional<redcars::model::Card> &redcars::model::Customer::getCard() const {
    return card;
}

const std::string &redcars::model::Customer::getAddress() const {
    return address;
}

const redcars::model::BankAccount &redcars::model::Customer::getBankAccount() const {
    return bankAccount;
}

