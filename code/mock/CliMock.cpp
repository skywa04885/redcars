#include "CliMock.hpp"

using namespace redcars::model;

redcars::mock::CliMock::CliMock(std::ostream &output) : output(output) {

}

bool redcars::mock::CliMock::fulfillCharge(Charge &charge, const BankAccount &from) {
    output << "Getting €" << charge.getAmount().eurosAsFloat() << " from " << from.getNumber() << std::endl;
    return true;
}

redcars::repo::CustomerRepository &redcars::mock::CliMock::customers() {
    return *this;
}

void redcars::mock::CliMock::createCustomer(const Customer &customer) {
    output << "Creating customer: " << customer.getFirstname() << " " << customer.getLastname() << " "
           << customer.getEmail() << std::endl;
}

bool redcars::mock::CliMock::requestAutomaticCharging(const BankAccount &account) {
    output << "Request automatic charging for " << account.getNumber() << ", success!" << std::endl;
    return true;
}

std::optional<redcars::model::BankAccount> redcars::mock::CliMock::getBankAccountByNumber(const std::string &number) {
    output << "Checking for bank account with number " << number << ", none found" << std::endl;
    return std::nullopt;
}

redcars::repo::BankAccountRepository &redcars::mock::CliMock::bankAccounts() {
    return *this;
}

void redcars::mock::CliMock::verifyCustomerEmail(Customer &customer) {
    output << "Verifying email: " << customer.getEmail() << ", success!" << std::endl;
}

std::optional<redcars::model::Customer> redcars::mock::CliMock::getCustomerByEmail(const std::string &email) {
    output << "Checking for account with email " << email << ", none found" << std::endl;
    return std::nullopt;
}

Money redcars::mock::CliMock::deliverToCustomer(const Customer &customer, const model::Card &card) {
    output << "Delivery card " << card.getNumber() << " to customer " << customer.getAddress() << std::endl;
    return model::Money(1000, std::time(nullptr));
}

redcars::repo::CardRepository &redcars::mock::CliMock::cards() {
    return *this;
}

Card redcars::mock::CliMock::generateCard() {
    output << "Generating card" << std::endl;
    return model::Card("0xdeadbeef");
}

void redcars::mock::CliMock::registerCard(const Card &card) {
    output << "Registering card " << card.getNumber() << std::endl;
}
