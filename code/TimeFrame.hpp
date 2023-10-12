#pragma once

#include <ctime>

class TimeFrame {
public:
  TimeFrame(std::time_t start, std::time_t duration);
  virtual ~TimeFrame() = default;

  std::time_t getStart() const;
  std::time_t getDuration() const;
  std::time_t getEnd() const;
  
  bool isInsideOf(const TimeFrame& other) const;
  bool isInsideOf(std::time_t current) const;

private:
  std::time_t start;
  std::time_t duration;
};
