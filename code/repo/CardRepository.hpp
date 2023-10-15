#pragma once

#include "../model/Card.hpp"

namespace redcars::repo {
    class CardRepository {
    public:

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        virtual model::Card generateCard() = 0;

        /**
         * pre-conditions:
         * - The card does not exist.
         * post-conditions:
         * - The card is registered.
         * */
        virtual void registerCard(const model::Card &card) = 0;
    };
}
