#include "Customer.hpp"
#include "Card.hpp"
#include "User.hpp"
#include <optional>

redcars::model::Customer::Customer(std::string firstname, std::string lastname, std::string email,
                                   std::optional<redcars::model::Card> card)
        : User(firstname, lastname, email), card(card) {}

const std::optional<redcars::model::Card> &redcars::model::Customer::getCard() const {
    return card;
}

