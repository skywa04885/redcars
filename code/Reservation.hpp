#pragma once

#include <ctime>
#include <vector>

#include "TimeFrame.hpp"
#include "Usage.hpp"
#include "Charge.hpp"

class Reservation {
public:
private:
	std::vector<Usage> usages;

	TimeFrame time;
	Charge initialChage;
};
