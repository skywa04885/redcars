#include "BankAccount.hpp"

redcars::model::BankAccount::BankAccount(std::string number) : number(number) {}

const std::string &redcars::model::BankAccount::getNumber() const {
    return number;
}
