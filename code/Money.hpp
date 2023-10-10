#pragma once

#include <ctime>

class Money {
public:
  Money(unsigned int euroCents, std::time_t valuedAt);
  virtual ~Money() = default;

private:
  unsigned int euroCents;
  std::time_t valuedAt;
};
