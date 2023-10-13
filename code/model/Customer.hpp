#pragma once

#include "User.hpp"
#include "Card.hpp"
#include <optional>

namespace redcars::model {
    class Customer : public User {
    public:
        Customer(std::string firstname, std::string lastname, std::string email, std::string address, std::optional<Card> card);

        virtual ~Customer() = default;

        const std::optional<Card> &getCard() const;

        const std::string &getAddress() const;

    private:
        std::string address;
        std::optional<Card> card;
    };
}
