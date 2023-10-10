#include "Charge.hpp"

Charge::Charge(bool paid, Money amount) : paid(paid), amount(amount) {}

void Charge::pay() { paid = true; }
