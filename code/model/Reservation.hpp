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

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        static Reservation calculateNew(TimeFrame time, Vehicle vehicle, Customer customer);

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const Charge &getInitialCharge() const;

        /**
         * pre-conditions:
         * - The initial charge is not paid.
         * post-conditions:
         * - The initial charge is paid.
         * */
        void payInitialCharge();

        bool isLinkedWithVehicle(const Vehicle &other) const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        bool hasOpenUsages() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const Vehicle &getVehicle() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const Customer &getCustomer() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        std::optional<Usage> getLastUsage();

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        const TimeFrame &getTime() const;

    private:
        std::vector<Usage> usages;

        TimeFrame time;
        Charge initialCharge;

        Vehicle vehicle;
        Customer customer;
    };
}
