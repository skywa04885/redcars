#pragma once

class Distance {
public:
  Distance(int meters);
  virtual ~Distance() = default;

  static Distance fromKm(int kilometers);

  int asKilometers() const;
  int asMeters() const;

  Distance operator-(const Distance &lhs) const;

private:
  int meters;
};