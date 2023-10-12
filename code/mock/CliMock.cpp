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
