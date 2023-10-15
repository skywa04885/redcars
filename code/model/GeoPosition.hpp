#pragma once

#include "Distance.hpp"

namespace redcars::model {
    /**
    * An immutable object representing geographic position, eg. longitude,
    * latitude.
    * */
    class GeoPosition {
    public:
        GeoPosition(double longitude, double latitude);

        virtual ~GeoPosition() = default;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        double getLongitude() const;

        /**
         * pre-conditions: none
         * post-conditions: none
         * */
        double getLatitude() const;

        /**
         * Calculate the distance between 2 geo points using the Haversine Formula.
         *
         * pre-conditions: none
         * post-conditions: none
         * */
        Distance distanceFrom(const GeoPosition &other) const;

    private:
        double longitude;
        double latitude;
    };
}
