#include "Charge.hpp"
#include "Money.hpp"

redcars::model::Charge::Charge(bool paid, Money amount) : paid(paid), amount(amount) {}

void redcars::model::Charge::pay() { paid = true; }
