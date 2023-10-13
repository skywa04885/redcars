#pragma once

#include "User.hpp"
#include "Card.hpp"
#include "BankAccount.hpp"
#include <optional>

namespace redcars::model {
    class Customer : public User {
    public:
        Customer(std::string firstname, std::string lastname, std::string email, bool emailVerified,
                 std::string address, std::optional<redcars::model::Card> card,
                 BankAccount bankAccount);

        virtual ~Customer() = default;

        const std::optional<Card> &getCard() const;

        const std::string &getAddress() const;

        const BankAccount &getBankAccount() const;

    private:
        std::string address;
        std::optional<Card> card;
        BankAccount bankAccount;
    };
}
