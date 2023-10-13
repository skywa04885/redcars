#pragma once

#include "CustomerRepository.hpp"
#include "BankAccountRepository.hpp"
#include "CardRepository.hpp"

namespace redcars::repo {
    class Repository {
    public:
        virtual ~Repository() = default;

        virtual CustomerRepository &customers() = 0;
        virtual BankAccountRepository &bankAccounts() = 0;
        virtual CardRepository& cards() = 0;
    };
}
