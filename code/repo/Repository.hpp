#pragma once

#include "CustomerRepository.hpp"
#include "BankAccountRepository.hpp"
#include "CardRepository.hpp"
#include "VehicleRepository.hpp"
#include "ReservationRepository.hpp"
#include "StationRepository.hpp"

namespace redcars::repo {
    class Repository {
    public:
        virtual ~Repository() = default;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        virtual CustomerRepository &customers() = 0;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        virtual BankAccountRepository &bankAccounts() = 0;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        virtual CardRepository &cards() = 0;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        virtual VehicleRepository &vehicles() = 0;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        virtual ReservationRepository &reservations() = 0;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        virtual StationRepository &stations() = 0;
    };
}
