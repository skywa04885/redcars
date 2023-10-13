#pragma once

#include "../model/Reservation.hpp"

namespace redcars::repo {
    class ReservationRepository {
    public:
        virtual void addReservation(const model::Reservation &reservation) = 0;
    };
}

