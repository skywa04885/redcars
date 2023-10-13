#pragma once

#include <ctime>
#include <vector>

#include "TimeFrame.hpp"
#include "Usage.hpp"
#include "Charge.hpp"
#include "Vehicle.hpp"
#include "Customer.hpp"

namespace redcars::model {
    class Reservation {
    public:
        Reservation(std::vector<Usage> usages, TimeFrame time, Charge initialCharge,
                    Vehicle vehicle, Customer customer);

        virtual ~Reservation() = default;

        static Reservation calculateNew(TimeFrame time, Vehicle vehicle, Customer customer);

        const Charge& getInitialCharge() const;
        void payInitialCharge();

    private:
        std::vector<Usage> usages;

        TimeFrame time;
        Charge initialCharge;

        Vehicle vehicle;
        Customer customer;
    };
}
