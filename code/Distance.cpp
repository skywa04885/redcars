#include "Distance.hpp"

const int KM_FACTOR = 1000;

Distance::Distance(int meters) : meters(meters) {}

Distance Distance::fromKm(int kilometers) {
  return Distance(kilometers * KM_FACTOR);
}

int Distance::asKilometers() const { return meters / KM_FACTOR; }
int Distance::asMeters() const { return meters; }

Distance Distance::operator-(const Distance &lhs) const {
	return Distance(asMeters() - lhs.asMeters());
}
