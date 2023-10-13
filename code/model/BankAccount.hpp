#pragma once

#include <string>

namespace redcars::model {
    class BankAccount {
    public:
        BankAccount(std::string number);

        const std::string &getNumber() const;

    private:
        std::string number;
    };
}

