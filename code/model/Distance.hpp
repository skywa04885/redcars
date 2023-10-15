#pragma once

namespace redcars::model {
    class Distance {
    public:
        Distance(int meters);

        virtual ~Distance() = default;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        static Distance fromKm(int kilometers);

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        int asKilometers() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        int asMeters() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        Distance operator-(const Distance &lhs) const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        bool operator<(const Distance &lhs) const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        bool operator>(const Distance &lhs) const;

    private:
        int meters;
    };
}
