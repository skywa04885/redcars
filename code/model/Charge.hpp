#pragma once

#include "Money.hpp"

namespace redcars::model {
    class Charge {
    public:
        Charge(bool paid, Money amount);

        virtual ~Charge() = default;

        void pay();

    private:
        bool paid;
        Money amount;
    };
}
