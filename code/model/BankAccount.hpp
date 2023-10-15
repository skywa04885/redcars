#pragma once

#include <string>

namespace redcars::model {
    class BankAccount {
    public:
        BankAccount(std::string number);

        virtual ~BankAccount() = default;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const std::string &getNumber() const;

    private:
        std::string number;
    };
}

