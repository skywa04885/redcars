#include "Card.hpp"

Card::Card(std::string number) : number(number) {}

const std::string &Card::getNumber() const { return number; }
