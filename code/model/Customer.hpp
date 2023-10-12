#pragma once

#include "User.hpp"
#include "Card.hpp"
#include <optional>

namespace redcars::model {
    class Customer : public User {
    public:
        Customer(std::string firstname, std::string lastname, std::string email, std::optional<Card> card);

        virtual ~Customer() = default;

    private:
        std::optional<Card> card;
    };
}
