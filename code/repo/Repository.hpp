#pragma once

#include "CustomerRepository.hpp"
#include "BankAccountRepository.hpp"
#include "CardRepository.hpp"
#include "VehicleRepository.hpp"
#include "ReservationRepository.hpp"

namespace redcars::repo {
    class Repository {
    public:
        virtual ~Repository() = default;

        virtual CustomerRepository &customers() = 0;
        virtual BankAccountRepository &bankAccounts() = 0;
        virtual CardRepository& cards() = 0;
        virtual VehicleRepository& vehicles() = 0;
        virtual ReservationRepository& reservations() = 0;
    };
}
