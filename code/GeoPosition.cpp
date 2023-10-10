#include "GeoPosition.hpp"
#include <cmath>

GeoPosition::GeoPosition(double longitude, double latitude)
    : longitude(longitude), latitude(latitude) {}

double GeoPosition::getLongitude() const { return longitude; }

double GeoPosition::getLatitude() const { return latitude; }

Distance GeoPosition::distanceFrom(const GeoPosition &other) const {
  // https://stackoverflow.com/questions/27928/calculate-distance-between-two-latitude-longitude-points-haversine-formula
  double distance =
      12742.0 *
      std::asin(std::sqrt(
          0.5 -
          std::cos((getLatitude() - other.getLatitude()) *
                   0.017453292519943295) /
              2.0 +
          std::cos(other.getLatitude() * 0.017453292519943295) *
              std::cos(getLatitude() * 0.017453292519943295) *
              (1.0 - std::cos((getLongitude() - other.getLongitude()) *
                              0.017453292519943295)) /
              2.0));

  return Distance::fromKm(static_cast<int>(distance));
}
