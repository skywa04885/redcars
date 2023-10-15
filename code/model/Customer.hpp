#pragma once

#include "User.hpp"
#include "Card.hpp"
#include "BankAccount.hpp"
#include "Subscription.hpp"
#include <optional>

namespace redcars::model {
    class Customer : public User {
    public:
        Customer(std::string firstname, std::string lastname, std::string email,
                 bool emailVerified, std::string address,
                 std::optional<redcars::model::Card> card, BankAccount bankAccount,
                 std::optional<Subscription> subscription, bool active);

        virtual ~Customer() = default;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const std::optional<Card> &getCard() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const std::string &getAddress() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const BankAccount &getBankAccount() const;

    private:
        std::string address;
        std::optional<Card> card;
        BankAccount bankAccount;
        std::optional<Subscription> subscription;
        bool active;
    };
}
