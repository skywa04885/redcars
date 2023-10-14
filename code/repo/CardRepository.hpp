#pragma once

#include "../model/Card.hpp"

namespace redcars::repo {
    class CardRepository {
    public:
        virtual model::Card generateCard() = 0;

        virtual void registerCard(const model::Card &card) = 0;
    };
}
