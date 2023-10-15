#pragma once

#include "Money.hpp"

namespace redcars::model {
    class Charge {
    public:
        Charge(bool paid, Money amount);

        virtual ~Charge() = default;

        /**
         * pre-conditions:
         * - The charge is not paid
         * post-conditions:
         * - The charge is paid.
         * */
        void pay();

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const Money &getAmount() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        bool isPaid() const;

    private:
        bool paid;
        Money amount;
    };
}
