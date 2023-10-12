#pragma once

#include <ctime>
#include <optional>

#include "Charge.hpp"
#include "Distance.hpp"
#include "TimeFrame.hpp"

class Usage {
public:
  Usage(std::time_t startTime, Distance startDistance);
  virtual ~Usage() = default;

  std::optional<TimeFrame> getTimeFrame() const;
  std::optional<Distance> getDistanceDriven() const;
  void finish(std::time_t duration, Distance endDistance, Charge charge);

private:
  std::time_t startTime;
  std::optional<std::time_t> duration;

  Distance startDistance;
  std::optional<Distance> endDistance;

  std::optional<Charge> charge;
};
