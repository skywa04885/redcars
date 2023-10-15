#pragma once

#include <string>
#include <optional>
#include "../model/BankAccount.hpp"

namespace redcars::repo
{
    class BankAccountRepository
    {
    public:
        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        virtual std::optional<model::BankAccount> getBankAccountByNumber(const std::string &number) = 0;
    };
}
