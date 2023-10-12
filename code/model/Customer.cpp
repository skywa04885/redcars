#include "Customer.hpp"
#include "Card.hpp"
#include "User.hpp"
#include <optional>

redcars::model::Customer::Customer(std::string firstname, std::string lastname, std::string email, std::string address,
                                   std::optional<redcars::model::Card> card)
        : User(firstname, lastname, email), address(address), card(card) {}

const std::optional<redcars::model::Card> &redcars::model::Customer::getCard() const {
    return card;
}

const std::string &redcars::model::Customer::getAddress() const {
    return address;
}

