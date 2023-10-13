#pragma once

#include <string>

namespace redcars::model {
    class Card {
    public:
        Card(std::string number);

        virtual ~Card() = default;

        const std::string &getNumber() const;

    private:
        std::string number;
    };
}
