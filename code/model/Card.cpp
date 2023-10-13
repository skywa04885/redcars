#include "Card.hpp"

redcars::model::Card::Card(std::string number) : number(number) {}

const std::string &redcars::model::Card::getNumber() const { return number; }
