#pragma once

#include "../model/Reservation.hpp"

namespace redcars::repo {
    class ReservationRepository {
    public:
        /**
         * pre-conditions:
         * - The reservation does not exist.
         * post-conditions:
         * - The reservation has been created.
         * */
        virtual void addReservation(const model::Reservation &reservation) = 0;

        /**
         * pre-conditions:
         * - The card exists.
         * post-conditions: none
         * */
        virtual std::optional<model::Reservation> getActiveReservationByCard(const model::Card &card) = 0;

        /**
         * pre-conditions:
         * - The reservation exists.
         * - The reservation does not have a incomplete reservation
         * post-conditions:
         * - A new usage has been added to the reservation.
         * */
        virtual void addReservationUsage(model::Reservation &reservation, model::Usage newUsage) = 0;
    };
}

