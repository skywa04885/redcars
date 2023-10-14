#pragma once

#include "../model/Reservation.hpp"

namespace redcars::repo {
    class ReservationRepository {
    public:
        virtual void addReservation(const model::Reservation &reservation) = 0;

        virtual std::optional<model::Reservation> getActiveReservationByCard(const model::Card &card) = 0;

        virtual void addReservationUsage(model::Reservation &reservation, model::Usage newUsage) = 0;
    };
}

